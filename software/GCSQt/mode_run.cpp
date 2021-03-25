#include "mode_run.h"
#include "ui_mode_run.h"

Mode_run::Mode_run(QWidget *parent, CommonObject *co) :
    Mode_common(parent, co),
    ui(new Ui::Mode_run)
{
    ui->setupUi(this);
    g_mode_name = "Mode run";

    g_controller_timer = new QTimer(this);
    connect(g_controller_timer, SIGNAL(timeout()), this, SLOT(remote_controll_cmd()));
    g_logging = false;

    g_3d_scatter = new Q3DScatter();
    g_input_handler = new Q3DInputHandler();
    g_3d_container = QWidget::createWindowContainer(g_3d_scatter);
    g_3d_scatter->setActiveInputHandler(g_input_handler);

    g_3d_scatter->scene()->activeCamera()->setZoomLevel(150.0f);
    g_3d_scatter->scene()->activeCamera()->setCameraPreset( Q3DCamera::CameraPresetBehindBelow);

    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    data << QVector3D(0.0f, 0.0f, 3.0f) << QVector3D(13.2f, 0.0f, 3.0f) << QVector3D(13.2f, 3.6f, 3.0f) << QVector3D(0.0f, 3.6f, 3.0f);
    series->setItemSize(0.2);
    series->dataProxy()->addItems(data);
    g_3d_scatter->addSeries(series);

    data.clear();
    series = new QScatter3DSeries;
    data << QVector3D(0.0f, 0.0f, 0.0f) << QVector3D(13.2f, 0.0f, 0.0f) << QVector3D(13.2f, 3.6f, 0.0f) << QVector3D(0.0f, 3.6f, 0.0f);
    series->dataProxy()->addItems(data);
    series->setBaseColor(QColor(0,255,0));
    series->setItemSize(0.01);
    g_3d_scatter->addSeries(series);

//    data.clear();
//    series = new QScatter3DSeries;
//    data << QVector3D(2.0f, 2.0f, 0.0f);
//    series->dataProxy()->addItems(data);
//    series->setBaseColor(QColor(255,0,0));
//    series->setItemSize(0.1);
//    g_3d_scatter->addSeries(series);

    g_plot_3d = new QPlot3D();
    QCurve3D *skeleton = new QCurve3D();
    skeleton->addData(0,0,0);
    skeleton->addData(QVector3D(13.2,0,0));
    skeleton->addData(QVector3D(13.2,3.6,0));
    skeleton->addData(QVector3D(0,3.6,0));
    skeleton->addData(QVector3D(0,0,3));
    skeleton->addData(QVector3D(13.2,0,3));
    skeleton->addData(QVector3D(13.2,3.6,3));
    skeleton->addData(QVector3D(0,3.6,3));
    skeleton->setColor(Qt::green);
    g_plot_3d->addCurve(skeleton);
}

Mode_run::~Mode_run()
{
    delete g_controller_timer;
    delete ui;
}

void Mode_run::select(){
   clear_drawing_area();
   g_co->drawing_area->addWidget(g_3d_container);
//   g_co->drawing_area->addWidget(g_plot_3d);
}

void Mode_run::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_EVT_RPY:
        mavlink_evt_rpy_t evt_rpy;
        mavlink_msg_evt_rpy_decode(msg, &evt_rpy);
        ui->txtBoxRoll->setText(QString::number(static_cast<double>(evt_rpy.roll)));
        ui->txtBoxPitch->setText(QString::number(static_cast<double>(evt_rpy.pitch)));
        ui->txtBoxYaw->setText(QString::number(static_cast<double>(evt_rpy.yaw)));
        break;
    case MAVLINK_MSG_ID_EVT_SENSOR:
        mavlink_evt_sensor_t sensor_status;
        mavlink_msg_evt_sensor_decode(msg,&sensor_status);
        if(sensor_status.imu_status == SENSOR_IMU_OK){
            show_status("IMU OK", 1000);
        }
        else{
            show_status("IMU ERROR", 1000);
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT_CAL:
        mavlink_evt_tilt_raw_t tilt_msg;
        mavlink_msg_evt_tilt_raw_decode(msg,&tilt_msg);
        ui->tb_tilt_cal->setText(QString::number(tilt_msg.tilt));
        break;
    case MAVLINK_MSG_ID_CONTROL:
        if(g_logging){
            mavlink_control_t control;
            mavlink_msg_control_decode(msg, &control);
            QString line;
            line = "C " + QString::number(control.left) + " " + QString::number(control.right) + "\n";
            g_file_control_measurement.write(line.toStdString().c_str());
            ui->pteControl->appendHtml(line);
        }
        break;
    case MAVLINK_MSG_ID_MEASUREMENT:
        if(g_logging){
            mavlink_measurement_t measurement;
            mavlink_msg_measurement_decode(msg, &measurement);
            QString line;
            line =  "M " + QString::number(measurement.x) + " " + QString::number(measurement.y) + " " + QString::number(measurement.z)
                    + " " + QString::number(measurement.r) + " " + QString::number(measurement.yaw) + "\n";
            g_file_control_measurement.write(line.toStdString().c_str());
            ui->pteMeasurement->appendHtml(line);
        }
    }
}

void Mode_run::remote_controll_cmd(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    float VX = ui->txtb_pidt_vx->text().toFloat();
    float OMEGA = ui->txtb_pidt_w->text().toFloat();
    mavlink_msg_cmd_velocity_pack(0,0,&msg,VX,OMEGA);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
}

void Mode_run::on_btn_control_enable_clicked()
{
    if(g_control_enable == false){
        g_control_enable=true;
        ui->btn_control_enable->setText("Enabled");
        g_controller_timer->start(100);
    }
    else{
        g_control_enable = false;
        ui->btn_control_enable->setText("Disabled");
        g_controller_timer->stop();
    }
}

void Mode_run::on_btn_change_mode_run_clicked()
{
    emit mode_change(MODE_RUN);
}

void Mode_run::update_joystick(int axis, double value){
    switch (axis){
    case 0:
        ui->txtb_pidt_w->setText(QString::number(value));
        break;
    case 1:
        ui->txtb_pidt_vx->setText(QString::number(value));
    }
}

void Mode_run::on_btn_log_clicked()
{
    if(g_logging){
        g_logging = false;
        ui->btn_log->setText("Log");
        if(g_file_control_measurement.isOpen()){
            g_file_control_measurement.close();
        }
    }
    else{
        g_file_control_measurement.setFileName("control_measurement.txt");
        if(g_file_control_measurement.open(QIODevice::WriteOnly | QIODevice::Text)){
            g_logging = true;
            ui->btn_log->setText("Logging");
            ui->pteMeasurement->clear();
            ui->pteControl->clear();
        }
    }
}
