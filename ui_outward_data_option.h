/********************************************************************************
** Form generated from reading UI file 'outward_data_option.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTWARD_DATA_OPTION_H
#define UI_OUTWARD_DATA_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_outward_data_option
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QPushButton *wh;
    QPushButton *other;
    QPushButton *krishna;
    QPushButton *arwade;
    QPushButton *office;
    QPushButton *unknown;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *outward_data_option)
    {
        if (outward_data_option->objectName().isEmpty())
            outward_data_option->setObjectName("outward_data_option");
        outward_data_option->resize(1120, 636);
        QPalette palette;
        QBrush brush(QColor(248, 248, 248, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        outward_data_option->setPalette(palette);
        centralwidget = new QWidget(outward_data_option);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 320, 1131, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(543, 0, 81, 631));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        wh = new QPushButton(centralwidget);
        wh->setObjectName("wh");
        wh->setGeometry(QRect(690, 210, 361, 91));
        QFont font;
        font.setPointSize(31);
        wh->setFont(font);
        other = new QPushButton(centralwidget);
        other->setObjectName("other");
        other->setGeometry(QRect(300, 210, 261, 91));
        other->setFont(font);
        krishna = new QPushButton(centralwidget);
        krishna->setObjectName("krishna");
        krishna->setGeometry(QRect(110, 110, 361, 91));
        krishna->setFont(font);
        arwade = new QPushButton(centralwidget);
        arwade->setObjectName("arwade");
        arwade->setGeometry(QRect(10, 210, 261, 91));
        arwade->setFont(font);
        office = new QPushButton(centralwidget);
        office->setObjectName("office");
        office->setGeometry(QRect(120, 490, 361, 91));
        office->setFont(font);
        unknown = new QPushButton(centralwidget);
        unknown->setObjectName("unknown");
        unknown->setGeometry(QRect(680, 490, 361, 91));
        unknown->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(620, 30, 461, 131));
        QFont font1;
        font1.setPointSize(26);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 20, 461, 71));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 370, 461, 71));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(590, 380, 461, 71));
        label_4->setFont(font1);
        outward_data_option->setCentralWidget(centralwidget);

        retranslateUi(outward_data_option);

        QMetaObject::connectSlotsByName(outward_data_option);
    } // setupUi

    void retranslateUi(QMainWindow *outward_data_option)
    {
        outward_data_option->setWindowTitle(QCoreApplication::translate("outward_data_option", "MainWindow", nullptr));
        wh->setText(QCoreApplication::translate("outward_data_option", "WAREHOUSE", nullptr));
        other->setText(QCoreApplication::translate("outward_data_option", "OTHER", nullptr));
        krishna->setText(QCoreApplication::translate("outward_data_option", "KRISHNA", nullptr));
        arwade->setText(QCoreApplication::translate("outward_data_option", "ARWADE", nullptr));
        office->setText(QCoreApplication::translate("outward_data_option", "OFFICE", nullptr));
        unknown->setText(QCoreApplication::translate("outward_data_option", "UNKNOWN", nullptr));
        label->setText(QCoreApplication::translate("outward_data_option", "WAREHOUSE DATA DISPLAY", nullptr));
        label_2->setText(QCoreApplication::translate("outward_data_option", "                    MILL", nullptr));
        label_3->setText(QCoreApplication::translate("outward_data_option", "                  OFFICE", nullptr));
        label_4->setText(QCoreApplication::translate("outward_data_option", "                 UNKNOWN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class outward_data_option: public Ui_outward_data_option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTWARD_DATA_OPTION_H
