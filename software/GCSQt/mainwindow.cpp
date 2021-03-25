#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("GCS");

    // Prepare status bar and led indicator
    g_led_indicator = new Led_indicator();
    ui->statusBar->addPermanentWidget(g_led_indicator);

    // Prepare joystick
    g_qjs = QJoysticks::getInstance();
    g_qjs->setVirtualJoystickRange(1);
    connect(g_qjs,SIGNAL(axisChanged(const int, const int, const qreal)),this,SLOT(js_axis_change(const int, const int, const qreal)));

    // Com
    g_com_gui = new Com_gui();
    // Message forwarding: com -> main -> mode
    connect(ui->wg_com,SIGNAL(ba_recv(QByteArray)),this,SLOT(app_main_on_data_recv(QByteArray)));
    connect(ui->wg_com,SIGNAL(connection_evt(Com::com_evt_t)),this,SLOT(com_connection_evt(Com::com_evt_t)));
    ui->wg_com->set_com_gui(g_com_gui);
    ui->wg_com->set_led_indicator(g_led_indicator);

    g_co.setStatusBar(ui->statusBar);
    g_co.setDrawingArea(ui->glDrawer);

    g_mode.append(new Mode_run(this, &g_co));
    g_mode.append(new Mode_hw_tw(this, &g_co));
    g_mode.append(new Mode_imu(this, &g_co));
    g_mode.append(new Mode_pidt_tw(this, &g_co));
    //g_mode.append(new Mode_pidt_ta(this, &g_co));

    for (Mode_common* &mode : g_mode){
        ui->Maintab->addTab(mode, mode->getName());
        // Mode change
        connect(mode,SIGNAL(mode_change(rmode_t)),this,SLOT(app_command_change_mode(rmode_t)));
        // Message forwarding: mode -> main -> com
        connect(mode,SIGNAL(mav_send(QByteArray)),this,SLOT(app_main_message_forward(QByteArray)));
    }
    connect(ui->Maintab, SIGNAL(currentChanged(int)), this, SLOT(onCurrentChanged(int)));
    g_mode[0]->select();

    g_current_mode = MODE_RUN;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_status(QString qstr, int timeout){
    ui->statusBar->showMessage(qstr,timeout);
}

void MainWindow::com_connection_evt(Com::com_evt_t evt){
    switch (evt) {
    case Com::SERIAL_OPEN_SUCCESS:
        show_status("Serial port opened",1000);
        break;
    case Com::SERIAL_OPEN_FAIL:
        show_status("Unable to open serial port",1000);
        break;
    case Com::SERIAL_CLOSED:
        show_status("Serial port closed",1000);
        break;
    case Com::TCP_SERVER_OPEN_SUCCESS:
        show_status("TCP server opened",1000);
        break;
    case Com::TCP_SERVER_OPEN_FAIL:
        show_status("Unable to open TCP server",1000);
        break;
    case Com::TCP_SERVER_CLOSED:
        show_status("TCP server closed",1000);
        break;
    case Com::SOCKET_CONNECTION_OPEN:
        show_status("Socket opened",1000);
        break;
    case Com::SOCKET_CONNECTION_CLOSE:
        show_status("Socket closed",1000);
        break;
    }
}

void MainWindow::js_axis_change(const int js, const int axis, const qreal value){
    Q_UNUSED(js)
    for (Mode_common* &mode : g_mode){
        mode->update_joystick(axis, -value);
    }
}

void MainWindow::app_main_on_data_recv(QByteArray bytes){
    for(uint16_t i = 0; i < bytes.size(); i++){
        uint8_t msg_received = mavlink_parse_char(MAVLINK_COMM_0, static_cast<uint8_t>(bytes[i]), &msg, &status);
        if(msg_received == 1){
            if(msg.msgid == MAVLINK_MSG_ID_RESPOND && g_is_changing_mode){
                g_is_changing_mode = false;
                mavlink_respond_t evt_respond;
                mavlink_msg_respond_decode(&msg, &evt_respond);
                if(evt_respond.respond == RESPOND_OK){
                    g_change_mode_success = true;
                    show_status("Succeed to change mode",1000);
                    switch (g_change_to_mode) {
                    case MODE_RUN:
                        g_current_mode = MODE_RUN;
                        break;
                    case MODE_IMU:
                        g_current_mode = MODE_IMU;
                        break;
                    case MODE_PIDT_TW:
                        g_current_mode = MODE_PIDT_TW;
                        break;
                    case MODE_PIDT_TA:
                        g_current_mode = MODE_PIDT_TA;
                        break;
                    case MODE_HW:
                        g_current_mode = MODE_HW;
                        break;
                    default:
                        break;
                    }
                }
                qDebug() << "Mode: " << g_current_mode;
            }
            else{
                switch (g_current_mode) {
                case MODE_RUN:
                    g_mode_run->mav_recv(&msg);
                    break;
                case MODE_IMU:
                    g_mode_imu->mav_recv(&msg);
                    break;
                case MODE_PIDT_TW:
                    g_mode_pidt_tw->mav_recv(&msg);
                    break;
                case MODE_PIDT_TA:
                    g_mode_pidt_ta->mav_recv(&msg);
                    break;
                case MODE_HW:
                    g_mode_hw_tw->mav_recv(&msg);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void MainWindow::app_main_message_forward(QByteArray bytes){
    g_com_gui->send(bytes);
}

void MainWindow::app_command_change_mode_timeout(){
    g_is_changing_mode = false;
    if(!g_change_mode_success){
        show_status("Unable to change mode",1000);
    }
}

void MainWindow::app_command_change_mode(rmode_t mode){
    g_is_changing_mode = true;
    g_change_to_mode = mode;
    g_change_mode_success = false;

    mavlink_message_t msg;
    uint8_t gmav_send_buf[255];
    mavlink_msg_cmd_change_mode_pack(0,0,&msg, mode);
    uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);

    show_status("Changing mode",1000);
    ui->wg_com->send(gmav_send_buf,len);
    QTimer::singleShot(1000, this, SLOT(app_command_change_mode_timeout()));
}

void MainWindow::onCurrentChanged(int index){
    g_mode[index]->select();
}
