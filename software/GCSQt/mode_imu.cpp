#include "mode_imu.h"
#include "ui_mode_imu.h"

Mode_imu::Mode_imu(QWidget *parent) : Mode_common(parent), ui(new Ui::Mode_imu)
{
    ui->setupUi(this);
    ui->cb_tilt->addItem("ROLL");
    ui->cb_tilt->addItem("PITCH");
}

Mode_imu::~Mode_imu()
{
    delete ui;
}

void Mode_imu::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW:
        mavlink_evt_gyro_accel_mag_raw_t gyro_accel_mag_raw_msg;
        mavlink_msg_evt_gyro_accel_mag_raw_decode(msg, &gyro_accel_mag_raw_msg);
        ui->tb_ax->setText(QString::number(gyro_accel_mag_raw_msg.ax));
        ui->tb_ay->setText(QString::number(gyro_accel_mag_raw_msg.ay));
        ui->tb_az->setText(QString::number(gyro_accel_mag_raw_msg.az));
        ui->tb_gx->setText(QString::number(gyro_accel_mag_raw_msg.gx));
        ui->tb_gy->setText(QString::number(gyro_accel_mag_raw_msg.gy));
        ui->tb_gz->setText(QString::number(gyro_accel_mag_raw_msg.gz));
        if(g_is_gyro_calibrating){
            g_gx_offset += UPDATE_COEFF*(gyro_accel_mag_raw_msg.gx - g_gx_offset);
            g_gy_offset += UPDATE_COEFF*(gyro_accel_mag_raw_msg.gy - g_gy_offset);
            g_gz_offset += UPDATE_COEFF*(gyro_accel_mag_raw_msg.gz - g_gz_offset);
            ui->tb_gx_offset->setText(QString::number(g_gx_offset));
            ui->tb_gy_offset->setText(QString::number(g_gy_offset));
            ui->tb_gz_offset->setText(QString::number(g_gz_offset));
        }
        ui->tb_mx->setText(QString::number(gyro_accel_mag_raw_msg.mx));
        ui->tb_my->setText(QString::number(gyro_accel_mag_raw_msg.my));
        ui->tb_mz->setText(QString::number(gyro_accel_mag_raw_msg.mz));
        break;
    case MAVLINK_MSG_ID_EVT_RPY:
        mavlink_evt_rpy_t rpy_msg;
        mavlink_msg_evt_rpy_decode(msg, &rpy_msg);
        ui->tb_roll->setText(QString::number(rpy_msg.roll));
        ui->tb_pitch->setText(QString::number(rpy_msg.pitch));
        ui->tb_yaw->setText(QString::number(rpy_msg.yaw));
        if(g_is_tilt_calibrating){
            float tilt = ui->cb_tilt->currentText() == "ROLL" ? rpy_msg.roll : rpy_msg.pitch;
            g_tilt_offset += UPDATE_COEFF*(tilt - g_tilt_offset);
            ui->tb_angle_adjust->setText(QString::number(static_cast<double>(g_tilt_offset)));
        }
        break;
    case MAVLINK_MSG_ID_RESPOND:
        {
            mavlink_respond_t respond_msg;
            mavlink_msg_respond_decode(msg,&respond_msg);
            if(respond_msg.respond == RESPOND_OK) succeed();
            else failed();
        }
        break;
    case MAVLINK_MSG_ID_GYRO_PARAMS:
        {
            mavlink_gyro_params_t gyro_params_msg;
            mavlink_msg_gyro_params_decode(msg,&gyro_params_msg);
            g_gx_offset = gyro_params_msg.gyro_offset_x;
            g_gy_offset = gyro_params_msg.gyro_offset_y;
            g_gz_offset = gyro_params_msg.gyro_offset_z;
            ui->tb_gx_offset->setText(QString::number(g_gx_offset));
            ui->tb_gy_offset->setText(QString::number(g_gy_offset));
            ui->tb_gz_offset->setText(QString::number(g_gz_offset));
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT:
        {
            mavlink_evt_tilt_t tilt_msg;
            mavlink_msg_evt_tilt_decode(msg, &tilt_msg);
            ui->txtb_tilt_0->setText(QString::number(tilt_msg.tilt));
        }
        break;
    case MAVLINK_MSG_ID_COMP_FILTER_PARAMS:
        {
            mavlink_comp_filter_params_t comp_filter_params;
            mavlink_msg_comp_filter_params_decode(msg, &comp_filter_params);
            ui->cb_tilt->setCurrentText(comp_filter_params.tilt_type == ROLL ? QString("ROLL"): QString("PITCH"));
            ui->tb_angle_adjust->setText(QString::number(static_cast<double>(comp_filter_params.tilt_offset)));
            ui->tb_gbelieve->setText(QString::number(static_cast<double>(comp_filter_params.g_believe)));
        }
        break;
    case MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED:
        {
            mavlink_evt_gyro_accel_mag_calibrated_t gyro_accel_mag_calibrated;
            mavlink_msg_evt_gyro_accel_mag_calibrated_decode(msg, &gyro_accel_mag_calibrated);
            ui->tb_cab_gx->setText(QString::number(gyro_accel_mag_calibrated.gx));
            ui->tb_cab_gy->setText(QString::number(gyro_accel_mag_calibrated.gy));
            ui->tb_cab_gz->setText(QString::number(gyro_accel_mag_calibrated.gz));
        }
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

    this->load_params();
}

void Mode_imu::on_btn_mode_imu_write_params_clicked()
{
    show_status("Writing imu params", 1000);

    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    uint16_t len;    

    float tbgx_offset = static_cast<float>(ui->tb_gx_offset->text().toFloat());
    float tbgy_offset = static_cast<float>(ui->tb_gy_offset->text().toFloat());
    float tbgz_offset = static_cast<float>(ui->tb_gz_offset->text().toFloat());
    mavlink_msg_gyro_params_pack(0,0,&msg,tbgx_offset,
                                tbgy_offset,tbgz_offset);
    len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    set_timeout(WRITE_TIMEOUT);

    float g_believe = ui->tb_gbelieve->text().toFloat();
    float tilt_offset = ui->tb_angle_adjust->text().toFloat();
    tilt_type_t tilt_type = ui->cb_tilt->currentText() == "ROLL" ? ROLL : PITCH;
    mavlink_msg_comp_filter_params_pack(0,0,&msg, tilt_type, tilt_offset, g_believe);
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
    if(!g_is_gyro_calibrating){
        g_is_gyro_calibrating = true;

        g_gx_offset = 0;
        g_gy_offset = 0;
        g_gz_offset = 0;

        ui->tb_gx_offset->setText(QString::number(g_gx_offset));
        ui->tb_gy_offset->setText(QString::number(g_gy_offset));
        ui->tb_gz_offset->setText(QString::number(g_gz_offset));

        ui->btn_gyro_calib->setText("Calibrating");
    }
    else{
        g_is_gyro_calibrating = false;
        ui->btn_gyro_calib->setText("G Calibrate");
    }
}

void Mode_imu::on_btn_tilt_calib_clicked()
{
    if(!g_is_tilt_calibrating){
        g_is_tilt_calibrating = true;
        g_tilt_offset = 0;
        ui->btn_tilt_calib->setText("Calibrating");
    }
    else{
        g_is_tilt_calibrating = false;
        ui->btn_tilt_calib->setText("T Calibrate");
    }
}


void Mode_imu::on_btn_change_mode_imu_clicked()
{
    emit mode_change(MODE_IMU);
}


