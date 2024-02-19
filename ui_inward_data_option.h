/********************************************************************************
** Form generated from reading UI file 'inward_data_option.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INWARD_DATA_OPTION_H
#define UI_INWARD_DATA_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inward_data_option
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QLabel *label;
    QPushButton *wh;
    QLabel *label_2;
    QPushButton *arwade;
    QPushButton *krishna;
    QPushButton *others;
    QLabel *label_3;
    QPushButton *office;
    QLabel *label_4;
    QPushButton *unreg;

    void setupUi(QMainWindow *inward_data_option)
    {
        if (inward_data_option->objectName().isEmpty())
            inward_data_option->setObjectName("inward_data_option");
        inward_data_option->resize(1027, 712);
        QPalette palette;
        QBrush brush(QColor(248, 248, 248, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(27, 27, 27, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        inward_data_option->setPalette(palette);
        QFont font;
        font.setPointSize(36);
        inward_data_option->setFont(font);
        centralwidget = new QWidget(inward_data_option);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 350, 1021, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(493, 10, 20, 701));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(540, 20, 461, 131));
        QFont font1;
        font1.setPointSize(26);
        label->setFont(font1);
        wh = new QPushButton(centralwidget);
        wh->setObjectName("wh");
        wh->setGeometry(QRect(604, 213, 321, 81));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 461, 131));
        label_2->setFont(font1);
        arwade = new QPushButton(centralwidget);
        arwade->setObjectName("arwade");
        arwade->setGeometry(QRect(30, 160, 131, 81));
        QFont font2;
        font2.setPointSize(20);
        arwade->setFont(font2);
        krishna = new QPushButton(centralwidget);
        krishna->setObjectName("krishna");
        krishna->setGeometry(QRect(340, 160, 131, 81));
        krishna->setFont(font2);
        others = new QPushButton(centralwidget);
        others->setObjectName("others");
        others->setGeometry(QRect(170, 260, 131, 81));
        others->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 370, 461, 131));
        label_3->setFont(font1);
        office = new QPushButton(centralwidget);
        office->setObjectName("office");
        office->setGeometry(QRect(60, 550, 371, 81));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 370, 461, 131));
        label_4->setFont(font1);
        unreg = new QPushButton(centralwidget);
        unreg->setObjectName("unreg");
        unreg->setGeometry(QRect(580, 550, 371, 81));
        inward_data_option->setCentralWidget(centralwidget);

        retranslateUi(inward_data_option);

        QMetaObject::connectSlotsByName(inward_data_option);
    } // setupUi

    void retranslateUi(QMainWindow *inward_data_option)
    {
        inward_data_option->setWindowTitle(QCoreApplication::translate("inward_data_option", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("inward_data_option", "WAREHOUSE DATA DISPLAY", nullptr));
        wh->setText(QCoreApplication::translate("inward_data_option", "WAREHOUSE", nullptr));
        label_2->setText(QCoreApplication::translate("inward_data_option", "                    MILLS", nullptr));
        arwade->setText(QCoreApplication::translate("inward_data_option", "ARWADE", nullptr));
        krishna->setText(QCoreApplication::translate("inward_data_option", "KRISHNA", nullptr));
        others->setText(QCoreApplication::translate("inward_data_option", "OTHERS", nullptr));
        label_3->setText(QCoreApplication::translate("inward_data_option", "                    OFFICE", nullptr));
        office->setText(QCoreApplication::translate("inward_data_option", "OFFICE STORAGE", nullptr));
        label_4->setText(QCoreApplication::translate("inward_data_option", "   UNREGISTERED DATA", nullptr));
        unreg->setText(QCoreApplication::translate("inward_data_option", "UNREGISTERED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inward_data_option: public Ui_inward_data_option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INWARD_DATA_OPTION_H
