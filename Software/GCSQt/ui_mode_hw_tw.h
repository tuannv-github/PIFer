/********************************************************************************
** Form generated from reading UI file 'mode_hw_tw.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_HW_TW_H
#define UI_MODE_HW_TW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_hw_tw
{
public:
    QGroupBox *groupBox_9;
    QLineEdit *txtb_motor1_duty;
    QLabel *label_17;
    QLabel *label_19;
    QLineEdit *txtb_enc1_speed;
    QPushButton *btn_set_duty1;
    QCheckBox *cb_motor1_invert;
    QCheckBox *cb_enc1_invert;
    QPushButton *btn_mode_hw_save_params;
    QPushButton *btn_mode_hw_write_params;
    QPushButton *btn_change_mode_hw;
    QGroupBox *groupBox_8;
    QLineEdit *txtb_motor0_duty;
    QLabel *label_16;
    QLabel *label_18;
    QLineEdit *txtb_enc0_speed;
    QPushButton *btn_set_duty0;
    QCheckBox *cb_motor0_invert;
    QCheckBox *cb_enc0_invert;
    QCheckBox *cb_enc_exchange;
    QPushButton *btn_mode_hw_load_params;

    void setupUi(QWidget *Mode_hw_tw)
    {
        if (Mode_hw_tw->objectName().isEmpty())
            Mode_hw_tw->setObjectName(QString::fromUtf8("Mode_hw_tw"));
        Mode_hw_tw->resize(653, 162);
        groupBox_9 = new QGroupBox(Mode_hw_tw);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 100, 631, 51));
        txtb_motor1_duty = new QLineEdit(groupBox_9);
        txtb_motor1_duty->setObjectName(QString::fromUtf8("txtb_motor1_duty"));
        txtb_motor1_duty->setGeometry(QRect(40, 20, 111, 20));
        label_17 = new QLabel(groupBox_9);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 20, 31, 16));
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(260, 20, 51, 20));
        txtb_enc1_speed = new QLineEdit(groupBox_9);
        txtb_enc1_speed->setObjectName(QString::fromUtf8("txtb_enc1_speed"));
        txtb_enc1_speed->setGeometry(QRect(320, 20, 101, 20));
        txtb_enc1_speed->setReadOnly(true);
        btn_set_duty1 = new QPushButton(groupBox_9);
        btn_set_duty1->setObjectName(QString::fromUtf8("btn_set_duty1"));
        btn_set_duty1->setGeometry(QRect(160, 20, 71, 23));
        cb_motor1_invert = new QCheckBox(groupBox_9);
        cb_motor1_invert->setObjectName(QString::fromUtf8("cb_motor1_invert"));
        cb_motor1_invert->setGeometry(QRect(450, 20, 81, 17));
        cb_enc1_invert = new QCheckBox(groupBox_9);
        cb_enc1_invert->setObjectName(QString::fromUtf8("cb_enc1_invert"));
        cb_enc1_invert->setGeometry(QRect(550, 20, 70, 16));
        btn_mode_hw_save_params = new QPushButton(Mode_hw_tw);
        btn_mode_hw_save_params->setObjectName(QString::fromUtf8("btn_mode_hw_save_params"));
        btn_mode_hw_save_params->setGeometry(QRect(370, 10, 101, 23));
        btn_mode_hw_write_params = new QPushButton(Mode_hw_tw);
        btn_mode_hw_write_params->setObjectName(QString::fromUtf8("btn_mode_hw_write_params"));
        btn_mode_hw_write_params->setGeometry(QRect(250, 10, 101, 23));
        btn_change_mode_hw = new QPushButton(Mode_hw_tw);
        btn_change_mode_hw->setObjectName(QString::fromUtf8("btn_change_mode_hw"));
        btn_change_mode_hw->setGeometry(QRect(10, 10, 101, 23));
        groupBox_8 = new QGroupBox(Mode_hw_tw);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 40, 631, 51));
        txtb_motor0_duty = new QLineEdit(groupBox_8);
        txtb_motor0_duty->setObjectName(QString::fromUtf8("txtb_motor0_duty"));
        txtb_motor0_duty->setGeometry(QRect(40, 20, 111, 20));
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 20, 31, 16));
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(260, 20, 71, 20));
        txtb_enc0_speed = new QLineEdit(groupBox_8);
        txtb_enc0_speed->setObjectName(QString::fromUtf8("txtb_enc0_speed"));
        txtb_enc0_speed->setGeometry(QRect(320, 20, 101, 20));
        txtb_enc0_speed->setReadOnly(true);
        btn_set_duty0 = new QPushButton(groupBox_8);
        btn_set_duty0->setObjectName(QString::fromUtf8("btn_set_duty0"));
        btn_set_duty0->setGeometry(QRect(160, 20, 71, 23));
        cb_motor0_invert = new QCheckBox(groupBox_8);
        cb_motor0_invert->setObjectName(QString::fromUtf8("cb_motor0_invert"));
        cb_motor0_invert->setGeometry(QRect(450, 20, 81, 17));
        cb_enc0_invert = new QCheckBox(groupBox_8);
        cb_enc0_invert->setObjectName(QString::fromUtf8("cb_enc0_invert"));
        cb_enc0_invert->setGeometry(QRect(550, 20, 70, 17));
        cb_enc_exchange = new QCheckBox(Mode_hw_tw);
        cb_enc_exchange->setObjectName(QString::fromUtf8("cb_enc_exchange"));
        cb_enc_exchange->setGeometry(QRect(490, 10, 111, 17));
        btn_mode_hw_load_params = new QPushButton(Mode_hw_tw);
        btn_mode_hw_load_params->setObjectName(QString::fromUtf8("btn_mode_hw_load_params"));
        btn_mode_hw_load_params->setGeometry(QRect(130, 10, 101, 23));

        retranslateUi(Mode_hw_tw);

        QMetaObject::connectSlotsByName(Mode_hw_tw);
    } // setupUi

    void retranslateUi(QWidget *Mode_hw_tw)
    {
        Mode_hw_tw->setWindowTitle(QApplication::translate("Mode_hw_tw", "Form", nullptr));
        groupBox_9->setTitle(QApplication::translate("Mode_hw_tw", "Motor 1:", nullptr));
        txtb_motor1_duty->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        label_17->setText(QApplication::translate("Mode_hw_tw", "Duty:", nullptr));
        label_19->setText(QApplication::translate("Mode_hw_tw", "Enc speed:", nullptr));
        txtb_enc1_speed->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        btn_set_duty1->setText(QApplication::translate("Mode_hw_tw", "Set duty", nullptr));
        cb_motor1_invert->setText(QApplication::translate("Mode_hw_tw", "Motor Invert", nullptr));
        cb_enc1_invert->setText(QApplication::translate("Mode_hw_tw", "Enc Invert", nullptr));
        btn_mode_hw_save_params->setText(QApplication::translate("Mode_hw_tw", "Save", nullptr));
        btn_mode_hw_write_params->setText(QApplication::translate("Mode_hw_tw", "Write", nullptr));
        btn_change_mode_hw->setText(QApplication::translate("Mode_hw_tw", "Mode HW", nullptr));
        groupBox_8->setTitle(QApplication::translate("Mode_hw_tw", "Motor 0:", nullptr));
        txtb_motor0_duty->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        label_16->setText(QApplication::translate("Mode_hw_tw", "Duty:", nullptr));
        label_18->setText(QApplication::translate("Mode_hw_tw", "Enc speed:", nullptr));
        txtb_enc0_speed->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        btn_set_duty0->setText(QApplication::translate("Mode_hw_tw", "Set duty", nullptr));
        cb_motor0_invert->setText(QApplication::translate("Mode_hw_tw", "Motor Invert", nullptr));
        cb_enc0_invert->setText(QApplication::translate("Mode_hw_tw", "Enc Invert", nullptr));
        cb_enc_exchange->setText(QApplication::translate("Mode_hw_tw", "Encoder exchange", nullptr));
        btn_mode_hw_load_params->setText(QApplication::translate("Mode_hw_tw", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_hw_tw: public Ui_Mode_hw_tw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_HW_TW_H
