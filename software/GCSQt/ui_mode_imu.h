/********************************************************************************
** Form generated from reading UI file 'mode_imu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_IMU_H
#define UI_MODE_IMU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_imu
{
public:
    QGroupBox *groupBox_7;
    QLineEdit *tb_my;
    QLineEdit *tb_mx;
    QLineEdit *tb_mz;
    QLabel *label_28;
    QLineEdit *tb_ay;
    QLineEdit *tb_ax;
    QLineEdit *tb_az;
    QLabel *label_37;
    QLineEdit *tb_gx;
    QLineEdit *tb_gz;
    QLabel *label_13;
    QLineEdit *tb_gy;
    QPushButton *btn_change_mode_imu;
    QGroupBox *groupBox_6;
    QLineEdit *tb_gbelieve;
    QLineEdit *tb_my_scale;
    QLabel *label_27;
    QLabel *label_46;
    QLabel *label_39;
    QLineEdit *tb_mz_scale;
    QLineEdit *tb_gx_bias;
    QLineEdit *tb_my_bias;
    QLineEdit *tb_mz_bias;
    QLineEdit *tb_angle_adjust;
    QLineEdit *tb_mx_bias;
    QLabel *label_22;
    QLineEdit *tb_gy_bias;
    QLineEdit *tb_gz_bias;
    QLineEdit *tb_mx_scale;
    QLabel *label_26;
    QComboBox *cb_tilt;
    QLabel *label_52;
    QLineEdit *tb_ay_bias;
    QLabel *label_33;
    QLineEdit *tb_ax_bias;
    QLineEdit *tb_az_bias;
    QLineEdit *tb_madgwick_beta;
    QLabel *label_32;
    QPushButton *btn_mode_imu_load_params;
    QPushButton *btn_mode_imu_write_params;
    QPushButton *btn_mode_imu_save_params;
    QGroupBox *groupBox;
    QLineEdit *tb_cab_mz;
    QLineEdit *tb_cab_my;
    QLineEdit *tb_cab_mx;
    QLineEdit *tb_cab_az;
    QLineEdit *tb_cab_ay;
    QLineEdit *tb_cab_ax;
    QLabel *label_40;
    QLabel *label_29;
    QLineEdit *tb_cab_gz;
    QLineEdit *tb_cab_gx;
    QLabel *label_14;
    QLineEdit *tb_cab_gy;
    QPushButton *btn_tilt_calib;
    QPushButton *btn_gyro_calib_2;
    QPushButton *btn_gyro_calib_3;
    QPushButton *btn_gyro_calib;
    QGroupBox *groupBox_2;
    QLabel *label_25;
    QLineEdit *txtb_tilt_0;
    QLineEdit *tb_yaw;
    QLineEdit *tb_pitch;
    QLineEdit *tb_roll;
    QLabel *label_31;

    void setupUi(QWidget *Mode_imu)
    {
        if (Mode_imu->objectName().isEmpty())
            Mode_imu->setObjectName(QString::fromUtf8("Mode_imu"));
        Mode_imu->resize(641, 483);
        groupBox_7 = new QGroupBox(Mode_imu);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 70, 291, 111));
        tb_my = new QLineEdit(groupBox_7);
        tb_my->setObjectName(QString::fromUtf8("tb_my"));
        tb_my->setGeometry(QRect(130, 80, 71, 20));
        tb_mx = new QLineEdit(groupBox_7);
        tb_mx->setObjectName(QString::fromUtf8("tb_mx"));
        tb_mx->setGeometry(QRect(50, 80, 71, 20));
        tb_mz = new QLineEdit(groupBox_7);
        tb_mz->setObjectName(QString::fromUtf8("tb_mz"));
        tb_mz->setGeometry(QRect(210, 80, 71, 20));
        label_28 = new QLabel(groupBox_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 80, 31, 16));
        tb_ay = new QLineEdit(groupBox_7);
        tb_ay->setObjectName(QString::fromUtf8("tb_ay"));
        tb_ay->setGeometry(QRect(130, 50, 71, 20));
        tb_ax = new QLineEdit(groupBox_7);
        tb_ax->setObjectName(QString::fromUtf8("tb_ax"));
        tb_ax->setGeometry(QRect(50, 50, 71, 20));
        tb_az = new QLineEdit(groupBox_7);
        tb_az->setObjectName(QString::fromUtf8("tb_az"));
        tb_az->setGeometry(QRect(210, 50, 71, 20));
        label_37 = new QLabel(groupBox_7);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 50, 31, 16));
        tb_gx = new QLineEdit(groupBox_7);
        tb_gx->setObjectName(QString::fromUtf8("tb_gx"));
        tb_gx->setGeometry(QRect(50, 20, 71, 20));
        tb_gz = new QLineEdit(groupBox_7);
        tb_gz->setObjectName(QString::fromUtf8("tb_gz"));
        tb_gz->setGeometry(QRect(210, 20, 71, 20));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 20, 31, 16));
        tb_gy = new QLineEdit(groupBox_7);
        tb_gy->setObjectName(QString::fromUtf8("tb_gy"));
        tb_gy->setGeometry(QRect(130, 20, 71, 20));
        btn_change_mode_imu = new QPushButton(Mode_imu);
        btn_change_mode_imu->setObjectName(QString::fromUtf8("btn_change_mode_imu"));
        btn_change_mode_imu->setGeometry(QRect(10, 10, 101, 23));
        groupBox_6 = new QGroupBox(Mode_imu);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 190, 561, 141));
        tb_gbelieve = new QLineEdit(groupBox_6);
        tb_gbelieve->setObjectName(QString::fromUtf8("tb_gbelieve"));
        tb_gbelieve->setGeometry(QRect(460, 80, 91, 20));
        tb_my_scale = new QLineEdit(groupBox_6);
        tb_my_scale->setObjectName(QString::fromUtf8("tb_my_scale"));
        tb_my_scale->setGeometry(QRect(170, 110, 91, 20));
        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(380, 80, 61, 16));
        label_46 = new QLabel(groupBox_6);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(10, 110, 61, 16));
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 80, 51, 16));
        tb_mz_scale = new QLineEdit(groupBox_6);
        tb_mz_scale->setObjectName(QString::fromUtf8("tb_mz_scale"));
        tb_mz_scale->setGeometry(QRect(270, 110, 91, 20));
        tb_gx_bias = new QLineEdit(groupBox_6);
        tb_gx_bias->setObjectName(QString::fromUtf8("tb_gx_bias"));
        tb_gx_bias->setGeometry(QRect(70, 20, 91, 20));
        tb_my_bias = new QLineEdit(groupBox_6);
        tb_my_bias->setObjectName(QString::fromUtf8("tb_my_bias"));
        tb_my_bias->setGeometry(QRect(170, 80, 91, 20));
        tb_mz_bias = new QLineEdit(groupBox_6);
        tb_mz_bias->setObjectName(QString::fromUtf8("tb_mz_bias"));
        tb_mz_bias->setGeometry(QRect(270, 80, 91, 20));
        tb_angle_adjust = new QLineEdit(groupBox_6);
        tb_angle_adjust->setObjectName(QString::fromUtf8("tb_angle_adjust"));
        tb_angle_adjust->setGeometry(QRect(460, 50, 91, 20));
        tb_mx_bias = new QLineEdit(groupBox_6);
        tb_mx_bias->setObjectName(QString::fromUtf8("tb_mx_bias"));
        tb_mx_bias->setGeometry(QRect(70, 80, 91, 20));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 20, 51, 16));
        tb_gy_bias = new QLineEdit(groupBox_6);
        tb_gy_bias->setObjectName(QString::fromUtf8("tb_gy_bias"));
        tb_gy_bias->setGeometry(QRect(170, 20, 91, 20));
        tb_gz_bias = new QLineEdit(groupBox_6);
        tb_gz_bias->setObjectName(QString::fromUtf8("tb_gz_bias"));
        tb_gz_bias->setGeometry(QRect(270, 20, 91, 20));
        tb_mx_scale = new QLineEdit(groupBox_6);
        tb_mx_scale->setObjectName(QString::fromUtf8("tb_mx_scale"));
        tb_mx_scale->setGeometry(QRect(70, 110, 91, 20));
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(380, 50, 61, 16));
        cb_tilt = new QComboBox(groupBox_6);
        cb_tilt->setObjectName(QString::fromUtf8("cb_tilt"));
        cb_tilt->setGeometry(QRect(460, 20, 91, 22));
        label_52 = new QLabel(groupBox_6);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(380, 20, 51, 16));
        tb_ay_bias = new QLineEdit(groupBox_6);
        tb_ay_bias->setObjectName(QString::fromUtf8("tb_ay_bias"));
        tb_ay_bias->setGeometry(QRect(170, 50, 91, 20));
        label_33 = new QLabel(groupBox_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 50, 51, 16));
        tb_ax_bias = new QLineEdit(groupBox_6);
        tb_ax_bias->setObjectName(QString::fromUtf8("tb_ax_bias"));
        tb_ax_bias->setGeometry(QRect(70, 50, 91, 20));
        tb_az_bias = new QLineEdit(groupBox_6);
        tb_az_bias->setObjectName(QString::fromUtf8("tb_az_bias"));
        tb_az_bias->setGeometry(QRect(270, 50, 91, 20));
        tb_madgwick_beta = new QLineEdit(groupBox_6);
        tb_madgwick_beta->setObjectName(QString::fromUtf8("tb_madgwick_beta"));
        tb_madgwick_beta->setGeometry(QRect(460, 110, 91, 20));
        label_32 = new QLabel(groupBox_6);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(380, 110, 81, 16));
        btn_mode_imu_load_params = new QPushButton(Mode_imu);
        btn_mode_imu_load_params->setObjectName(QString::fromUtf8("btn_mode_imu_load_params"));
        btn_mode_imu_load_params->setGeometry(QRect(130, 10, 101, 23));
        btn_mode_imu_write_params = new QPushButton(Mode_imu);
        btn_mode_imu_write_params->setObjectName(QString::fromUtf8("btn_mode_imu_write_params"));
        btn_mode_imu_write_params->setGeometry(QRect(250, 10, 101, 23));
        btn_mode_imu_save_params = new QPushButton(Mode_imu);
        btn_mode_imu_save_params->setObjectName(QString::fromUtf8("btn_mode_imu_save_params"));
        btn_mode_imu_save_params->setGeometry(QRect(370, 10, 101, 23));
        groupBox = new QGroupBox(Mode_imu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(310, 70, 291, 111));
        tb_cab_mz = new QLineEdit(groupBox);
        tb_cab_mz->setObjectName(QString::fromUtf8("tb_cab_mz"));
        tb_cab_mz->setGeometry(QRect(210, 80, 71, 20));
        tb_cab_my = new QLineEdit(groupBox);
        tb_cab_my->setObjectName(QString::fromUtf8("tb_cab_my"));
        tb_cab_my->setGeometry(QRect(130, 80, 71, 20));
        tb_cab_mx = new QLineEdit(groupBox);
        tb_cab_mx->setObjectName(QString::fromUtf8("tb_cab_mx"));
        tb_cab_mx->setGeometry(QRect(50, 80, 71, 20));
        tb_cab_az = new QLineEdit(groupBox);
        tb_cab_az->setObjectName(QString::fromUtf8("tb_cab_az"));
        tb_cab_az->setGeometry(QRect(210, 50, 71, 20));
        tb_cab_ay = new QLineEdit(groupBox);
        tb_cab_ay->setObjectName(QString::fromUtf8("tb_cab_ay"));
        tb_cab_ay->setGeometry(QRect(130, 50, 71, 20));
        tb_cab_ax = new QLineEdit(groupBox);
        tb_cab_ax->setObjectName(QString::fromUtf8("tb_cab_ax"));
        tb_cab_ax->setGeometry(QRect(50, 50, 71, 20));
        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(10, 50, 31, 16));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 80, 31, 16));
        tb_cab_gz = new QLineEdit(groupBox);
        tb_cab_gz->setObjectName(QString::fromUtf8("tb_cab_gz"));
        tb_cab_gz->setGeometry(QRect(210, 20, 71, 20));
        tb_cab_gx = new QLineEdit(groupBox);
        tb_cab_gx->setObjectName(QString::fromUtf8("tb_cab_gx"));
        tb_cab_gx->setGeometry(QRect(50, 20, 71, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 31, 16));
        tb_cab_gy = new QLineEdit(groupBox);
        tb_cab_gy->setObjectName(QString::fromUtf8("tb_cab_gy"));
        tb_cab_gy->setGeometry(QRect(130, 20, 71, 20));
        btn_tilt_calib = new QPushButton(Mode_imu);
        btn_tilt_calib->setObjectName(QString::fromUtf8("btn_tilt_calib"));
        btn_tilt_calib->setGeometry(QRect(370, 40, 101, 23));
        btn_gyro_calib_2 = new QPushButton(Mode_imu);
        btn_gyro_calib_2->setObjectName(QString::fromUtf8("btn_gyro_calib_2"));
        btn_gyro_calib_2->setGeometry(QRect(250, 40, 101, 23));
        btn_gyro_calib_3 = new QPushButton(Mode_imu);
        btn_gyro_calib_3->setObjectName(QString::fromUtf8("btn_gyro_calib_3"));
        btn_gyro_calib_3->setGeometry(QRect(130, 40, 101, 23));
        btn_gyro_calib = new QPushButton(Mode_imu);
        btn_gyro_calib->setObjectName(QString::fromUtf8("btn_gyro_calib"));
        btn_gyro_calib->setGeometry(QRect(10, 40, 101, 23));
        groupBox_2 = new QGroupBox(Mode_imu);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 340, 371, 80));
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 20, 51, 16));
        txtb_tilt_0 = new QLineEdit(groupBox_2);
        txtb_tilt_0->setObjectName(QString::fromUtf8("txtb_tilt_0"));
        txtb_tilt_0->setGeometry(QRect(70, 20, 91, 20));
        tb_yaw = new QLineEdit(groupBox_2);
        tb_yaw->setObjectName(QString::fromUtf8("tb_yaw"));
        tb_yaw->setGeometry(QRect(270, 50, 91, 20));
        tb_pitch = new QLineEdit(groupBox_2);
        tb_pitch->setObjectName(QString::fromUtf8("tb_pitch"));
        tb_pitch->setGeometry(QRect(170, 50, 91, 20));
        tb_roll = new QLineEdit(groupBox_2);
        tb_roll->setObjectName(QString::fromUtf8("tb_roll"));
        tb_roll->setGeometry(QRect(70, 50, 91, 20));
        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(10, 50, 21, 16));

        retranslateUi(Mode_imu);

        QMetaObject::connectSlotsByName(Mode_imu);
    } // setupUi

    void retranslateUi(QWidget *Mode_imu)
    {
        Mode_imu->setWindowTitle(QApplication::translate("Mode_imu", "Form", nullptr));
        groupBox_7->setTitle(QApplication::translate("Mode_imu", "Raw", nullptr));
        label_28->setText(QApplication::translate("Mode_imu", "Mxyz:", nullptr));
        label_37->setText(QApplication::translate("Mode_imu", "Axyz:", nullptr));
        label_13->setText(QApplication::translate("Mode_imu", "Gxyz:", nullptr));
        btn_change_mode_imu->setText(QApplication::translate("Mode_imu", "Mode IMU", nullptr));
        groupBox_6->setTitle(QApplication::translate("Mode_imu", "Parameters:", nullptr));
        label_27->setText(QApplication::translate("Mode_imu", "G believe:", nullptr));
        label_46->setText(QApplication::translate("Mode_imu", "Mxyz scale:", nullptr));
        label_39->setText(QApplication::translate("Mode_imu", "Mxyz bias:", nullptr));
        label_22->setText(QApplication::translate("Mode_imu", "Gxyz bias:", nullptr));
        label_26->setText(QApplication::translate("Mode_imu", "Tilt offset:", nullptr));
        label_52->setText(QApplication::translate("Mode_imu", "Tilt:", nullptr));
        label_33->setText(QApplication::translate("Mode_imu", "Axyz bias:", nullptr));
        label_32->setText(QApplication::translate("Mode_imu", "Madgwick beta:", nullptr));
        btn_mode_imu_load_params->setText(QApplication::translate("Mode_imu", "Load", nullptr));
        btn_mode_imu_write_params->setText(QApplication::translate("Mode_imu", "Write", nullptr));
        btn_mode_imu_save_params->setText(QApplication::translate("Mode_imu", "Save", nullptr));
        groupBox->setTitle(QApplication::translate("Mode_imu", "Calibrated", nullptr));
        label_40->setText(QApplication::translate("Mode_imu", "Axyz:", nullptr));
        label_29->setText(QApplication::translate("Mode_imu", "Mxyz:", nullptr));
        label_14->setText(QApplication::translate("Mode_imu", "Gxyz:", nullptr));
        btn_tilt_calib->setText(QApplication::translate("Mode_imu", "T Calibrate", nullptr));
        btn_gyro_calib_2->setText(QApplication::translate("Mode_imu", "M Calibrate", nullptr));
        btn_gyro_calib_3->setText(QApplication::translate("Mode_imu", "A Calibrate", nullptr));
        btn_gyro_calib->setText(QApplication::translate("Mode_imu", "G Calibrate", nullptr));
        groupBox_2->setTitle(QApplication::translate("Mode_imu", "Result", nullptr));
        label_25->setText(QApplication::translate("Mode_imu", "Tilt Angle:", nullptr));
        label_31->setText(QApplication::translate("Mode_imu", "RPY:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_imu: public Ui_Mode_imu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_IMU_H
