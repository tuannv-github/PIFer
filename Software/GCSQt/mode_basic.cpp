#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_mode_basic_mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_EVT_RPY:
        mavlink_evt_rpy_t evt_rpy;
        mavlink_msg_evt_rpy_decode(msg, &evt_rpy);
        ui->txtBoxRoll->setText(QString::number(evt_rpy.roll));
        ui->txtBoxPitch->setText(QString::number(evt_rpy.pitch));
        break;
    case MAVLINK_MSG_ID_EVT_SENSOR:
        mavlink_evt_sensor_t sensor_status;
        mavlink_msg_evt_sensor_decode(msg,&sensor_status);
        if(sensor_status.imu_status == SENSOR_IMU_OK){
            ui->txtBoxMPU->setText("GOOD");
        }
        else{
            ui->txtBoxMPU->setText("BAD");
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT:
        mavlink_evt_tilt_t tilt_msg;
        mavlink_msg_evt_tilt_decode(msg,&tilt_msg);
        on_tilt_recv(tilt_msg.tilt);
        break;
    }
}

void MainWindow::on_js_axis_change(const int js, const int axis, const qreal value){
    if(axis == 0){
            ui->txtBoxOMEGA->setText((QString::number(value)));
    }
    else if(axis == 1){
            ui->txtBoxVX->setText(QString::number((value)));
    }
}

void MainWindow::on_controller_cmd(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t VX = ui->txtBoxVX->text().toDouble()*100;
    int16_t OMEGA = ui->txtBoxOMEGA->text().toDouble()*100;
    qDebug() << VX << " " << OMEGA;
    mavlink_msg_cmd_velocity_pack(0,0,&msg,VX,OMEGA);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    send(QByteArray::fromRawData((char*)(mav_send_buf),len));
}
