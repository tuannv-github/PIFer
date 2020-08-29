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

    // Prepare plotter
    g_q_custom_plot.append(ui->plot_0);
    g_q_custom_plot.append(ui->plot_1);
    g_q_custom_plot.append(ui->plot_2);
    g_q_custom_plot.append(ui->plot_3);
    g_q_custom_plot.append(ui->plot_4);
    g_q_custom_plot.append(ui->plot_5);
    for(int i=0;i < g_q_custom_plot.size();i++){
        for(int j = 0 ; j < 6; j ++){
            g_q_custom_plot[i]->addGraph();
            g_q_custom_plot[i]->graph(j)->setPen(QPen(QColor(10*i%255,20*j%255,30*i*j%255)));
        }
    }

    // Com
    g_com_gui = new Com_gui();
    // Message forwarding: com -> main -> mode
    connect(ui->wg_com,SIGNAL(ba_recv(QByteArray)),this,SLOT(app_main_on_data_recv(QByteArray)));
    connect(ui->wg_com,SIGNAL(connection_evt(Com::com_evt_t)),this,SLOT(com_connection_evt(Com::com_evt_t)));
    ui->wg_com->set_com_gui(g_com_gui);
    ui->wg_com->set_led_indicator(g_led_indicator);

    // Run mode
    g_mode_run = new Mode_run();
    g_mode_run->set_status_bar(ui->statusBar);
    g_mode_run->set_plotter(g_q_custom_plot);

    // Imu mode
    g_mode_imu = new Mode_imu();
    g_mode_imu->set_status_bar(ui->statusBar);
    g_mode_imu->set_plotter(g_q_custom_plot);

    // PID mode of tw robot
    g_mode_pidt_tw = new Mode_pidt_tw();
    g_mode_pidt_tw->set_status_bar(ui->statusBar);
    g_mode_pidt_tw->set_plotter(g_q_custom_plot);

    // PID mode of ta robot
    g_mode_pidt_ta = new Mode_pidt_ta();
    g_mode_pidt_ta->set_status_bar(ui->statusBar);
    g_mode_pidt_ta->set_plotter(g_q_custom_plot);

    // Hardware mode
    g_mode_hw_tw = new Mode_hw_tw();
    g_mode_hw_tw->set_status_bar(ui->statusBar);
    g_mode_hw_tw->set_plotter(g_q_custom_plot);

    // Add mode tab
    ui->Maintab->addTab(g_mode_run,"Mode Run");
    ui->Maintab->addTab(g_mode_imu,"Mode IMU");
    ui->Maintab->addTab(g_mode_hw_tw,"Mode HW");
    ui->Maintab->addTab(g_mode_pidt_tw,"Mode PIDT TW");
    ui->Maintab->addTab(g_mode_pidt_ta,"Mode PIDT TA");
    ui->Maintab->addTab(g_com_gui,"Com");

    // Mode change
    connect(g_mode_run,SIGNAL(mode_change(rmode_t)),this,SLOT(app_command_change_mode(rmode_t)));
    connect(g_mode_imu,SIGNAL(mode_change(rmode_t)),this,SLOT(app_command_change_mode(rmode_t)));
    connect(g_mode_hw_tw,SIGNAL(mode_change(rmode_t)),this,SLOT(app_command_change_mode(rmode_t)));
    connect(g_mode_pidt_tw,SIGNAL(mode_change(rmode_t)),this,SLOT(app_command_change_mode(rmode_t)));
    connect(g_mode_pidt_ta,SIGNAL(mode_change(rmode_t)),this,SLOT(app_command_change_mode(rmode_t)));

    // Message forwarding: mode -> main -> com
    connect(g_mode_run,SIGNAL(mav_send(QByteArray)),this,SLOT(app_main_message_forward(QByteArray)));
    connect(g_mode_hw_tw,SIGNAL(mav_send(QByteArray)),this,SLOT(app_main_message_forward(QByteArray)));
    connect(g_mode_imu,SIGNAL(mav_send(QByteArray)),this,SLOT(app_main_message_forward(QByteArray)));
    connect(g_mode_pidt_tw,SIGNAL(mav_send(QByteArray)),this,SLOT(app_main_message_forward(QByteArray)));
    connect(g_mode_pidt_ta,SIGNAL(mav_send(QByteArray)),this,SLOT(app_main_message_forward(QByteArray)));

    app_main_init();
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
    if(axis == 0){
        g_mode_pidt_tw->update_joystick(Mode_common::AXIS_0, value);
        g_mode_pidt_ta->update_joystick(Mode_common::AXIS_0, value);
        g_mode_run->update_joystick(Mode_common::AXIS_0, value);
    }
    else if(axis == 1){
        g_mode_pidt_tw->update_joystick(Mode_common::AXIS_1, -value);
        g_mode_pidt_ta->update_joystick(Mode_common::AXIS_1, -value);
        g_mode_run->update_joystick(Mode_common::AXIS_1, -value);
    }
}
