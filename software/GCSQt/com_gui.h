#ifndef COM_GUI_H
#define COM_GUI_H

#include <QWidget>

namespace Ui {
class Com_gui;
}

class Com_gui : public QWidget
{
    Q_OBJECT

public:
    explicit Com_gui(QWidget *parent = nullptr);
    ~Com_gui();

    void appendHtml(QString str);

signals:
    void send(QByteArray ba);

private slots:
    void on_btn_send_clicked();

private:
    Ui::Com_gui *ui;
};

#endif // COM_GUI_H
