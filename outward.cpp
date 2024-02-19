#include "outward.h"
#include "ui_outward.h"
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
outward::outward(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::outward)
{
    ui->setupUi(this);
    connect(ui->Insert, &QPushButton::clicked, this, &outward::onInsertClicked);
    connect(ui->dashboard, &QPushButton::clicked, this, &outward::onDashboardClicked);

    connect(ui->exit, &QPushButton::clicked, this, &outward::onExitClicked);

    //ui->Insert->setVisible(true);

    setWindowTitle("WareWise Outward Entry Platform");
    ui->Insert->setFocusPolicy(Qt::StrongFocus);
    ui->dashboard->setFocusPolicy(Qt::StrongFocus);
    ui->exit->setFocusPolicy(Qt::StrongFocus);
    QWidget::setTabOrder(ui->Insert, ui->lot);

    QWidget::setTabOrder(ui->lot, ui->name);
    QWidget::setTabOrder(ui->name, ui->dateEdit);
    QWidget::setTabOrder(ui->dateEdit, ui->dc);
    QWidget::setTabOrder(ui->dc, ui->lorry);
    QWidget::setTabOrder(ui->lorry, ui->tcode);
    QWidget::setTabOrder(ui->tcode, ui->bags);
    QWidget::setTabOrder(ui->bags, ui->weight);
    QWidget::setTabOrder(ui->weight, ui->rate);
    QWidget::setTabOrder(ui->rate, ui->grade);
    QWidget::setTabOrder(ui->grade, ui->frieght);
    QWidget::setTabOrder(ui->frieght, ui->dep);
    QWidget::setTabOrder(ui->dep, ui->dispatch);
    QWidget::setTabOrder(ui->dispatch, ui->Insert);




}

outward::~outward()
{
    delete ui;
}

void outward::onDashboardClicked(){

    dashboard *dashboard1 = new dashboard(this);

    // Show the dashboard window
    dashboard1->show();
    this->close();


}
void outward::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        if(ui->Insert->isVisible()){
            onInsertClicked();  // Call your Insert action

        }

        // Handle Enter key press
    }

    else
    {
        // Call the base class implementation for other key events
        QMainWindow::keyPressEvent(event);
    }
}
void outward::onExitClicked(){
    QMessageBox::information(this, "EXIT", "Thank You for using WareWise , Have a nice day !");
    // Close the current main window
    this->close();
}
void outward::onInsertClicked()
{
    //ui->Insert->setVisible(false);

    QDate selectedDate = ui->dateEdit->date();
    QString date = selectedDate.toString("dd-MM-yyyy");
    QString dep = ui->dep->text();
    //QString date = ui->date->text();
    QString lot = ui->lot->text();
    QString name = ui->name->text();
    QString dc = ui->dc->text();
    QString lorry = ui->lorry->text();
    QString tcode = ui->tcode->text();
    QString bags = ui->bags->text();
    QString weight = ui->weight->text();
    QString rate = ui->rate->text();
    QString grade = ui->grade->text();
    QString frieght = ui->frieght->text();
    QString dispatch = ui->dispatch->text();

    double d_rate = rate.toDouble();
    double d_weight = weight.toDouble();
    double d_bags = bags.toDouble();
    double d_frieght = frieght.toDouble();

    double amount = (d_weight) * d_rate / 100;

    QVariantMap data;
    data["Dispatch"] = dispatch;
    data["Date"] = date;
    data["Lot"] = lot;
    data["Name"] = name;
    data["DC"] = dc;
    data["Lorry"] = lorry;
    data["Transporter Code"] = tcode;
    data["Bags"] = d_bags;
    data["Weight"] = d_weight;
    data["Rate"] = d_rate;
    data["Grade"] = grade;
    data["Amount"] = amount;
    double t_amt = amount;
    data["CGST"] = t_amt * 2.5 / 100;
    data["SGST"] = t_amt * 2.5 / 100;
    data["Frieght"] = d_frieght;
    data["Total Amount"] = t_amt + (t_amt * 5 / 100) ;
    data["EWAY BILL NUMBER"] = QJsonValue::Null;

    if (name == QString() || bags == QString() || weight == QString() || rate == QString())
    {
        QMessageBox::information(this, "ERROR", "CHECK RATE, WEIGHT,  BAGS AND NAME FIELDS");
    }
    else if (dep == QString())
    {
        QMessageBox::information(this, "ERROR", "Warehouse/Mill LOCATION CODE IS EMPTY , It can't be Empty");
    }
    else
    {
        QString depositUrl = "";
        SKQtRealTimeDatabase database;

        if (dep == "W" || dep == "w")
        {
            depositUrl = "ENTER URL";
        }
        
        else
        {
            QMessageBox::information(this, "ERROR", "ENTER CORRECT DEPOSIT CODE");
            ui->dep->setFocus();
        }

        database.setDataRootUrl(depositUrl);

        QByteArray responseData = database.readData(depositUrl);
        QJsonDocument responseJson = QJsonDocument::fromJson(responseData);
        QJsonObject responseObj = responseJson.object();
        // Generate a unique key using timestamp and a random number
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, 9999);
        int randomNumber = distribution(gen);
        QString newKey = QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + QString::number(randomNumber);
        QString postUrl = depositUrl + "/" + newKey;
        QJsonObject jsonObject = QJsonObject::fromVariantMap(data);
        database.put(newKey, data);
        QMessageBox::information(this, "SUCCESS", "Data added successfully!");
        //ui->Insert->setVisible(true);

        ui->dep->clear();
        //ui->date->clear();
        ui->lot->clear();
        ui->name->clear();
        ui->dc->clear();
        ui->lorry->clear();
        ui->tcode->clear();
        ui->bags->clear();
        ui->weight->clear();
        ui->rate->clear();
        ui->grade->clear();
        ui->frieght->clear();
        ui->dispatch->clear();
    }
}

