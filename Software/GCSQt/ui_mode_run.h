/********************************************************************************
** Form generated from reading UI file 'mode_run.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
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
    QLabel *label_48;
    QLineEdit *txtBoxPitch;
    QLabel *label_54;
    QLineEdit *txtBoxYaw;
    QLabel *label_79;
    QLineEdit *txtb_tilt_1;
    QPushButton *btn_change_mode_run;
    QGroupBox *groupBox_12;
    QLabel *label_61;
    QLineEdit *txtb_pidt_vx;
    QLabel *label_62;
    QLineEdit *txtBoxVY;
    QLabel *label_63;
    QLineEdit *txtb_pidt_w;
    QPushButton *btn_control_enable;

    void setupUi(QWidget *Mode_run)
    {
        if (Mode_run->objectName().isEmpty())
            Mode_run->setObjectName(QString::fromUtf8("Mode_run"));
        Mode_run->resize(640, 180);
        groupBox_11 = new QGroupBox(Mode_run);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 40, 621, 61));
        label_47 = new QLabel(groupBox_11);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(10, 30, 31, 16));
        txtBoxRoll = new QLineEdit(groupBox_11);
        txtBoxRoll->setObjectName(QString::fromUtf8("txtBoxRoll"));
        txtBoxRoll->setGeometry(QRect(40, 30, 91, 20));
        txtBoxRoll->setReadOnly(true);
        label_48 = new QLabel(groupBox_11);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(160, 30, 31, 16));
        txtBoxPitch = new QLineEdit(groupBox_11);
        txtBoxPitch->setObjectName(QString::fromUtf8("txtBoxPitch"));
        txtBoxPitch->setGeometry(QRect(190, 30, 91, 20));
        txtBoxPitch->setReadOnly(true);
        label_54 = new QLabel(groupBox_11);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(310, 30, 31, 16));
        txtBoxYaw = new QLineEdit(groupBox_11);
        txtBoxYaw->setObjectName(QString::fromUtf8("txtBoxYaw"));
        txtBoxYaw->setGeometry(QRect(350, 30, 91, 20));
        txtBoxYaw->setReadOnly(true);
        label_79 = new QLabel(groupBox_11);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(470, 30, 31, 16));
        txtb_tilt_1 = new QLineEdit(groupBox_11);
        txtb_tilt_1->setObjectName(QString::fromUtf8("txtb_tilt_1"));
        txtb_tilt_1->setGeometry(QRect(510, 30, 91, 20));
        txtb_tilt_1->setReadOnly(true);
        btn_change_mode_run = new QPushButton(Mode_run);
        btn_change_mode_run->setObjectName(QString::fromUtf8("btn_change_mode_run"));
        btn_change_mode_run->setGeometry(QRect(10, 10, 101, 23));
        groupBox_12 = new QGroupBox(Mode_run);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 110, 621, 61));
        label_61 = new QLabel(groupBox_12);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(10, 30, 31, 16));
        txtb_pidt_vx = new QLineEdit(groupBox_12);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(40, 30, 113, 20));
        txtb_pidt_vx->setReadOnly(true);
        label_62 = new QLabel(groupBox_12);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(170, 30, 31, 16));
        txtBoxVY = new QLineEdit(groupBox_12);
        txtBoxVY->setObjectName(QString::fromUtf8("txtBoxVY"));
        txtBoxVY->setGeometry(QRect(210, 30, 113, 20));
        txtBoxVY->setReadOnly(true);
        label_63 = new QLabel(groupBox_12);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(340, 30, 41, 16));
        txtb_pidt_w = new QLineEdit(groupBox_12);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(390, 30, 113, 20));
        txtb_pidt_w->setReadOnly(true);
        btn_control_enable = new QPushButton(groupBox_12);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(520, 30, 81, 21));

        retranslateUi(Mode_run);

        QMetaObject::connectSlotsByName(Mode_run);
    } // setupUi

    void retranslateUi(QWidget *Mode_run)
    {
        Mode_run->setWindowTitle(QApplication::translate("Mode_run", "Form", nullptr));
        groupBox_11->setTitle(QApplication::translate("Mode_run", "Roll Pitch Yaw", nullptr));
        label_47->setText(QApplication::translate("Mode_run", "Roll:", nullptr));
        txtBoxRoll->setText(QApplication::translate("Mode_run", "NR", nullptr));
        label_48->setText(QApplication::translate("Mode_run", "Pitch:", nullptr));
        txtBoxPitch->setText(QApplication::translate("Mode_run", "NR", nullptr));
        label_54->setText(QApplication::translate("Mode_run", "Yaw:", nullptr));
        txtBoxYaw->setText(QApplication::translate("Mode_run", "NR", nullptr));
        label_79->setText(QApplication::translate("Mode_run", "Tilt:", nullptr));
        txtb_tilt_1->setText(QApplication::translate("Mode_run", "NR", nullptr));
        btn_change_mode_run->setText(QApplication::translate("Mode_run", "Mode Run", nullptr));
        groupBox_12->setTitle(QApplication::translate("Mode_run", "Control", nullptr));
        label_61->setText(QApplication::translate("Mode_run", "VX:", nullptr));
        txtb_pidt_vx->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_62->setText(QApplication::translate("Mode_run", "VY:", nullptr));
        txtBoxVY->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_63->setText(QApplication::translate("Mode_run", "OMEGA:", nullptr));
        txtb_pidt_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        btn_control_enable->setText(QApplication::translate("Mode_run", "Disabled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_run: public Ui_Mode_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_RUN_H
