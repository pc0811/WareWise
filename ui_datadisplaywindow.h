/********************************************************************************
** Form generated from reading UI file 'datadisplaywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADISPLAYWINDOW_H
#define UI_DATADISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataDisplayWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;

    void setupUi(QMainWindow *DataDisplayWindow)
    {
        if (DataDisplayWindow->objectName().isEmpty())
            DataDisplayWindow->setObjectName("DataDisplayWindow");
        DataDisplayWindow->resize(1489, 891);
        centralwidget = new QWidget(DataDisplayWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 1471, 781));
        DataDisplayWindow->setCentralWidget(centralwidget);

        retranslateUi(DataDisplayWindow);

        QMetaObject::connectSlotsByName(DataDisplayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataDisplayWindow)
    {
        DataDisplayWindow->setWindowTitle(QCoreApplication::translate("DataDisplayWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataDisplayWindow: public Ui_DataDisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADISPLAYWINDOW_H
