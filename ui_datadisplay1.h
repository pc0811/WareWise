/********************************************************************************
** Form generated from reading UI file 'datadisplay1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADISPLAY1_H
#define UI_DATADISPLAY1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_datadisplay1
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *datadisplay1)
    {
        if (datadisplay1->objectName().isEmpty())
            datadisplay1->setObjectName("datadisplay1");
        datadisplay1->resize(800, 600);
        centralwidget = new QWidget(datadisplay1);
        centralwidget->setObjectName("centralwidget");
        datadisplay1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(datadisplay1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        datadisplay1->setMenuBar(menubar);
        statusbar = new QStatusBar(datadisplay1);
        statusbar->setObjectName("statusbar");
        datadisplay1->setStatusBar(statusbar);

        retranslateUi(datadisplay1);

        QMetaObject::connectSlotsByName(datadisplay1);
    } // setupUi

    void retranslateUi(QMainWindow *datadisplay1)
    {
        datadisplay1->setWindowTitle(QCoreApplication::translate("datadisplay1", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class datadisplay1: public Ui_datadisplay1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADISPLAY1_H
