#include "mode_pidt_ta.h"
#include "ui_mode_pidt_ta.h"

Mode_pidt_ta::Mode_pidt_ta(QWidget *parent) :
    Mode_common(parent),
    ui(new Ui::Mode_pidt_ta)
{
    ui->setupUi(this);
    g_mode_name = "PIDT";
    g_controller_timer = new QTimer(this);
    connect(g_controller_timer, SIGNAL(timeout()), this, SLOT(remote_control_pidt()));
    g_control_enable = false;
}

Mode_pidt_ta::~Mode_pidt_ta()
{
    delete ui;
}

void Mode_pidt_ta::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_PID_PARAMS:
        {
            reset_timeout();

            mavlink_pid_params_t pid;
            mavlink_msg_pid_params_decode(msg, &pid);
            show_status("Succeed to load PID params",2000);

            switch (pid.pid_control) {
                case PID_WHE0:
                    ui->sb_w0_kp->setValue(static_cast<double>(pid.KP));
                    ui->sb_w0_ki->setValue(static_cast<double>(pid.KI));
                    ui->sb_w0_kd->setValue(static_cast<double>(pid.KD));
                break;
                case PID_WHE1:
                    ui->sb_w1_kp->setValue(static_cast<double>(pid.KP));
                    ui->sb_w1_ki->setValue(static_cast<double>(pid.KI));
                    ui->sb_w1_kd->setValue(static_cast<double>(pid.KD));
                break;
                case PID_SYNC:
                    ui->sb_sta_kp->setValue(static_cast<double>(pid.KP));
                    ui->sb_sta_ki->setValue(static_cast<double>(pid.KI));
                    ui->sb_sta_kd->setValue(static_cast<double>(pid.KD));
                break;
            }
        }
        break;
    case MAVLINK_MSG_ID_RESPOND:
        if(g_does_st_successfullly == false){
            mavlink_respond_t evt_respond;
            mavlink_msg_respond_decode(msg,&evt_respond);
            if(evt_respond.respond == RESPOND_OK){
                reset_timeout();
                show_status("Succeed to write or save params",2000);
            }
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT:
        mavlink_evt_tilt_t tilt_msg;
        mavlink_msg_evt_tilt_decode(msg,&tilt_msg);
//        on_tilt_recv(tilt_msg.tilt);
        break;
    case MAVLINK_MSG_ID_PID_REPORT:
//        on_pid_report_recv(msg);
        break;
    case MAVLINK_MSG_ID_MOTOR_SPEED:
        mavlink_motor_speed_t motor_speed_msg;
        mavlink_msg_motor_speed_decode(msg, &motor_speed_msg);
        ui->txtb_enc0_ta_speed->setText(QString::number(motor_speed_msg.motor_speed_0));
        ui->txtb_enc1_ta_speed->setText(QString::number(motor_speed_msg.motor_speed_1));
        break;
    }
}

void Mode_pidt_ta::on_btn_change_mode_pidt_clicked()
{
    emit mode_change(MODE_PIDT_TA);
}

void Mode_pidt_ta::on_btn_mode_pidt_load_params_clicked()
{
    load_params();
}

void Mode_pidt_ta::on_btn_mode_pidt_write_params_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float sync_KP = static_cast<float>(ui->sb_sta_kp->value());
    float sync_KI = static_cast<float>(ui->sb_sta_ki->value());
    float sync_KD = static_cast<float>(ui->sb_sta_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_SYNC,sync_KP,sync_KI,sync_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    float w0_KP = static_cast<float>(ui->sb_w0_kp->value());
    float w0_KI = static_cast<float>(ui->sb_w0_ki->value());
    float w0_KD = static_cast<float>(ui->sb_w0_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_WHE0,w0_KP,w0_KI,w0_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    float w1_KP = static_cast<float>(ui->sb_w1_kp->value());
    float w1_KI = static_cast<float>(ui->sb_w1_ki->value());
    float w1_KD = static_cast<float>(ui->sb_w1_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_WHE1,w1_KP,w1_KI,w1_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_ta::on_btn_mode_pidt_save_params_clicked()
{
    save_params();
}

void Mode_pidt_ta::on_btn_mode_pidt_write_params_pid_whe0_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float w0_KP = static_cast<float>(ui->sb_w0_kp->value());
    float w0_KI = static_cast<float>(ui->sb_w0_ki->value());
    float w0_KD = static_cast<float>(ui->sb_w0_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_WHE0,w0_KP,w0_KI,w0_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_ta::on_btn_mode_pidt_write_params_pid_whe1_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float w1_KP = static_cast<float>(ui->sb_w1_kp->value());
    float w1_KI = static_cast<float>(ui->sb_w1_ki->value());
    float w1_KD = static_cast<float>(ui->sb_w1_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_WHE1,w1_KP,w1_KI,w1_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_ta::on_btn_mode_pidt_write_params_pid_sync_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float sync_KP = static_cast<float>(ui->sb_sta_kp->value());
    float sync_KI = static_cast<float>(ui->sb_sta_ki->value());
    float sync_KD = static_cast<float>(ui->sb_sta_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_SYNC,sync_KP,sync_KI,sync_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_ta::on_btn_set_speed0_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t motor0_duty = static_cast<int16_t>(ui->txtb_motor0_speed->text().toInt());
    int16_t motor1_duty = static_cast<int16_t>(ui->txtb_motor1_speed->text().toInt());

    mavlink_msg_motor_speed_pack(0,0,&msg,motor0_duty,motor1_duty);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Set wheel speed",1000);

}

void Mode_pidt_ta::on_btn_set_speed1_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t motor0_duty = static_cast<int16_t>(ui->txtb_motor0_speed->text().toInt());
    int16_t motor1_duty = static_cast<int16_t>(ui->txtb_motor1_speed->text().toInt());

    mavlink_msg_motor_speed_pack(0,0,&msg,motor0_duty,motor1_duty);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Set wheel speed",1000);
}

void Mode_pidt_ta::update_joystick(axis_t axis, double value){
    switch (axis){
    case AXIS_0:
        ui->txtb_pidt_w->setText(QString::number(value));
        break;
    case AXIS_1:
        ui->txtb_pidt_vx->setText(QString::number(value));
    }
}

void Mode_pidt_ta::on_btn_control_enable_clicked()
{
    if(g_control_enable == false){
        g_control_enable = true;
        ui->btn_control_enable->setText("Enabled");
        g_controller_timer->start(100);
    }
    else{
        g_control_enable = false;
        ui->btn_control_enable->setText("Disabled");
        g_controller_timer->stop();
    }
}

void Mode_pidt_ta::remote_control_pidt(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t VX = static_cast<int16_t>(ui->txtb_pidt_vx->text().toDouble()*80);
    int16_t OMEGA = static_cast<int16_t>(ui->txtb_pidt_w->text().toDouble()*100/2);
    if(VX > -5 && VX < 5) VX = 0;
    if(VX > 100) VX = 100;
    if(VX < -100) VX = -100;
    if(OMEGA > -5 && OMEGA < 5) OMEGA = 0;
    if(OMEGA > 100) OMEGA = 100;
    if(OMEGA < -100) OMEGA = -100;
    mavlink_msg_cmd_velocity_pack(0,0,&msg,VX,OMEGA);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
}

void Mode_pidt_ta::on_btn_change_mode_pidt_ta_clicked()
{

}
