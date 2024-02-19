/********************************************************************************
** Form generated from reading UI file 'datadisplaywindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADISPLAYWINDOW1_H
#define UI_DATADISPLAYWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataDisplayWindow1
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DataDisplayWindow1)
    {
        if (DataDisplayWindow1->objectName().isEmpty())
            DataDisplayWindow1->setObjectName("DataDisplayWindow1");
        DataDisplayWindow1->resize(800, 600);
        centralwidget = new QWidget(DataDisplayWindow1);
        centralwidget->setObjectName("centralwidget");
        DataDisplayWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataDisplayWindow1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        DataDisplayWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(DataDisplayWindow1);
        statusbar->setObjectName("statusbar");
        DataDisplayWindow1->setStatusBar(statusbar);

        retranslateUi(DataDisplayWindow1);

        QMetaObject::connectSlotsByName(DataDisplayWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *DataDisplayWindow1)
    {
        DataDisplayWindow1->setWindowTitle(QCoreApplication::translate("DataDisplayWindow1", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataDisplayWindow1: public Ui_DataDisplayWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADISPLAYWINDOW1_H
