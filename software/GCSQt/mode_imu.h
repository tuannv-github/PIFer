#ifndef MODE_IMU_H
#define MODE_IMU_H

#include <QWidget>
#include <QtWidgets/QStatusBar>

#include <MAV/protocol/mavlink.h>
#include <mode_common.h>

namespace Ui {
class Mode_imu;
}

#define  UPDATE_COEFF 0.01

class Mode_imu : public Mode_common
{
    Q_OBJECT

public:
    explicit Mode_imu(QWidget *parent = nullptr);
    ~Mode_imu();

    void mav_recv(mavlink_message_t *msg) override;

private slots:
    void on_btn_mode_imu_load_params_clicked();
    void on_btn_mode_imu_write_params_clicked();
    void on_btn_mode_imu_save_params_clicked();

    void on_btn_gyro_calib_clicked();
    void on_btn_change_mode_imu_clicked();

    void on_btn_tilt_calib_clicked();

private:
    Ui::Mode_imu *ui;
    QStatusBar *g_q_status_bar = nullptr;
};

#endif // MODE_IMU_H
