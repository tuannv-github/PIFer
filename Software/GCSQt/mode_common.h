#ifndef MODE_COMMON_H
#define MODE_COMMON_H

#include <QTimer>
#include <QtWidgets/QStatusBar>

#include <MAV/protocol/mavlink.h>
#include <qcustomplot/qcustomplot.h>

#define PID_VECTOR_LEN  40

class Mode_common : public QWidget
{
    Q_OBJECT

public:
    Mode_common(QWidget *parent);
    virtual ~Mode_common();

    typedef enum{
        AXIS_0,
        AXIS_1,
    }axis_t;

    virtual void mav_recv(mavlink_message_t *msg);
    virtual void update_joystick(axis_t axis, double value);

    void set_status_bar(QStatusBar *q_status_bar);
    void set_plotter(QVector<QCustomPlot*> q_custom_plot);

protected:

    typedef enum{
        WRITE_TIMEOUT,
        LOAD_TIMEOUT,
        SAVE_TIMEOUT
    }timeout_t;

    bool g_does_st_successfullly = true;
    QString g_mode_name = "";
    QVector<QCustomPlot*> g_q_custom_plot;

    void show_status(QString q_str, int timeout);

    void load_params();
    void save_params();

    void set_timeout(timeout_t timeout);
    void reset_timeout();
    bool is_timing();

    void truncate_vector(QVector<double> *v);
    void truncate_matrix(QVector<QVector<double>> &v);
    double vector_min(QVector<double> q_vector);
    double vector_max(QVector<double> q_vector);

signals:
    void mav_send(QByteArray ba);
    void mode_change(rmode_t mode);

protected slots:
    void load_timeout();
    void write_timeout();
    void save_timeout();

private:
    QStatusBar *g_q_status_bar = nullptr;
};

#endif // MODE_COMMON_H
