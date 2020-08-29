#ifndef MODE_PIDT_TA_H
#define MODE_PIDT_TA_H

#include <QWidget>

#include <mode_common.h>

namespace Ui {
class Mode_pidt_ta;
}

class Mode_pidt_ta : public Mode_common
{
    Q_OBJECT

public:
    explicit Mode_pidt_ta(QWidget *parent = nullptr);
    ~Mode_pidt_ta() override;

    void mav_recv(mavlink_message_t *msg) override;
    void update_joystick(axis_t axis, double value) override;

private slots:
    void on_btn_change_mode_pidt_clicked();
    void on_btn_mode_pidt_load_params_clicked();
    void on_btn_mode_pidt_write_params_clicked();
    void on_btn_mode_pidt_save_params_clicked();
    void on_btn_mode_pidt_write_params_pid_whe0_clicked();
    void on_btn_mode_pidt_write_params_pid_whe1_clicked();
    void on_btn_mode_pidt_write_params_pid_sync_clicked();
    void on_btn_set_speed0_clicked();
    void on_btn_set_speed1_clicked();
    void on_btn_control_enable_clicked();

    void remote_control_pidt();
    void on_btn_change_mode_pidt_ta_clicked();

private:
    Ui::Mode_pidt_ta *ui;
    bool g_control_enable = false;
    QTimer *g_controller_timer;
};

#endif // MODE_PIDT_TA_H
