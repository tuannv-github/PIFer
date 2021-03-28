#ifndef MODE_RUN_H
#define MODE_RUN_H

#include <QWidget>
#include <QTimer>
#include <QtWidgets/QStatusBar>
#include <QFile>
#include <mode_common.h>

#include <EKF/ekf.h>
#include <EKF/ekf_utils.h>
#include <TrajectoryGen/trajectorygen.h>
#include <TrajectoryGen/trajectory_utils.h>

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

    typedef enum{
        REAL_TIME,
        FROM_FILE,
        RT_PREDICT,
        FILE_PREDICT
    }ekf_mode_t;

private slots:
    void remote_controll_cmd();

    void on_btn_control_enable_clicked();
    void on_btn_change_mode_run_clicked();

    void on_btn_log_clicked();

    void on_btn_cm_clicked();

    void on_btn_run_ekf_clicked();

    void on_hs_ekf_state_sliderMoved(int position);

    void on_btn_init_ekf_clicked();

    void on_cb_ekf_mode_currentIndexChanged(int index);

    void on_btn_trajectory_gen_clicked();

    void on_btn_follow_clicked();

    void dwa_follow_callback();

private:
    Ui::Mode_run *ui;
    QTimer *g_controller_timer;
    QTimer *g_dwa_follow_timer;
    bool g_control_enable;
    bool g_logging;
    bool g_ekf_initing;
    bool g_ekf_running;
    ekf_mode_t g_ekf_mode;
    ekf_t g_ekf;
    ekf_params_t g_ekf_params;
    QVector<ekf_state_t> g_trajectory;
    QScatter3DSeries *g_qs3s_trajectory;
    QVector<sphere_t> g_spheres;
    float g_yaw;

    QFile g_file_control_measurement;
    QVector<trajectory_point_2d_t> g_ref_trajectory_2d;
    QScatter3DSeries *g_qs3s_ref_trajectory;
    QScatter3DSeries *g_qs3s_dwa_trajectory;
    QScatter3DSeries *g_qs3s_dwa_ref_trajectory;
    bool dwa_following;

    QScatter3DSeries *g_qs3s_state;
    QScatter3DSeries *g_qs3s_state_origin;

    void ekf_reset(float x, float y, float w);
    void show_current_state(float x, float y, float w);
};

#endif // MODE_RUN_H
