#include "com.h"
#include "ui_com.h"

Com::Com(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Com)
{
    ui->setupUi(this);

    ui->cb_serial_port->clear();
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->cb_serial_port->addItem(port.portName());
    }

    g_serial = new QSerialPort();
    connect(g_serial,  SIGNAL(readyRead()), this, SLOT(serial_data_ready()));

    g_socket = new QTcpSocket();
    connect(g_socket, SIGNAL(readyRead()), this, SLOT(socket_data_ready()));
}

Com::~Com()
{
    delete ui;
}

void Com::on_btn_open_socket_clicked()
{
    if(g_socket->isOpen()){
        ui->btn_open_socket->setText("Open");
        ui->tb_server_ip->setEnabled(true);
        ui->tb_server_port->setEnabled(true);
        g_socket->close();
    }
    else{
        g_socket->connectToHost(QHostAddress(ui->tb_server_ip->text()), static_cast<quint16>(ui->tb_server_port->text().toInt()));
        ui->btn_open_socket->setText("Close");
        ui->tb_server_ip->setEnabled(false);
        ui->tb_server_port->setEnabled(false);
    }

}

void Com::on_btn_open_com_clicked()
{

    if(g_serial->isOpen()){
        g_serial->clear();
        ui->btn_open_com->setText("Open");
        ui->cb_serial_port->setEnabled(true);
        ui->cb_baud->setEnabled(true);
        g_serial->close();
        emit connection_evt(SERIAL_CLOSED);
    }
    else{
        g_serial->setPortName(ui->cb_serial_port->currentText());
        g_serial->setBaudRate(ui->cb_baud->currentText().toInt());
        if(g_serial->open(QIODevice::ReadWrite)){
            ui->btn_open_com->setText("Close");
            ui->cb_serial_port->setEnabled(false);
            ui->cb_baud->setEnabled(false);
            emit connection_evt(SERIAL_OPEN_SUCCESS);
        }
        else{
            emit connection_evt(SERIAL_OPEN_FAIL);
        }
    }
}


void Com::serial_data_ready()
{
    const QByteArray ba = g_serial->readAll();

    if(g_led_indicator != nullptr){
        g_led_indicator->setState(true);
        QTimer::singleShot(100, this, SLOT(led_indicator_off()));
    }
    if(g_com_gui != nullptr){
        QString qstr = ByteArrayToString(ba);
        g_com_gui->appendHtml("<font color=\"blue\">"+qstr+"</font>");
    }

    emit ba_recv(ba);
}

void Com::socket_data_ready(){
    const QByteArray ba = g_socket->readAll();

    if(g_led_indicator != nullptr){
        g_led_indicator->setState(true);
        QTimer::singleShot(100, this, SLOT(led_indicator_off()));
    }
    if(g_com_gui != nullptr){
        QString qstr = ByteArrayToString(ba);
        g_com_gui->appendHtml("<font color=\"blue\">"+qstr+"</font>");
    }

    emit ba_recv(ba);
}

Com::com_send_t Com::send(QByteArray bytes){
    bool serialSuccess = false;
    bool socketSuccess = false;

    if(g_serial->isOpen()){
        if(g_serial->write(bytes)){
            serialSuccess = true;
        }

    }
    if(g_socket->isOpen()){
        if(g_socket->write(bytes)){
            socketSuccess = true;
        }
    }

    if(serialSuccess || socketSuccess){
        if(g_led_indicator != nullptr){
            g_led_indicator->setState(true);
            QTimer::singleShot(100, this, SLOT(led_indicator_off()));
        }
        if(g_com_gui != nullptr){
            QString qstr = ByteArrayToString(bytes);
            g_com_gui->appendHtml("<font color=\"green\">"+qstr+"</font>");
        }
        return Com::COM_SEND_SUCCESS;
    }
    else{
        return Com::COM_SEND_FAIL;
    }
}

Com::com_send_t Com::send(uint8_t* arr, uint16_t len){
    return send(QByteArray::fromRawData(reinterpret_cast<char*>(arr),len));
}

void Com::set_com_gui(Com_gui* cg){
    g_com_gui = cg;
    connect(g_com_gui,SIGNAL(send(QByteArray)),this,SLOT(gui_send(QByteArray)));
}

void Com::set_led_indicator(Led_indicator *led_indicator){
    g_led_indicator = led_indicator;
}

QString Com::ByteArrayToString(QByteArray ba)
{
    QString qstr;
    char tmp[20];
    for (char byte : ba) {
        sprintf(tmp, "{%02x}", static_cast<uint8_t>(byte));
        qstr.append(QString(tmp));
    }
    return qstr;
}

void Com::led_indicator_off(){
    g_led_indicator->setState(false);
}

void Com::gui_send(QByteArray ba){
    send(ba);
}
