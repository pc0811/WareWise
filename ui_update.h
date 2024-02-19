/********************************************************************************
** Form generated from reading UI file 'update.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_update
{
public:
    QWidget *centralwidget;
    QComboBox *entrytype;
    QComboBox *location;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *bags;
    QLabel *label_5;
    QLineEdit *rate;
    QLabel *label_6;
    QLineEdit *weight;
    QLabel *label_7;
    QLineEdit *freight;
    QLabel *label_8;
    QLineEdit *eway;
    QPushButton *next;
    QPushButton *previous;
    QPushButton *up;
    QPushButton *exit;
    QLabel *label_9;
    QLineEdit *date;
    QLabel *label_10;

    void setupUi(QMainWindow *update)
    {
        if (update->objectName().isEmpty())
            update->setObjectName("update");
        update->resize(1397, 760);
        QPalette palette;
        QBrush brush(QColor(243, 243, 243, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(15, 15, 15, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush2(QColor(16, 16, 16, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        update->setPalette(palette);
        QFont font;
        font.setPointSize(20);
        update->setFont(font);
        centralwidget = new QWidget(update);
        centralwidget->setObjectName("centralwidget");
        entrytype = new QComboBox(centralwidget);
        entrytype->addItem(QString());
        entrytype->addItem(QString());
        entrytype->addItem(QString());
        entrytype->setObjectName("entrytype");
        entrytype->setGeometry(QRect(20, 50, 281, 51));
        QFont font1;
        font1.setPointSize(17);
        entrytype->setFont(font1);
        location = new QComboBox(centralwidget);
        location->addItem(QString());
        location->addItem(QString());
        location->addItem(QString());
        location->addItem(QString());
        location->addItem(QString());
        location->addItem(QString());
        location->addItem(QString());
        location->setObjectName("location");
        location->setGeometry(QRect(410, 50, 281, 51));
        location->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 181, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(480, 10, 181, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 250, 111, 51));
        name = new QLineEdit(centralwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(380, 250, 221, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 390, 101, 51));
        bags = new QLineEdit(centralwidget);
        bags->setObjectName("bags");
        bags->setGeometry(QRect(190, 400, 221, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1090, 400, 61, 51));
        rate = new QLineEdit(centralwidget);
        rate->setObjectName("rate");
        rate->setGeometry(QRect(1160, 400, 221, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(580, 400, 111, 51));
        weight = new QLineEdit(centralwidget);
        weight->setObjectName("weight");
        weight->setGeometry(QRect(700, 400, 221, 41));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(260, 540, 111, 51));
        freight = new QLineEdit(centralwidget);
        freight->setObjectName("freight");
        freight->setGeometry(QRect(380, 540, 221, 41));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(750, 530, 181, 51));
        eway = new QLineEdit(centralwidget);
        eway->setObjectName("eway");
        eway->setGeometry(QRect(930, 540, 221, 41));
        next = new QPushButton(centralwidget);
        next->setObjectName("next");
        next->setGeometry(QRect(900, 680, 171, 51));
        previous = new QPushButton(centralwidget);
        previous->setObjectName("previous");
        previous->setGeometry(QRect(110, 680, 171, 51));
        up = new QPushButton(centralwidget);
        up->setObjectName("up");
        up->setGeometry(QRect(510, 680, 171, 51));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(1210, 670, 171, 51));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(510, 150, 381, 71));
        QFont font2;
        font2.setPointSize(25);
        label_9->setFont(font2);
        date = new QLineEdit(centralwidget);
        date->setObjectName("date");
        date->setGeometry(QRect(980, 250, 221, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(870, 240, 111, 51));
        update->setCentralWidget(centralwidget);

        retranslateUi(update);

        QMetaObject::connectSlotsByName(update);
    } // setupUi

    void retranslateUi(QMainWindow *update)
    {
        update->setWindowTitle(QCoreApplication::translate("update", "MainWindow", nullptr));
        entrytype->setItemText(0, QCoreApplication::translate("update", "SELECT", nullptr));
        entrytype->setItemText(1, QCoreApplication::translate("update", "INWARD ENTRY UPDATE", nullptr));
        entrytype->setItemText(2, QCoreApplication::translate("update", "OUTWARD ENTRY UPDATE", nullptr));

        location->setItemText(0, QCoreApplication::translate("update", "SELECT", nullptr));
        location->setItemText(1, QCoreApplication::translate("update", "WAREHOUSE", nullptr));
        location->setItemText(2, QCoreApplication::translate("update", "KRISHNA MILL", nullptr));
        location->setItemText(3, QCoreApplication::translate("update", "ARWADE MILL", nullptr));
        location->setItemText(4, QCoreApplication::translate("update", "OTHER MILL", nullptr));
        location->setItemText(5, QCoreApplication::translate("update", "OFFICE", nullptr));
        location->setItemText(6, QCoreApplication::translate("update", "UNREG", nullptr));

        label->setText(QCoreApplication::translate("update", "ENTRY TYPE", nullptr));
        label_2->setText(QCoreApplication::translate("update", "LOCATION", nullptr));
        label_3->setText(QCoreApplication::translate("update", "  NAME ", nullptr));
        label_4->setText(QCoreApplication::translate("update", "BAGS", nullptr));
        label_5->setText(QCoreApplication::translate("update", "RATE", nullptr));
        label_6->setText(QCoreApplication::translate("update", "WEIGHT", nullptr));
        label_7->setText(QCoreApplication::translate("update", "FREIGHT", nullptr));
        label_8->setText(QCoreApplication::translate("update", "EWAY BILL NO.", nullptr));
        next->setText(QCoreApplication::translate("update", "NEXT", nullptr));
        previous->setText(QCoreApplication::translate("update", "PREVIOUS", nullptr));
        up->setText(QCoreApplication::translate("update", "UPDATE", nullptr));
        exit->setText(QCoreApplication::translate("update", "EXIT", nullptr));
        label_9->setText(QCoreApplication::translate("update", "UPDATE DATA PLATFORM", nullptr));
        label_10->setText(QCoreApplication::translate("update", "DATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class update: public Ui_update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_H
