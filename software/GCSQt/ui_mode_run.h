/********************************************************************************
** Form generated from reading UI file 'mode_run.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_run
{
public:
    QGroupBox *groupBox_11;
    QLabel *label_47;
    QLineEdit *txtBoxRoll;
    QLineEdit *txtBoxPitch;
    QLineEdit *txtBoxYaw;
    QLabel *label_79;
    QLineEdit *tb_tilt_cal;
    QPushButton *btn_change_mode_run;
    QGroupBox *groupBox_12;
    QLabel *label_61;
    QLineEdit *txtb_pidt_vx;
    QLabel *label_62;
    QLabel *label_63;
    QLineEdit *txtBoxVY;
    QLineEdit *txtb_pidt_w;
    QPushButton *btn_control_enable;
    QPushButton *btn_log;
    QGroupBox *groupBox;
    QPlainTextEdit *pteControl;
    QGroupBox *groupBox_2;
    QPlainTextEdit *pteMeasurement;
    QLineEdit *tb_cm;
    QPushButton *btn_cm;
    QPushButton *btn_run_ekf;
    QSlider *hs_ekf_state;
    QLabel *lb_curren_state;
    QLabel *label_2;
    QLabel *lb_total_state;
    QGroupBox *groupBox_13;
    QLabel *label_48;
    QLineEdit *tb_pm_w;
    QLineEdit *tb_pm_cmf;
    QLabel *label_49;
    QLabel *label_50;
    QLineEdit *tb_pm_ctf;
    QLineEdit *tb_pm_tcx;
    QLabel *label_51;
    QLabel *label_52;
    QLineEdit *tb_pm_tcy;
    QLabel *label_53;
    QLineEdit *tb_pm_mds;
    QLineEdit *tb_pm_mas;
    QLabel *label_54;
    QLineEdit *tb_pm_ppr;
    QLabel *label_56;
    QLineEdit *tb_pm_wd;
    QLabel *label_57;
    QLineEdit *tb_initial_state_z;
    QLabel *label_55;
    QLineEdit *tb_initial_state_y;
    QLineEdit *tb_initial_state_x;
    QPushButton *btn_reset_ekf;

    void setupUi(QWidget *Mode_run)
    {
        if (Mode_run->objectName().isEmpty())
            Mode_run->setObjectName(QString::fromUtf8("Mode_run"));
        Mode_run->resize(649, 482);
        groupBox_11 = new QGroupBox(Mode_run);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 40, 321, 61));
        label_47 = new QLabel(groupBox_11);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(10, 30, 31, 16));
        txtBoxRoll = new QLineEdit(groupBox_11);
        txtBoxRoll->setObjectName(QString::fromUtf8("txtBoxRoll"));
        txtBoxRoll->setGeometry(QRect(50, 30, 51, 20));
        txtBoxRoll->setReadOnly(true);
        txtBoxPitch = new QLineEdit(groupBox_11);
        txtBoxPitch->setObjectName(QString::fromUtf8("txtBoxPitch"));
        txtBoxPitch->setGeometry(QRect(110, 30, 51, 20));
        txtBoxPitch->setReadOnly(true);
        txtBoxYaw = new QLineEdit(groupBox_11);
        txtBoxYaw->setObjectName(QString::fromUtf8("txtBoxYaw"));
        txtBoxYaw->setGeometry(QRect(170, 30, 51, 20));
        txtBoxYaw->setReadOnly(true);
        label_79 = new QLabel(groupBox_11);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(230, 30, 31, 16));
        tb_tilt_cal = new QLineEdit(groupBox_11);
        tb_tilt_cal->setObjectName(QString::fromUtf8("tb_tilt_cal"));
        tb_tilt_cal->setGeometry(QRect(260, 30, 51, 20));
        tb_tilt_cal->setReadOnly(true);
        btn_change_mode_run = new QPushButton(Mode_run);
        btn_change_mode_run->setObjectName(QString::fromUtf8("btn_change_mode_run"));
        btn_change_mode_run->setGeometry(QRect(10, 10, 101, 23));
        groupBox_12 = new QGroupBox(Mode_run);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 100, 321, 61));
        label_61 = new QLabel(groupBox_12);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(10, 30, 31, 16));
        txtb_pidt_vx = new QLineEdit(groupBox_12);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(40, 30, 51, 20));
        txtb_pidt_vx->setReadOnly(true);
        label_62 = new QLabel(groupBox_12);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(100, 30, 31, 16));
        label_63 = new QLabel(groupBox_12);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(190, 30, 61, 16));
        txtBoxVY = new QLineEdit(groupBox_12);
        txtBoxVY->setObjectName(QString::fromUtf8("txtBoxVY"));
        txtBoxVY->setGeometry(QRect(130, 30, 51, 20));
        txtBoxVY->setReadOnly(true);
        txtb_pidt_w = new QLineEdit(groupBox_12);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(260, 30, 51, 20));
        txtb_pidt_w->setReadOnly(true);
        btn_control_enable = new QPushButton(Mode_run);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(120, 10, 101, 23));
        btn_log = new QPushButton(Mode_run);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(230, 10, 101, 23));
        groupBox = new QGroupBox(Mode_run);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 200, 301, 251));
        pteControl = new QPlainTextEdit(groupBox);
        pteControl->setObjectName(QString::fromUtf8("pteControl"));
        pteControl->setGeometry(QRect(0, 20, 301, 231));
        groupBox_2 = new QGroupBox(Mode_run);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 200, 311, 251));
        pteMeasurement = new QPlainTextEdit(groupBox_2);
        pteMeasurement->setObjectName(QString::fromUtf8("pteMeasurement"));
        pteMeasurement->setGeometry(QRect(0, 20, 311, 231));
        tb_cm = new QLineEdit(Mode_run);
        tb_cm->setObjectName(QString::fromUtf8("tb_cm"));
        tb_cm->setGeometry(QRect(340, 10, 211, 23));
        tb_cm->setReadOnly(true);
        btn_cm = new QPushButton(Mode_run);
        btn_cm->setObjectName(QString::fromUtf8("btn_cm"));
        btn_cm->setGeometry(QRect(560, 10, 81, 23));
        btn_run_ekf = new QPushButton(Mode_run);
        btn_run_ekf->setObjectName(QString::fromUtf8("btn_run_ekf"));
        btn_run_ekf->setGeometry(QRect(410, 170, 101, 21));
        hs_ekf_state = new QSlider(Mode_run);
        hs_ekf_state->setObjectName(QString::fromUtf8("hs_ekf_state"));
        hs_ekf_state->setGeometry(QRect(10, 460, 531, 16));
        hs_ekf_state->setOrientation(Qt::Horizontal);
        lb_curren_state = new QLabel(Mode_run);
        lb_curren_state->setObjectName(QString::fromUtf8("lb_curren_state"));
        lb_curren_state->setGeometry(QRect(550, 460, 51, 17));
        label_2 = new QLabel(Mode_run);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 460, 16, 17));
        lb_total_state = new QLabel(Mode_run);
        lb_total_state->setObjectName(QString::fromUtf8("lb_total_state"));
        lb_total_state->setGeometry(QRect(600, 460, 51, 17));
        groupBox_13 = new QGroupBox(Mode_run);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(340, 40, 301, 121));
        label_48 = new QLabel(groupBox_13);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(210, 30, 31, 16));
        tb_pm_w = new QLineEdit(groupBox_13);
        tb_pm_w->setObjectName(QString::fromUtf8("tb_pm_w"));
        tb_pm_w->setGeometry(QRect(240, 30, 51, 20));
        tb_pm_w->setReadOnly(false);
        tb_pm_cmf = new QLineEdit(groupBox_13);
        tb_pm_cmf->setObjectName(QString::fromUtf8("tb_pm_cmf"));
        tb_pm_cmf->setGeometry(QRect(50, 30, 51, 20));
        tb_pm_cmf->setReadOnly(false);
        label_49 = new QLabel(groupBox_13);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 30, 31, 16));
        label_50 = new QLabel(groupBox_13);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(110, 30, 31, 16));
        tb_pm_ctf = new QLineEdit(groupBox_13);
        tb_pm_ctf->setObjectName(QString::fromUtf8("tb_pm_ctf"));
        tb_pm_ctf->setGeometry(QRect(150, 30, 51, 20));
        tb_pm_ctf->setReadOnly(false);
        tb_pm_tcx = new QLineEdit(groupBox_13);
        tb_pm_tcx->setObjectName(QString::fromUtf8("tb_pm_tcx"));
        tb_pm_tcx->setGeometry(QRect(50, 60, 51, 20));
        tb_pm_tcx->setReadOnly(false);
        label_51 = new QLabel(groupBox_13);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(10, 60, 31, 16));
        label_52 = new QLabel(groupBox_13);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(110, 60, 31, 16));
        tb_pm_tcy = new QLineEdit(groupBox_13);
        tb_pm_tcy->setObjectName(QString::fromUtf8("tb_pm_tcy"));
        tb_pm_tcy->setGeometry(QRect(150, 60, 51, 20));
        tb_pm_tcy->setReadOnly(false);
        label_53 = new QLabel(groupBox_13);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 90, 31, 16));
        tb_pm_mds = new QLineEdit(groupBox_13);
        tb_pm_mds->setObjectName(QString::fromUtf8("tb_pm_mds"));
        tb_pm_mds->setGeometry(QRect(50, 90, 51, 20));
        tb_pm_mds->setReadOnly(false);
        tb_pm_mas = new QLineEdit(groupBox_13);
        tb_pm_mas->setObjectName(QString::fromUtf8("tb_pm_mas"));
        tb_pm_mas->setGeometry(QRect(150, 90, 51, 20));
        tb_pm_mas->setReadOnly(false);
        label_54 = new QLabel(groupBox_13);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(110, 90, 31, 16));
        tb_pm_ppr = new QLineEdit(groupBox_13);
        tb_pm_ppr->setObjectName(QString::fromUtf8("tb_pm_ppr"));
        tb_pm_ppr->setGeometry(QRect(240, 60, 51, 20));
        tb_pm_ppr->setReadOnly(false);
        label_56 = new QLabel(groupBox_13);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(210, 60, 31, 16));
        tb_pm_wd = new QLineEdit(groupBox_13);
        tb_pm_wd->setObjectName(QString::fromUtf8("tb_pm_wd"));
        tb_pm_wd->setGeometry(QRect(240, 90, 51, 20));
        tb_pm_wd->setReadOnly(false);
        label_57 = new QLabel(groupBox_13);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(210, 90, 31, 16));
        tb_initial_state_z = new QLineEdit(Mode_run);
        tb_initial_state_z->setObjectName(QString::fromUtf8("tb_initial_state_z"));
        tb_initial_state_z->setGeometry(QRect(310, 170, 81, 20));
        tb_initial_state_z->setReadOnly(true);
        label_55 = new QLabel(Mode_run);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(20, 170, 91, 16));
        tb_initial_state_y = new QLineEdit(Mode_run);
        tb_initial_state_y->setObjectName(QString::fromUtf8("tb_initial_state_y"));
        tb_initial_state_y->setGeometry(QRect(210, 170, 81, 20));
        tb_initial_state_y->setReadOnly(true);
        tb_initial_state_x = new QLineEdit(Mode_run);
        tb_initial_state_x->setObjectName(QString::fromUtf8("tb_initial_state_x"));
        tb_initial_state_x->setGeometry(QRect(110, 170, 81, 20));
        tb_initial_state_x->setReadOnly(true);
        btn_reset_ekf = new QPushButton(Mode_run);
        btn_reset_ekf->setObjectName(QString::fromUtf8("btn_reset_ekf"));
        btn_reset_ekf->setGeometry(QRect(530, 170, 101, 21));
        groupBox_11->raise();
        btn_change_mode_run->raise();
        groupBox_12->raise();
        btn_control_enable->raise();
        btn_log->raise();
        groupBox->raise();
        groupBox_2->raise();
        tb_cm->raise();
        btn_cm->raise();
        hs_ekf_state->raise();
        lb_curren_state->raise();
        label_2->raise();
        lb_total_state->raise();
        groupBox_13->raise();
        btn_run_ekf->raise();
        tb_initial_state_z->raise();
        label_55->raise();
        tb_initial_state_y->raise();
        tb_initial_state_x->raise();
        btn_reset_ekf->raise();

        retranslateUi(Mode_run);

        QMetaObject::connectSlotsByName(Mode_run);
    } // setupUi

    void retranslateUi(QWidget *Mode_run)
    {
        Mode_run->setWindowTitle(QApplication::translate("Mode_run", "Form", nullptr));
        groupBox_11->setTitle(QApplication::translate("Mode_run", "Attitude", nullptr));
        label_47->setText(QApplication::translate("Mode_run", "RPY:", nullptr));
        txtBoxRoll->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtBoxPitch->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtBoxYaw->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_79->setText(QApplication::translate("Mode_run", "Tilt:", nullptr));
        tb_tilt_cal->setText(QApplication::translate("Mode_run", "0", nullptr));
        btn_change_mode_run->setText(QApplication::translate("Mode_run", "Mode Run", nullptr));
        groupBox_12->setTitle(QApplication::translate("Mode_run", "Control", nullptr));
        label_61->setText(QApplication::translate("Mode_run", "VX:", nullptr));
        txtb_pidt_vx->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_62->setText(QApplication::translate("Mode_run", "VY:", nullptr));
        label_63->setText(QApplication::translate("Mode_run", "OMEGA:", nullptr));
        txtBoxVY->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtb_pidt_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        btn_control_enable->setText(QApplication::translate("Mode_run", "Disabled", nullptr));
        btn_log->setText(QApplication::translate("Mode_run", "Log", nullptr));
        groupBox->setTitle(QApplication::translate("Mode_run", "Control", nullptr));
        groupBox_2->setTitle(QApplication::translate("Mode_run", "Measurement", nullptr));
        tb_cm->setText(QApplication::translate("Mode_run", "control_measurement.txt", nullptr));
        btn_cm->setText(QApplication::translate("Mode_run", "Browse", nullptr));
        btn_run_ekf->setText(QApplication::translate("Mode_run", "Run EKF", nullptr));
        lb_curren_state->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_2->setText(QApplication::translate("Mode_run", "/", nullptr));
        lb_total_state->setText(QApplication::translate("Mode_run", "99", nullptr));
        groupBox_13->setTitle(QApplication::translate("Mode_run", "EKF parameters", nullptr));
        label_48->setText(QApplication::translate("Mode_run", "W", nullptr));
        tb_pm_w->setText(QApplication::translate("Mode_run", "0.24", nullptr));
        tb_pm_cmf->setText(QApplication::translate("Mode_run", "0.001", nullptr));
        label_49->setText(QApplication::translate("Mode_run", "CMF", nullptr));
        label_50->setText(QApplication::translate("Mode_run", "CTF", nullptr));
        tb_pm_ctf->setText(QApplication::translate("Mode_run", "0.001", nullptr));
        tb_pm_tcx->setText(QApplication::translate("Mode_run", "0.0", nullptr));
        label_51->setText(QApplication::translate("Mode_run", "TCX", nullptr));
        label_52->setText(QApplication::translate("Mode_run", "TCY", nullptr));
        tb_pm_tcy->setText(QApplication::translate("Mode_run", "0.0", nullptr));
        label_53->setText(QApplication::translate("Mode_run", "MDS", nullptr));
        tb_pm_mds->setText(QApplication::translate("Mode_run", "0.2", nullptr));
        tb_pm_mas->setText(QApplication::translate("Mode_run", "10", nullptr));
        label_54->setText(QApplication::translate("Mode_run", "MAS", nullptr));
        tb_pm_ppr->setText(QApplication::translate("Mode_run", "780", nullptr));
        label_56->setText(QApplication::translate("Mode_run", "PPR", nullptr));
        tb_pm_wd->setText(QApplication::translate("Mode_run", "0.065", nullptr));
        label_57->setText(QApplication::translate("Mode_run", "WD", nullptr));
        tb_initial_state_z->setText(QString());
        label_55->setText(QApplication::translate("Mode_run", "Intial state:", nullptr));
        tb_initial_state_y->setText(QString());
        tb_initial_state_x->setText(QString());
        btn_reset_ekf->setText(QApplication::translate("Mode_run", "Reset EKF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_run: public Ui_Mode_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_RUN_H
