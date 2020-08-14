#-------------------------------------------------
#
# Project created by QtCreator 2019-09-20T18:44:25
#
#-------------------------------------------------

QT       += core gui serialport network gamepad printsupport

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
    com.cpp \
    com_gui.cpp \
    led_indicator.cpp \
    main.cpp \
    mainwindow.cpp \
    appmain.cpp \
    mode_common.cpp \
    mode_hw_tw.cpp \
    mode_imu.cpp \
    mode_pidt_ta.cpp \
    mode_pidt_tw.cpp \
    mode_run.cpp \
    qcustomplot/qcustomplot.cpp

HEADERS += \
    MAV/checksum.h \
    MAV/mavlink_conversions.h \
    MAV/mavlink_helpers.h \
    MAV/mavlink_types.h \
    MAV/protocol.h \
    MAV/protocol/mavlink.h \
    MAV/protocol/mavlink_msg_cmd_change_mode.h \
    MAV/protocol/mavlink_msg_cmd_encoder_invert.h \
    MAV/protocol/mavlink_msg_cmd_hw.h \
    MAV/protocol/mavlink_msg_cmd_motor_invert.h \
    MAV/protocol/mavlink_msg_cmd_params.h \
    MAV/protocol/mavlink_msg_cmd_velocity.h \
    MAV/protocol/mavlink_msg_evt_accel_raw.h \
    MAV/protocol/mavlink_msg_evt_gyro_raw.h \
    MAV/protocol/mavlink_msg_evt_imu_raw.h \
    MAV/protocol/mavlink_msg_evt_mag_raw.h \
    MAV/protocol/mavlink_msg_evt_rpy.h \
    MAV/protocol/mavlink_msg_evt_sensor.h \
    MAV/protocol/mavlink_msg_evt_tilt.h \
    MAV/protocol/mavlink_msg_hw_params.h \
    MAV/protocol/mavlink_msg_imu_calibration_params.h \
    MAV/protocol/mavlink_msg_imu_params.h \
    MAV/protocol/mavlink_msg_motor_speed.h \
    MAV/protocol/mavlink_msg_pid_params.h \
    MAV/protocol/mavlink_msg_pid_report.h \
    MAV/protocol/mavlink_msg_respond.h \
    MAV/protocol/protocol.h \
    MAV/protocol/testsuite.h \
    MAV/protocol/version.h \
    com.h \
    com_gui.h \
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
