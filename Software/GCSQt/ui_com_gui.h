/********************************************************************************
** Form generated from reading UI file 'com_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COM_GUI_H
#define UI_COM_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Com_gui
{
public:
    QLineEdit *tb_send;
    QPlainTextEdit *tb_receive;
    QPushButton *btn_send;

    void setupUi(QWidget *Com_gui)
    {
        if (Com_gui->objectName().isEmpty())
            Com_gui->setObjectName(QString::fromUtf8("Com_gui"));
        Com_gui->resize(642, 511);
        tb_send = new QLineEdit(Com_gui);
        tb_send->setObjectName(QString::fromUtf8("tb_send"));
        tb_send->setGeometry(QRect(10, 10, 531, 20));
        tb_receive = new QPlainTextEdit(Com_gui);
        tb_receive->setObjectName(QString::fromUtf8("tb_receive"));
        tb_receive->setGeometry(QRect(10, 40, 621, 461));
        btn_send = new QPushButton(Com_gui);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setGeometry(QRect(550, 10, 81, 21));

        retranslateUi(Com_gui);

        QMetaObject::connectSlotsByName(Com_gui);
    } // setupUi

    void retranslateUi(QWidget *Com_gui)
    {
        Com_gui->setWindowTitle(QApplication::translate("Com_gui", "Form", nullptr));
        btn_send->setText(QApplication::translate("Com_gui", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Com_gui: public Ui_Com_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COM_GUI_H
