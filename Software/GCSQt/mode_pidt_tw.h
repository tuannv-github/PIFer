#ifndef MODE_PIDT_TW_H
#define MODE_PIDT_TW_H

#include <QWidget>
#include <QTimer>
#include <QtWidgets/QStatusBar>

#include <MAV/protocol/mavlink.h>
#include <mode_common.h>

namespace Ui {
class Mode_pidt_tw;
}

class Mode_pidt_tw : public Mode_common
{
    Q_OBJECT

public:
    explicit Mode_pidt_tw(QWidget *parent = nullptr);
    ~Mode_pidt_tw();

    void mav_recv(mavlink_message_t *msg) override;
    void update_joystick(axis_t axis, double value) override;

private slots:
    void mode_pidt_load_timeout();
    void mode_pidt_write_timeout();
    void mode_pidt_save_timeout();
    void remote_control_pidt();

    void on_btn_mode_pidt_load_params_clicked();
    void on_btn_mode_pidt_write_params_clicked();
    void on_btn_mode_pidt_save_params_clicked();

    void on_btn_mode_pidt_write_params_pidt_tilt_clicked();
    void on_btn_mode_pidt_write_params_pidt_vel_clicked();
    void on_btn_mode_pidt_write_params_pidt_pos_clicked();

    void on_btn_control_enable_clicked();

    void on_sb_pid_tilt_kp_step_valueChanged(double arg1);
    void on_sb_pid_tilt_ki_step_valueChanged(double arg1);
    void on_sb_pid_tilt_kd_step_valueChanged(double arg1);

    void on_sb_pid_vel_kp_step_valueChanged(double arg1);
    void on_sb_pid_vel_ki_step_valueChanged(double arg1);
    void on_sb_pid_vel_kd_step_valueChanged(double arg1);

    void on_sb_pid_pos_kp_step_valueChanged(double arg1);
    void on_sb_pid_pos_ki_step_valueChanged(double arg1);
    void on_sb_pid_pos_kd_step_valueChanged(double arg1);

    void on_btn_change_mode_pidt_clicked();

private:
    Ui::Mode_pidt_tw *ui;

    QTimer *g_controller_timer;
    bool g_control_enable = false;

    void pid_plot(uint32_t len, QVector<QVector<double>> q, QCustomPlot *q_custom_plot);
    void pid_report_recv(mavlink_message_t *msg);

    QVector<QVector<double>> pid_tilt, pid_tilt_sp_fb;
    QVector<QVector<double>> pid_vel, pid_vel_sp_fb;
    QVector<QVector<double>> pid_pos, pid_pos_sp_fb;
};

#endif // MODE_PIDT_TW_H
