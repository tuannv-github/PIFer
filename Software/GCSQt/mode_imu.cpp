#include "mode_imu.h"
#include "ui_mode_imu.h"

Mode_imu::Mode_imu(QWidget *parent) :
    Mode_common(parent),
    ui(new Ui::Mode_imu)
{
    ui->setupUi(this);
}

Mode_imu::~Mode_imu()
{
    delete ui;
}

void Mode_imu::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_EVT_GYRO_RAW:
        mavlink_evt_gyro_raw_t gyro_raw_msg;
        mavlink_msg_evt_gyro_raw_decode(msg, &gyro_raw_msg);
        ui->tb_gx->setText(QString::number(gyro_raw_msg.gyro_x));
        ui->tb_gy->setText(QString::number(gyro_raw_msg.gyro_y));
        ui->tb_gz->setText(QString::number(gyro_raw_msg.gyro_z));
        if(g_is_imu_calibrating){
            g_gx_offset = (g_gx_offset + gyro_raw_msg.gyro_x)/2;
            g_gy_offset = (g_gy_offset + gyro_raw_msg.gyro_y)/2;
            g_gz_offset = (g_gz_offset + gyro_raw_msg.gyro_z)/2;
            ui->tb_gx_offset->setText(QString::number(g_gx_offset));
            ui->tb_gy_offset->setText(QString::number(g_gy_offset));
            ui->tb_gz_offset->setText(QString::number(g_gz_offset));
        }
        break;
    case MAVLINK_MSG_ID_RESPOND:
        if(is_timing()){
            mavlink_respond_t evt_respond;
            mavlink_msg_respond_decode(msg,&evt_respond);
            if(evt_respond.respond == RESPOND_OK){
                reset_timeout();
                show_status("Succeed",2000);
            }
        }
        break;
    case MAVLINK_MSG_ID_IMU_PARAMS:
        {
            mavlink_imu_params_t imu_params_msg;
            mavlink_msg_imu_params_decode(msg,&imu_params_msg);
            g_gx_offset = imu_params_msg.gyro_offset_x;
            g_gy_offset = imu_params_msg.gyro_offset_y;
            g_gz_offset = imu_params_msg.gyro_offset_z;
            g_angle_adjust = imu_params_msg.angle_adjusted;
            g_gbelive = imu_params_msg.believe_in_gyro;
            ui->tb_gx_offset->setText(QString::number(g_gx_offset));
            ui->tb_gy_offset->setText(QString::number(g_gy_offset));
            ui->tb_gz_offset->setText(QString::number(g_gz_offset));
            ui->tb_angle_adjust->setText(QString::number(static_cast<double>(g_angle_adjust)));
            ui->tb_gbelieve->setText(QString::number(static_cast<double>(g_gbelive)));

        }
        reset_timeout();
        break;
    case MAVLINK_MSG_ID_EVT_TILT:
        {
            mavlink_evt_tilt_t tilt_msg;
            mavlink_msg_evt_tilt_decode(msg, &tilt_msg);
            if(g_is_imu_calibrating){
                g_angle_adjust = (g_angle_adjust + tilt_msg.tilt)/2;
                ui->tb_angle_adjust->setText(QString::number(static_cast<double>(g_angle_adjust)));
            }
        }
        break;
    default:
        break;
    }
}

void Mode_imu::on_btn_mode_imu_load_params_clicked()
{

    ui->tb_gx_offset->setText("");
    ui->tb_gy_offset->setText("");
    ui->tb_gz_offset->setText("");
    ui->tb_angle_adjust->setText("");
    ui->tb_gbelieve->setText("");
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_LOAD);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Loading imu params",1000);

    set_timeout(LOAD_TIMEOUT);
}

void Mode_imu::on_btn_mode_imu_write_params_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    int16_t tbgx_offset = static_cast<int16_t>(ui->tb_gx_offset->text().toInt());
    int16_t tbgy_offset = static_cast<int16_t>(ui->tb_gy_offset->text().toInt());
    int16_t tbgz_offset = static_cast<int16_t>(ui->tb_gz_offset->text().toInt());
    float tbstand_point = ui->tb_angle_adjust->text().toFloat();
    float gbelieve = ui->tb_gbelieve->text().toFloat();
    mavlink_msg_imu_params_pack(0,0,&msg,tbgx_offset,
                                tbgy_offset,tbgz_offset,
                                0,0,0,
                                0,0,0,
                                tbstand_point,gbelieve);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Writing imu params",1000);

    set_timeout(WRITE_TIMEOUT);
}

void Mode_imu::on_btn_mode_imu_save_params_clicked()
{

    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_SAVE);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Saving gyro offset params",1000);

    set_timeout(SAVE_TIMEOUT);
}

void Mode_imu::on_btn_gyro_calib_clicked()
{
    if(!g_is_imu_calibrating){
        g_is_imu_calibrating = true;
        g_gx_offset = 0;
        g_gy_offset = 0;
        g_gz_offset = 0;
        g_angle_adjust = 0;
        ui->tb_gx_offset->setText(QString::number(g_gx_offset));
        ui->tb_gy_offset->setText(QString::number(g_gy_offset));
        ui->tb_gz_offset->setText(QString::number(g_gz_offset));
        ui->btn_gyro_calib->setText("Calibrating");
    }
    else{
        g_is_imu_calibrating = false;
        ui->btn_gyro_calib->setText("Calibrate");
    }
}

void Mode_imu::on_btn_change_mode_imu_clicked()
{
    emit mode_change(MODE_IMU);
}
