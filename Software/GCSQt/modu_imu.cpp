#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_mode_imu_mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_EVT_IMU_RAW:
        mavlink_evt_imu_raw_t gyro_raw;
        mavlink_msg_evt_imu_raw_decode(msg, &gyro_raw);
        ui->tb_gx->setText(QString::number(gyro_raw.gyro_x));
        ui->tb_gy->setText(QString::number(gyro_raw.gyro_y));
        ui->tb_gz->setText(QString::number(gyro_raw.gyro_z));
        ui->tb_stand_point_current->setText(QString::number(gyro_raw.roll));
        if(is_imu_calibrating){
            gx_offset = (gx_offset + gyro_raw.gyro_x)/2;
            gy_offset = (gy_offset + gyro_raw.gyro_y)/2;
            gz_offset = (gz_offset + gyro_raw.gyro_z)/2;
            stand_point = (stand_point + gyro_raw.roll)/2;
            ui->tb_gx_offset->setText(QString::number(gx_offset));
            ui->tb_gy_offset->setText(QString::number(gy_offset));
            ui->tb_gz_offset->setText(QString::number(gz_offset));
            ui->tb_stand_point->setText(QString::number(stand_point));
        }
        break;
    case MAVLINK_MSG_ID_RESPOND:
        if(isDoStSuccessfull == false){
            mavlink_respond_t evt_respond;
            mavlink_msg_respond_decode(msg,&evt_respond);
            if(evt_respond.respond == RESPOND_OK){
                isDoStSuccessfull = true;
                showStatus("Succeed to write or save params",2000);
            }
        }
        break;
    case MAVLINK_MSG_ID_IMU_PARAMS:
        {
            mavlink_imu_params_t gyro_offet;
            mavlink_msg_imu_params_decode(msg,&gyro_offet);
            gx_offset = gyro_offet.gyro_offet_x;
            gy_offset = gyro_offet.gyro_offet_y;
            gz_offset = gyro_offet.gyro_offet_z;
            stand_point = gyro_offet.angle_ajusted;
            ui->tb_gx_offset->setText(QString::number(gx_offset));
            ui->tb_gy_offset->setText(QString::number(gy_offset));
            ui->tb_gz_offset->setText(QString::number(gz_offset));
            ui->tb_stand_point->setText(QString::number(stand_point));
        }
        break;
    default:
        break;
    }
}

void MainWindow::mode_imu_load_timeout(){
    if(!isDoStSuccessfull){
        isDoStSuccessfull = true;
        showStatus("Unable to load gyro offset params",2000);
    }
}

void MainWindow::mode_imu_write_timeout(){
    if(!isDoStSuccessfull){
        isDoStSuccessfull = true;
        showStatus("Unable to write gyro offset params",2000);
    }
}

void MainWindow::mode_imu_save_timeout(){
    if(!isDoStSuccessfull){
        isDoStSuccessfull = true;
        showStatus("Unable to save gyro offset params",2000);
    }
}

void MainWindow::on_btn_mode_imu_load_params_clicked()
{
    if(currentMode != MODE_IMU){
        showStatus("Change mode to imu calibration first",1000);
        return;
    }
    ui->tb_gx_offset->setText("");
    ui->tb_gy_offset->setText("");
    ui->tb_gz_offset->setText("");
    ui->tb_stand_point->setText("");
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_LOAD);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    if(send(QByteArray::fromRawData((char*)(mav_send_buf),len))){
        showStatus("Loading gyro offset params",1000);
   }
   else{
       showStatus("Cannot load gyro offset params",1000);
   }
   isDoStSuccessfull = false;
   QTimer::singleShot(1000, this, SLOT(mode_imu_load_timeout()));
}

void MainWindow::on_btn_mode_imu_write_params_clicked()
{
    if(currentMode != MODE_IMU){
        showStatus("Change mode to imu calibration first",1000);
        return;
    }
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t tbgx_offset = ui->tb_gx_offset->text().toInt();
    int16_t tbgy_offset = ui->tb_gy_offset->text().toInt();
    int16_t tbgz_offset = ui->tb_gz_offset->text().toInt();
    float tbstand_point = ui->tb_stand_point->text().toFloat();
    mavlink_msg_imu_params_pack(0,0,&msg,tbgx_offset,tbgy_offset,tbgz_offset,tbstand_point,0.99);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    if(send(QByteArray::fromRawData((char*)(mav_send_buf),len))){
        showStatus("Writing gyro offset params",1000);
   }
   else{
       showStatus("Cannot write gyro offset params",1000);
   }
   isDoStSuccessfull = false;
   QTimer::singleShot(1000, this, SLOT(mode_imu_write_timeout()));
}

void MainWindow::on_btn_mode_imu_save_params_clicked()
{
    if(currentMode != MODE_IMU){
        showStatus("Change mode to imu calibration first",1000);
        return;
    }

    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_SAVE);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    if(send(QByteArray::fromRawData((char*)(mav_send_buf),len))){
        showStatus("Saving gyro offset params",1000);
   }
   else{
       showStatus("Cannot save gyro offset params",1000);
   }
   isDoStSuccessfull = false;
   QTimer::singleShot(1000, this, SLOT(mode_imu_save_timeout()));
}

void MainWindow::on_btn_gyro_calib_clicked()
{
    if(!is_imu_calibrating){
        is_imu_calibrating = true;
        gx_offset = 0;
        gy_offset = 0;
        gz_offset = 0;
        ui->tb_gx_offset->setText(QString::number(gx_offset));
        ui->tb_gy_offset->setText(QString::number(gy_offset));
        ui->tb_gz_offset->setText(QString::number(gz_offset));
        ui->btn_gyro_calib->setText("Calibrating");
    }
    else{
        is_imu_calibrating = false;
        ui->btn_gyro_calib->setText("Calibrate");
    }
}


