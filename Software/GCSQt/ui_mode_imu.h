/********************************************************************************
** Form generated from reading UI file 'mode_imu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_IMU_H
#define UI_MODE_IMU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *tb_mx;
    QLineEdit *tb_mz;
    QLabel *label_28;
    QLineEdit *tb_ay;
    QLabel *label_29;
    QLabel *label_36;
    QLineEdit *tb_ax;
    QLineEdit *tb_az;
    QLabel *label_37;
    QPushButton *btn_gyro_calib_2;
    QPushButton *btn_gyro_calib_3;
    QPushButton *btn_gyro_calib;
    QLineEdit *tb_gx;
    QLineEdit *tb_gz;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_15;
    QLineEdit *tb_gy;
    QLineEdit *tb_roll;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *tb_pitch;
    QLineEdit *tb_yaw;
    QLabel *label_32;
    QPushButton *btn_change_mode_imu;
    QGroupBox *groupBox_6;
    QLineEdit *tb_gbelieve;
    QLineEdit *tb_gy_offset_3;
    QLabel *label_27;
    QLabel *label_46;
    QLabel *label_39;
    QLabel *label_45;
    QLineEdit *tb_gz_offset_3;
    QLineEdit *tb_gx_offset;
    QLineEdit *tb_gy_offset_2;
    QLineEdit *tb_gz_offset_2;
    QLabel *label_23;
    QLabel *label_42;
    QLabel *label_25;
    QLineEdit *tb_angle_adjust;
    QLineEdit *tb_gx_offset_2;
    QLabel *label_22;
    QLineEdit *txtb_tilt_0;
    QLineEdit *tb_gy_offset;
    QLineEdit *tb_gz_offset;
    QLabel *label_44;
    QLabel *label_38;
    QLineEdit *tb_gx_offset_3;
    QLabel *label_24;
    QLabel *label_26;
    QPushButton *btn_mode_imu_load_params;
    QPushButton *btn_mode_imu_write_params;
    QPushButton *btn_mode_imu_save_params;

    void setupUi(QWidget *Mode_imu)
    {
        if (Mode_imu->objectName().isEmpty())
            Mode_imu->setObjectName(QString::fromUtf8("Mode_imu"));
        Mode_imu->resize(640, 431);
        groupBox_7 = new QGroupBox(Mode_imu);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 40, 621, 141));
        tb_my = new QLineEdit(groupBox_7);
        tb_my->setObjectName(QString::fromUtf8("tb_my"));
        tb_my->setGeometry(QRect(250, 80, 91, 20));
        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(370, 80, 21, 16));
        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(190, 80, 21, 16));
        tb_mx = new QLineEdit(groupBox_7);
        tb_mx->setObjectName(QString::fromUtf8("tb_mx"));
        tb_mx->setGeometry(QRect(70, 80, 91, 20));
        tb_mz = new QLineEdit(groupBox_7);
        tb_mz->setObjectName(QString::fromUtf8("tb_mz"));
        tb_mz->setGeometry(QRect(430, 80, 91, 20));
        label_28 = new QLabel(groupBox_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 80, 21, 16));
        tb_ay = new QLineEdit(groupBox_7);
        tb_ay->setObjectName(QString::fromUtf8("tb_ay"));
        tb_ay->setGeometry(QRect(250, 20, 91, 20));
        label_29 = new QLabel(groupBox_7);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(370, 20, 21, 16));
        label_36 = new QLabel(groupBox_7);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(190, 20, 21, 16));
        tb_ax = new QLineEdit(groupBox_7);
        tb_ax->setObjectName(QString::fromUtf8("tb_ax"));
        tb_ax->setGeometry(QRect(70, 20, 91, 20));
        tb_az = new QLineEdit(groupBox_7);
        tb_az->setObjectName(QString::fromUtf8("tb_az"));
        tb_az->setGeometry(QRect(430, 20, 91, 20));
        label_37 = new QLabel(groupBox_7);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 20, 21, 16));
        btn_gyro_calib_2 = new QPushButton(groupBox_7);
        btn_gyro_calib_2->setObjectName(QString::fromUtf8("btn_gyro_calib_2"));
        btn_gyro_calib_2->setGeometry(QRect(540, 80, 71, 21));
        btn_gyro_calib_3 = new QPushButton(groupBox_7);
        btn_gyro_calib_3->setObjectName(QString::fromUtf8("btn_gyro_calib_3"));
        btn_gyro_calib_3->setGeometry(QRect(540, 20, 71, 21));
        btn_gyro_calib = new QPushButton(groupBox_7);
        btn_gyro_calib->setObjectName(QString::fromUtf8("btn_gyro_calib"));
        btn_gyro_calib->setGeometry(QRect(540, 50, 71, 21));
        tb_gx = new QLineEdit(groupBox_7);
        tb_gx->setObjectName(QString::fromUtf8("tb_gx"));
        tb_gx->setGeometry(QRect(70, 50, 91, 20));
        tb_gz = new QLineEdit(groupBox_7);
        tb_gz->setObjectName(QString::fromUtf8("tb_gz"));
        tb_gz->setGeometry(QRect(430, 50, 91, 20));
        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(190, 50, 21, 16));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 50, 21, 16));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(370, 50, 21, 16));
        tb_gy = new QLineEdit(groupBox_7);
        tb_gy->setObjectName(QString::fromUtf8("tb_gy"));
        tb_gy->setGeometry(QRect(250, 50, 91, 20));
        tb_roll = new QLineEdit(groupBox_7);
        tb_roll->setObjectName(QString::fromUtf8("tb_roll"));
        tb_roll->setGeometry(QRect(70, 110, 91, 20));
        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(190, 110, 31, 16));
        label_31 = new QLabel(groupBox_7);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(10, 110, 21, 16));
        tb_pitch = new QLineEdit(groupBox_7);
        tb_pitch->setObjectName(QString::fromUtf8("tb_pitch"));
        tb_pitch->setGeometry(QRect(250, 110, 91, 20));
        tb_yaw = new QLineEdit(groupBox_7);
        tb_yaw->setObjectName(QString::fromUtf8("tb_yaw"));
        tb_yaw->setGeometry(QRect(430, 110, 91, 20));
        label_32 = new QLabel(groupBox_7);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(370, 110, 21, 16));
        btn_change_mode_imu = new QPushButton(Mode_imu);
        btn_change_mode_imu->setObjectName(QString::fromUtf8("btn_change_mode_imu"));
        btn_change_mode_imu->setGeometry(QRect(10, 10, 101, 23));
        groupBox_6 = new QGroupBox(Mode_imu);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 190, 621, 151));
        tb_gbelieve = new QLineEdit(groupBox_6);
        tb_gbelieve->setObjectName(QString::fromUtf8("tb_gbelieve"));
        tb_gbelieve->setGeometry(QRect(430, 120, 91, 20));
        tb_gy_offset_3 = new QLineEdit(groupBox_6);
        tb_gy_offset_3->setObjectName(QString::fromUtf8("tb_gy_offset_3"));
        tb_gy_offset_3->setGeometry(QRect(250, 90, 91, 20));
        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(370, 120, 61, 16));
        label_46 = new QLabel(groupBox_6);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(10, 90, 51, 16));
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 60, 51, 16));
        label_45 = new QLabel(groupBox_6);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(370, 90, 51, 16));
        tb_gz_offset_3 = new QLineEdit(groupBox_6);
        tb_gz_offset_3->setObjectName(QString::fromUtf8("tb_gz_offset_3"));
        tb_gz_offset_3->setGeometry(QRect(430, 90, 91, 20));
        tb_gx_offset = new QLineEdit(groupBox_6);
        tb_gx_offset->setObjectName(QString::fromUtf8("tb_gx_offset"));
        tb_gx_offset->setGeometry(QRect(70, 30, 91, 20));
        tb_gy_offset_2 = new QLineEdit(groupBox_6);
        tb_gy_offset_2->setObjectName(QString::fromUtf8("tb_gy_offset_2"));
        tb_gy_offset_2->setGeometry(QRect(250, 60, 91, 20));
        tb_gz_offset_2 = new QLineEdit(groupBox_6);
        tb_gz_offset_2->setObjectName(QString::fromUtf8("tb_gz_offset_2"));
        tb_gz_offset_2->setGeometry(QRect(430, 60, 91, 20));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(190, 30, 51, 16));
        label_42 = new QLabel(groupBox_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(370, 60, 51, 16));
        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 120, 51, 16));
        tb_angle_adjust = new QLineEdit(groupBox_6);
        tb_angle_adjust->setObjectName(QString::fromUtf8("tb_angle_adjust"));
        tb_angle_adjust->setGeometry(QRect(250, 120, 91, 20));
        tb_gx_offset_2 = new QLineEdit(groupBox_6);
        tb_gx_offset_2->setObjectName(QString::fromUtf8("tb_gx_offset_2"));
        tb_gx_offset_2->setGeometry(QRect(70, 60, 91, 20));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 30, 51, 16));
        txtb_tilt_0 = new QLineEdit(groupBox_6);
        txtb_tilt_0->setObjectName(QString::fromUtf8("txtb_tilt_0"));
        txtb_tilt_0->setGeometry(QRect(70, 120, 91, 20));
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
        tb_gx_offset_3 = new QLineEdit(groupBox_6);
        tb_gx_offset_3->setObjectName(QString::fromUtf8("tb_gx_offset_3"));
        tb_gx_offset_3->setGeometry(QRect(70, 90, 91, 20));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(370, 30, 51, 16));
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(190, 120, 61, 16));
        btn_mode_imu_load_params = new QPushButton(Mode_imu);
        btn_mode_imu_load_params->setObjectName(QString::fromUtf8("btn_mode_imu_load_params"));
        btn_mode_imu_load_params->setGeometry(QRect(130, 10, 101, 23));
        btn_mode_imu_write_params = new QPushButton(Mode_imu);
        btn_mode_imu_write_params->setObjectName(QString::fromUtf8("btn_mode_imu_write_params"));
        btn_mode_imu_write_params->setGeometry(QRect(250, 10, 101, 23));
        btn_mode_imu_save_params = new QPushButton(Mode_imu);
        btn_mode_imu_save_params->setObjectName(QString::fromUtf8("btn_mode_imu_save_params"));
        btn_mode_imu_save_params->setGeometry(QRect(370, 10, 101, 23));

        retranslateUi(Mode_imu);

        QMetaObject::connectSlotsByName(Mode_imu);
    } // setupUi

    void retranslateUi(QWidget *Mode_imu)
    {
        Mode_imu->setWindowTitle(QCoreApplication::translate("Mode_imu", "Form", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Mode_imu", "Value", nullptr));
        label_20->setText(QCoreApplication::translate("Mode_imu", "Mz:", nullptr));
        label_21->setText(QCoreApplication::translate("Mode_imu", "My:", nullptr));
        label_28->setText(QCoreApplication::translate("Mode_imu", "Mx:", nullptr));
        label_29->setText(QCoreApplication::translate("Mode_imu", "Az:", nullptr));
        label_36->setText(QCoreApplication::translate("Mode_imu", "Ay:", nullptr));
        label_37->setText(QCoreApplication::translate("Mode_imu", "Ax:", nullptr));
        btn_gyro_calib_2->setText(QCoreApplication::translate("Mode_imu", "M Calibrate", nullptr));
        btn_gyro_calib_3->setText(QCoreApplication::translate("Mode_imu", "A Calibrate", nullptr));
        btn_gyro_calib->setText(QCoreApplication::translate("Mode_imu", "G Calibrate", nullptr));
        label_14->setText(QCoreApplication::translate("Mode_imu", "Gy:", nullptr));
        label_13->setText(QCoreApplication::translate("Mode_imu", "Gx:", nullptr));
        label_15->setText(QCoreApplication::translate("Mode_imu", "Gz:", nullptr));
        label_30->setText(QCoreApplication::translate("Mode_imu", "Pitch:", nullptr));
        label_31->setText(QCoreApplication::translate("Mode_imu", "Roll:", nullptr));
        label_32->setText(QCoreApplication::translate("Mode_imu", "Yaw:", nullptr));
        btn_change_mode_imu->setText(QCoreApplication::translate("Mode_imu", "Mode IMU", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Mode_imu", "Parameters:", nullptr));
        label_27->setText(QCoreApplication::translate("Mode_imu", "G Believe:", nullptr));
        label_46->setText(QCoreApplication::translate("Mode_imu", "Mx scale:", nullptr));
        label_39->setText(QCoreApplication::translate("Mode_imu", "Mx offset:", nullptr));
        label_45->setText(QCoreApplication::translate("Mode_imu", "Mx scale:", nullptr));
        label_23->setText(QCoreApplication::translate("Mode_imu", "Gy offset:", nullptr));
        label_42->setText(QCoreApplication::translate("Mode_imu", "Mz offset:", nullptr));
        label_25->setText(QCoreApplication::translate("Mode_imu", "Tilt Angle:", nullptr));
        label_22->setText(QCoreApplication::translate("Mode_imu", "Gx offset:", nullptr));
        label_44->setText(QCoreApplication::translate("Mode_imu", "Mx scale:", nullptr));
        label_38->setText(QCoreApplication::translate("Mode_imu", "My offset:", nullptr));
        label_24->setText(QCoreApplication::translate("Mode_imu", "Gz offset:", nullptr));
        label_26->setText(QCoreApplication::translate("Mode_imu", "Angle adj:", nullptr));
        btn_mode_imu_load_params->setText(QCoreApplication::translate("Mode_imu", "Load", nullptr));
        btn_mode_imu_write_params->setText(QCoreApplication::translate("Mode_imu", "Write", nullptr));
        btn_mode_imu_save_params->setText(QCoreApplication::translate("Mode_imu", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_imu: public Ui_Mode_imu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_IMU_H
