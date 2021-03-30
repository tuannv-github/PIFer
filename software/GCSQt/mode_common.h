#ifndef MODE_COMMON_H
#define MODE_COMMON_H

#include <QTimer>
#include <QSettings>
#include <QtWidgets/QStatusBar>
#include <MAVLink/protocol/mavlink.h>
#include <QCustomPlot/qcustomplot.h>
#include <Q3DScatter>
#include <Q3DInputHandler>
#include <commonobject.h>
#include <Q3DInputHandler>

#define PID_VECTOR_LEN  40

using namespace QtDataVisualization;

class Mode_common : public QWidget
{
    Q_OBJECT

public:
    Mode_common(QWidget *parent, CommonObject *co);
    virtual ~Mode_common();

    virtual void mav_recv(mavlink_message_t *msg);
    virtual void update_joystick(int axis, double value);
    virtual void select();

    QString getName();
protected:

    typedef enum{
        WRITE_TIMEOUT,
        LOAD_TIMEOUT,
        SAVE_TIMEOUT
    }timeout_t;

    bool g_does_st_successfullly = true;
    QString g_mode_name = "";
    CommonObject *g_co;

    QVector<QCustomPlot*> g_custom_plot;
    Q3DScatter *g_3d_scatter;
    Q3DInputHandler *g_input_handler;
    QWidget *g_3d_container;
    QSettings g_settings;

    void show_status(QString q_str, int timeout);

    void load_params();
    void save_params();

    void set_timeout(timeout_t timeout);
    void reset_timeout();
    void succeed();
    void failed();

    void truncate_vector(QVector<double> *v);
    void truncate_matrix(QVector<QVector<double>> &v);
    double vector_min(QVector<double> q_vector);
    double vector_max(QVector<double> q_vector);

    void clear_drawing_area();

signals:
    void mav_send(QByteArray ba);
    void mode_change(rmode_t mode);

protected slots:
    void load_timeout();
    void write_timeout();
    void save_timeout();

};

#endif // MODE_COMMON_H
