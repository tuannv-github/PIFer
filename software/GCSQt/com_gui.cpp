#include "com_gui.h"
#include "ui_com_gui.h"

Com_gui::Com_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Com_gui)
{
    ui->setupUi(this);
}

Com_gui::~Com_gui()
{
    delete ui;
}

void Com_gui::on_btn_send_clicked()
{
    emit send(ui->tb_send->text().toUtf8());
}

void Com_gui::appendHtml(QString str){
    ui->tb_receive->appendHtml(str);
}
