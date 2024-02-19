#include "inward.h"
#include "ui_inward.h"
#include "QMessageBox"
#include "dashboard.h"
#include "skqtrealtimedatabase.h"
#include "skqtstorage.h"
#include "skqtauth.h"
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonArray>
#include <QImageWriter>
#include "SKQtFirebase_global.h"
#include <QImageReader>
#include <algorithm>
#include <random>
#include "QInputDialog"
#include <iostream>
#include <string>
#include <QKeyEvent>
inward::inward(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inward)
{
    ui->setupUi(this);
    connect(ui->newins, &QPushButton::clicked, this, &inward::onnewInsertClicked);
    connect(ui->Insert, &QPushButton::clicked, this, &inward::onInsertClicked);

    connect(ui->dashboard, &QPushButton::clicked, this, &inward::onDashboardClicked);

    connect(ui->exit, &QPushButton::clicked, this, &inward::onExitClicked);
    ui->newins->setFocusPolicy(Qt::StrongFocus);
    ui->Insert->setFocusPolicy(Qt::StrongFocus);
    ui->dashboard->setFocusPolicy(Qt::StrongFocus);
    ui->exit->setFocusPolicy(Qt::StrongFocus);
    QWidget::setTabOrder(ui->dashboard, ui->lot);
    QWidget::setTabOrder(ui->lot, ui->dateEdit);
    QWidget::setTabOrder(ui->dateEdit, ui->lorry);
    QWidget::setTabOrder(ui->lorry, ui->tcode);
    QWidget::setTabOrder(ui->tcode, ui->grade);
    QWidget::setTabOrder(ui->grade, ui->bags);
    QWidget::setTabOrder(ui->bags, ui->weight);
    QWidget::setTabOrder(ui->weight, ui->rate);
    QWidget::setTabOrder(ui->rate, ui->Insert);
    QWidget::setTabOrder(ui->Insert, ui->newins);

    ui->Insert->setVisible(true);
    ui->Insert->setEnabled(false);  // Initially, enable the push button


    setWindowTitle("WareWise Inward Entry Platform");


}

void inward::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        if(ui->Insert->isVisible()){
            onInsertClicked();  // Call your Insert action
           // Call your newInsert action

        }
        // Handle Enter key press
    }
    else if (event->key() == Qt::Key_Escape)
    {
        if(ui->newins->isVisible()){
            onnewInsertClicked();  // Call your newInsert action

        }
        // Handle Escape key press
    }
    else
    {
        // Call the base class implementation for other key events
        QMainWindow::keyPressEvent(event);
    }
}

inward::~inward()
{
    delete ui;
}

void inward::onDashboardClicked(){

    dashboard *dashboard1 = new dashboard(this);

    // Show the dashboard window
    dashboard1->show();
    this->close();


}
void inward::onExitClicked(){
    QMessageBox::information(this, "EXIT", "Thank You for using WareWise , Have a nice day !");
    // Close the current main window
    this->close();
}
int inward::gstcheck(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Question", "IS THIS A GST BILL?",
                                  QMessageBox::Yes | QMessageBox::No);

    // Check the user's response
    if (reply == QMessageBox::Yes) {
        // User clicked Yes
        return 1;
    } else {
        // User clicked No or closed the message box
        return 0;
    }

}
int inward::localcheck(){
    QMessageBox msgBox;
    //QMessageBox msgBox;
    msgBox.setText("IS THIS LOCAL OR OMS PURCHASE?");

    QAbstractButton* localButton = msgBox.addButton("Local", QMessageBox::YesRole);
    QAbstractButton* omsButton = msgBox.addButton("OMS", QMessageBox::NoRole);

    msgBox.exec();

    if (msgBox.clickedButton() == localButton) {
        // User clicked Local
        return 0;
    } else {
        // User clicked OMS or closed the message box
        return 1;
    }

}
void inward::onInsertClicked(){
    //ui->Insert->setVisible(false);

    if (dep == "W" || dep == "w") {
        depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Warehouse";
        freight = 23.2;
    } else if (dep == "U" || dep == "u") {
        depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Unknown";
    }else if (dep == "K" || dep == "k") {
        depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Krishna";
        freight = 19.75;
    } else if (dep == "A" || dep == "a") {
        depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Arwade";
        freight = 19.75;
    } else if (dep == "OM" || dep == "om" || dep == "Om" || dep == "Other" || dep == "other" || dep == "O" || dep == "o") {
        depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Other";
        freight =19.75;
    } else if (dep == "OF" || dep == "of" || dep == "Of" || dep == "S" || dep == "s" || dep == "SKSK" || dep == "Office") {
        depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Office";
        freight = 18.25;
    } else {
        QMessageBox::information(this, "ERROR", "ENTER CORRECT DEPOSIT CODE");
        return;
    }

    database.setDataRootUrl(depositUrl);
    QDate selectedDate = ui->dateEdit->date();
    QString date = selectedDate.toString("dd-MM-yyyy");
    QString lot;
    QByteArray outarr = database.readData("");
    QJsonDocument outjson = QJsonDocument::fromJson(outarr);
    QJsonObject outobj = outjson.object();
    QStringList keysinw = outobj.keys();
    if(keysinw.isEmpty()){
        lot = "1";
    }
    else{
        QString num = keysinw.last();
        QString prevlot = jsonObject.value("Lot").toString();
        int num1 = prevlot.toInt()+1;
        lot = QString::number(num1);


    }



    //QString dep = ui->dep->text();
    //QString date = ui->date->text();

    //lot = ui->lot->text();
    //QString name = ui->name->text();
    //QString dc = ui->dc->text();
    QString lorry = ui->lorry->text();
    QString tcode = ui->tcode->text();
    QString bags = ui->bags->text();
    QString weight = ui->weight->text();
    QString rate = ui->rate->text();
    QString grade = ui->grade->text();
    //QString frieght = ui->frieght->text();
    double amount = (weight.toDouble()) * (rate.toDouble()) / 100;


    // Convert QVariantMap to QJsonObject for proper JSON serialization
    jsonObject = QJsonObject::fromVariantMap({
        {"Date", date},
        {"Lot", lot},
        {"Name", name},
        {"DC", dcNumber},
        {"Lorry", lorry},
        {"Transporter Code", tcode},
        {"Bags", bags.toDouble()},
        {"Weight", weight.toDouble()},
        {"Rate", rate.toDouble()},
        {"Grade", grade},
        {"Amount", amount},
        {"Commission", amount * 2.5 / 100},
        {"Container", bags.toDouble() * 8},
        {"Bag Levy", bags.toDouble() * 4.48 * 30 / 100},
        {"Weight Levy", weight.toDouble() * 5 / 100 * 30 / 100},
        {"CGST", 0.0},
        {"SGST", 0.0},
        {"TOTAL GST PAID", 0.0},
        {"Freight", freight*(bags.toDouble())},
        {"Total Amount", 0.0},
        {"EWAY BILL NUMBER", QJsonValue::Null}
    });

    double totalAmount = 0;
    double gstcalc = 0;

    if(gstcheck1==1 && check==1){
        totalAmount=jsonObject["Amount"].toDouble();
        jsonObject["CGST"] = totalAmount * 2.5 / 100;
        jsonObject["SGST"] = totalAmount * 2.5 / 100;
        jsonObject["Commission"] =0;
        jsonObject["Container"] =0;
        jsonObject["Commission"] =0;

        gstcalc = totalAmount*5/100;
        //message = message + " || GST => YES";
        //ui->labelResult->setText(message);
    }
    //else if(gstcheck1==1 && check==1)
    else{
        jsonObject["CGST"]=0.0;
        jsonObject["SGST"]=0.0;
        //message = message + " ||  GST => NO";
        //ui->labelResult->setText(message);

    }
    totalAmount = jsonObject["Amount"].toDouble() +
                         jsonObject["Commission"].toDouble() +
                         jsonObject["Container"].toDouble() +
                         jsonObject["Bag Levy"].toDouble() +
                         jsonObject["Weight Levy"].toDouble();



    jsonObject["TOTAL GST PAID"] = totalAmount*5/100;
    jsonObject["Total Amount"] = totalAmount + (gstcalc);

    if (name == QString() || bags == QString() || weight == QString() || rate == QString()) {
        QMessageBox::information(this, "ERROR", "CHECK RATE, WEIGHT AND BAGS FIELDS");
        if (bags.isEmpty()) {
            ui->bags->setFocus();
        } else if (weight.isEmpty()) {
            ui->weight->setFocus();
        } else if (rate.isEmpty()) {
            ui->rate->setFocus();
        }
    }
    else {

        // Find the last key and increment it by 1
        // Generate a unique key using timestamp and a random number
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, 9999);
        int randomNumber = distribution(gen);
        QString newKey = QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + QString::number(randomNumber);
        //QString key1 = dcNumber + "/"+newKey;
        //QString postUrl = depositUrl + "/" + newKey;
        QVariantMap data = jsonObject.toVariantMap();
        database.put(newKey, data);
        QMessageBox::information(this, "SUCCESS", "Data added successfully!");

    QMessageBox::information(this, "SUCCESS", "Data added successfully!");
        ui->newins->setVisible(true);
       // ui->Insert->setVisible(false);


    //ui->dep->clear();
    //ui->date->clear();
    //ui->lot->clear();
    //ui->name->clear();
    //ui->dc->clear();
    ui->lorry->clear();
    ui->tcode->clear();
    ui->bags->clear();
    ui->weight->clear();
    ui->rate->clear();
    ui->grade->clear();
    //ui->frieght->clear();

 }
}
void inward::onnewInsertClicked() {
    ui->Insert->setVisible(true);

    message = "";
    ui->labelResult->setText(message);

    QMessageBox::StandardButton reply;
    dcNumber = QInputDialog::getText(this, "DC Number", "Enter DC Number:", QLineEdit::Normal, "", nullptr, Qt::WindowFlags());
    dep = QInputDialog::getText(this, "Deposit Location", "Enter Deposit Location : ", QLineEdit::Normal, "", nullptr, Qt::WindowFlags());

    if(!dcNumber.isEmpty()&&!dep.isEmpty()){
        QString str = dcNumber;
        QMessageBox::information(this, "INWARD", "Making Inward Entry With Dc Number "+str);
        reply = QMessageBox::question(this, "Name Confirmation", "DO YOU WANT TO USE THE SAME PARTY NAME FOR THIS LOT ??",
                                      QMessageBox::Yes|QMessageBox::No);
        // Set depositUrl based on dep value
        if (dep == "W" || dep == "w") {
            depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Warehouse";
            freight = 4.2;
        } else if (dep == "U" || dep == "u") {
            depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Unknown";
        }else if (dep == "K" || dep == "k") {
            depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Krishna";
            freight = 3.2;
        } else if (dep == "A" || dep == "a") {
            depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Arwade";
            freight = 3.2;
        } else if (dep == "OM" || dep == "om" || dep == "Om" || dep == "Other" || dep == "other" || dep == "O" || dep == "o") {
            depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Other";
            freight = 3.2;
        } else if (dep == "OF" || dep == "of" || dep == "Of" || dep == "S" || dep == "s" || dep == "SKSK" || dep == "Office") {
            depositUrl = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Office";
            freight = 2.2;
        } else {
            QMessageBox::information(this, "ERROR", "ENTER CORRECT DEPOSIT CODE");
            return;
        }
        database.setDataRootUrl(depositUrl);



        if (reply == QMessageBox::Yes) {
            QByteArray K1 = database.readData("");
            QJsonDocument K11 = QJsonDocument::fromJson(K1);
            QJsonObject K12 = K11.object();
            QStringList keys = K12.keys();
            QString endkey = keys.last();



            // Set data root URL for the database
           // QString keyset = dcNumber;
            if (QJsonDocument::fromJson(database.readData(endkey)).isEmpty()){
                QMessageBox::information(this, "ERROR", "The Delivery Challan has no previous Entries , Enter Party Name Manually");
                do {
                    name = QInputDialog::getText(this, "Name", "Enter Party Name:", QLineEdit::Normal, "", nullptr, Qt::WindowFlags());
                } while (name.isEmpty());
            }
            else{

                QJsonObject jsonObject = K12.value(endkey).toObject();
                QString addname = jsonObject.value("Name").toString();
                reply = QMessageBox::question(this, "Name Confirmation", "DO YOU WANT TO USE PARTY NAME AS "+addname+" ?",
                                              QMessageBox::Yes|QMessageBox::No);
                if(reply == QMessageBox::Yes){
                    name = addname ;
                }
                else{
                    do {
                        name = QInputDialog::getText(this, "Name", "Enter Party Name:", QLineEdit::Normal, "", nullptr, Qt::WindowFlags());
                    } while (name.isEmpty());
                }


            }

        }
        else{
            // User does not want to use the same name
            // You can handle this case accordingly
            do {
                name = QInputDialog::getText(this, "Name", "Enter Party Name:", QLineEdit::Normal, "", nullptr, Qt::WindowFlags());
            } while (name.isEmpty());


        }
        message = "DC Number " + dcNumber + "||  Name: " + name + "     ||  Deposit to: " + dep;
        gstcheck1 = 0;
        check = localcheck();

        gstcheck1 = gstcheck();
        if(gstcheck1 == 1){
            message += "GST INCL";
        }
        else{
            message += "NON GST";

        }
        ui->labelResult->setText(message);


        //ui->dep->clear();
        //ui->date->clear();
        //ui->lot->clear();
        //ui->name->clear();
        //ui->dc->clear();
        ui->lorry->clear();
        ui->tcode->clear();
        ui->bags->clear();
        ui->weight->clear();
        ui->rate->clear();
        ui->grade->clear();
        //ui->frieght->clear();
        ui->newins->setVisible(false);
        ui->Insert->setEnabled(true);






            // Clear UI fields


        }
    else{
        QMessageBox::information(this, "ERROR", "DC NUMBER OR DEPOSIT LOCATION CANT BE EMPTY");

    }
    // Read existing data from the database

}









