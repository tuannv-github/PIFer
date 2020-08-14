#include "mode_pidt_tw.h"
#include "ui_mode_pidt_tw.h"

Mode_pidt_tw::Mode_pidt_tw(QWidget *parent) :
    Mode_common(parent),
    ui(new Ui::Mode_pidt_tw)
{
    ui->setupUi(this);
    g_controller_timer = new QTimer(this);
    connect(g_controller_timer, SIGNAL(timeout()), this, SLOT(remote_control_pidt()));

    pid_tilt_sp_fb = QVector<QVector<double>>(3);
    pid_vel_sp_fb = QVector<QVector<double>>(3);
    pid_pos_sp_fb = QVector<QVector<double>>(3);

    pid_tilt = QVector<QVector<double>>(5);
    pid_vel = QVector<QVector<double>>(5);
    pid_pos = QVector<QVector<double>>(5);
}

Mode_pidt_tw::~Mode_pidt_tw()
{
    delete ui;
}

void Mode_pidt_tw::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_PID_PARAMS:
            reset_timeout();
            mavlink_pid_params_t pid;
            mavlink_msg_pid_params_decode(msg, &pid);
            show_status("Succeed to load PID params",2000);
            switch (pid.pid_control) {
                case PID_TILT:
                    ui->sb_pid_tilt_kp->setValue(static_cast<double>(pid.KP));
                    ui->sb_pid_tilt_ki->setValue(static_cast<double>(pid.KI));
                    ui->sb_pid_tilt_kd->setValue(static_cast<double>(pid.KD));
                break;
                case PID_VEL:
                    ui->sb_pid_vel_kp->setValue(static_cast<double>(pid.KP));
                    ui->sb_pid_vel_ki->setValue(static_cast<double>(pid.KI));
                    ui->sb_pid_vel_kd->setValue(static_cast<double>(pid.KD));
                break;
                case PID_POS:
                    ui->sb_pid_pos_kp->setValue(static_cast<double>(pid.KP));
                    ui->sb_pid_pos_ki->setValue(static_cast<double>(pid.KI));
                    ui->sb_pid_pos_kd->setValue(static_cast<double>(pid.KD));
                break;
        }
        break;
    case MAVLINK_MSG_ID_RESPOND:
        if(is_timing()){
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
        pid_report_recv(msg);
        break;
    }
}

void Mode_pidt_tw::pid_plot(uint32_t len, QVector<QVector<double>> q, QCustomPlot *q_custom_plot){

    double min_y = vector_min(q[1]);
    double max_y = vector_max(q[1]);

    for (int i=2; i < q.size(); i++) {
        min_y = std::min(min_y, vector_min(q[i]));
    }

    for (int i=2; i < q.size(); i++) {
        max_y = std::max(max_y, vector_max(q[i]));
    }

    q_custom_plot->xAxis->setRange(len-PID_VECTOR_LEN, len);
    q_custom_plot->yAxis->setRange(min_y-5,max_y+5);

    for (int i=1; i < q.size(); i++) {
        q_custom_plot->graph(i)->setData(q[0],q[i]);
    }
    q_custom_plot->replot();
}

void Mode_pidt_tw::pid_report_recv(mavlink_message_t *msg){
    static uint32_t tilt_cnt = 0;
    static uint32_t vel_cnt = 0;
    static uint32_t pos_cnt = 0;


    mavlink_pid_report_t pid_report_msg;
    mavlink_msg_pid_report_decode(msg,&pid_report_msg);
    switch(pid_report_msg.pid_control){
    case PID_TILT:
        pid_tilt_sp_fb[0].append(tilt_cnt);
        pid_tilt_sp_fb[1].append(static_cast<double>(pid_report_msg.sp));
        pid_tilt_sp_fb[2].append(static_cast<double>(pid_report_msg.fb));
        truncate_matrix(pid_tilt_sp_fb);

        pid_tilt[0].append(tilt_cnt);
        pid_tilt[1].append(static_cast<double>(pid_report_msg.P_Part));
        pid_tilt[2].append(static_cast<double>(pid_report_msg.I_Part));
        pid_tilt[3].append(static_cast<double>(pid_report_msg.D_Part));
        pid_tilt[4].append(static_cast<double>(pid_report_msg.U));
        truncate_matrix(pid_tilt);

        pid_plot(tilt_cnt, pid_tilt, g_q_custom_plot[0]);
        pid_plot(tilt_cnt, pid_tilt_sp_fb, g_q_custom_plot[1]);

        tilt_cnt++;
        break;
    case PID_VEL:
        pid_vel_sp_fb[0].append(vel_cnt);
        pid_vel_sp_fb[1].append(static_cast<double>(pid_report_msg.sp));
        pid_vel_sp_fb[2].append(static_cast<double>(pid_report_msg.fb));
        truncate_matrix(pid_vel_sp_fb);

        pid_vel[0].append(vel_cnt);
        pid_vel[1].append(static_cast<double>(pid_report_msg.P_Part));
        pid_vel[2].append(static_cast<double>(pid_report_msg.I_Part));
        pid_vel[3].append(static_cast<double>(pid_report_msg.D_Part));
        pid_vel[4].append(static_cast<double>(pid_report_msg.U));
        truncate_matrix(pid_vel);

        pid_plot(vel_cnt, pid_vel, g_q_custom_plot[2]);
        pid_plot(vel_cnt, pid_vel_sp_fb, g_q_custom_plot[3]);

        vel_cnt++;
        break;
    case PID_POS:
        pid_pos_sp_fb[0].append(pos_cnt);
        pid_pos_sp_fb[1].append(static_cast<double>(pid_report_msg.sp));
        pid_pos_sp_fb[2].append(static_cast<double>(pid_report_msg.fb));
        truncate_matrix(pid_pos_sp_fb);

        pid_pos[0].append(pos_cnt);
        pid_pos[1].append(static_cast<double>(pid_report_msg.P_Part));
        pid_pos[2].append(static_cast<double>(pid_report_msg.I_Part));
        pid_pos[3].append(static_cast<double>(pid_report_msg.D_Part));
        pid_pos[4].append(static_cast<double>(pid_report_msg.U));
        truncate_matrix(pid_pos);

        pid_plot(pos_cnt,pid_pos, g_q_custom_plot[4]);
        pid_plot(pos_cnt,pid_pos_sp_fb, g_q_custom_plot[5]);

        pos_cnt++;
        break;
    }
}

void Mode_pidt_tw::mode_pidt_load_timeout(){
    if(!g_does_st_successfullly){
        g_does_st_successfullly = true;
        show_status("Unable to load PID params",2000);
    }
}

void Mode_pidt_tw::mode_pidt_write_timeout(){
    if(!g_does_st_successfullly){
        g_does_st_successfullly = true;
        show_status("Unable to write PID params",2000);
    }
}

void Mode_pidt_tw::mode_pidt_save_timeout(){
    if(!g_does_st_successfullly){
        g_does_st_successfullly = true;
        show_status("Unable to save PID params",2000);
    }
}

void Mode_pidt_tw::on_btn_mode_pidt_load_params_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_LOAD);

    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Loading PID params",1000);

    set_timeout(LOAD_TIMEOUT);
}

void Mode_pidt_tw::on_btn_mode_pidt_write_params_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float tilt_KP = static_cast<float>(ui->sb_pid_tilt_kp->value());
    float tilt_KI = static_cast<float>(ui->sb_pid_tilt_ki->value());
    float tilt_KD = static_cast<float>(ui->sb_pid_tilt_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_TILT,tilt_KP,tilt_KI,tilt_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    float vel_KP = static_cast<float>(ui->sb_pid_vel_kp->value());
    float vel_KI = static_cast<float>(ui->sb_pid_vel_ki->value());
    float vel_KD = static_cast<float>(ui->sb_pid_vel_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_VEL,vel_KP,vel_KI,vel_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    float pos_KP = static_cast<float>(ui->sb_pid_pos_kp->value());
    float pos_KI = static_cast<float>(ui->sb_pid_pos_ki->value());
    float pos_KD = static_cast<float>(ui->sb_pid_pos_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_POS,pos_KP,pos_KI,pos_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_tw::on_btn_mode_pidt_save_params_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_SAVE);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Saving PID params",1000);

    set_timeout(SAVE_TIMEOUT);
}

void Mode_pidt_tw::on_btn_mode_pidt_write_params_pidt_tilt_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float tilt_KP = static_cast<float>(ui->sb_pid_tilt_kp->value());
    float tilt_KI = static_cast<float>(ui->sb_pid_tilt_ki->value());
    float tilt_KD = static_cast<float>(ui->sb_pid_tilt_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_TILT,tilt_KP,tilt_KI,tilt_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID tilt params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_tw::on_btn_mode_pidt_write_params_pidt_vel_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float vel_KP = static_cast<float>(ui->sb_pid_vel_kp->value());
    float vel_KI = static_cast<float>(ui->sb_pid_vel_ki->value());
    float vel_KD = static_cast<float>(ui->sb_pid_vel_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_VEL,vel_KP,vel_KI,vel_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID velocity params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_tw::on_btn_mode_pidt_write_params_pidt_pos_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float pos_KP = static_cast<float>(ui->sb_pid_pos_kp->value());
    float pos_KI = static_cast<float>(ui->sb_pid_pos_ki->value());
    float pos_KD = static_cast<float>(ui->sb_pid_pos_kd->value());
    mavlink_msg_pid_params_pack(0,0,&msg,PID_POS,pos_KP,pos_KI,pos_KD);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));

    show_status("Writing PID params",2000);
    set_timeout(WRITE_TIMEOUT);
}

void Mode_pidt_tw::remote_control_pidt(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t VX = static_cast<int16_t>(ui->txtb_pidt_vx->text().toDouble()*100);
    int16_t OMEGA = static_cast<int16_t>(ui->txtb_pidt_w->text().toDouble()*100);
    mavlink_msg_cmd_velocity_pack(0,0,&msg,VX,OMEGA);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
}

void Mode_pidt_tw::on_btn_control_enable_clicked()
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

void Mode_pidt_tw::on_btn_change_mode_pidt_clicked()
{
    emit mode_change(MODE_PIDT_TW);
}

void Mode_pidt_tw::update_joystick(axis_t axis, double value){
    switch (axis){
    case AXIS_0:
        ui->txtb_pidt_w->setText(QString::number(value));
        break;
    case AXIS_1:
        ui->txtb_pidt_vx->setText(QString::number(value));
    }
}

void Mode_pidt_tw::on_sb_pid_tilt_kp_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_tilt_kp->setSingleStep(ui->sb_pid_tilt_kp_step->value());
}

void Mode_pidt_tw::on_sb_pid_tilt_ki_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_tilt_ki->setSingleStep(ui->sb_pid_tilt_ki_step->value());
}

void Mode_pidt_tw::on_sb_pid_tilt_kd_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_tilt_kd->setSingleStep(ui->sb_pid_tilt_kd_step->value());
}

void Mode_pidt_tw::on_sb_pid_vel_kp_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_vel_kp->setSingleStep(ui->sb_pid_vel_kp_step->value());
}

void Mode_pidt_tw::on_sb_pid_vel_ki_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_vel_ki->setSingleStep(ui->sb_pid_vel_ki_step->value());
}

void Mode_pidt_tw::on_sb_pid_vel_kd_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_vel_kd->setSingleStep(ui->sb_pid_vel_kd_step->value());
}

void Mode_pidt_tw::on_sb_pid_pos_kp_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_pos_kp->setSingleStep(ui->sb_pid_pos_kp_step->value());
}

void Mode_pidt_tw::on_sb_pid_pos_ki_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_pos_ki->setSingleStep(ui->sb_pid_pos_ki_step->value());
}

void Mode_pidt_tw::on_sb_pid_pos_kd_step_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->sb_pid_pos_kd->setSingleStep(ui->sb_pid_pos_kd_step->value());
}
