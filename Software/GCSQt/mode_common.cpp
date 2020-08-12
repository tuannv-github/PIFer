#include "mode_common.h"

Mode_common::Mode_common(QWidget *parent) : QWidget(parent)
{

}

Mode_common::~Mode_common()
{

}

void Mode_common::mav_recv(mavlink_message_t *msg){
    Q_UNUSED(msg)
    show_status("Mav receive is not implement yet", 1000);
}

void Mode_common::set_status_bar(QStatusBar *q_status_bar){
    g_q_status_bar = q_status_bar;
}

void Mode_common::show_status(QString q_str, int timeout){
    if(g_q_status_bar != nullptr){
        g_q_status_bar->showMessage(q_str,timeout);
    }
}

void Mode_common::load_timeout(){
    if(!g_does_st_successfullly){
        g_does_st_successfullly = true;
        show_status("Unable to load " + g_mode_name +" params",2000);
    }
}

void Mode_common::write_timeout(){
    if(!g_does_st_successfullly){
        g_does_st_successfullly = true;
        show_status("Unable to write " + g_mode_name + " params",2000);
    }
}

void Mode_common::save_timeout(){
    if(!g_does_st_successfullly){
        g_does_st_successfullly = true;
        show_status("Unable to save " + g_mode_name + " params",2000);
    }
}

void Mode_common::load_params(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_LOAD);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Loading " + g_mode_name + " params",1000);

    set_timeout(LOAD_TIMEOUT);
}

void Mode_common::save_params(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    mavlink_msg_cmd_params_pack(0,0,&msg,CMD_SAVE);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Saving " + g_mode_name + " params",1000);

    set_timeout(SAVE_TIMEOUT);
}

void Mode_common::set_timeout(timeout_t timeout){
    g_does_st_successfullly = false;
    switch(timeout){
    case SAVE_TIMEOUT:
        QTimer::singleShot(1000, this, SLOT(save_timeout()));
        break;
    case WRITE_TIMEOUT:
        QTimer::singleShot(1000, this, SLOT(write_timeout()));
        break;
    case LOAD_TIMEOUT:
        QTimer::singleShot(1000, this, SLOT(load_timeout()));
        break;
    }

}

void Mode_common::reset_timeout(){
    g_does_st_successfullly = true;
}

bool Mode_common::is_timing(){
    return !g_does_st_successfullly;
}

void Mode_common::set_plotter(QVector<QCustomPlot*> q_custom_plot){
    g_q_custom_plot = q_custom_plot;
}

void Mode_common::update_joystick(axis_t axis, double value){
    Q_UNUSED(axis)
    Q_UNUSED(value)
}

void Mode_common::truncate_vector(QVector<double> *v){
    while(v->size() > PID_VECTOR_LEN){
        v->pop_front();
    }
}

void Mode_common::truncate_matrix(QVector<QVector<double>> &m){
    for (QVector<QVector<double>>::iterator it = m.begin(); it != m.end(); ++it) {
        truncate_vector(it);
    }
}

double Mode_common::vector_min(QVector<double> q_vector){
    return *std::min_element(q_vector.constBegin(), q_vector.constEnd());
}

double Mode_common::vector_max(QVector<double> q_vector){
    return *std::max_element(q_vector.constBegin(), q_vector.constEnd());
}

