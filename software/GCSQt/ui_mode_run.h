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
#include <QtWidgets/QComboBox>
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
    QLabel *label_63;
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
    QLineEdit *tb_initial_state_w;
    QLabel *label_55;
    QLineEdit *tb_initial_state_y;
    QLineEdit *tb_initial_state_x;
    QPushButton *btn_init_ekf;
    QComboBox *cb_ekf_mode;
    QPushButton *btn_trajectory_gen;
    QPushButton *btn_follow;
    QLineEdit *tb_trajectory_params_0;
    QLabel *label_58;
    QLineEdit *tb_trajectory_params_1;
    QLineEdit *tb_trajectory_params_2;
    QLineEdit *tb_trajectory_params_3;
    QLineEdit *tb_current_state_x;
    QLineEdit *tb_current_state_w;
    QLabel *label_59;
    QLineEdit *tb_current_state_y;
    QLabel *label_60;
    QLineEdit *tb_dwa_v;
    QLineEdit *tb_dwa_w;
    QComboBox *cb_trajectory;

    void setupUi(QWidget *Mode_run)
    {
        if (Mode_run->objectName().isEmpty())
            Mode_run->setObjectName(QString::fromUtf8("Mode_run"));
        Mode_run->resize(649, 482);
        groupBox_11 = new QGroupBox(Mode_run);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 40, 321, 91));
        label_47 = new QLabel(groupBox_11);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(10, 30, 31, 16));
        txtBoxRoll = new QLineEdit(groupBox_11);
        txtBoxRoll->setObjectName(QString::fromUtf8("txtBoxRoll"));
        txtBoxRoll->setGeometry(QRect(50, 30, 81, 20));
        txtBoxRoll->setReadOnly(true);
        txtBoxPitch = new QLineEdit(groupBox_11);
        txtBoxPitch->setObjectName(QString::fromUtf8("txtBoxPitch"));
        txtBoxPitch->setGeometry(QRect(140, 30, 81, 20));
        txtBoxPitch->setReadOnly(true);
        txtBoxYaw = new QLineEdit(groupBox_11);
        txtBoxYaw->setObjectName(QString::fromUtf8("txtBoxYaw"));
        txtBoxYaw->setGeometry(QRect(230, 30, 81, 20));
        txtBoxYaw->setReadOnly(true);
        label_79 = new QLabel(groupBox_11);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(10, 60, 31, 16));
        tb_tilt_cal = new QLineEdit(groupBox_11);
        tb_tilt_cal->setObjectName(QString::fromUtf8("tb_tilt_cal"));
        tb_tilt_cal->setGeometry(QRect(50, 60, 81, 20));
        tb_tilt_cal->setReadOnly(true);
        btn_change_mode_run = new QPushButton(Mode_run);
        btn_change_mode_run->setObjectName(QString::fromUtf8("btn_change_mode_run"));
        btn_change_mode_run->setGeometry(QRect(10, 10, 101, 23));
        groupBox_12 = new QGroupBox(Mode_run);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 130, 321, 61));
        label_61 = new QLabel(groupBox_12);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(10, 30, 31, 16));
        txtb_pidt_vx = new QLineEdit(groupBox_12);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(40, 30, 121, 20));
        txtb_pidt_vx->setReadOnly(true);
        label_63 = new QLabel(groupBox_12);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(170, 30, 61, 16));
        txtb_pidt_w = new QLineEdit(groupBox_12);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(190, 30, 121, 20));
        txtb_pidt_w->setReadOnly(true);
        btn_control_enable = new QPushButton(Mode_run);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(120, 10, 101, 23));
        btn_log = new QPushButton(Mode_run);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(230, 10, 101, 23));
        groupBox = new QGroupBox(Mode_run);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 290, 311, 161));
        pteControl = new QPlainTextEdit(groupBox);
        pteControl->setObjectName(QString::fromUtf8("pteControl"));
        pteControl->setGeometry(QRect(0, 20, 311, 141));
        groupBox_2 = new QGroupBox(Mode_run);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 290, 311, 161));
        pteMeasurement = new QPlainTextEdit(groupBox_2);
        pteMeasurement->setObjectName(QString::fromUtf8("pteMeasurement"));
        pteMeasurement->setGeometry(QRect(0, 20, 311, 141));
        tb_cm = new QLineEdit(Mode_run);
        tb_cm->setObjectName(QString::fromUtf8("tb_cm"));
        tb_cm->setGeometry(QRect(340, 10, 211, 23));
        tb_cm->setReadOnly(true);
        btn_cm = new QPushButton(Mode_run);
        btn_cm->setObjectName(QString::fromUtf8("btn_cm"));
        btn_cm->setGeometry(QRect(560, 10, 81, 23));
        btn_run_ekf = new QPushButton(Mode_run);
        btn_run_ekf->setObjectName(QString::fromUtf8("btn_run_ekf"));
        btn_run_ekf->setGeometry(QRect(450, 200, 70, 23));
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
        groupBox_13->setGeometry(QRect(340, 40, 301, 151));
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
        tb_pm_tcx->setGeometry(QRect(50, 70, 51, 20));
        tb_pm_tcx->setReadOnly(false);
        label_51 = new QLabel(groupBox_13);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(10, 70, 31, 16));
        label_52 = new QLabel(groupBox_13);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(110, 70, 31, 16));
        tb_pm_tcy = new QLineEdit(groupBox_13);
        tb_pm_tcy->setObjectName(QString::fromUtf8("tb_pm_tcy"));
        tb_pm_tcy->setGeometry(QRect(150, 70, 51, 20));
        tb_pm_tcy->setReadOnly(false);
        label_53 = new QLabel(groupBox_13);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 110, 31, 16));
        tb_pm_mds = new QLineEdit(groupBox_13);
        tb_pm_mds->setObjectName(QString::fromUtf8("tb_pm_mds"));
        tb_pm_mds->setGeometry(QRect(50, 110, 51, 20));
        tb_pm_mds->setReadOnly(false);
        tb_pm_mas = new QLineEdit(groupBox_13);
        tb_pm_mas->setObjectName(QString::fromUtf8("tb_pm_mas"));
        tb_pm_mas->setGeometry(QRect(150, 110, 51, 20));
        tb_pm_mas->setReadOnly(false);
        label_54 = new QLabel(groupBox_13);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(110, 110, 31, 16));
        tb_pm_ppr = new QLineEdit(groupBox_13);
        tb_pm_ppr->setObjectName(QString::fromUtf8("tb_pm_ppr"));
        tb_pm_ppr->setGeometry(QRect(240, 70, 51, 20));
        tb_pm_ppr->setReadOnly(false);
        label_56 = new QLabel(groupBox_13);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(210, 70, 31, 16));
        tb_pm_wd = new QLineEdit(groupBox_13);
        tb_pm_wd->setObjectName(QString::fromUtf8("tb_pm_wd"));
        tb_pm_wd->setGeometry(QRect(240, 110, 51, 20));
        tb_pm_wd->setReadOnly(false);
        label_57 = new QLabel(groupBox_13);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(210, 110, 31, 16));
        tb_initial_state_w = new QLineEdit(Mode_run);
        tb_initial_state_w->setObjectName(QString::fromUtf8("tb_initial_state_w"));
        tb_initial_state_w->setGeometry(QRect(270, 200, 91, 20));
        tb_initial_state_w->setReadOnly(false);
        label_55 = new QLabel(Mode_run);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(10, 200, 91, 16));
        tb_initial_state_y = new QLineEdit(Mode_run);
        tb_initial_state_y->setObjectName(QString::fromUtf8("tb_initial_state_y"));
        tb_initial_state_y->setGeometry(QRect(180, 200, 81, 20));
        tb_initial_state_y->setReadOnly(false);
        tb_initial_state_x = new QLineEdit(Mode_run);
        tb_initial_state_x->setObjectName(QString::fromUtf8("tb_initial_state_x"));
        tb_initial_state_x->setGeometry(QRect(90, 200, 81, 20));
        tb_initial_state_x->setReadOnly(false);
        btn_init_ekf = new QPushButton(Mode_run);
        btn_init_ekf->setObjectName(QString::fromUtf8("btn_init_ekf"));
        btn_init_ekf->setGeometry(QRect(370, 200, 70, 23));
        cb_ekf_mode = new QComboBox(Mode_run);
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->setObjectName(QString::fromUtf8("cb_ekf_mode"));
        cb_ekf_mode->setGeometry(QRect(530, 200, 111, 25));
        btn_trajectory_gen = new QPushButton(Mode_run);
        btn_trajectory_gen->setObjectName(QString::fromUtf8("btn_trajectory_gen"));
        btn_trajectory_gen->setGeometry(QRect(559, 260, 81, 23));
        btn_follow = new QPushButton(Mode_run);
        btn_follow->setObjectName(QString::fromUtf8("btn_follow"));
        btn_follow->setGeometry(QRect(450, 230, 70, 23));
        tb_trajectory_params_0 = new QLineEdit(Mode_run);
        tb_trajectory_params_0->setObjectName(QString::fromUtf8("tb_trajectory_params_0"));
        tb_trajectory_params_0->setGeometry(QRect(90, 260, 61, 20));
        tb_trajectory_params_0->setReadOnly(false);
        label_58 = new QLabel(Mode_run);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(10, 260, 81, 16));
        tb_trajectory_params_1 = new QLineEdit(Mode_run);
        tb_trajectory_params_1->setObjectName(QString::fromUtf8("tb_trajectory_params_1"));
        tb_trajectory_params_1->setGeometry(QRect(160, 260, 61, 20));
        tb_trajectory_params_1->setReadOnly(false);
        tb_trajectory_params_2 = new QLineEdit(Mode_run);
        tb_trajectory_params_2->setObjectName(QString::fromUtf8("tb_trajectory_params_2"));
        tb_trajectory_params_2->setGeometry(QRect(230, 260, 61, 20));
        tb_trajectory_params_2->setReadOnly(false);
        tb_trajectory_params_3 = new QLineEdit(Mode_run);
        tb_trajectory_params_3->setObjectName(QString::fromUtf8("tb_trajectory_params_3"));
        tb_trajectory_params_3->setGeometry(QRect(300, 260, 61, 20));
        tb_trajectory_params_3->setReadOnly(false);
        tb_current_state_x = new QLineEdit(Mode_run);
        tb_current_state_x->setObjectName(QString::fromUtf8("tb_current_state_x"));
        tb_current_state_x->setGeometry(QRect(120, 230, 91, 20));
        tb_current_state_x->setReadOnly(false);
        tb_current_state_w = new QLineEdit(Mode_run);
        tb_current_state_w->setObjectName(QString::fromUtf8("tb_current_state_w"));
        tb_current_state_w->setGeometry(QRect(340, 230, 101, 20));
        tb_current_state_w->setReadOnly(false);
        label_59 = new QLabel(Mode_run);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(10, 230, 101, 16));
        tb_current_state_y = new QLineEdit(Mode_run);
        tb_current_state_y->setObjectName(QString::fromUtf8("tb_current_state_y"));
        tb_current_state_y->setGeometry(QRect(230, 230, 91, 20));
        tb_current_state_y->setReadOnly(false);
        label_60 = new QLabel(Mode_run);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(370, 260, 41, 16));
        tb_dwa_v = new QLineEdit(Mode_run);
        tb_dwa_v->setObjectName(QString::fromUtf8("tb_dwa_v"));
        tb_dwa_v->setGeometry(QRect(420, 260, 61, 20));
        tb_dwa_v->setReadOnly(false);
        tb_dwa_w = new QLineEdit(Mode_run);
        tb_dwa_w->setObjectName(QString::fromUtf8("tb_dwa_w"));
        tb_dwa_w->setGeometry(QRect(490, 260, 61, 20));
        tb_dwa_w->setReadOnly(false);
        cb_trajectory = new QComboBox(Mode_run);
        cb_trajectory->addItem(QString());
        cb_trajectory->setObjectName(QString::fromUtf8("cb_trajectory"));
        cb_trajectory->setGeometry(QRect(530, 230, 111, 25));
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
        tb_initial_state_w->raise();
        label_55->raise();
        tb_initial_state_y->raise();
        tb_initial_state_x->raise();
        btn_init_ekf->raise();
        cb_ekf_mode->raise();
        btn_trajectory_gen->raise();
        btn_follow->raise();
        tb_trajectory_params_0->raise();
        label_58->raise();
        tb_trajectory_params_1->raise();
        tb_trajectory_params_2->raise();
        tb_trajectory_params_3->raise();
        tb_current_state_x->raise();
        tb_current_state_w->raise();
        label_59->raise();
        tb_current_state_y->raise();
        label_60->raise();
        tb_dwa_v->raise();
        tb_dwa_w->raise();
        cb_trajectory->raise();

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
        label_63->setText(QApplication::translate("Mode_run", "W:", nullptr));
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
        tb_pm_cmf->setText(QApplication::translate("Mode_run", "0.1", nullptr));
        label_49->setText(QApplication::translate("Mode_run", "CMF", nullptr));
        label_50->setText(QApplication::translate("Mode_run", "CTF", nullptr));
        tb_pm_ctf->setText(QApplication::translate("Mode_run", "0.2", nullptr));
        tb_pm_tcx->setText(QApplication::translate("Mode_run", "0.02", nullptr));
        label_51->setText(QApplication::translate("Mode_run", "TCX", nullptr));
        label_52->setText(QApplication::translate("Mode_run", "TCY", nullptr));
        tb_pm_tcy->setText(QApplication::translate("Mode_run", "0.0", nullptr));
        label_53->setText(QApplication::translate("Mode_run", "MDS", nullptr));
        tb_pm_mds->setText(QApplication::translate("Mode_run", "0.1", nullptr));
        tb_pm_mas->setText(QApplication::translate("Mode_run", "10", nullptr));
        label_54->setText(QApplication::translate("Mode_run", "MAS", nullptr));
        tb_pm_ppr->setText(QApplication::translate("Mode_run", "780", nullptr));
        label_56->setText(QApplication::translate("Mode_run", "PPR", nullptr));
        tb_pm_wd->setText(QApplication::translate("Mode_run", "0.065", nullptr));
        label_57->setText(QApplication::translate("Mode_run", "WD", nullptr));
        tb_initial_state_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_55->setText(QApplication::translate("Mode_run", "Intial state:", nullptr));
        tb_initial_state_y->setText(QApplication::translate("Mode_run", "3", nullptr));
        tb_initial_state_x->setText(QApplication::translate("Mode_run", "9", nullptr));
        btn_init_ekf->setText(QApplication::translate("Mode_run", "Init EKF", nullptr));
        cb_ekf_mode->setItemText(0, QApplication::translate("Mode_run", "Real time", nullptr));
        cb_ekf_mode->setItemText(1, QApplication::translate("Mode_run", "From file", nullptr));
        cb_ekf_mode->setItemText(2, QApplication::translate("Mode_run", "RT predict", nullptr));
        cb_ekf_mode->setItemText(3, QApplication::translate("Mode_run", "File predict", nullptr));

        btn_trajectory_gen->setText(QApplication::translate("Mode_run", "Traj gen", nullptr));
        btn_follow->setText(QApplication::translate("Mode_run", "Follow", nullptr));
        tb_trajectory_params_0->setText(QApplication::translate("Mode_run", "6", nullptr));
        label_58->setText(QApplication::translate("Mode_run", "Trajectory:", nullptr));
        tb_trajectory_params_1->setText(QApplication::translate("Mode_run", "1.5", nullptr));
        tb_trajectory_params_2->setText(QApplication::translate("Mode_run", "5", nullptr));
        tb_trajectory_params_3->setText(QApplication::translate("Mode_run", "1000", nullptr));
        tb_current_state_x->setText(QApplication::translate("Mode_run", "0", nullptr));
        tb_current_state_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_59->setText(QApplication::translate("Mode_run", "Current state:", nullptr));
        tb_current_state_y->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_60->setText(QApplication::translate("Mode_run", "DWA:", nullptr));
        tb_dwa_v->setText(QApplication::translate("Mode_run", "0.3", nullptr));
        tb_dwa_w->setText(QApplication::translate("Mode_run", "2.8", nullptr));
        cb_trajectory->setItemText(0, QApplication::translate("Mode_run", "Lemniscate", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Mode_run: public Ui_Mode_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_RUN_H
