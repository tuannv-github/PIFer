#ifndef MODE_RUN_H
#define MODE_RUN_H

#include <QWidget>
#include <QTimer>
#include <QtWidgets/QStatusBar>
#include <QFile>
#include <EKF/ekf.h>
#include <mode_common.h>

namespace Ui {
class Mode_run;
}

class Mode_run : public Mode_common
{
    Q_OBJECT

public:
    explicit Mode_run(QWidget *parent = nullptr, CommonObject *co = nullptr);
    ~Mode_run() override;

    void mav_recv(mavlink_message_t *msg) override;
    void update_joystick(int axis, double value) override;
    void select() override;

private slots:
    void remote_controll_cmd();

    void on_btn_control_enable_clicked();
    void on_btn_change_mode_run_clicked();

    void on_btn_log_clicked();

    void on_btn_cm_clicked();

    void on_btn_run_ekf_clicked();

    void on_hs_ekf_state_sliderMoved(int position);

private:
    Ui::Mode_run *ui;
    QTimer *g_controller_timer;
    bool g_control_enable;
    bool g_logging;
    ekf_t g_ekf;
    ekf_params_t g_ekf_params;
    QVector<ekf_state_t> g_trajectory;

    QScatter3DSeries *g_qs3s_trajectory;
    QScatter3DSeries *g_state;

    QFile g_file_control_measurement;
};

#endif // MODE_RUN_H
