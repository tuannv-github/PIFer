/********************************************************************************
** Form generated from reading UI file 'mode_pidt_ta.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_PIDT_TA_H
#define UI_MODE_PIDT_TA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_pidt_ta
{
public:
    QPushButton *btn_mode_pidt_save_params;
    QGroupBox *groupBox_5;
    QDoubleSpinBox *sb_w1_kp;
    QLabel *label_43;
    QLabel *label_69;
    QDoubleSpinBox *sb_w1_ki;
    QLabel *label_70;
    QDoubleSpinBox *sb_w1_kd;
    QLabel *label_71;
    QDoubleSpinBox *sb_step_w1_kp;
    QLabel *label_72;
    QDoubleSpinBox *sb_step_w1_ki;
    QLabel *label_73;
    QDoubleSpinBox *sb_step_w1_kd;
    QPushButton *btn_mode_pidt_write_params_pid_whe1;
    QPushButton *btn_change_mode_pidt;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *sb_sta_kp;
    QLabel *label_40;
    QLabel *label_49;
    QDoubleSpinBox *sb_sta_ki;
    QLabel *label_50;
    QDoubleSpinBox *sb_sta_kd;
    QLabel *label_51;
    QDoubleSpinBox *sb_step_sta_kp;
    QLabel *label_52;
    QDoubleSpinBox *sb_step_sta_ki;
    QLabel *label_53;
    QDoubleSpinBox *sb_step_sta_kd;
    QPushButton *btn_mode_pidt_write_params_pid_sync;
    QGroupBox *groupBox_14;
    QLineEdit *txtb_motor0_speed;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *txtb_enc0_ta_speed;
    QPushButton *btn_set_speed0;
    QPushButton *btn_mode_pidt_load_params;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *sb_w0_kp;
    QLabel *label_41;
    QLabel *label_56;
    QDoubleSpinBox *sb_w0_ki;
    QLabel *label_57;
    QDoubleSpinBox *sb_w0_kd;
    QLabel *label_58;
    QDoubleSpinBox *sb_step_w0_kp;
    QLabel *label_59;
    QDoubleSpinBox *sb_step_w0_ki;
    QLabel *label_60;
    QDoubleSpinBox *sb_step_w0_kd;
    QPushButton *btn_mode_pidt_write_params_pid_whe0;
    QPushButton *btn_mode_pidt_write_params;
    QGroupBox *groupBox_4;
    QLabel *label_34;
    QLineEdit *txtb_pidt_vx;
    QLabel *label_35;
    QLineEdit *txtb_pidt_w;
    QPushButton *btn_control_enable;
    QGroupBox *groupBox_10;
    QLineEdit *txtb_motor1_speed;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *txtb_enc1_ta_speed;
    QPushButton *btn_set_speed1;

    void setupUi(QWidget *Mode_pidt_ta)
    {
        if (Mode_pidt_ta->objectName().isEmpty())
            Mode_pidt_ta->setObjectName(QString::fromUtf8("Mode_pidt_ta"));
        Mode_pidt_ta->resize(642, 511);
        btn_mode_pidt_save_params = new QPushButton(Mode_pidt_ta);
        btn_mode_pidt_save_params->setObjectName(QString::fromUtf8("btn_mode_pidt_save_params"));
        btn_mode_pidt_save_params->setGeometry(QRect(370, 10, 101, 23));
        groupBox_5 = new QGroupBox(Mode_pidt_ta);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 160, 621, 111));
        sb_w1_kp = new QDoubleSpinBox(groupBox_5);
        sb_w1_kp->setObjectName(QString::fromUtf8("sb_w1_kp"));
        sb_w1_kp->setGeometry(QRect(30, 20, 371, 22));
        sb_w1_kp->setSingleStep(0.100000000000000);
        label_43 = new QLabel(groupBox_5);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(10, 20, 21, 16));
        label_69 = new QLabel(groupBox_5);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setGeometry(QRect(10, 50, 21, 16));
        sb_w1_ki = new QDoubleSpinBox(groupBox_5);
        sb_w1_ki->setObjectName(QString::fromUtf8("sb_w1_ki"));
        sb_w1_ki->setGeometry(QRect(30, 50, 371, 22));
        sb_w1_ki->setSingleStep(0.100000000000000);
        label_70 = new QLabel(groupBox_5);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(10, 80, 21, 16));
        sb_w1_kd = new QDoubleSpinBox(groupBox_5);
        sb_w1_kd->setObjectName(QString::fromUtf8("sb_w1_kd"));
        sb_w1_kd->setGeometry(QRect(30, 80, 371, 22));
        sb_w1_kd->setSingleStep(0.100000000000000);
        label_71 = new QLabel(groupBox_5);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setGeometry(QRect(410, 20, 31, 16));
        sb_step_w1_kp = new QDoubleSpinBox(groupBox_5);
        sb_step_w1_kp->setObjectName(QString::fromUtf8("sb_step_w1_kp"));
        sb_step_w1_kp->setGeometry(QRect(450, 20, 101, 22));
        sb_step_w1_kp->setSingleStep(0.100000000000000);
        sb_step_w1_kp->setValue(0.100000000000000);
        label_72 = new QLabel(groupBox_5);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setGeometry(QRect(410, 50, 31, 16));
        sb_step_w1_ki = new QDoubleSpinBox(groupBox_5);
        sb_step_w1_ki->setObjectName(QString::fromUtf8("sb_step_w1_ki"));
        sb_step_w1_ki->setGeometry(QRect(450, 50, 101, 22));
        sb_step_w1_ki->setSingleStep(0.100000000000000);
        sb_step_w1_ki->setValue(0.100000000000000);
        label_73 = new QLabel(groupBox_5);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setGeometry(QRect(410, 80, 31, 16));
        sb_step_w1_kd = new QDoubleSpinBox(groupBox_5);
        sb_step_w1_kd->setObjectName(QString::fromUtf8("sb_step_w1_kd"));
        sb_step_w1_kd->setGeometry(QRect(450, 80, 101, 22));
        sb_step_w1_kd->setSingleStep(0.100000000000000);
        sb_step_w1_kd->setValue(0.100000000000000);
        btn_mode_pidt_write_params_pid_whe1 = new QPushButton(groupBox_5);
        btn_mode_pidt_write_params_pid_whe1->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params_pid_whe1"));
        btn_mode_pidt_write_params_pid_whe1->setGeometry(QRect(560, 20, 51, 81));
        btn_change_mode_pidt = new QPushButton(Mode_pidt_ta);
        btn_change_mode_pidt->setObjectName(QString::fromUtf8("btn_change_mode_pidt"));
        btn_change_mode_pidt->setGeometry(QRect(10, 10, 101, 23));
        groupBox_2 = new QGroupBox(Mode_pidt_ta);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 280, 621, 111));
        sb_sta_kp = new QDoubleSpinBox(groupBox_2);
        sb_sta_kp->setObjectName(QString::fromUtf8("sb_sta_kp"));
        sb_sta_kp->setGeometry(QRect(30, 20, 371, 22));
        sb_sta_kp->setMinimum(-1000.000000000000000);
        sb_sta_kp->setMaximum(1000.000000000000000);
        sb_sta_kp->setSingleStep(0.100000000000000);
        label_40 = new QLabel(groupBox_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(10, 20, 21, 16));
        label_49 = new QLabel(groupBox_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 50, 21, 16));
        sb_sta_ki = new QDoubleSpinBox(groupBox_2);
        sb_sta_ki->setObjectName(QString::fromUtf8("sb_sta_ki"));
        sb_sta_ki->setGeometry(QRect(30, 50, 371, 22));
        sb_sta_ki->setMinimum(-1000.000000000000000);
        sb_sta_ki->setMaximum(1000.000000000000000);
        sb_sta_ki->setSingleStep(0.100000000000000);
        label_50 = new QLabel(groupBox_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(10, 80, 21, 16));
        sb_sta_kd = new QDoubleSpinBox(groupBox_2);
        sb_sta_kd->setObjectName(QString::fromUtf8("sb_sta_kd"));
        sb_sta_kd->setGeometry(QRect(30, 80, 371, 22));
        sb_sta_kd->setMinimum(-1000.000000000000000);
        sb_sta_kd->setMaximum(1000.000000000000000);
        sb_sta_kd->setSingleStep(0.100000000000000);
        label_51 = new QLabel(groupBox_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(410, 20, 31, 16));
        sb_step_sta_kp = new QDoubleSpinBox(groupBox_2);
        sb_step_sta_kp->setObjectName(QString::fromUtf8("sb_step_sta_kp"));
        sb_step_sta_kp->setGeometry(QRect(450, 20, 101, 22));
        sb_step_sta_kp->setSingleStep(0.100000000000000);
        sb_step_sta_kp->setValue(0.100000000000000);
        label_52 = new QLabel(groupBox_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(410, 50, 31, 16));
        sb_step_sta_ki = new QDoubleSpinBox(groupBox_2);
        sb_step_sta_ki->setObjectName(QString::fromUtf8("sb_step_sta_ki"));
        sb_step_sta_ki->setGeometry(QRect(450, 50, 101, 22));
        sb_step_sta_ki->setSingleStep(0.100000000000000);
        sb_step_sta_ki->setValue(0.100000000000000);
        label_53 = new QLabel(groupBox_2);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(410, 80, 31, 16));
        sb_step_sta_kd = new QDoubleSpinBox(groupBox_2);
        sb_step_sta_kd->setObjectName(QString::fromUtf8("sb_step_sta_kd"));
        sb_step_sta_kd->setGeometry(QRect(450, 80, 101, 22));
        sb_step_sta_kd->setSingleStep(0.100000000000000);
        sb_step_sta_kd->setValue(0.100000000000000);
        btn_mode_pidt_write_params_pid_sync = new QPushButton(groupBox_2);
        btn_mode_pidt_write_params_pid_sync->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params_pid_sync"));
        btn_mode_pidt_write_params_pid_sync->setGeometry(QRect(560, 20, 51, 81));
        groupBox_14 = new QGroupBox(Mode_pidt_ta);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 390, 411, 51));
        txtb_motor0_speed = new QLineEdit(groupBox_14);
        txtb_motor0_speed->setObjectName(QString::fromUtf8("txtb_motor0_speed"));
        txtb_motor0_speed->setGeometry(QRect(90, 20, 71, 20));
        label_32 = new QLabel(groupBox_14);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(10, 20, 81, 16));
        label_33 = new QLabel(groupBox_14);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(260, 20, 71, 20));
        txtb_enc0_ta_speed = new QLineEdit(groupBox_14);
        txtb_enc0_ta_speed->setObjectName(QString::fromUtf8("txtb_enc0_ta_speed"));
        txtb_enc0_ta_speed->setGeometry(QRect(320, 20, 81, 20));
        btn_set_speed0 = new QPushButton(groupBox_14);
        btn_set_speed0->setObjectName(QString::fromUtf8("btn_set_speed0"));
        btn_set_speed0->setGeometry(QRect(170, 20, 81, 23));
        btn_mode_pidt_load_params = new QPushButton(Mode_pidt_ta);
        btn_mode_pidt_load_params->setObjectName(QString::fromUtf8("btn_mode_pidt_load_params"));
        btn_mode_pidt_load_params->setGeometry(QRect(130, 10, 101, 23));
        groupBox_3 = new QGroupBox(Mode_pidt_ta);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 40, 621, 111));
        sb_w0_kp = new QDoubleSpinBox(groupBox_3);
        sb_w0_kp->setObjectName(QString::fromUtf8("sb_w0_kp"));
        sb_w0_kp->setGeometry(QRect(30, 20, 371, 22));
        sb_w0_kp->setSingleStep(0.100000000000000);
        label_41 = new QLabel(groupBox_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 20, 21, 16));
        label_56 = new QLabel(groupBox_3);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(10, 50, 21, 16));
        sb_w0_ki = new QDoubleSpinBox(groupBox_3);
        sb_w0_ki->setObjectName(QString::fromUtf8("sb_w0_ki"));
        sb_w0_ki->setGeometry(QRect(30, 50, 371, 22));
        sb_w0_ki->setSingleStep(0.100000000000000);
        label_57 = new QLabel(groupBox_3);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(10, 80, 21, 16));
        sb_w0_kd = new QDoubleSpinBox(groupBox_3);
        sb_w0_kd->setObjectName(QString::fromUtf8("sb_w0_kd"));
        sb_w0_kd->setGeometry(QRect(30, 80, 371, 22));
        sb_w0_kd->setSingleStep(0.100000000000000);
        label_58 = new QLabel(groupBox_3);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(410, 20, 31, 16));
        sb_step_w0_kp = new QDoubleSpinBox(groupBox_3);
        sb_step_w0_kp->setObjectName(QString::fromUtf8("sb_step_w0_kp"));
        sb_step_w0_kp->setGeometry(QRect(450, 20, 101, 22));
        sb_step_w0_kp->setSingleStep(0.100000000000000);
        sb_step_w0_kp->setValue(0.100000000000000);
        label_59 = new QLabel(groupBox_3);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(410, 50, 31, 16));
        sb_step_w0_ki = new QDoubleSpinBox(groupBox_3);
        sb_step_w0_ki->setObjectName(QString::fromUtf8("sb_step_w0_ki"));
        sb_step_w0_ki->setGeometry(QRect(450, 50, 101, 22));
        sb_step_w0_ki->setSingleStep(0.100000000000000);
        sb_step_w0_ki->setValue(0.100000000000000);
        label_60 = new QLabel(groupBox_3);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(410, 80, 31, 16));
        sb_step_w0_kd = new QDoubleSpinBox(groupBox_3);
        sb_step_w0_kd->setObjectName(QString::fromUtf8("sb_step_w0_kd"));
        sb_step_w0_kd->setGeometry(QRect(450, 80, 101, 22));
        sb_step_w0_kd->setSingleStep(0.100000000000000);
        sb_step_w0_kd->setValue(0.100000000000000);
        btn_mode_pidt_write_params_pid_whe0 = new QPushButton(groupBox_3);
        btn_mode_pidt_write_params_pid_whe0->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params_pid_whe0"));
        btn_mode_pidt_write_params_pid_whe0->setGeometry(QRect(560, 20, 51, 81));
        btn_mode_pidt_write_params = new QPushButton(Mode_pidt_ta);
        btn_mode_pidt_write_params->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params"));
        btn_mode_pidt_write_params->setGeometry(QRect(250, 10, 101, 23));
        groupBox_4 = new QGroupBox(Mode_pidt_ta);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(430, 390, 201, 111));
        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(20, 30, 31, 16));
        txtb_pidt_vx = new QLineEdit(groupBox_4);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(50, 30, 71, 20));
        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(20, 70, 31, 16));
        txtb_pidt_w = new QLineEdit(groupBox_4);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(50, 70, 71, 20));
        btn_control_enable = new QPushButton(groupBox_4);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(130, 30, 61, 61));
        groupBox_10 = new QGroupBox(Mode_pidt_ta);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 450, 411, 51));
        txtb_motor1_speed = new QLineEdit(groupBox_10);
        txtb_motor1_speed->setObjectName(QString::fromUtf8("txtb_motor1_speed"));
        txtb_motor1_speed->setGeometry(QRect(90, 20, 71, 20));
        label_30 = new QLabel(groupBox_10);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 20, 81, 16));
        label_31 = new QLabel(groupBox_10);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(260, 20, 71, 20));
        txtb_enc1_ta_speed = new QLineEdit(groupBox_10);
        txtb_enc1_ta_speed->setObjectName(QString::fromUtf8("txtb_enc1_ta_speed"));
        txtb_enc1_ta_speed->setGeometry(QRect(320, 20, 81, 20));
        btn_set_speed1 = new QPushButton(groupBox_10);
        btn_set_speed1->setObjectName(QString::fromUtf8("btn_set_speed1"));
        btn_set_speed1->setGeometry(QRect(170, 20, 81, 23));

        retranslateUi(Mode_pidt_ta);

        QMetaObject::connectSlotsByName(Mode_pidt_ta);
    } // setupUi

    void retranslateUi(QWidget *Mode_pidt_ta)
    {
        Mode_pidt_ta->setWindowTitle(QApplication::translate("Mode_pidt_ta", "Form", nullptr));
        btn_mode_pidt_save_params->setText(QApplication::translate("Mode_pidt_ta", "Save", nullptr));
        groupBox_5->setTitle(QApplication::translate("Mode_pidt_ta", "Wheel 1 Control", nullptr));
        label_43->setText(QApplication::translate("Mode_pidt_ta", "KP:", nullptr));
        label_69->setText(QApplication::translate("Mode_pidt_ta", "KI:", nullptr));
        label_70->setText(QApplication::translate("Mode_pidt_ta", "KD:", nullptr));
        label_71->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        label_72->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        label_73->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        btn_mode_pidt_write_params_pid_whe1->setText(QApplication::translate("Mode_pidt_ta", "Write", nullptr));
        btn_change_mode_pidt->setText(QApplication::translate("Mode_pidt_ta", "Mode PIDT", nullptr));
        groupBox_2->setTitle(QApplication::translate("Mode_pidt_ta", "Sync Control", nullptr));
        label_40->setText(QApplication::translate("Mode_pidt_ta", "KP:", nullptr));
        label_49->setText(QApplication::translate("Mode_pidt_ta", "KI:", nullptr));
        label_50->setText(QApplication::translate("Mode_pidt_ta", "KD:", nullptr));
        label_51->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        label_52->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        label_53->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        btn_mode_pidt_write_params_pid_sync->setText(QApplication::translate("Mode_pidt_ta", "Write", nullptr));
        groupBox_14->setTitle(QApplication::translate("Mode_pidt_ta", "Motor 0:", nullptr));
        txtb_motor0_speed->setText(QApplication::translate("Mode_pidt_ta", "0", nullptr));
        label_32->setText(QApplication::translate("Mode_pidt_ta", "Desired speed:", nullptr));
        label_33->setText(QApplication::translate("Mode_pidt_ta", "Enc speed:", nullptr));
        btn_set_speed0->setText(QApplication::translate("Mode_pidt_ta", "Set speed", nullptr));
        btn_mode_pidt_load_params->setText(QApplication::translate("Mode_pidt_ta", "Load", nullptr));
        groupBox_3->setTitle(QApplication::translate("Mode_pidt_ta", "Wheel 0 Control", nullptr));
        label_41->setText(QApplication::translate("Mode_pidt_ta", "KP:", nullptr));
        label_56->setText(QApplication::translate("Mode_pidt_ta", "KI:", nullptr));
        label_57->setText(QApplication::translate("Mode_pidt_ta", "KD:", nullptr));
        label_58->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        label_59->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        label_60->setText(QApplication::translate("Mode_pidt_ta", "Step:", nullptr));
        btn_mode_pidt_write_params_pid_whe0->setText(QApplication::translate("Mode_pidt_ta", "Write", nullptr));
        btn_mode_pidt_write_params->setText(QApplication::translate("Mode_pidt_ta", "Write", nullptr));
        groupBox_4->setTitle(QApplication::translate("Mode_pidt_ta", "Control", nullptr));
        label_34->setText(QApplication::translate("Mode_pidt_ta", "VX:", nullptr));
        txtb_pidt_vx->setText(QApplication::translate("Mode_pidt_ta", "0", nullptr));
        label_35->setText(QApplication::translate("Mode_pidt_ta", "W:", nullptr));
        txtb_pidt_w->setText(QApplication::translate("Mode_pidt_ta", "0", nullptr));
        btn_control_enable->setText(QApplication::translate("Mode_pidt_ta", "Disabled", nullptr));
        groupBox_10->setTitle(QApplication::translate("Mode_pidt_ta", "Motor 1:", nullptr));
        txtb_motor1_speed->setText(QApplication::translate("Mode_pidt_ta", "0", nullptr));
        label_30->setText(QApplication::translate("Mode_pidt_ta", "Desired speed:", nullptr));
        label_31->setText(QApplication::translate("Mode_pidt_ta", "Enc speed:", nullptr));
        btn_set_speed1->setText(QApplication::translate("Mode_pidt_ta", "Set speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_pidt_ta: public Ui_Mode_pidt_ta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_PIDT_TA_H
