/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *title;
    QLabel *label;
    QPushButton *signin;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *email;
    QLineEdit *passkey;
    QPushButton *exit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1134, 663);
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Gabriola")});
        font.setPointSize(48);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(350, 60, 491, 91));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gabriola")});
        font1.setPointSize(74);
        title->setFont(font1);
        title->setLayoutDirection(Qt::LeftToRight);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 160, 391, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gabriola")});
        font2.setPointSize(26);
        label->setFont(font2);
        signin = new QPushButton(centralwidget);
        signin->setObjectName("signin");
        signin->setGeometry(QRect(390, 420, 271, 51));
        QPalette palette1;
        QBrush brush2(QColor(157, 157, 157, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(139, 139, 139, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(250, 250, 250, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        signin->setPalette(palette1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Liberation Mono")});
        font3.setPointSize(31);
        signin->setFont(font3);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 250, 141, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Gabriola")});
        font4.setPointSize(30);
        label_2->setFont(font4);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 340, 131, 31));
        label_3->setFont(font4);
        email = new QLineEdit(centralwidget);
        email->setObjectName("email");
        email->setGeometry(QRect(480, 250, 341, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Times New Roman")});
        font5.setPointSize(20);
        email->setFont(font5);
        passkey = new QLineEdit(centralwidget);
        passkey->setObjectName("passkey");
        passkey->setGeometry(QRect(480, 340, 341, 31));
        passkey->setFont(font5);
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(390, 490, 271, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        exit->setPalette(palette2);
        exit->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:72pt; color:#c4cf50;\">WareWise</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "SURESH KUMAR SATISH KUMAR ", nullptr));
        signin->setText(QCoreApplication::translate("MainWindow", "SIGN IN", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        passkey->setText(QString());
        exit->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
