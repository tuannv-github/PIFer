#ifndef COM_H
#define COM_H

#include <QWidget>

#include <QSerialPortInfo>
#include <QSerialPort>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

#include <com_gui.h>
#include <led_indicator.h>

namespace Ui {
class Com;
}

class Com : public QWidget
{
    Q_OBJECT

public:
    explicit Com(QWidget *parent = nullptr);
    ~Com();

    typedef enum{
        // Serial event
        SERIAL_OPEN_SUCCESS,
        SERIAL_OPEN_FAIL,
        SERIAL_CLOSED,

        // TCP event
        TCP_SERVER_OPEN_SUCCESS,
        TCP_SERVER_OPEN_FAIL,
        TCP_SERVER_CLOSED,

        // Socket event
        SOCKET_CONNECTION_OPEN,
        SOCKET_CONNECTION_CLOSE
    }com_evt_t;

    typedef enum{
        COM_SEND_SUCCESS,
        COM_SEND_FAIL
    }com_send_t;

    com_send_t send(QByteArray bytes);
    com_send_t send(uint8_t* arr, uint16_t len);

    void set_com_gui(Com_gui* cg);
    void set_led_indicator(Led_indicator *led_indicator);

signals:
    void ba_recv(QByteArray ba);
    void connection_evt(Com::com_evt_t evt);

private slots:

    // Serial slot
    void serial_data_ready();

    // Socker slot
    void new_connection();
    void socket_data_ready();
    void socket_state_changed(QAbstractSocket::SocketState socketState);

    // Led indicator
    void led_indicator_off();

    // Gui send slot
    void gui_send(QByteArray ba);

    void on_btn_open_com_clicked();
    void on_btn_open_server_clicked();

private:
    Ui::Com *ui;
    QSerialPort *g_serial;
    QTcpServer *g_tcp_server;
    QTcpSocket *g_socket;
    Com_gui *g_com_gui;
    Led_indicator *g_led_indicator;

    QString ByteArrayToString(QByteArray ba);
};

#endif // COM_H
