#include "mode_imu.h"
#include "ui_mode_imu.h"

Mode_imu::Mode_imu(QWidget *parent, CommonObject *co)
    : Mode_common(parent, co), ui(new Ui::Mode_imu)
{
    ui->setupUi(this);
    g_mode_name = "Mode IMU";

    ui->cb_tilt->addItem("ROLL");
    ui->cb_tilt->addItem("PITCH");
}

Mode_imu::~Mode_imu()
{
    delete ui;
}

void Mode_imu::select(){
//   clear_drawing_area();
}

void Mode_imu::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_RESPOND:
        {
            mavlink_respond_t respond_msg;
            mavlink_msg_respond_decode(msg,&respond_msg);
            if(respond_msg.respond == RESPOND_OK) succeed();
            else failed();
        }
        break;
    case MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW:
        {
            mavlink_evt_gyro_accel_mag_raw_t gyro_accel_mag_raw_msg;
            mavlink_msg_evt_gyro_accel_mag_raw_decode(msg, &gyro_accel_mag_raw_msg);
            ui->tb_gx->setText(QString::number(gyro_accel_mag_raw_msg.gx));
            ui->tb_gy->setText(QString::number(gyro_accel_mag_raw_msg.gy));
            ui->tb_gz->setText(QString::number(gyro_accel_mag_raw_msg.gz));
            ui->tb_ax->setText(QString::number(gyro_accel_mag_raw_msg.ax));
            ui->tb_ay->setText(QString::number(gyro_accel_mag_raw_msg.ay));
            ui->tb_az->setText(QString::number(gyro_accel_mag_raw_msg.az));
            ui->tb_mx->setText(QString::number(gyro_accel_mag_raw_msg.mx));
            ui->tb_my->setText(QString::number(gyro_accel_mag_raw_msg.my));
            ui->tb_mz->setText(QString::number(gyro_accel_mag_raw_msg.mz));
        }
        break;
    case MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED:
        {
            mavlink_evt_gyro_accel_mag_calibrated_t gyro_accel_mag_calibrated;
            mavlink_msg_evt_gyro_accel_mag_calibrated_decode(msg, &gyro_accel_mag_calibrated);
            ui->tb_cab_gx->setText(QString::number(gyro_accel_mag_calibrated.gx));
            ui->tb_cab_gy->setText(QString::number(gyro_accel_mag_calibrated.gy));
            ui->tb_cab_gz->setText(QString::number(gyro_accel_mag_calibrated.gz));
            ui->tb_cab_ax->setText(QString::number(gyro_accel_mag_calibrated.ax));
            ui->tb_cab_ay->setText(QString::number(gyro_accel_mag_calibrated.ay));
            ui->tb_cab_az->setText(QString::number(gyro_accel_mag_calibrated.az));
            ui->tb_cab_mx->setText(QString::number(gyro_accel_mag_calibrated.mx));
            ui->tb_cab_my->setText(QString::number(gyro_accel_mag_calibrated.my));
            ui->tb_cab_mz->setText(QString::number(gyro_accel_mag_calibrated.mz));
        }
        break;
    case MAVLINK_MSG_ID_EVT_RPY:
        mavlink_evt_rpy_t rpy_msg;
        mavlink_msg_evt_rpy_decode(msg, &rpy_msg);
        ui->tb_roll->setText(QString::number(rpy_msg.roll));
        ui->tb_pitch->setText(QString::number(rpy_msg.pitch));
        ui->tb_yaw->setText(QString::number(rpy_msg.yaw));
        break;
    case MAVLINK_MSG_ID_GYRO_PARAMS:
        {
            mavlink_gyro_params_t params_msg;
            mavlink_msg_gyro_params_decode(msg,&params_msg);
            ui->tb_gx_bias->setText(QString::number(params_msg.gyro_bias_x));
            ui->tb_gy_bias->setText(QString::number(params_msg.gyro_bias_y));
            ui->tb_gz_bias->setText(QString::number(params_msg.gyro_bias_z));
        }
        break;
    case MAVLINK_MSG_ID_ACCEL_PARAMS:
        {
            mavlink_accel_params_t params_msg;
            mavlink_msg_accel_params_decode(msg,&params_msg);
            ui->tb_ax_bias->setText(QString::number(params_msg.accel_bias_x));
            ui->tb_ay_bias->setText(QString::number(params_msg.accel_bias_y));
            ui->tb_az_bias->setText(QString::number(params_msg.accel_bias_z));
        }
        break;
    case MAVLINK_MSG_ID_MAG_PARAMS:
        {
            mavlink_mag_params_t params_msg;
            mavlink_msg_mag_params_decode(msg,&params_msg);
            ui->tb_mx_bias->setText(QString::number(params_msg.mag_bias_x));
            ui->tb_my_bias->setText(QString::number(params_msg.mag_bias_y));
            ui->tb_mz_bias->setText(QString::number(params_msg.mag_bias_z));
            ui->tb_mx_scale->setText(QString::number(params_msg.mag_scale_x));
            ui->tb_my_scale->setText(QString::number(params_msg.mag_scale_y));
            ui->tb_mz_scale->setText(QString::number(params_msg.mag_scale_z));
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT_RAW:
        {
            mavlink_evt_tilt_raw_t tilt_msg;
            mavlink_msg_evt_tilt_raw_decode(msg, &tilt_msg);
            ui->tb_tilt_raw->setText(QString::number(tilt_msg.tilt));
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT_CAL:
        {
            mavlink_evt_tilt_cal_t tilt_msg;
            mavlink_msg_evt_tilt_cal_decode(msg, &tilt_msg);
            ui->tb_tilt_cal->setText(QString::number(tilt_msg.tilt));
        }
        break;
    case MAVLINK_MSG_ID_FILTER_PARAMS:
        {
            mavlink_filter_params_t filter_params;
            mavlink_msg_filter_params_decode(msg, &filter_params);
            ui->cb_tilt->setCurrentText(filter_params.tilt_type == ROLL ? QString("ROLL"): QString("PITCH"));
            ui->tb_angle_adjust->setText(QString::number(static_cast<double>(filter_params.tilt_offset)));

            ui->tb_gbelieve->setText(QString::number(static_cast<double>(filter_params.g_believe)));
            ui->tb_madgwick_beta->setText(QString::number(static_cast<double>(filter_params.madgwick_beta)));
            ui->tb_complementary_gain->setText(QString::number(static_cast<double>(filter_params.complementary_gain)));
        }
        break;
    default:
        break;
    }
}

void Mode_imu::on_btn_mode_imu_load_params_clicked()
{
    ui->tb_gx_bias->setText("");
    ui->tb_gy_bias->setText("");
    ui->tb_gz_bias->setText("");

    ui->tb_ax_bias->setText("");
    ui->tb_ay_bias->setText("");
    ui->tb_az_bias->setText("");

    ui->tb_mx_bias->setText("");
    ui->tb_my_bias->setText("");
    ui->tb_mz_bias->setText("");

    ui->tb_mx_scale->setText("");
    ui->tb_my_scale->setText("");
    ui->tb_mz_scale->setText("");

    ui->tb_angle_adjust->setText("");


    ui->tb_gbelieve->setText("");
    ui->tb_complementary_gain->setText("");
    ui->tb_madgwick_beta->setText("");

    this->load_params();
}

void Mode_imu::on_btn_mode_imu_write_params_clicked()
{
    show_status("Writing imu params", 1000);

    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;

    float tbgx_offset = static_cast<float>(ui->tb_gx_bias->text().toFloat());
    float tbgy_offset = static_cast<float>(ui->tb_gy_bias->text().toFloat());
    float tbgz_offset = static_cast<float>(ui->tb_gz_bias->text().toFloat());
    mavlink_msg_gyro_params_pack(0,0,&msg,tbgx_offset,tbgy_offset,tbgz_offset);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    set_timeout(WRITE_TIMEOUT);

    float ax_bias = static_cast<float>(ui->tb_ax_bias->text().toFloat());
    float ay_bias = static_cast<float>(ui->tb_ay_bias->text().toFloat());
    float az_bias = static_cast<float>(ui->tb_az_bias->text().toFloat());
    mavlink_msg_accel_params_pack(0,0,&msg,ax_bias,ay_bias,az_bias);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    set_timeout(WRITE_TIMEOUT);

    float mx_bias = static_cast<float>(ui->tb_mx_bias->text().toFloat());
    float my_bias = static_cast<float>(ui->tb_my_bias->text().toFloat());
    float mz_bias = static_cast<float>(ui->tb_mz_bias->text().toFloat());
    float mx_scale = static_cast<float>(ui->tb_mx_scale->text().toFloat());
    float my_scale = static_cast<float>(ui->tb_my_scale->text().toFloat());
    float mz_scale = static_cast<float>(ui->tb_mz_scale->text().toFloat());
    mavlink_msg_mag_params_pack(0,0,&msg,mx_bias,my_bias,mz_bias,mx_scale,my_scale,mz_scale);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    set_timeout(WRITE_TIMEOUT);


    float tilt_offset = ui->tb_angle_adjust->text().toFloat();
    tilt_type_t tilt_type = ui->cb_tilt->currentText() == "ROLL" ? ROLL : PITCH;
    float g_believe = ui->tb_gbelieve->text().toFloat();
    float complementary_gain = ui->tb_complementary_gain->text().toFloat();
    float madgwick_beta = ui->tb_madgwick_beta->text().toFloat();
    mavlink_msg_filter_params_pack(0,0,&msg, tilt_type, tilt_offset, g_believe, complementary_gain, madgwick_beta);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    set_timeout(WRITE_TIMEOUT);
}

void Mode_imu::on_btn_mode_imu_save_params_clicked()
{
    this->save_params();
}

void Mode_imu::on_btn_gyro_calib_clicked()
{
}

void Mode_imu::on_btn_tilt_calib_clicked()
{
}

void Mode_imu::on_btn_change_mode_imu_clicked()
{
    emit mode_change(MODE_IMU);
}


