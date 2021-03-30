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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode_run
{
public:
    QPushButton *btn_change_mode_run;
    QPushButton *btn_control_enable;
    QPushButton *btn_log;
    QLineEdit *tb_cm;
    QPushButton *btn_cm;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *lb_total_state;
    QSlider *hs_ekf_state;
    QLabel *lb_curren_state;
    QGroupBox *groupBox;
    QPlainTextEdit *pteControl;
    QGroupBox *groupBox_2;
    QPlainTextEdit *pteMeasurement;
    QLineEdit *tb_initial_state_w;
    QLabel *label_55;
    QLineEdit *tb_initial_state_x;
    QLineEdit *tb_initial_state_y;
    QLineEdit *tb_current_state_w;
    QLabel *label_59;
    QLineEdit *tb_current_state_x;
    QLineEdit *tb_current_state_y;
    QComboBox *cb_ekf_mode;
    QPushButton *btn_run_ekf;
    QPushButton *btn_init_ekf;
    QLineEdit *tb_pm_w;
    QLineEdit *tb_pm_cmf;
    QLabel *label_49;
    QLabel *label_50;
    QLineEdit *tb_pm_ctf;
    QLabel *label_48;
    QLabel *label_51;
    QLabel *label_52;
    QLineEdit *tb_pm_tcy;
    QLineEdit *tb_pm_tcx;
    QLineEdit *tb_pm_ppr;
    QLabel *label_56;
    QLineEdit *tb_pm_wd;
    QLabel *label_53;
    QLabel *label_57;
    QLabel *label_54;
    QLineEdit *tb_pm_mas;
    QLineEdit *tb_pm_mds;
    QLabel *lb_curren_state_2;
    QWidget *tab_4;
    QGroupBox *groupBox_4;
    QLineEdit *tb_trajectory_params_size;
    QLineEdit *tb_trajectory_params_cx;
    QLineEdit *tb_trajectory_params_a;
    QComboBox *cb_trajectory;
    QLineEdit *tb_trajectory_params_cy;
    QPushButton *btn_trajectory_gen;
    QLabel *label_65;
    QLineEdit *tb_trajectory_params_b;
    QLabel *label_69;
    QLabel *label_70;
    QGroupBox *groupBox_5;
    QPushButton *btn_follow;
    QLineEdit *tb_dwa_v;
    QLineEdit *tb_dwa_result_w;
    QLineEdit *tb_dwa_alpha_v;
    QLineEdit *tb_dwa_send_w;
    QLineEdit *tb_dwa_w;
    QLineEdit *tb_dwa_alpha_w;
    QLineEdit *tb_dwa_send_v;
    QLineEdit *tb_dwa_result_v;
    QLabel *label_66;
    QLabel *label_67;
    QLabel *label_68;
    QGroupBox *groupBox_11;
    QLabel *label_47;
    QLineEdit *txtBoxRoll;
    QLineEdit *txtBoxPitch;
    QLineEdit *txtBoxYaw;
    QLineEdit *tb_tilt_cal;
    QLineEdit *txtb_pidt_vx;
    QLineEdit *txtb_pidt_w;

    void setupUi(QWidget *Mode_run)
    {
        if (Mode_run->objectName().isEmpty())
            Mode_run->setObjectName(QString::fromUtf8("Mode_run"));
        Mode_run->resize(649, 482);
        btn_change_mode_run = new QPushButton(Mode_run);
        btn_change_mode_run->setObjectName(QString::fromUtf8("btn_change_mode_run"));
        btn_change_mode_run->setGeometry(QRect(10, 10, 101, 23));
        btn_control_enable = new QPushButton(Mode_run);
        btn_control_enable->setObjectName(QString::fromUtf8("btn_control_enable"));
        btn_control_enable->setGeometry(QRect(120, 10, 101, 23));
        btn_log = new QPushButton(Mode_run);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(230, 10, 101, 23));
        tb_cm = new QLineEdit(Mode_run);
        tb_cm->setObjectName(QString::fromUtf8("tb_cm"));
        tb_cm->setGeometry(QRect(340, 10, 211, 23));
        tb_cm->setReadOnly(true);
        btn_cm = new QPushButton(Mode_run);
        btn_cm->setObjectName(QString::fromUtf8("btn_cm"));
        btn_cm->setGeometry(QRect(560, 10, 81, 23));
        label_2 = new QLabel(Mode_run);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 460, 16, 17));
        tabWidget = new QTabWidget(Mode_run);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 110, 631, 371));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lb_total_state = new QLabel(tab_2);
        lb_total_state->setObjectName(QString::fromUtf8("lb_total_state"));
        lb_total_state->setGeometry(QRect(580, 130, 51, 17));
        hs_ekf_state = new QSlider(tab_2);
        hs_ekf_state->setObjectName(QString::fromUtf8("hs_ekf_state"));
        hs_ekf_state->setGeometry(QRect(10, 130, 511, 16));
        hs_ekf_state->setOrientation(Qt::Horizontal);
        lb_curren_state = new QLabel(tab_2);
        lb_curren_state->setObjectName(QString::fromUtf8("lb_curren_state"));
        lb_curren_state->setGeometry(QRect(530, 130, 51, 17));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 150, 301, 181));
        pteControl = new QPlainTextEdit(groupBox);
        pteControl->setObjectName(QString::fromUtf8("pteControl"));
        pteControl->setGeometry(QRect(0, 20, 301, 161));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(320, 150, 301, 181));
        pteMeasurement = new QPlainTextEdit(groupBox_2);
        pteMeasurement->setObjectName(QString::fromUtf8("pteMeasurement"));
        pteMeasurement->setGeometry(QRect(0, 20, 301, 161));
        tb_initial_state_w = new QLineEdit(tab_2);
        tb_initial_state_w->setObjectName(QString::fromUtf8("tb_initial_state_w"));
        tb_initial_state_w->setGeometry(QRect(520, 10, 101, 20));
        tb_initial_state_w->setReadOnly(false);
        label_55 = new QLabel(tab_2);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(230, 10, 91, 16));
        tb_initial_state_x = new QLineEdit(tab_2);
        tb_initial_state_x->setObjectName(QString::fromUtf8("tb_initial_state_x"));
        tb_initial_state_x->setGeometry(QRect(320, 10, 91, 20));
        tb_initial_state_x->setReadOnly(false);
        tb_initial_state_y = new QLineEdit(tab_2);
        tb_initial_state_y->setObjectName(QString::fromUtf8("tb_initial_state_y"));
        tb_initial_state_y->setGeometry(QRect(420, 10, 91, 20));
        tb_initial_state_y->setReadOnly(false);
        tb_current_state_w = new QLineEdit(tab_2);
        tb_current_state_w->setObjectName(QString::fromUtf8("tb_current_state_w"));
        tb_current_state_w->setGeometry(QRect(520, 50, 101, 20));
        tb_current_state_w->setReadOnly(false);
        label_59 = new QLabel(tab_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(220, 50, 101, 16));
        tb_current_state_x = new QLineEdit(tab_2);
        tb_current_state_x->setObjectName(QString::fromUtf8("tb_current_state_x"));
        tb_current_state_x->setGeometry(QRect(320, 50, 91, 20));
        tb_current_state_x->setReadOnly(false);
        tb_current_state_y = new QLineEdit(tab_2);
        tb_current_state_y->setObjectName(QString::fromUtf8("tb_current_state_y"));
        tb_current_state_y->setGeometry(QRect(420, 50, 91, 20));
        tb_current_state_y->setReadOnly(false);
        cb_ekf_mode = new QComboBox(tab_2);
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->addItem(QString());
        cb_ekf_mode->setObjectName(QString::fromUtf8("cb_ekf_mode"));
        cb_ekf_mode->setGeometry(QRect(520, 90, 101, 25));
        btn_run_ekf = new QPushButton(tab_2);
        btn_run_ekf->setObjectName(QString::fromUtf8("btn_run_ekf"));
        btn_run_ekf->setGeometry(QRect(420, 90, 91, 23));
        btn_init_ekf = new QPushButton(tab_2);
        btn_init_ekf->setObjectName(QString::fromUtf8("btn_init_ekf"));
        btn_init_ekf->setGeometry(QRect(320, 90, 91, 23));
        tb_pm_w = new QLineEdit(tab_2);
        tb_pm_w->setObjectName(QString::fromUtf8("tb_pm_w"));
        tb_pm_w->setGeometry(QRect(250, 90, 51, 20));
        tb_pm_w->setReadOnly(false);
        tb_pm_cmf = new QLineEdit(tab_2);
        tb_pm_cmf->setObjectName(QString::fromUtf8("tb_pm_cmf"));
        tb_pm_cmf->setGeometry(QRect(50, 10, 51, 20));
        tb_pm_cmf->setReadOnly(false);
        label_49 = new QLabel(tab_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 10, 31, 16));
        label_50 = new QLabel(tab_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(110, 10, 31, 16));
        tb_pm_ctf = new QLineEdit(tab_2);
        tb_pm_ctf->setObjectName(QString::fromUtf8("tb_pm_ctf"));
        tb_pm_ctf->setGeometry(QRect(150, 10, 51, 20));
        tb_pm_ctf->setReadOnly(false);
        label_48 = new QLabel(tab_2);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(220, 90, 31, 16));
        label_51 = new QLabel(tab_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(10, 40, 31, 16));
        label_52 = new QLabel(tab_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(110, 40, 31, 16));
        tb_pm_tcy = new QLineEdit(tab_2);
        tb_pm_tcy->setObjectName(QString::fromUtf8("tb_pm_tcy"));
        tb_pm_tcy->setGeometry(QRect(150, 40, 51, 20));
        tb_pm_tcy->setReadOnly(false);
        tb_pm_tcx = new QLineEdit(tab_2);
        tb_pm_tcx->setObjectName(QString::fromUtf8("tb_pm_tcx"));
        tb_pm_tcx->setGeometry(QRect(50, 40, 51, 20));
        tb_pm_tcx->setReadOnly(false);
        tb_pm_ppr = new QLineEdit(tab_2);
        tb_pm_ppr->setObjectName(QString::fromUtf8("tb_pm_ppr"));
        tb_pm_ppr->setGeometry(QRect(50, 100, 51, 20));
        tb_pm_ppr->setReadOnly(false);
        label_56 = new QLabel(tab_2);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(10, 100, 31, 16));
        tb_pm_wd = new QLineEdit(tab_2);
        tb_pm_wd->setObjectName(QString::fromUtf8("tb_pm_wd"));
        tb_pm_wd->setGeometry(QRect(150, 100, 51, 20));
        tb_pm_wd->setReadOnly(false);
        label_53 = new QLabel(tab_2);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 70, 31, 16));
        label_57 = new QLabel(tab_2);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(110, 100, 31, 16));
        label_54 = new QLabel(tab_2);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(110, 70, 31, 16));
        tb_pm_mas = new QLineEdit(tab_2);
        tb_pm_mas->setObjectName(QString::fromUtf8("tb_pm_mas"));
        tb_pm_mas->setGeometry(QRect(150, 70, 51, 20));
        tb_pm_mas->setReadOnly(false);
        tb_pm_mds = new QLineEdit(tab_2);
        tb_pm_mds->setObjectName(QString::fromUtf8("tb_pm_mds"));
        tb_pm_mds->setGeometry(QRect(50, 70, 51, 20));
        tb_pm_mds->setReadOnly(false);
        lb_curren_state_2 = new QLabel(tab_2);
        lb_curren_state_2->setObjectName(QString::fromUtf8("lb_curren_state_2"));
        lb_curren_state_2->setGeometry(QRect(570, 130, 16, 17));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 0, 411, 121));
        tb_trajectory_params_size = new QLineEdit(groupBox_4);
        tb_trajectory_params_size->setObjectName(QString::fromUtf8("tb_trajectory_params_size"));
        tb_trajectory_params_size->setGeometry(QRect(70, 90, 111, 20));
        tb_trajectory_params_size->setReadOnly(false);
        tb_trajectory_params_cx = new QLineEdit(groupBox_4);
        tb_trajectory_params_cx->setObjectName(QString::fromUtf8("tb_trajectory_params_cx"));
        tb_trajectory_params_cx->setGeometry(QRect(70, 30, 111, 20));
        tb_trajectory_params_cx->setReadOnly(false);
        tb_trajectory_params_a = new QLineEdit(groupBox_4);
        tb_trajectory_params_a->setObjectName(QString::fromUtf8("tb_trajectory_params_a"));
        tb_trajectory_params_a->setGeometry(QRect(70, 60, 111, 20));
        tb_trajectory_params_a->setReadOnly(false);
        cb_trajectory = new QComboBox(groupBox_4);
        cb_trajectory->addItem(QString());
        cb_trajectory->addItem(QString());
        cb_trajectory->addItem(QString());
        cb_trajectory->addItem(QString());
        cb_trajectory->addItem(QString());
        cb_trajectory->setObjectName(QString::fromUtf8("cb_trajectory"));
        cb_trajectory->setGeometry(QRect(190, 90, 111, 25));
        tb_trajectory_params_cy = new QLineEdit(groupBox_4);
        tb_trajectory_params_cy->setObjectName(QString::fromUtf8("tb_trajectory_params_cy"));
        tb_trajectory_params_cy->setGeometry(QRect(190, 30, 111, 20));
        tb_trajectory_params_cy->setReadOnly(false);
        btn_trajectory_gen = new QPushButton(groupBox_4);
        btn_trajectory_gen->setObjectName(QString::fromUtf8("btn_trajectory_gen"));
        btn_trajectory_gen->setGeometry(QRect(310, 30, 91, 81));
        label_65 = new QLabel(groupBox_4);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(10, 30, 61, 16));
        tb_trajectory_params_b = new QLineEdit(groupBox_4);
        tb_trajectory_params_b->setObjectName(QString::fromUtf8("tb_trajectory_params_b"));
        tb_trajectory_params_b->setGeometry(QRect(190, 60, 111, 20));
        tb_trajectory_params_b->setReadOnly(false);
        label_69 = new QLabel(groupBox_4);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setGeometry(QRect(10, 60, 61, 16));
        label_70 = new QLabel(groupBox_4);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(10, 90, 61, 16));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 130, 611, 121));
        btn_follow = new QPushButton(groupBox_5);
        btn_follow->setObjectName(QString::fromUtf8("btn_follow"));
        btn_follow->setGeometry(QRect(510, 30, 91, 81));
        tb_dwa_v = new QLineEdit(groupBox_5);
        tb_dwa_v->setObjectName(QString::fromUtf8("tb_dwa_v"));
        tb_dwa_v->setGeometry(QRect(110, 30, 91, 20));
        tb_dwa_v->setReadOnly(false);
        tb_dwa_result_w = new QLineEdit(groupBox_5);
        tb_dwa_result_w->setObjectName(QString::fromUtf8("tb_dwa_result_w"));
        tb_dwa_result_w->setGeometry(QRect(410, 30, 91, 20));
        tb_dwa_result_w->setReadOnly(true);
        tb_dwa_alpha_v = new QLineEdit(groupBox_5);
        tb_dwa_alpha_v->setObjectName(QString::fromUtf8("tb_dwa_alpha_v"));
        tb_dwa_alpha_v->setGeometry(QRect(310, 60, 91, 20));
        tb_dwa_alpha_v->setReadOnly(false);
        tb_dwa_send_w = new QLineEdit(groupBox_5);
        tb_dwa_send_w->setObjectName(QString::fromUtf8("tb_dwa_send_w"));
        tb_dwa_send_w->setGeometry(QRect(410, 90, 91, 20));
        tb_dwa_send_w->setReadOnly(true);
        tb_dwa_w = new QLineEdit(groupBox_5);
        tb_dwa_w->setObjectName(QString::fromUtf8("tb_dwa_w"));
        tb_dwa_w->setGeometry(QRect(210, 30, 91, 20));
        tb_dwa_w->setReadOnly(false);
        tb_dwa_alpha_w = new QLineEdit(groupBox_5);
        tb_dwa_alpha_w->setObjectName(QString::fromUtf8("tb_dwa_alpha_w"));
        tb_dwa_alpha_w->setGeometry(QRect(410, 60, 91, 20));
        tb_dwa_alpha_w->setReadOnly(false);
        tb_dwa_send_v = new QLineEdit(groupBox_5);
        tb_dwa_send_v->setObjectName(QString::fromUtf8("tb_dwa_send_v"));
        tb_dwa_send_v->setGeometry(QRect(310, 90, 91, 20));
        tb_dwa_send_v->setReadOnly(true);
        tb_dwa_result_v = new QLineEdit(groupBox_5);
        tb_dwa_result_v->setObjectName(QString::fromUtf8("tb_dwa_result_v"));
        tb_dwa_result_v->setGeometry(QRect(310, 30, 91, 20));
        tb_dwa_result_v->setReadOnly(true);
        label_66 = new QLabel(groupBox_5);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setGeometry(QRect(10, 30, 71, 16));
        label_67 = new QLabel(groupBox_5);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(10, 60, 71, 16));
        label_68 = new QLabel(groupBox_5);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setGeometry(QRect(10, 90, 111, 16));
        tabWidget->addTab(tab_4, QString());
        groupBox_11 = new QGroupBox(Mode_run);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 40, 621, 61));
        label_47 = new QLabel(groupBox_11);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(10, 30, 61, 16));
        txtBoxRoll = new QLineEdit(groupBox_11);
        txtBoxRoll->setObjectName(QString::fromUtf8("txtBoxRoll"));
        txtBoxRoll->setGeometry(QRect(80, 30, 81, 20));
        txtBoxRoll->setReadOnly(true);
        txtBoxPitch = new QLineEdit(groupBox_11);
        txtBoxPitch->setObjectName(QString::fromUtf8("txtBoxPitch"));
        txtBoxPitch->setGeometry(QRect(170, 30, 81, 20));
        txtBoxPitch->setReadOnly(true);
        txtBoxYaw = new QLineEdit(groupBox_11);
        txtBoxYaw->setObjectName(QString::fromUtf8("txtBoxYaw"));
        txtBoxYaw->setGeometry(QRect(260, 30, 81, 20));
        txtBoxYaw->setReadOnly(true);
        tb_tilt_cal = new QLineEdit(groupBox_11);
        tb_tilt_cal->setObjectName(QString::fromUtf8("tb_tilt_cal"));
        tb_tilt_cal->setGeometry(QRect(350, 30, 81, 20));
        tb_tilt_cal->setReadOnly(true);
        txtb_pidt_vx = new QLineEdit(groupBox_11);
        txtb_pidt_vx->setObjectName(QString::fromUtf8("txtb_pidt_vx"));
        txtb_pidt_vx->setGeometry(QRect(440, 30, 81, 20));
        txtb_pidt_vx->setReadOnly(true);
        txtb_pidt_w = new QLineEdit(groupBox_11);
        txtb_pidt_w->setObjectName(QString::fromUtf8("txtb_pidt_w"));
        txtb_pidt_w->setGeometry(QRect(530, 30, 81, 20));
        txtb_pidt_w->setReadOnly(true);

        retranslateUi(Mode_run);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Mode_run);
    } // setupUi

    void retranslateUi(QWidget *Mode_run)
    {
        Mode_run->setWindowTitle(QApplication::translate("Mode_run", "Form", nullptr));
        btn_change_mode_run->setText(QApplication::translate("Mode_run", "Mode Run", nullptr));
        btn_control_enable->setText(QApplication::translate("Mode_run", "Disabled", nullptr));
        btn_log->setText(QApplication::translate("Mode_run", "Log", nullptr));
        tb_cm->setText(QApplication::translate("Mode_run", "control_measurement.txt", nullptr));
        btn_cm->setText(QApplication::translate("Mode_run", "Browse", nullptr));
        label_2->setText(QApplication::translate("Mode_run", "/", nullptr));
        lb_total_state->setText(QApplication::translate("Mode_run", "99", nullptr));
        lb_curren_state->setText(QApplication::translate("Mode_run", "0", nullptr));
        groupBox->setTitle(QApplication::translate("Mode_run", "Control", nullptr));
        groupBox_2->setTitle(QApplication::translate("Mode_run", "Measurement", nullptr));
        tb_initial_state_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_55->setText(QApplication::translate("Mode_run", "Initial state:", nullptr));
        tb_initial_state_x->setText(QApplication::translate("Mode_run", "8", nullptr));
        tb_initial_state_y->setText(QApplication::translate("Mode_run", "1.5", nullptr));
        tb_current_state_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_59->setText(QApplication::translate("Mode_run", "Current state:", nullptr));
        tb_current_state_x->setText(QApplication::translate("Mode_run", "0", nullptr));
        tb_current_state_y->setText(QApplication::translate("Mode_run", "0", nullptr));
        cb_ekf_mode->setItemText(0, QApplication::translate("Mode_run", "Real time", nullptr));
        cb_ekf_mode->setItemText(1, QApplication::translate("Mode_run", "From file", nullptr));
        cb_ekf_mode->setItemText(2, QApplication::translate("Mode_run", "RT predict", nullptr));
        cb_ekf_mode->setItemText(3, QApplication::translate("Mode_run", "File predict", nullptr));

        btn_run_ekf->setText(QApplication::translate("Mode_run", "Run EKF", nullptr));
        btn_init_ekf->setText(QApplication::translate("Mode_run", "Init EKF", nullptr));
        tb_pm_w->setText(QApplication::translate("Mode_run", "0.24", nullptr));
        tb_pm_cmf->setText(QApplication::translate("Mode_run", "0.1", nullptr));
        label_49->setText(QApplication::translate("Mode_run", "CMF", nullptr));
        label_50->setText(QApplication::translate("Mode_run", "CTF", nullptr));
        tb_pm_ctf->setText(QApplication::translate("Mode_run", "0.2", nullptr));
        label_48->setText(QApplication::translate("Mode_run", "W", nullptr));
        label_51->setText(QApplication::translate("Mode_run", "TCX", nullptr));
        label_52->setText(QApplication::translate("Mode_run", "TCY", nullptr));
        tb_pm_tcy->setText(QApplication::translate("Mode_run", "0.0", nullptr));
        tb_pm_tcx->setText(QApplication::translate("Mode_run", "0.02", nullptr));
        tb_pm_ppr->setText(QApplication::translate("Mode_run", "780", nullptr));
        label_56->setText(QApplication::translate("Mode_run", "PPR", nullptr));
        tb_pm_wd->setText(QApplication::translate("Mode_run", "0.065", nullptr));
        label_53->setText(QApplication::translate("Mode_run", "MDS", nullptr));
        label_57->setText(QApplication::translate("Mode_run", "WD", nullptr));
        label_54->setText(QApplication::translate("Mode_run", "MAS", nullptr));
        tb_pm_mas->setText(QApplication::translate("Mode_run", "10", nullptr));
        tb_pm_mds->setText(QApplication::translate("Mode_run", "0.1", nullptr));
        lb_curren_state_2->setText(QApplication::translate("Mode_run", "/", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Mode_run", "State estimatior", nullptr));
        groupBox_4->setTitle(QApplication::translate("Mode_run", "Trajectory", nullptr));
        tb_trajectory_params_size->setText(QApplication::translate("Mode_run", "600", nullptr));
        tb_trajectory_params_cx->setText(QApplication::translate("Mode_run", "8", nullptr));
        tb_trajectory_params_a->setText(QApplication::translate("Mode_run", "1", nullptr));
        cb_trajectory->setItemText(0, QApplication::translate("Mode_run", "Lemniscate", nullptr));
        cb_trajectory->setItemText(1, QApplication::translate("Mode_run", "Torpedor", nullptr));
        cb_trajectory->setItemText(2, QApplication::translate("Mode_run", "Rectangle", nullptr));
        cb_trajectory->setItemText(3, QApplication::translate("Mode_run", "Circle", nullptr));
        cb_trajectory->setItemText(4, QApplication::translate("Mode_run", "Ellipse", nullptr));

        tb_trajectory_params_cy->setText(QApplication::translate("Mode_run", "1.5", nullptr));
        btn_trajectory_gen->setText(QApplication::translate("Mode_run", "Traj gen", nullptr));
        label_65->setText(QApplication::translate("Mode_run", "Cx-Cy:", nullptr));
        tb_trajectory_params_b->setText(QApplication::translate("Mode_run", "1", nullptr));
        label_69->setText(QApplication::translate("Mode_run", "Params:", nullptr));
        label_70->setText(QApplication::translate("Mode_run", "Size:", nullptr));
        groupBox_5->setTitle(QApplication::translate("Mode_run", "Dynamic Window Approach", nullptr));
        btn_follow->setText(QApplication::translate("Mode_run", "Follow", nullptr));
        tb_dwa_v->setText(QApplication::translate("Mode_run", "0.1", nullptr));
        tb_dwa_result_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        tb_dwa_alpha_v->setText(QApplication::translate("Mode_run", "10", nullptr));
        tb_dwa_send_w->setText(QApplication::translate("Mode_run", "0", nullptr));
        tb_dwa_w->setText(QApplication::translate("Mode_run", "2", nullptr));
        tb_dwa_alpha_w->setText(QApplication::translate("Mode_run", "0.5", nullptr));
        tb_dwa_send_v->setText(QApplication::translate("Mode_run", "0", nullptr));
        tb_dwa_result_v->setText(QApplication::translate("Mode_run", "0", nullptr));
        label_66->setText(QApplication::translate("Mode_run", "V-W_max:", nullptr));
        label_67->setText(QApplication::translate("Mode_run", "Alpha:", nullptr));
        label_68->setText(QApplication::translate("Mode_run", "V-W_command:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Mode_run", "Path tracker", nullptr));
        groupBox_11->setTitle(QApplication::translate("Mode_run", "Attitude", nullptr));
        label_47->setText(QApplication::translate("Mode_run", "RPY-T-C:", nullptr));
        txtBoxRoll->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtBoxPitch->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtBoxYaw->setText(QApplication::translate("Mode_run", "0", nullptr));
        tb_tilt_cal->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtb_pidt_vx->setText(QApplication::translate("Mode_run", "0", nullptr));
        txtb_pidt_w->setText(QApplication::translate("Mode_run", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode_run: public Ui_Mode_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_RUN_H
