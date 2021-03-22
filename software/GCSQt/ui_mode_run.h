/********************************************************************************
** Form generated from reading UI file 'mode_run.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_RUN_H
#define UI_MODE_RUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_run
{
public:
    QGroupBox *groupBox_11;
    QLabel *label_47;
    QLineEdit *txtBoxRoll;
    QLineEdit *txtBoxPitch;
    QLineEdit *txtBoxYaw;
    QLabel *label_79;
    QLineEdit *tb_tilt_cal;
    QPushButton *btn_change_mode_run;
    QGroupBox *groupBox_12;
    QLabel *label_61;
    QLineEdit *txtb_pidt_vx;
    QLabel *label_62;
    QLabel *label_63;
    QLineEdit *txtBoxVY;
    QLineEdit *txtb_pidt_w;
    QPushButton *btn_control_enable;

    void setupUi(QWidget *Mode_run)
    {
        if (Mode_run->objectName().isEmpty())
            Mode_run->setObjectName(QString::fromUtf8("Mode_run"));
        Mode_run->resize(640, 272);
        groupBox_11 = new QGroupBox(Mode_run);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 40, 481, 51));
        label_47 = new QLabel(groupBox_11);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(10, 20, 31, 16));
        txtBoxRoll = new QLineEdit(groupBox_11);
        txtBoxRoll->setObjectName(QString::fromUtf8("txtBoxRoll"));
        txtBoxRoll->setGeometry(QRect(40, 20, 91, 20));
        txtBoxRoll->setReadOnly(true);
        txtBoxPitch = new QLineEdit(groupBox_11);
        txtBoxPitch->setObjectName(QString::fromUtf8("txtBoxPitch"));
        txtBoxPitch->setGeometry(QRect(140, 20, 91, 20));
        txtBoxPitch->setReadOnly(true);
        txtBoxYaw = new QLineEdit(groupBox_11);
        txtBoxYaw->setObjectName(QString::fromUtf8("txtBoxYaw"));
        txtBoxYaw->setGeometry(QRect(240, 20, 91, 20));
        txtBoxYaw->setReadOnly(true);
        label_79 = new QLabel(groupBox_11);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(350, 20, 31, 16));
        tb_tilt_cal = new QLineEdit(groupBox_11);
        tb_tilt_cal->setObjectName(QString::fromUtf8("tb_tilt_cal"));
        tb_tilt_cal->setGeometry(QRect(380, 20, 91, 20));
        tb_tilt_cal->setReadOnly(true);
        btn_change_mode_run = new QPushButton(Mode_run);
        btn_change_mode_run->setObjectName(QString::fromUtf8("btn_change_mode_run"));
        btn_change_mode_run->setGeometry(QRect(10, 10, 101, 23));
        groupBox_12 = new QGroupBox(Mode_run);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 90, 441, 51));
        label_61 = new QLabel(groupBox_12);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(10, 20, 31, 16));
        txtb_pidt_vx = new QLineEdit(groupBox_12);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(40, 20, 91, 20));
        txtb_pidt_vx->setReadOnly(true);
        label_62 = new QLabel(groupBox_12);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(150, 20, 31, 16));
        label_63 = new QLabel(groupBox_12);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(290, 20, 41, 16));
        txtBoxVY = new QLineEdit(groupBox_12);
        txtBoxVY->setObjectName(QString::fromUtf8("txtBoxVY"));
        txtBoxVY->setGeometry(QRect(180, 20, 91, 20));
        txtBoxVY->setReadOnly(true);
        txtb_pidt_w = new QLineEdit(groupBox_12);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(340, 20, 91, 20));
        txtb_pidt_w->setReadOnly(true);
        btn_control_enable = new QPushButton(Mode_run);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(120, 10, 101, 23));

        retranslateUi(Mode_run);

        QMetaObject::connectSlotsByName(Mode_run);
    } // setupUi

    void retranslateUi(QWidget *Mode_run)
    {
        Mode_run->setWindowTitle(QApplication::translate("Mode_run", "Form", nullptr));
        groupBox_11->setTitle(QApplication::translate("Mode_run", "Attitude", nullptr));
        label_47->setText(QApplication::translate("Mode_run", "RPY:", nullptr));
        txtBoxRoll->setText(QApplication::translate("Mode_run", "NR", nullptr));
        txtBoxPitch->setText(QApplication::translate("Mode_run", "NR", nullptr));
        txtBoxYaw->setText(QApplication::translate("Mode_run", "NR", nullptr));
        label_79->setText(QApplication::translate("Mode_run", "Tilt:", nullptr));
        tb_tilt_cal->setText(QApplication::translate("Mode_run", "NR", nullptr));
        btn_change_mode_run->setText(QApplication::translate("Mode_run", "Mode Run", nullptr));
        groupBox_12->setTitle(QApplication::translate("Mode_run", "Control", nullptr));
        label_61->setText(QApplication::translate("Mode_run", "VX:", nullptr));
        txtb_pidt_vx->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_62->setText(QApplication::translate("Mode_run", "VY:", nullptr));
        label_63->setText(QApplication::translate("Mode_run", "OMEGA:", nullptr));
        txtBoxVY->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtb_pidt_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        btn_control_enable->setText(QApplication::translate("Mode_run", "Disabled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_run: public Ui_Mode_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_RUN_H
