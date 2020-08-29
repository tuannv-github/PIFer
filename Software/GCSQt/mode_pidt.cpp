#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_mode_pidt_mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_PID_PARAMS:
        if(isDoStSuccessfull == false){
            isDoStSuccessfull = true;
            mavlink_pid_params_t pid;
            mavlink_msg_pid_params_decode(msg, &pid);
            showStatus("Succeed to load PID params",2000);
            ui->sb_KP->setValue(pid.sta_KP);
            ui->sb_KI->setValue(pid.sta_KI);
            ui->sb_KD->setValue(pid.sta_KD);
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
    case MAVLINK_MSG_ID_EVT_TILT:
        mavlink_evt_tilt_t tilt_msg;
        mavlink_msg_evt_tilt_decode(msg,&tilt_msg);
        on_tilt_recv(tilt_msg.tilt);
        break;
    }
}

void MainWindow::load_pid_params(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_LOAD);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    if(send(QByteArray::fromRawData((char*)(mav_send_buf),len))){
        showStatus("Loading PID params",1000);
   }
   else{
       showStatus("Cannot load PID params",1000);
   }
   isDoStSuccessfull = false;
   QTimer::singleShot(3000, this, SLOT(mode_pidt_load_timeout()));
}


void MainWindow::mode_pidt_load_timeout(){
    if(!isDoStSuccessfull){
        isDoStSuccessfull = true;
        showStatus("Unable to load PID params",2000);
    }
}

void MainWindow::mode_pidt_write_timeout(){
    if(!isDoStSuccessfull){
        isDoStSuccessfull = true;
        showStatus("Unable to write PID params",2000);
    }
}

void MainWindow::mode_pidt_save_timeout(){
    if(!isDoStSuccessfull){
        isDoStSuccessfull = true;
        showStatus("Unable to save PID params",2000);
    }
}

void MainWindow::write_pid_params(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    double KP = ui->sb_KP->value();
    double KI = ui->sb_KI->value();
    double KD = ui->sb_KD->value();
    mavlink_msg_pid_params_pack(0,0,&msg,0,0,0,0,0,0,KP,KI,KD,0,0,0);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    if(send(QByteArray::fromRawData((char*)(mav_send_buf),len))){
        showStatus("Writing PID params",2000);
   }
   else{
       showStatus("Cannot write PID params",2000);
   }
   isDoStSuccessfull = false;
   QTimer::singleShot(3000, this, SLOT(mode_pidt_write_timeout()));
}

void MainWindow::save_pid_params(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_SAVE);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    if(send(QByteArray::fromRawData((char*)(mav_send_buf),len))){
        showStatus("Saving PID params",1000);
   }
   else{
       showStatus("Cannot save PID params",1000);
   }
   isDoStSuccessfull = false;
   QTimer::singleShot(3000, this, SLOT(mode_pidt_save_timeout()));
}

void MainWindow::on_btn_mode_pidt_load_params_clicked()
{
    if(currentMode == MODE_PID){
        load_pid_params();
    }
    else{
        showStatus("Change mode to pid tunning first",2000);
    }
}

void MainWindow::on_btn_mode_pidt_write_params_clicked()
{
    if(currentMode == MODE_PID){
        write_pid_params();
    }
    else{
        showStatus("Change mode to pid tunning first",2000);
    }
}

void MainWindow::on_btn_mode_pidt_save_params_clicked()
{
    if(currentMode == MODE_PID){
        save_pid_params();
    }
    else{
        showStatus("Change mode to pid tunning first",2000);
    }
}

void MainWindow::on_sb_step_KP_valueChanged(const QString &arg1)
{
    ui->sb_KP->setSingleStep(ui->sb_step_KP->value());
}

void MainWindow::on_sb_step_KI_valueChanged(const QString &arg1)
{
    ui->sb_KI->setSingleStep(ui->sb_step_KI->value());
}

void MainWindow::on_sb_KD_valueChanged(const QString &arg1)
{
    ui->sb_KD->setSingleStep(ui->sb_step_KD->value());
}
