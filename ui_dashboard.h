/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashboard
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *inward;
    QPushButton *outward;
    QPushButton *exit;
    QPushButton *updinw_2;
    QPushButton *data_outward;
    QLabel *CurrentStock;
    QLabel *whreport;
    QLabel *whreport_2;
    QPushButton *genreport;
    QPushButton *updinw;

    void setupUi(QMainWindow *dashboard)
    {
        if (dashboard->objectName().isEmpty())
            dashboard->setObjectName("dashboard");
        dashboard->resize(1275, 600);
        QPalette palette;
        QBrush brush(QColor(244, 244, 244, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(9, 9, 9, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        dashboard->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(72);
        dashboard->setFont(font);
        centralwidget = new QWidget(dashboard);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(430, 10, 401, 111));
        inward = new QPushButton(centralwidget);
        inward->setObjectName("inward");
        inward->setGeometry(QRect(110, 210, 171, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(20);
        inward->setFont(font1);
        outward = new QPushButton(centralwidget);
        outward->setObjectName("outward");
        outward->setGeometry(QRect(940, 220, 181, 41));
        outward->setFont(font1);
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(530, 360, 171, 41));
        exit->setFont(font1);
        updinw_2 = new QPushButton(centralwidget);
        updinw_2->setObjectName("updinw_2");
        updinw_2->setGeometry(QRect(60, 360, 241, 41));
        updinw_2->setFont(font1);
        data_outward = new QPushButton(centralwidget);
        data_outward->setObjectName("data_outward");
        data_outward->setGeometry(QRect(890, 350, 271, 41));
        data_outward->setFont(font1);
        CurrentStock = new QLabel(centralwidget);
        CurrentStock->setObjectName("CurrentStock");
        CurrentStock->setGeometry(QRect(100, 100, 1031, 111));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(33);
        CurrentStock->setFont(font2);
        whreport = new QLabel(centralwidget);
        whreport->setObjectName("whreport");
        whreport->setGeometry(QRect(250, 450, 831, 81));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(36);
        whreport->setFont(font3);
        whreport_2 = new QLabel(centralwidget);
        whreport_2->setObjectName("whreport_2");
        whreport_2->setGeometry(QRect(270, 480, 861, 81));
        whreport_2->setFont(font3);
        genreport = new QPushButton(centralwidget);
        genreport->setObjectName("genreport");
        genreport->setGeometry(QRect(490, 220, 271, 41));
        genreport->setFont(font1);
        updinw = new QPushButton(centralwidget);
        updinw->setObjectName("updinw");
        updinw->setGeometry(QRect(480, 460, 341, 41));
        updinw->setFont(font1);
        dashboard->setCentralWidget(centralwidget);

        retranslateUi(dashboard);

        QMetaObject::connectSlotsByName(dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *dashboard)
    {
        dashboard->setWindowTitle(QCoreApplication::translate("dashboard", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("dashboard", "WareWise", nullptr));
        inward->setText(QCoreApplication::translate("dashboard", "Inward Entry", nullptr));
        outward->setText(QCoreApplication::translate("dashboard", "Outward Entry", nullptr));
        exit->setText(QCoreApplication::translate("dashboard", "Exit", nullptr));
        updinw_2->setText(QCoreApplication::translate("dashboard", "Inward Data Display", nullptr));
        data_outward->setText(QCoreApplication::translate("dashboard", "Outward Data Display", nullptr));
        CurrentStock->setText(QCoreApplication::translate("dashboard", "   DESIGNED FOR SURESH KUMAR SATISH KUMAR", nullptr));
        whreport->setText(QString());
        whreport_2->setText(QString());
        genreport->setText(QCoreApplication::translate("dashboard", "GENERATE REPORT", nullptr));
        updinw->setText(QCoreApplication::translate("dashboard", "DELETE AND UPDATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dashboard: public Ui_dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
