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
    QLabel *label_45;
    QLineEdit *tb_mz_scale;
    QLineEdit *tb_gx_offset;
    QLineEdit *tb_my_bias;
    QLineEdit *tb_mz_bias;
    QLabel *label_23;
    QLabel *label_42;
    QLineEdit *tb_angle_adjust;
    QLineEdit *tb_mx_bias;
    QLabel *label_22;
    QLineEdit *tb_gy_offset;
    QLineEdit *tb_gz_offset;
    QLabel *label_44;
    QLabel *label_38;
    QLineEdit *tb_mx_scale;
    QLabel *label_24;
    QLabel *label_26;
    QComboBox *cb_tilt;
    QLabel *label_52;
    QPushButton *btn_gyro_calib_3;
    QPushButton *btn_gyro_calib;
    QPushButton *btn_mode_imu_load_params;
    QPushButton *btn_mode_imu_write_params;
    QPushButton *btn_mode_imu_save_params;
    QGroupBox *groupBox;
    QLineEdit *tb_cab_gx;
    QLineEdit *tb_cab_gz;
    QLineEdit *tb_cab_gy;
    QLineEdit *tb_gz_offset_4;
    QLineEdit *tb_gy_offset_4;
    QLineEdit *tb_mx_3;
    QLineEdit *tb_cab_gz_2;
    QLineEdit *tb_cab_gy_2;
    QLineEdit *tb_cab_gx_2;
    QLabel *label_40;
    QLabel *label_14;
    QLabel *label_29;
    QPushButton *btn_tilt_calib;
    QPushButton *btn_gyro_calib_2;
    QLabel *label_31;
    QLineEdit *tb_roll;
    QLineEdit *tb_pitch;
    QLineEdit *tb_yaw;
    QLineEdit *txtb_tilt_0;
    QLabel *label_25;

    void setupUi(QWidget *Mode_imu)
    {
        if (Mode_imu->objectName().isEmpty())
            Mode_imu->setObjectName(QString::fromUtf8("Mode_imu"));
        Mode_imu->resize(641, 483);
        groupBox_7 = new QGroupBox(Mode_imu);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 40, 291, 111));
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
        tb_ay->setGeometry(QRect(130, 20, 71, 20));
        tb_ax = new QLineEdit(groupBox_7);
        tb_ax->setObjectName(QString::fromUtf8("tb_ax"));
        tb_ax->setGeometry(QRect(50, 20, 71, 20));
        tb_az = new QLineEdit(groupBox_7);
        tb_az->setObjectName(QString::fromUtf8("tb_az"));
        tb_az->setGeometry(QRect(210, 20, 71, 20));
        label_37 = new QLabel(groupBox_7);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 20, 31, 16));
        tb_gx = new QLineEdit(groupBox_7);
        tb_gx->setObjectName(QString::fromUtf8("tb_gx"));
        tb_gx->setGeometry(QRect(50, 50, 71, 20));
        tb_gz = new QLineEdit(groupBox_7);
        tb_gz->setObjectName(QString::fromUtf8("tb_gz"));
        tb_gz->setGeometry(QRect(210, 50, 71, 20));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 50, 31, 16));
        tb_gy = new QLineEdit(groupBox_7);
        tb_gy->setObjectName(QString::fromUtf8("tb_gy"));
        tb_gy->setGeometry(QRect(130, 50, 71, 20));
        btn_change_mode_imu = new QPushButton(Mode_imu);
        btn_change_mode_imu->setObjectName(QString::fromUtf8("btn_change_mode_imu"));
        btn_change_mode_imu->setGeometry(QRect(10, 10, 101, 23));
        groupBox_6 = new QGroupBox(Mode_imu);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 290, 621, 151));
        tb_gbelieve = new QLineEdit(groupBox_6);
        tb_gbelieve->setObjectName(QString::fromUtf8("tb_gbelieve"));
        tb_gbelieve->setGeometry(QRect(250, 120, 91, 20));
        tb_my_scale = new QLineEdit(groupBox_6);
        tb_my_scale->setObjectName(QString::fromUtf8("tb_my_scale"));
        tb_my_scale->setGeometry(QRect(250, 90, 91, 20));
        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(190, 120, 61, 16));
        label_46 = new QLabel(groupBox_6);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(10, 90, 51, 16));
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 60, 51, 16));
        label_45 = new QLabel(groupBox_6);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(370, 90, 51, 16));
        tb_mz_scale = new QLineEdit(groupBox_6);
        tb_mz_scale->setObjectName(QString::fromUtf8("tb_mz_scale"));
        tb_mz_scale->setGeometry(QRect(430, 90, 91, 20));
        tb_gx_offset = new QLineEdit(groupBox_6);
        tb_gx_offset->setObjectName(QString::fromUtf8("tb_gx_offset"));
        tb_gx_offset->setGeometry(QRect(70, 30, 91, 20));
        tb_my_bias = new QLineEdit(groupBox_6);
        tb_my_bias->setObjectName(QString::fromUtf8("tb_my_bias"));
        tb_my_bias->setGeometry(QRect(250, 60, 91, 20));
        tb_mz_bias = new QLineEdit(groupBox_6);
        tb_mz_bias->setObjectName(QString::fromUtf8("tb_mz_bias"));
        tb_mz_bias->setGeometry(QRect(430, 60, 91, 20));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(190, 30, 51, 16));
        label_42 = new QLabel(groupBox_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(370, 60, 51, 16));
        tb_angle_adjust = new QLineEdit(groupBox_6);
        tb_angle_adjust->setObjectName(QString::fromUtf8("tb_angle_adjust"));
        tb_angle_adjust->setGeometry(QRect(430, 120, 91, 20));
        tb_mx_bias = new QLineEdit(groupBox_6);
        tb_mx_bias->setObjectName(QString::fromUtf8("tb_mx_bias"));
        tb_mx_bias->setGeometry(QRect(70, 60, 91, 20));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 30, 51, 16));
        tb_gy_offset = new QLineEdit(groupBox_6);
        tb_gy_offset->setObjectName(QString::fromUtf8("tb_gy_offset"));
        tb_gy_offset->setGeometry(QRect(250, 30, 91, 20));
        tb_gz_offset = new QLineEdit(groupBox_6);
        tb_gz_offset->setObjectName(QString::fromUtf8("tb_gz_offset"));
        tb_gz_offset->setGeometry(QRect(430, 30, 91, 20));
        label_44 = new QLabel(groupBox_6);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(190, 90, 51, 16));
        label_38 = new QLabel(groupBox_6);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(190, 60, 51, 16));
        tb_mx_scale = new QLineEdit(groupBox_6);
        tb_mx_scale->setObjectName(QString::fromUtf8("tb_mx_scale"));
        tb_mx_scale->setGeometry(QRect(70, 90, 91, 20));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(370, 30, 51, 16));
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(370, 120, 61, 16));
        cb_tilt = new QComboBox(groupBox_6);
        cb_tilt->setObjectName(QString::fromUtf8("cb_tilt"));
        cb_tilt->setGeometry(QRect(70, 120, 91, 22));
        label_52 = new QLabel(groupBox_6);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(10, 120, 51, 16));
        btn_gyro_calib_3 = new QPushButton(groupBox_6);
        btn_gyro_calib_3->setObjectName(QString::fromUtf8("btn_gyro_calib_3"));
        btn_gyro_calib_3->setGeometry(QRect(530, 70, 71, 21));
        btn_gyro_calib = new QPushButton(groupBox_6);
        btn_gyro_calib->setObjectName(QString::fromUtf8("btn_gyro_calib"));
        btn_gyro_calib->setGeometry(QRect(530, 110, 71, 21));
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
        groupBox->setGeometry(QRect(310, 40, 291, 111));
        tb_cab_gx = new QLineEdit(groupBox);
        tb_cab_gx->setObjectName(QString::fromUtf8("tb_cab_gx"));
        tb_cab_gx->setGeometry(QRect(50, 50, 71, 20));
        tb_cab_gz = new QLineEdit(groupBox);
        tb_cab_gz->setObjectName(QString::fromUtf8("tb_cab_gz"));
        tb_cab_gz->setGeometry(QRect(210, 50, 71, 20));
        tb_cab_gy = new QLineEdit(groupBox);
        tb_cab_gy->setObjectName(QString::fromUtf8("tb_cab_gy"));
        tb_cab_gy->setGeometry(QRect(130, 50, 71, 20));
        tb_gz_offset_4 = new QLineEdit(groupBox);
        tb_gz_offset_4->setObjectName(QString::fromUtf8("tb_gz_offset_4"));
        tb_gz_offset_4->setGeometry(QRect(210, 80, 71, 20));
        tb_gy_offset_4 = new QLineEdit(groupBox);
        tb_gy_offset_4->setObjectName(QString::fromUtf8("tb_gy_offset_4"));
        tb_gy_offset_4->setGeometry(QRect(130, 80, 71, 20));
        tb_mx_3 = new QLineEdit(groupBox);
        tb_mx_3->setObjectName(QString::fromUtf8("tb_mx_3"));
        tb_mx_3->setGeometry(QRect(50, 80, 71, 20));
        tb_cab_gz_2 = new QLineEdit(groupBox);
        tb_cab_gz_2->setObjectName(QString::fromUtf8("tb_cab_gz_2"));
        tb_cab_gz_2->setGeometry(QRect(210, 20, 71, 20));
        tb_cab_gy_2 = new QLineEdit(groupBox);
        tb_cab_gy_2->setObjectName(QString::fromUtf8("tb_cab_gy_2"));
        tb_cab_gy_2->setGeometry(QRect(130, 20, 71, 20));
        tb_cab_gx_2 = new QLineEdit(groupBox);
        tb_cab_gx_2->setObjectName(QString::fromUtf8("tb_cab_gx_2"));
        tb_cab_gx_2->setGeometry(QRect(50, 20, 71, 20));
        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(10, 20, 31, 16));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 50, 31, 16));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 80, 31, 16));
        btn_tilt_calib = new QPushButton(Mode_imu);
        btn_tilt_calib->setObjectName(QString::fromUtf8("btn_tilt_calib"));
        btn_tilt_calib->setGeometry(QRect(410, 210, 71, 21));
        btn_gyro_calib_2 = new QPushButton(Mode_imu);
        btn_gyro_calib_2->setObjectName(QString::fromUtf8("btn_gyro_calib_2"));
        btn_gyro_calib_2->setGeometry(QRect(520, 210, 71, 21));
        label_31 = new QLabel(Mode_imu);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(150, 450, 21, 16));
        tb_roll = new QLineEdit(Mode_imu);
        tb_roll->setObjectName(QString::fromUtf8("tb_roll"));
        tb_roll->setGeometry(QRect(190, 450, 91, 20));
        tb_pitch = new QLineEdit(Mode_imu);
        tb_pitch->setObjectName(QString::fromUtf8("tb_pitch"));
        tb_pitch->setGeometry(QRect(300, 450, 91, 20));
        tb_yaw = new QLineEdit(Mode_imu);
        tb_yaw->setObjectName(QString::fromUtf8("tb_yaw"));
        tb_yaw->setGeometry(QRect(420, 450, 91, 20));
        txtb_tilt_0 = new QLineEdit(Mode_imu);
        txtb_tilt_0->setObjectName(QString::fromUtf8("txtb_tilt_0"));
        txtb_tilt_0->setGeometry(QRect(280, 230, 91, 20));
        label_25 = new QLabel(Mode_imu);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(180, 240, 51, 16));

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
        label_27->setText(QApplication::translate("Mode_imu", "G Believe:", nullptr));
        label_46->setText(QApplication::translate("Mode_imu", "Mx scale:", nullptr));
        label_39->setText(QApplication::translate("Mode_imu", "Mx offset:", nullptr));
        label_45->setText(QApplication::translate("Mode_imu", "Mx scale:", nullptr));
        label_23->setText(QApplication::translate("Mode_imu", "Gy offset:", nullptr));
        label_42->setText(QApplication::translate("Mode_imu", "Mz offset:", nullptr));
        label_22->setText(QApplication::translate("Mode_imu", "Gx offset:", nullptr));
        label_44->setText(QApplication::translate("Mode_imu", "Mx scale:", nullptr));
        label_38->setText(QApplication::translate("Mode_imu", "My offset:", nullptr));
        label_24->setText(QApplication::translate("Mode_imu", "Gz offset:", nullptr));
        label_26->setText(QApplication::translate("Mode_imu", "Tilt offset:", nullptr));
        label_52->setText(QApplication::translate("Mode_imu", "Tilt:", nullptr));
        btn_gyro_calib_3->setText(QApplication::translate("Mode_imu", "A Calibrate", nullptr));
        btn_gyro_calib->setText(QApplication::translate("Mode_imu", "G Calibrate", nullptr));
        btn_mode_imu_load_params->setText(QApplication::translate("Mode_imu", "Load", nullptr));
        btn_mode_imu_write_params->setText(QApplication::translate("Mode_imu", "Write", nullptr));
        btn_mode_imu_save_params->setText(QApplication::translate("Mode_imu", "Save", nullptr));
        groupBox->setTitle(QApplication::translate("Mode_imu", "Calibrated", nullptr));
        label_40->setText(QApplication::translate("Mode_imu", "Axyz:", nullptr));
        label_14->setText(QApplication::translate("Mode_imu", "Gxyz:", nullptr));
        label_29->setText(QApplication::translate("Mode_imu", "Mxyz:", nullptr));
        btn_tilt_calib->setText(QApplication::translate("Mode_imu", "T Calibrate", nullptr));
        btn_gyro_calib_2->setText(QApplication::translate("Mode_imu", "M Calibrate", nullptr));
        label_31->setText(QApplication::translate("Mode_imu", "RPY:", nullptr));
        label_25->setText(QApplication::translate("Mode_imu", "Tilt Angle:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_imu: public Ui_Mode_imu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_IMU_H
