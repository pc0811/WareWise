/********************************************************************************
** Form generated from reading UI file 'reportgen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTGEN_H
#define UI_REPORTGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportGen
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QPushButton *wh;
    QPushButton *krishna;
    QPushButton *other;
    QPushButton *arwade;
    QPushButton *office;
    QPushButton *unreg;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *ReportGen)
    {
        if (ReportGen->objectName().isEmpty())
            ReportGen->setObjectName("ReportGen");
        ReportGen->resize(1070, 645);
        QPalette palette;
        QBrush brush(QColor(238, 238, 238, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(248, 248, 248, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush2(QColor(13, 13, 13, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        ReportGen->setPalette(palette);
        QFont font;
        font.setPointSize(25);
        ReportGen->setFont(font);
        centralwidget = new QWidget(ReportGen);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 310, 1041, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(520, 10, 16, 621));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        wh = new QPushButton(centralwidget);
        wh->setObjectName("wh");
        wh->setGeometry(QRect(610, 170, 321, 81));
        QPalette palette1;
        QBrush brush3(QColor(30, 30, 30, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        wh->setPalette(palette1);
        krishna = new QPushButton(centralwidget);
        krishna->setObjectName("krishna");
        krishna->setGeometry(QRect(10, 220, 211, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        krishna->setPalette(palette2);
        other = new QPushButton(centralwidget);
        other->setObjectName("other");
        other->setGeometry(QRect(260, 220, 231, 81));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        other->setPalette(palette3);
        arwade = new QPushButton(centralwidget);
        arwade->setObjectName("arwade");
        arwade->setGeometry(QRect(140, 130, 241, 81));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        arwade->setPalette(palette4);
        office = new QPushButton(centralwidget);
        office->setObjectName("office");
        office->setGeometry(QRect(110, 510, 321, 81));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        office->setPalette(palette5);
        unreg = new QPushButton(centralwidget);
        unreg->setObjectName("unreg");
        unreg->setGeometry(QRect(650, 520, 321, 81));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        unreg->setPalette(palette6);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 10, 461, 131));
        QFont font1;
        font1.setPointSize(26);
        label_2->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 391, 81));
        label->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 360, 391, 131));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(640, 370, 381, 131));
        label_4->setFont(font1);
        ReportGen->setCentralWidget(centralwidget);

        retranslateUi(ReportGen);

        QMetaObject::connectSlotsByName(ReportGen);
    } // setupUi

    void retranslateUi(QMainWindow *ReportGen)
    {
        ReportGen->setWindowTitle(QCoreApplication::translate("ReportGen", "MainWindow", nullptr));
        wh->setText(QCoreApplication::translate("ReportGen", "WAREHOUSE", nullptr));
        krishna->setText(QCoreApplication::translate("ReportGen", "KRISHNA", nullptr));
        other->setText(QCoreApplication::translate("ReportGen", "OTHERS", nullptr));
        arwade->setText(QCoreApplication::translate("ReportGen", "ARWADE", nullptr));
        office->setText(QCoreApplication::translate("ReportGen", "OFFICE", nullptr));
        unreg->setText(QCoreApplication::translate("ReportGen", "UNREG", nullptr));
        label_2->setText(QCoreApplication::translate("ReportGen", "WAREHOUSE DATA DISPLAY", nullptr));
        label->setText(QCoreApplication::translate("ReportGen", "MILL DATA DISPLAY", nullptr));
        label_3->setText(QCoreApplication::translate("ReportGen", "OFFICE DATA DISPLAY", nullptr));
        label_4->setText(QCoreApplication::translate("ReportGen", "UNREG DATA DISPLAY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportGen: public Ui_ReportGen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTGEN_H
