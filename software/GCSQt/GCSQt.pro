#-------------------------------------------------
#
# Project created by QtCreator 2019-09-20T18:44:25
#
#-------------------------------------------------

QT       += core gui serialport network gamepad printsupport opengl datavisualization
UI_DIR = $$PWD

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GCSQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    EKF/ekf.cpp \
    EKF/utils.cpp \
    QCustomPlot/qcustomplot.cpp \
    QPlot3D/QPlot3D.cpp \
    com.cpp \
    com_gui.cpp \
    commonobject.cpp \
    led_indicator.cpp \
    main.cpp \
    mainwindow.cpp \
    mode_common.cpp \
    mode_hw_tw.cpp \
    mode_imu.cpp \
    mode_pidt_ta.cpp \
    mode_pidt_tw.cpp \
    mode_run.cpp \

HEADERS += \
    EKF/ekf.h \
    MAVLink/checksum.h \
    MAVLink/mavlink_conversions.h \
    MAVLink/mavlink_helpers.h \
    MAVLink/mavlink_types.h \
    MAVLink/protocol.h \
    MAVLink/protocol/mavlink.h \
    MAVLink/protocol/mavlink_msg_accel_params.h \
    MAVLink/protocol/mavlink_msg_ble_mesh.h \
    MAVLink/protocol/mavlink_msg_blink.h \
    MAVLink/protocol/mavlink_msg_cmd_change_mode.h \
    MAVLink/protocol/mavlink_msg_cmd_encoder_invert.h \
    MAVLink/protocol/mavlink_msg_cmd_hw.h \
    MAVLink/protocol/mavlink_msg_cmd_motor_invert.h \
    MAVLink/protocol/mavlink_msg_cmd_params.h \
    MAVLink/protocol/mavlink_msg_cmd_velocity.h \
    MAVLink/protocol/mavlink_msg_comp_filter_params.h \
    MAVLink/protocol/mavlink_msg_control.h \
    MAVLink/protocol/mavlink_msg_control_measurement.h \
    MAVLink/protocol/mavlink_msg_distance.h \
    MAVLink/protocol/mavlink_msg_evt_accel_raw.h \
    MAVLink/protocol/mavlink_msg_evt_calibrated_gyro_raw.h \
    MAVLink/protocol/mavlink_msg_evt_gyro_accel_mag_calibrated.h \
    MAVLink/protocol/mavlink_msg_evt_gyro_accel_mag_raw.h \
    MAVLink/protocol/mavlink_msg_evt_gyro_raw.h \
    MAVLink/protocol/mavlink_msg_evt_imu_raw.h \
    MAVLink/protocol/mavlink_msg_evt_mag_raw.h \
    MAVLink/protocol/mavlink_msg_evt_rpy.h \
    MAVLink/protocol/mavlink_msg_evt_sensor.h \
    MAVLink/protocol/mavlink_msg_evt_tilt.h \
    MAVLink/protocol/mavlink_msg_evt_tilt_cal.h \
    MAVLink/protocol/mavlink_msg_evt_tilt_raw.h \
    MAVLink/protocol/mavlink_msg_filter_params.h \
    MAVLink/protocol/mavlink_msg_gyro_params.h \
    MAVLink/protocol/mavlink_msg_hw_params.h \
    MAVLink/protocol/mavlink_msg_imu_calibration_params.h \
    MAVLink/protocol/mavlink_msg_imu_params.h \
    MAVLink/protocol/mavlink_msg_location.h \
    MAVLink/protocol/mavlink_msg_location_reduced.h \
    MAVLink/protocol/mavlink_msg_mag_params.h \
    MAVLink/protocol/mavlink_msg_measurement.h \
    MAVLink/protocol/mavlink_msg_motor_speed.h \
    MAVLink/protocol/mavlink_msg_motor_speed_step.h \
    MAVLink/protocol/mavlink_msg_onoff.h \
    MAVLink/protocol/mavlink_msg_pid_params.h \
    MAVLink/protocol/mavlink_msg_pid_report.h \
    MAVLink/protocol/mavlink_msg_respond.h \
    MAVLink/protocol/mavlink_msg_slot.h \
    MAVLink/protocol/mavlink_msg_tag.h \
    MAVLink/protocol/mavlink_msg_tof.h \
    MAVLink/protocol/protocol.h \
    MAVLink/protocol/testsuite.h \
    MAVLink/protocol/version.h \
    QCustomPlot/qcustomplot.h \
    QPlot3D/QPlot3D.h \
    QPlot3D/QPlot3D.h \
    com.h \
    com_gui.h \
    commonobject.h \
    led_indicator.h \
    mainwindow.h \
    mainwindow.h \
    mode_common.h \
    mode_imu.h \
    mode_pidt_ta.h \
    mode_pidt_tw.h \
    mode_run.h \
    mode_hw_tw.h \
    qcustomplot/qcustomplot.h

FORMS += \
    com.ui \
    com_gui.ui \
    mainwindow.ui \
    mode_imu.ui \
    mode_hw_tw.ui \
    mode_pidt_ta.ui \
    mode_pidt_tw.ui \
    mode_run.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include (QJoysticks/QJoysticks.pri)
