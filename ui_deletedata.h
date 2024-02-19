/********************************************************************************
** Form generated from reading UI file 'deletedata.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDATA_H
#define UI_DELETEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deletedata
{
public:
    QWidget *centralwidget;
    QPushButton *prev;
    QPushButton *next;
    QPushButton *del;
    QPushButton *start;
    QPushButton *end;
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QPushButton *db;
    QLabel *label;
    QPushButton *DEL2;
    QToolBar *toolBar;

    void setupUi(QMainWindow *deletedata)
    {
        if (deletedata->objectName().isEmpty())
            deletedata->setObjectName("deletedata");
        deletedata->resize(1082, 625);
        QFont font;
        font.setPointSize(20);
        deletedata->setFont(font);
        centralwidget = new QWidget(deletedata);
        centralwidget->setObjectName("centralwidget");
        prev = new QPushButton(centralwidget);
        prev->setObjectName("prev");
        prev->setGeometry(QRect(190, 480, 81, 91));
        QFont font1;
        font1.setPointSize(15);
        prev->setFont(font1);
        next = new QPushButton(centralwidget);
        next->setObjectName("next");
        next->setGeometry(QRect(270, 480, 81, 91));
        del = new QPushButton(centralwidget);
        del->setObjectName("del");
        del->setGeometry(QRect(670, 470, 221, 91));
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(60, 480, 121, 91));
        end = new QPushButton(centralwidget);
        end->setObjectName("end");
        end->setGeometry(QRect(360, 480, 121, 91));
        l1 = new QLabel(centralwidget);
        l1->setObjectName("l1");
        l1->setGeometry(QRect(130, 105, 831, 71));
        QFont font2;
        font2.setPointSize(17);
        l1->setFont(font2);
        l1->setAlignment(Qt::AlignCenter);
        l2 = new QLabel(centralwidget);
        l2->setObjectName("l2");
        l2->setGeometry(QRect(130, 200, 831, 71));
        l2->setFont(font2);
        l2->setAlignment(Qt::AlignCenter);
        l3 = new QLabel(centralwidget);
        l3->setObjectName("l3");
        l3->setGeometry(QRect(130, 320, 831, 71));
        l3->setFont(font2);
        l3->setAlignment(Qt::AlignCenter);
        db = new QPushButton(centralwidget);
        db->setObjectName("db");
        db->setGeometry(QRect(70, 570, 411, 51));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 10, 341, 31));
        DEL2 = new QPushButton(centralwidget);
        DEL2->setObjectName("DEL2");
        DEL2->setGeometry(QRect(580, 570, 411, 51));
        deletedata->setCentralWidget(centralwidget);
        toolBar = new QToolBar(deletedata);
        toolBar->setObjectName("toolBar");
        deletedata->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(deletedata);

        QMetaObject::connectSlotsByName(deletedata);
    } // setupUi

    void retranslateUi(QMainWindow *deletedata)
    {
        deletedata->setWindowTitle(QCoreApplication::translate("deletedata", "MainWindow", nullptr));
        prev->setText(QCoreApplication::translate("deletedata", "Previous", nullptr));
        next->setText(QCoreApplication::translate("deletedata", "Next", nullptr));
        del->setText(QCoreApplication::translate("deletedata", "DELETE", nullptr));
        start->setText(QCoreApplication::translate("deletedata", "TO START", nullptr));
        end->setText(QCoreApplication::translate("deletedata", "TO END", nullptr));
        l1->setText(QString());
        l2->setText(QString());
        l3->setText(QString());
        db->setText(QCoreApplication::translate("deletedata", "BACK TO DASHBOARD", nullptr));
        label->setText(QCoreApplication::translate("deletedata", "WAREWISE DATA MANAGER", nullptr));
        DEL2->setText(QCoreApplication::translate("deletedata", "DELETE THROUGH ACCESS KEY", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("deletedata", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deletedata: public Ui_deletedata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDATA_H
