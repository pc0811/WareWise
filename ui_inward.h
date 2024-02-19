/********************************************************************************
** Form generated from reading UI file 'inward.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INWARD_H
#define UI_INWARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inward
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *weig;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *Insert;
    QLineEdit *lot;
    QLineEdit *lorry;
    QLineEdit *tcode;
    QLineEdit *bags;
    QLineEdit *weight;
    QLineEdit *rate;
    QLineEdit *grade;
    QPushButton *exit;
    QPushButton *dashboard;
    QPushButton *newins;
    QLabel *labelResult;
    QDateEdit *dateEdit;
    QFrame *line;

    void setupUi(QMainWindow *inward)
    {
        if (inward->objectName().isEmpty())
            inward->setObjectName("inward");
        inward->resize(1330, 676);
        QPalette palette;
        QBrush brush(QColor(226, 226, 226, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        inward->setPalette(palette);
        QFont font;
        font.setPointSize(20);
        inward->setFont(font);
        centralwidget = new QWidget(inward);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(580, 0, 241, 51));
        QFont font1;
        font1.setPointSize(36);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 60, 461, 51));
        QFont font2;
        font2.setPointSize(31);
        label_2->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 220, 91, 31));
        QFont font3;
        font3.setPointSize(17);
        label_3->setFont(font3);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1010, 230, 61, 31));
        label_5->setFont(font3);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 300, 101, 31));
        label_7->setFont(font3);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(490, 310, 111, 31));
        label_8->setFont(font3);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(890, 300, 61, 31));
        label_9->setFont(font3);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(60, 430, 51, 31));
        label_10->setFont(font3);
        weig = new QLabel(centralwidget);
        weig->setObjectName("weig");
        weig->setGeometry(QRect(460, 430, 71, 31));
        weig->setFont(font3);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(890, 420, 51, 31));
        label_12->setFont(font3);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(1000, 480, 61, 31));
        label_13->setFont(font3);
        Insert = new QPushButton(centralwidget);
        Insert->setObjectName("Insert");
        Insert->setGeometry(QRect(350, 520, 261, 71));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(24);
        Insert->setFont(font4);
        lot = new QLineEdit(centralwidget);
        lot->setObjectName("lot");
        lot->setGeometry(QRect(130, 230, 171, 31));
        QFont font5;
        font5.setPointSize(15);
        lot->setFont(font5);
        lorry = new QLineEdit(centralwidget);
        lorry->setObjectName("lorry");
        lorry->setGeometry(QRect(230, 310, 231, 31));
        lorry->setFont(font5);
        tcode = new QLineEdit(centralwidget);
        tcode->setObjectName("tcode");
        tcode->setGeometry(QRect(650, 310, 171, 31));
        tcode->setFont(font5);
        bags = new QLineEdit(centralwidget);
        bags->setObjectName("bags");
        bags->setGeometry(QRect(130, 430, 171, 31));
        bags->setFont(font5);
        weight = new QLineEdit(centralwidget);
        weight->setObjectName("weight");
        weight->setGeometry(QRect(560, 430, 171, 31));
        weight->setFont(font5);
        rate = new QLineEdit(centralwidget);
        rate->setObjectName("rate");
        rate->setGeometry(QRect(970, 420, 171, 31));
        rate->setFont(font5);
        grade = new QLineEdit(centralwidget);
        grade->setObjectName("grade");
        grade->setGeometry(QRect(1000, 300, 171, 31));
        grade->setFont(font5);
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(1110, 520, 201, 71));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Times New Roman")});
        font6.setPointSize(28);
        exit->setFont(font6);
        dashboard = new QPushButton(centralwidget);
        dashboard->setObjectName("dashboard");
        dashboard->setGeometry(QRect(690, 520, 361, 71));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Times New Roman")});
        font7.setPointSize(19);
        dashboard->setFont(font7);
        newins = new QPushButton(centralwidget);
        newins->setObjectName("newins");
        newins->setGeometry(QRect(30, 520, 261, 71));
        newins->setFont(font4);
        labelResult = new QLabel(centralwidget);
        labelResult->setObjectName("labelResult");
        labelResult->setGeometry(QRect(280, 130, 901, 51));
        labelResult->setFont(font);
        labelResult->setAlignment(Qt::AlignCenter);
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(1080, 230, 191, 31));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(370, 230, 581, 31));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        inward->setCentralWidget(centralwidget);

        retranslateUi(inward);

        QMetaObject::connectSlotsByName(inward);
    } // setupUi

    void retranslateUi(QMainWindow *inward)
    {
        inward->setWindowTitle(QCoreApplication::translate("inward", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("inward", "WareWise", nullptr));
        label_2->setText(QCoreApplication::translate("inward", "Inward Entry Platform", nullptr));
        label_3->setText(QCoreApplication::translate("inward", "Lot No.", nullptr));
        label_5->setText(QCoreApplication::translate("inward", "Date", nullptr));
        label_7->setText(QCoreApplication::translate("inward", "Lorry No.", nullptr));
        label_8->setText(QCoreApplication::translate("inward", "Trans Code", nullptr));
        label_9->setText(QCoreApplication::translate("inward", "Grade", nullptr));
        label_10->setText(QCoreApplication::translate("inward", "Bags", nullptr));
        weig->setText(QCoreApplication::translate("inward", "Weight", nullptr));
        label_12->setText(QCoreApplication::translate("inward", "Rate", nullptr));
        label_13->setText(QString());
        Insert->setText(QCoreApplication::translate("inward", "PUSH TO DB", nullptr));
        lot->setText(QString());
        lorry->setText(QString());
        tcode->setText(QString());
        bags->setText(QString());
        weight->setText(QString());
        rate->setText(QString());
        grade->setText(QString());
        exit->setText(QCoreApplication::translate("inward", "EXIT", nullptr));
        dashboard->setText(QCoreApplication::translate("inward", "BACK TO DASHBOARD", nullptr));
        newins->setText(QCoreApplication::translate("inward", "NEW INSERT", nullptr));
        labelResult->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class inward: public Ui_inward {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INWARD_H
