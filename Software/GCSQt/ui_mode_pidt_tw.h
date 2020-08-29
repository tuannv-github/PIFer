/********************************************************************************
** Form generated from reading UI file 'mode_pidt_tw.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_PIDT_TW_H
#define UI_MODE_PIDT_TW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_pidt_tw
{
public:
    QPushButton *btn_change_mode_pidt;
    QGroupBox *groupBox_13;
    QDoubleSpinBox *sb_pid_vel_kp;
    QLabel *label_55;
    QLabel *label_80;
    QDoubleSpinBox *sb_pid_vel_ki;
    QLabel *label_81;
    QDoubleSpinBox *sb_pid_vel_kd;
    QLabel *label_82;
    QDoubleSpinBox *sb_pid_vel_kp_step;
    QLabel *label_83;
    QDoubleSpinBox *sb_pid_vel_ki_step;
    QLabel *label_84;
    QDoubleSpinBox *sb_pid_vel_kd_step;
    QPushButton *btn_mode_pidt_write_params_pidt_vel;
    QGroupBox *groupBox_17;
    QDoubleSpinBox *sb_pid_tilt_kp;
    QLabel *label_85;
    QLabel *label_86;
    QDoubleSpinBox *sb_pid_tilt_ki;
    QLabel *label_87;
    QDoubleSpinBox *sb_pid_tilt_kd;
    QLabel *label_88;
    QDoubleSpinBox *sb_pid_tilt_kp_step;
    QLabel *label_89;
    QDoubleSpinBox *sb_pid_tilt_ki_step;
    QLabel *label_90;
    QDoubleSpinBox *sb_pid_tilt_kd_step;
    QPushButton *btn_mode_pidt_write_params_pidt_tilt;
    QComboBox *cb_vel_pos_pidt;
    QGroupBox *groupBox_18;
    QDoubleSpinBox *sb_pid_pos_kp;
    QLabel *label_91;
    QLabel *label_92;
    QDoubleSpinBox *sb_pid_pos_ki;
    QLabel *label_93;
    QDoubleSpinBox *sb_pid_pos_kd;
    QLabel *label_94;
    QDoubleSpinBox *sb_pid_pos_kp_step;
    QLabel *label_95;
    QDoubleSpinBox *sb_pid_pos_ki_step;
    QLabel *label_96;
    QDoubleSpinBox *sb_pid_pos_kd_step;
    QPushButton *btn_mode_pidt_write_params_pidt_pos;
    QPushButton *btn_mode_pidt_save_params;
    QPushButton *btn_mode_pidt_load_params;
    QPushButton *btn_mode_pidt_write_params;
    QGroupBox *groupBox_4;
    QLabel *label_34;
    QLineEdit *txtb_pidt_vx;
    QLabel *label_35;
    QLineEdit *txtb_pidt_w;
    QPushButton *btn_control_enable;

    void setupUi(QWidget *Mode_pidt_tw)
    {
        if (Mode_pidt_tw->objectName().isEmpty())
            Mode_pidt_tw->setObjectName(QString::fromUtf8("Mode_pidt_tw"));
        Mode_pidt_tw->resize(641, 472);
        btn_change_mode_pidt = new QPushButton(Mode_pidt_tw);
        btn_change_mode_pidt->setObjectName(QString::fromUtf8("btn_change_mode_pidt"));
        btn_change_mode_pidt->setGeometry(QRect(10, 10, 101, 23));
        groupBox_13 = new QGroupBox(Mode_pidt_tw);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 160, 621, 111));
        sb_pid_vel_kp = new QDoubleSpinBox(groupBox_13);
        sb_pid_vel_kp->setObjectName(QString::fromUtf8("sb_pid_vel_kp"));
        sb_pid_vel_kp->setGeometry(QRect(30, 20, 371, 22));
        sb_pid_vel_kp->setDecimals(5);
        sb_pid_vel_kp->setMinimum(-100.000000000000000);
        sb_pid_vel_kp->setMaximum(100.000000000000000);
        sb_pid_vel_kp->setSingleStep(0.100000000000000);
        label_55 = new QLabel(groupBox_13);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(10, 20, 21, 16));
        label_80 = new QLabel(groupBox_13);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        label_80->setGeometry(QRect(10, 50, 21, 16));
        sb_pid_vel_ki = new QDoubleSpinBox(groupBox_13);
        sb_pid_vel_ki->setObjectName(QString::fromUtf8("sb_pid_vel_ki"));
        sb_pid_vel_ki->setGeometry(QRect(30, 50, 371, 22));
        sb_pid_vel_ki->setDecimals(5);
        sb_pid_vel_ki->setMinimum(-100.000000000000000);
        sb_pid_vel_ki->setMaximum(100.000000000000000);
        sb_pid_vel_ki->setSingleStep(0.100000000000000);
        label_81 = new QLabel(groupBox_13);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setGeometry(QRect(10, 80, 21, 16));
        sb_pid_vel_kd = new QDoubleSpinBox(groupBox_13);
        sb_pid_vel_kd->setObjectName(QString::fromUtf8("sb_pid_vel_kd"));
        sb_pid_vel_kd->setGeometry(QRect(30, 80, 371, 22));
        sb_pid_vel_kd->setDecimals(5);
        sb_pid_vel_kd->setMinimum(-100.000000000000000);
        sb_pid_vel_kd->setMaximum(100.000000000000000);
        sb_pid_vel_kd->setSingleStep(0.100000000000000);
        label_82 = new QLabel(groupBox_13);
        label_82->setObjectName(QString::fromUtf8("label_82"));
        label_82->setGeometry(QRect(410, 20, 31, 16));
        sb_pid_vel_kp_step = new QDoubleSpinBox(groupBox_13);
        sb_pid_vel_kp_step->setObjectName(QString::fromUtf8("sb_pid_vel_kp_step"));
        sb_pid_vel_kp_step->setGeometry(QRect(450, 20, 101, 22));
        sb_pid_vel_kp_step->setSingleStep(0.100000000000000);
        sb_pid_vel_kp_step->setValue(0.100000000000000);
        label_83 = new QLabel(groupBox_13);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        label_83->setGeometry(QRect(410, 50, 31, 16));
        sb_pid_vel_ki_step = new QDoubleSpinBox(groupBox_13);
        sb_pid_vel_ki_step->setObjectName(QString::fromUtf8("sb_pid_vel_ki_step"));
        sb_pid_vel_ki_step->setGeometry(QRect(450, 50, 101, 22));
        sb_pid_vel_ki_step->setSingleStep(0.100000000000000);
        sb_pid_vel_ki_step->setValue(0.100000000000000);
        label_84 = new QLabel(groupBox_13);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setGeometry(QRect(410, 80, 31, 16));
        sb_pid_vel_kd_step = new QDoubleSpinBox(groupBox_13);
        sb_pid_vel_kd_step->setObjectName(QString::fromUtf8("sb_pid_vel_kd_step"));
        sb_pid_vel_kd_step->setGeometry(QRect(450, 80, 101, 22));
        sb_pid_vel_kd_step->setSingleStep(0.100000000000000);
        sb_pid_vel_kd_step->setValue(0.100000000000000);
        btn_mode_pidt_write_params_pidt_vel = new QPushButton(groupBox_13);
        btn_mode_pidt_write_params_pidt_vel->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params_pidt_vel"));
        btn_mode_pidt_write_params_pidt_vel->setGeometry(QRect(560, 20, 51, 81));
        groupBox_17 = new QGroupBox(Mode_pidt_tw);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(10, 40, 621, 111));
        sb_pid_tilt_kp = new QDoubleSpinBox(groupBox_17);
        sb_pid_tilt_kp->setObjectName(QString::fromUtf8("sb_pid_tilt_kp"));
        sb_pid_tilt_kp->setGeometry(QRect(30, 20, 371, 22));
        sb_pid_tilt_kp->setMinimum(-1000.000000000000000);
        sb_pid_tilt_kp->setMaximum(1000.000000000000000);
        sb_pid_tilt_kp->setSingleStep(0.100000000000000);
        sb_pid_tilt_kp->setValue(0.000000000000000);
        label_85 = new QLabel(groupBox_17);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        label_85->setGeometry(QRect(10, 20, 21, 16));
        label_86 = new QLabel(groupBox_17);
        label_86->setObjectName(QString::fromUtf8("label_86"));
        label_86->setGeometry(QRect(10, 50, 21, 16));
        sb_pid_tilt_ki = new QDoubleSpinBox(groupBox_17);
        sb_pid_tilt_ki->setObjectName(QString::fromUtf8("sb_pid_tilt_ki"));
        sb_pid_tilt_ki->setGeometry(QRect(30, 50, 371, 22));
        sb_pid_tilt_ki->setMinimum(-1000.000000000000000);
        sb_pid_tilt_ki->setSingleStep(0.100000000000000);
        sb_pid_tilt_ki->setValue(0.000000000000000);
        label_87 = new QLabel(groupBox_17);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        label_87->setGeometry(QRect(10, 80, 21, 16));
        sb_pid_tilt_kd = new QDoubleSpinBox(groupBox_17);
        sb_pid_tilt_kd->setObjectName(QString::fromUtf8("sb_pid_tilt_kd"));
        sb_pid_tilt_kd->setGeometry(QRect(30, 80, 371, 22));
        sb_pid_tilt_kd->setMinimum(-1000.000000000000000);
        sb_pid_tilt_kd->setMaximum(1000.000000000000000);
        sb_pid_tilt_kd->setSingleStep(0.100000000000000);
        label_88 = new QLabel(groupBox_17);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        label_88->setGeometry(QRect(410, 20, 31, 16));
        sb_pid_tilt_kp_step = new QDoubleSpinBox(groupBox_17);
        sb_pid_tilt_kp_step->setObjectName(QString::fromUtf8("sb_pid_tilt_kp_step"));
        sb_pid_tilt_kp_step->setGeometry(QRect(450, 20, 101, 22));
        sb_pid_tilt_kp_step->setSingleStep(0.100000000000000);
        sb_pid_tilt_kp_step->setValue(0.100000000000000);
        label_89 = new QLabel(groupBox_17);
        label_89->setObjectName(QString::fromUtf8("label_89"));
        label_89->setGeometry(QRect(410, 50, 31, 16));
        sb_pid_tilt_ki_step = new QDoubleSpinBox(groupBox_17);
        sb_pid_tilt_ki_step->setObjectName(QString::fromUtf8("sb_pid_tilt_ki_step"));
        sb_pid_tilt_ki_step->setGeometry(QRect(450, 50, 101, 22));
        sb_pid_tilt_ki_step->setSingleStep(0.100000000000000);
        sb_pid_tilt_ki_step->setValue(0.100000000000000);
        label_90 = new QLabel(groupBox_17);
        label_90->setObjectName(QString::fromUtf8("label_90"));
        label_90->setGeometry(QRect(410, 80, 31, 16));
        sb_pid_tilt_kd_step = new QDoubleSpinBox(groupBox_17);
        sb_pid_tilt_kd_step->setObjectName(QString::fromUtf8("sb_pid_tilt_kd_step"));
        sb_pid_tilt_kd_step->setGeometry(QRect(450, 80, 101, 22));
        sb_pid_tilt_kd_step->setSingleStep(0.100000000000000);
        sb_pid_tilt_kd_step->setValue(0.100000000000000);
        btn_mode_pidt_write_params_pidt_tilt = new QPushButton(groupBox_17);
        btn_mode_pidt_write_params_pidt_tilt->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params_pidt_tilt"));
        btn_mode_pidt_write_params_pidt_tilt->setGeometry(QRect(560, 20, 51, 81));
        cb_vel_pos_pidt = new QComboBox(Mode_pidt_tw);
        cb_vel_pos_pidt->addItem(QString());
        cb_vel_pos_pidt->addItem(QString());
        cb_vel_pos_pidt->setObjectName(QString::fromUtf8("cb_vel_pos_pidt"));
        cb_vel_pos_pidt->setGeometry(QRect(490, 10, 131, 22));
        groupBox_18 = new QGroupBox(Mode_pidt_tw);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(10, 280, 621, 111));
        sb_pid_pos_kp = new QDoubleSpinBox(groupBox_18);
        sb_pid_pos_kp->setObjectName(QString::fromUtf8("sb_pid_pos_kp"));
        sb_pid_pos_kp->setGeometry(QRect(30, 20, 371, 22));
        sb_pid_pos_kp->setSingleStep(0.100000000000000);
        label_91 = new QLabel(groupBox_18);
        label_91->setObjectName(QString::fromUtf8("label_91"));
        label_91->setGeometry(QRect(10, 20, 21, 16));
        label_92 = new QLabel(groupBox_18);
        label_92->setObjectName(QString::fromUtf8("label_92"));
        label_92->setGeometry(QRect(10, 50, 21, 16));
        sb_pid_pos_ki = new QDoubleSpinBox(groupBox_18);
        sb_pid_pos_ki->setObjectName(QString::fromUtf8("sb_pid_pos_ki"));
        sb_pid_pos_ki->setGeometry(QRect(30, 50, 371, 22));
        sb_pid_pos_ki->setSingleStep(0.100000000000000);
        label_93 = new QLabel(groupBox_18);
        label_93->setObjectName(QString::fromUtf8("label_93"));
        label_93->setGeometry(QRect(10, 80, 21, 16));
        sb_pid_pos_kd = new QDoubleSpinBox(groupBox_18);
        sb_pid_pos_kd->setObjectName(QString::fromUtf8("sb_pid_pos_kd"));
        sb_pid_pos_kd->setGeometry(QRect(30, 80, 371, 22));
        sb_pid_pos_kd->setSingleStep(0.100000000000000);
        label_94 = new QLabel(groupBox_18);
        label_94->setObjectName(QString::fromUtf8("label_94"));
        label_94->setGeometry(QRect(410, 20, 31, 16));
        sb_pid_pos_kp_step = new QDoubleSpinBox(groupBox_18);
        sb_pid_pos_kp_step->setObjectName(QString::fromUtf8("sb_pid_pos_kp_step"));
        sb_pid_pos_kp_step->setGeometry(QRect(450, 20, 101, 22));
        sb_pid_pos_kp_step->setSingleStep(0.100000000000000);
        sb_pid_pos_kp_step->setValue(0.100000000000000);
        label_95 = new QLabel(groupBox_18);
        label_95->setObjectName(QString::fromUtf8("label_95"));
        label_95->setGeometry(QRect(410, 50, 31, 16));
        sb_pid_pos_ki_step = new QDoubleSpinBox(groupBox_18);
        sb_pid_pos_ki_step->setObjectName(QString::fromUtf8("sb_pid_pos_ki_step"));
        sb_pid_pos_ki_step->setGeometry(QRect(450, 50, 101, 22));
        sb_pid_pos_ki_step->setSingleStep(0.100000000000000);
        sb_pid_pos_ki_step->setValue(0.100000000000000);
        label_96 = new QLabel(groupBox_18);
        label_96->setObjectName(QString::fromUtf8("label_96"));
        label_96->setGeometry(QRect(410, 80, 31, 16));
        sb_pid_pos_kd_step = new QDoubleSpinBox(groupBox_18);
        sb_pid_pos_kd_step->setObjectName(QString::fromUtf8("sb_pid_pos_kd_step"));
        sb_pid_pos_kd_step->setGeometry(QRect(450, 80, 101, 22));
        sb_pid_pos_kd_step->setSingleStep(0.100000000000000);
        sb_pid_pos_kd_step->setValue(0.100000000000000);
        btn_mode_pidt_write_params_pidt_pos = new QPushButton(groupBox_18);
        btn_mode_pidt_write_params_pidt_pos->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params_pidt_pos"));
        btn_mode_pidt_write_params_pidt_pos->setGeometry(QRect(560, 20, 51, 81));
        btn_mode_pidt_save_params = new QPushButton(Mode_pidt_tw);
        btn_mode_pidt_save_params->setObjectName(QString::fromUtf8("btn_mode_pidt_save_params"));
        btn_mode_pidt_save_params->setGeometry(QRect(370, 10, 101, 23));
        btn_mode_pidt_load_params = new QPushButton(Mode_pidt_tw);
        btn_mode_pidt_load_params->setObjectName(QString::fromUtf8("btn_mode_pidt_load_params"));
        btn_mode_pidt_load_params->setGeometry(QRect(130, 10, 101, 23));
        btn_mode_pidt_write_params = new QPushButton(Mode_pidt_tw);
        btn_mode_pidt_write_params->setObjectName(QString::fromUtf8("btn_mode_pidt_write_params"));
        btn_mode_pidt_write_params->setGeometry(QRect(250, 10, 101, 23));
        groupBox_4 = new QGroupBox(Mode_pidt_tw);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 390, 621, 81));
        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 20, 21, 16));
        txtb_pidt_vx = new QLineEdit(groupBox_4);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(30, 20, 511, 20));
        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(10, 50, 21, 16));
        txtb_pidt_w = new QLineEdit(groupBox_4);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(30, 50, 511, 20));
        btn_control_enable = new QPushButton(groupBox_4);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(550, 20, 61, 51));

        retranslateUi(Mode_pidt_tw);

        QMetaObject::connectSlotsByName(Mode_pidt_tw);
    } // setupUi

    void retranslateUi(QWidget *Mode_pidt_tw)
    {
        Mode_pidt_tw->setWindowTitle(QApplication::translate("Mode_pidt_tw", "Form", nullptr));
        btn_change_mode_pidt->setText(QApplication::translate("Mode_pidt_tw", "Mode PIDT", nullptr));
        groupBox_13->setTitle(QApplication::translate("Mode_pidt_tw", "Velocity Control", nullptr));
        label_55->setText(QApplication::translate("Mode_pidt_tw", "KP:", nullptr));
        label_80->setText(QApplication::translate("Mode_pidt_tw", "KI:", nullptr));
        label_81->setText(QApplication::translate("Mode_pidt_tw", "KD:", nullptr));
        label_82->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        label_83->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        label_84->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        btn_mode_pidt_write_params_pidt_vel->setText(QApplication::translate("Mode_pidt_tw", "Write", nullptr));
        groupBox_17->setTitle(QApplication::translate("Mode_pidt_tw", "Tilt Control", nullptr));
        label_85->setText(QApplication::translate("Mode_pidt_tw", "KP:", nullptr));
        label_86->setText(QApplication::translate("Mode_pidt_tw", "KI:", nullptr));
        label_87->setText(QApplication::translate("Mode_pidt_tw", "KD:", nullptr));
        label_88->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        label_89->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        label_90->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        btn_mode_pidt_write_params_pidt_tilt->setText(QApplication::translate("Mode_pidt_tw", "Write", nullptr));
        cb_vel_pos_pidt->setItemText(0, QApplication::translate("Mode_pidt_tw", "Velocity Control", nullptr));
        cb_vel_pos_pidt->setItemText(1, QApplication::translate("Mode_pidt_tw", "Position Control", nullptr));

        groupBox_18->setTitle(QApplication::translate("Mode_pidt_tw", "Position Control", nullptr));
        label_91->setText(QApplication::translate("Mode_pidt_tw", "KP:", nullptr));
        label_92->setText(QApplication::translate("Mode_pidt_tw", "KI:", nullptr));
        label_93->setText(QApplication::translate("Mode_pidt_tw", "KD:", nullptr));
        label_94->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        label_95->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        label_96->setText(QApplication::translate("Mode_pidt_tw", "Step:", nullptr));
        btn_mode_pidt_write_params_pidt_pos->setText(QApplication::translate("Mode_pidt_tw", "Write", nullptr));
        btn_mode_pidt_save_params->setText(QApplication::translate("Mode_pidt_tw", "Save", nullptr));
        btn_mode_pidt_load_params->setText(QApplication::translate("Mode_pidt_tw", "Load", nullptr));
        btn_mode_pidt_write_params->setText(QApplication::translate("Mode_pidt_tw", "Write", nullptr));
        groupBox_4->setTitle(QApplication::translate("Mode_pidt_tw", "Control", nullptr));
        label_34->setText(QApplication::translate("Mode_pidt_tw", "VX:", nullptr));
        txtb_pidt_vx->setText(QApplication::translate("Mode_pidt_tw", "0", nullptr));
        label_35->setText(QApplication::translate("Mode_pidt_tw", "W:", nullptr));
        txtb_pidt_w->setText(QApplication::translate("Mode_pidt_tw", "0", nullptr));
        btn_control_enable->setText(QApplication::translate("Mode_pidt_tw", "Disabled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_pidt_tw: public Ui_Mode_pidt_tw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_PIDT_TW_H
