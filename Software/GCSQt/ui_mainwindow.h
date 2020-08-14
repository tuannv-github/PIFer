/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "com.h"
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *Maintab;
    QCustomPlot *plot_0;
    QCustomPlot *plot_2;
    QCustomPlot *plot_4;
    QCustomPlot *plot_1;
    QCustomPlot *plot_5;
    QCustomPlot *plot_3;
    Com *wg_com;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1410, 675);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Maintab = new QTabWidget(centralWidget);
        Maintab->setObjectName(QString::fromUtf8("Maintab"));
        Maintab->setGeometry(QRect(10, 80, 651, 541));
        plot_0 = new QCustomPlot(centralWidget);
        plot_0->setObjectName(QString::fromUtf8("plot_0"));
        plot_0->setGeometry(QRect(670, 10, 361, 201));
        plot_2 = new QCustomPlot(centralWidget);
        plot_2->setObjectName(QString::fromUtf8("plot_2"));
        plot_2->setGeometry(QRect(670, 220, 361, 191));
        plot_4 = new QCustomPlot(centralWidget);
        plot_4->setObjectName(QString::fromUtf8("plot_4"));
        plot_4->setGeometry(QRect(670, 420, 361, 201));
        plot_1 = new QCustomPlot(centralWidget);
        plot_1->setObjectName(QString::fromUtf8("plot_1"));
        plot_1->setGeometry(QRect(1040, 10, 361, 201));
        plot_5 = new QCustomPlot(centralWidget);
        plot_5->setObjectName(QString::fromUtf8("plot_5"));
        plot_5->setGeometry(QRect(1040, 420, 361, 201));
        plot_3 = new QCustomPlot(centralWidget);
        plot_3->setObjectName(QString::fromUtf8("plot_3"));
        plot_3->setGeometry(QRect(1040, 220, 361, 191));
        wg_com = new Com(centralWidget);
        wg_com->setObjectName(QString::fromUtf8("wg_com"));
        wg_com->setGeometry(QRect(10, 0, 651, 80));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1410, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Maintab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
