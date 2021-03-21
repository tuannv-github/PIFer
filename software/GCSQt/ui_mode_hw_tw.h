/********************************************************************************
** Form generated from reading UI file 'mode_hw_tw.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_HW_TW_H
#define UI_MODE_HW_TW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_hw_tw
{
public:
    QPushButton *btn_mode_hw_save_params;
    QPushButton *btn_mode_hw_write_params;
    QPushButton *btn_change_mode_hw;
    QGroupBox *groupBox_8;
    QLineEdit *txtb_motor0_duty;
    QPushButton *btn_set_duty0;
    QLineEdit *txtb_motor1_duty;
    QPushButton *btn_mode_hw_load_params;
    QComboBox *cb_motor_type;
    QGroupBox *groupBox;
    QLineEdit *txtb_enc0_speed;
    QLineEdit *txtb_enc1_speed;
    QGroupBox *groupBox_2;
    QLineEdit *txtb_motor0_pos_deadband;
    QLineEdit *txtb_motor1_pos_deadband;
    QGroupBox *groupBox_3;
    QLineEdit *txtb_motor0_neg_deadband;
    QLineEdit *txtb_motor1_neg_deadband;
    QGroupBox *groupBox_4;
    QCheckBox *cb_motor0_invert;
    QCheckBox *cb_motor1_invert;
    QGroupBox *groupBox_5;
    QCheckBox *cb_enc0_invert;
    QCheckBox *cb_enc1_invert;
    QCheckBox *cb_enc_exchange;

    void setupUi(QWidget *Mode_hw_tw)
    {
        if (Mode_hw_tw->objectName().isEmpty())
            Mode_hw_tw->setObjectName(QString::fromUtf8("Mode_hw_tw"));
        Mode_hw_tw->resize(648, 316);
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
        groupBox_8->setGeometry(QRect(10, 40, 81, 111));
        txtb_motor0_duty = new QLineEdit(groupBox_8);
        txtb_motor0_duty->setObjectName(QString::fromUtf8("txtb_motor0_duty"));
        txtb_motor0_duty->setGeometry(QRect(10, 20, 61, 20));
        btn_set_duty0 = new QPushButton(groupBox_8);
        btn_set_duty0->setObjectName(QString::fromUtf8("btn_set_duty0"));
        btn_set_duty0->setGeometry(QRect(10, 80, 61, 23));
        txtb_motor1_duty = new QLineEdit(groupBox_8);
        txtb_motor1_duty->setObjectName(QString::fromUtf8("txtb_motor1_duty"));
        txtb_motor1_duty->setGeometry(QRect(10, 50, 61, 20));
        btn_mode_hw_load_params = new QPushButton(Mode_hw_tw);
        btn_mode_hw_load_params->setObjectName(QString::fromUtf8("btn_mode_hw_load_params"));
        btn_mode_hw_load_params->setGeometry(QRect(130, 10, 101, 23));
        cb_motor_type = new QComboBox(Mode_hw_tw);
        cb_motor_type->addItem(QString());
        cb_motor_type->addItem(QString());
        cb_motor_type->setObjectName(QString::fromUtf8("cb_motor_type"));
        cb_motor_type->setGeometry(QRect(490, 10, 91, 22));
        groupBox = new QGroupBox(Mode_hw_tw);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 40, 81, 111));
        txtb_enc0_speed = new QLineEdit(groupBox);
        txtb_enc0_speed->setObjectName(QString::fromUtf8("txtb_enc0_speed"));
        txtb_enc0_speed->setGeometry(QRect(10, 20, 61, 20));
        txtb_enc0_speed->setReadOnly(true);
        txtb_enc1_speed = new QLineEdit(groupBox);
        txtb_enc1_speed->setObjectName(QString::fromUtf8("txtb_enc1_speed"));
        txtb_enc1_speed->setGeometry(QRect(10, 50, 61, 20));
        txtb_enc1_speed->setReadOnly(true);
        groupBox_2 = new QGroupBox(Mode_hw_tw);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 40, 81, 111));
        txtb_motor0_pos_deadband = new QLineEdit(groupBox_2);
        txtb_motor0_pos_deadband->setObjectName(QString::fromUtf8("txtb_motor0_pos_deadband"));
        txtb_motor0_pos_deadband->setGeometry(QRect(10, 20, 61, 20));
        txtb_motor1_pos_deadband = new QLineEdit(groupBox_2);
        txtb_motor1_pos_deadband->setObjectName(QString::fromUtf8("txtb_motor1_pos_deadband"));
        txtb_motor1_pos_deadband->setGeometry(QRect(10, 50, 61, 20));
        groupBox_3 = new QGroupBox(Mode_hw_tw);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(280, 40, 81, 111));
        txtb_motor0_neg_deadband = new QLineEdit(groupBox_3);
        txtb_motor0_neg_deadband->setObjectName(QString::fromUtf8("txtb_motor0_neg_deadband"));
        txtb_motor0_neg_deadband->setGeometry(QRect(10, 20, 61, 20));
        txtb_motor1_neg_deadband = new QLineEdit(groupBox_3);
        txtb_motor1_neg_deadband->setObjectName(QString::fromUtf8("txtb_motor1_neg_deadband"));
        txtb_motor1_neg_deadband->setGeometry(QRect(10, 50, 61, 20));
        groupBox_4 = new QGroupBox(Mode_hw_tw);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(370, 40, 81, 111));
        cb_motor0_invert = new QCheckBox(groupBox_4);
        cb_motor0_invert->setObjectName(QString::fromUtf8("cb_motor0_invert"));
        cb_motor0_invert->setGeometry(QRect(10, 20, 81, 17));
        cb_motor1_invert = new QCheckBox(groupBox_4);
        cb_motor1_invert->setObjectName(QString::fromUtf8("cb_motor1_invert"));
        cb_motor1_invert->setGeometry(QRect(10, 50, 81, 17));
        groupBox_5 = new QGroupBox(Mode_hw_tw);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(460, 40, 81, 111));
        cb_enc0_invert = new QCheckBox(groupBox_5);
        cb_enc0_invert->setObjectName(QString::fromUtf8("cb_enc0_invert"));
        cb_enc0_invert->setGeometry(QRect(10, 50, 70, 17));
        cb_enc1_invert = new QCheckBox(groupBox_5);
        cb_enc1_invert->setObjectName(QString::fromUtf8("cb_enc1_invert"));
        cb_enc1_invert->setGeometry(QRect(10, 80, 70, 16));
        cb_enc_exchange = new QCheckBox(groupBox_5);
        cb_enc_exchange->setObjectName(QString::fromUtf8("cb_enc_exchange"));
        cb_enc_exchange->setGeometry(QRect(10, 20, 71, 17));

        retranslateUi(Mode_hw_tw);

        QMetaObject::connectSlotsByName(Mode_hw_tw);
    } // setupUi

    void retranslateUi(QWidget *Mode_hw_tw)
    {
        Mode_hw_tw->setWindowTitle(QApplication::translate("Mode_hw_tw", "Form", nullptr));
        btn_mode_hw_save_params->setText(QApplication::translate("Mode_hw_tw", "Save", nullptr));
        btn_mode_hw_write_params->setText(QApplication::translate("Mode_hw_tw", "Write", nullptr));
        btn_change_mode_hw->setText(QApplication::translate("Mode_hw_tw", "Mode HW", nullptr));
        groupBox_8->setTitle(QApplication::translate("Mode_hw_tw", "Set Speed", nullptr));
        txtb_motor0_duty->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        btn_set_duty0->setText(QApplication::translate("Mode_hw_tw", "Set speed", nullptr));
        txtb_motor1_duty->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        btn_mode_hw_load_params->setText(QApplication::translate("Mode_hw_tw", "Load", nullptr));
        cb_motor_type->setItemText(0, QApplication::translate("Mode_hw_tw", "DC", nullptr));
        cb_motor_type->setItemText(1, QApplication::translate("Mode_hw_tw", "STEP", nullptr));

        groupBox->setTitle(QApplication::translate("Mode_hw_tw", "Encoder", nullptr));
        txtb_enc0_speed->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        txtb_enc1_speed->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        groupBox_2->setTitle(QApplication::translate("Mode_hw_tw", "Pos dead", nullptr));
        txtb_motor0_pos_deadband->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        txtb_motor1_pos_deadband->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        groupBox_3->setTitle(QApplication::translate("Mode_hw_tw", "Neg dead", nullptr));
        txtb_motor0_neg_deadband->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        txtb_motor1_neg_deadband->setText(QApplication::translate("Mode_hw_tw", "0", nullptr));
        groupBox_4->setTitle(QApplication::translate("Mode_hw_tw", "Inverse", nullptr));
        cb_motor0_invert->setText(QApplication::translate("Mode_hw_tw", "Motor 0", nullptr));
        cb_motor1_invert->setText(QApplication::translate("Mode_hw_tw", "Motor 1", nullptr));
        groupBox_5->setTitle(QApplication::translate("Mode_hw_tw", "Encoder", nullptr));
        cb_enc0_invert->setText(QApplication::translate("Mode_hw_tw", "Enc Inv 0", nullptr));
        cb_enc1_invert->setText(QApplication::translate("Mode_hw_tw", "Enc Inv 1", nullptr));
        cb_enc_exchange->setText(QApplication::translate("Mode_hw_tw", "Exchange", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_hw_tw: public Ui_Mode_hw_tw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_HW_TW_H
