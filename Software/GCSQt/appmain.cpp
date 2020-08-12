#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::app_main_init(){
    g_current_mode = MODE_RUN;
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

