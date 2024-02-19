#include "update.h"
#include "ui_update.h"
#include <QComboBox>
#include "skqtrealtimedatabase.h"
#include <QMessageBox>
#include <QDebug>
#include <QSet>

update::update(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::update),
    database(new SKQtRealTimeDatabase()),
    i(0),
    buttonClickResult(0)  // Initialize buttonClickResult to 0
// Initialize i to 0
{
    ui->setupUi(this);

    // Connect signal for entry type combo box change
    connect(ui->entrytype, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &update::entryType);

    // Connect signals for button clicks
    connect(ui->next, &QPushButton::clicked, this, &update::nextfunc);
    connect(ui->up, &QPushButton::clicked, this, &update::executeupdation);
    connect(ui->previous, &QPushButton::clicked, this, &update::previousfunc);
    connect(ui->exit, &QPushButton::clicked, this, &update::exitfunc);
}

update::~update()
{
    delete ui;
}

void update::nextfunc()
{
    if (i < keys.length() )
    {
        ++i;
        makeupdate();
    }
    else
    {
        QMessageBox::information(this, "UPDATE", "ALREADY THE LAST ENTRY");
    }
}

void update::executeupdation()
{
    QString newdate = ui->date->text();
    QString newname = ui->name->text();
    QString newbags = ui->bags->text();
    QString newweight = ui->weight->text();
    QString newrate = ui->rate->text();
    QString newfrieght = ui->freight->text();
    QString newEway = ui->eway->text();
    QJsonObject jsonObject1 = QJsonObject::fromVariantMap({
        {"Date", newdate},

        {"Name", newname},



        {"Bags", newbags.toDouble()},
        {"Weight", newweight.toDouble()},
        {"Rate", newrate.toDouble()},

        {"Amount", (newweight.toDouble()) * (newrate.toDouble()) / 100},
        {"Commission", (newweight.toDouble()) * (newrate.toDouble()) * 2.5 / 100},
        {"Container", newbags.toDouble() * 8},
        {"Bag Levy", newbags.toDouble() * 4.48 * 30 / 100},
        {"Weight Levy", newweight.toDouble() * 5 / 100 * 30 / 100},
        {"CGST", 0.0},
        {"SGST", 0.0},
        {"Frieght", newfrieght.toDouble()},
        {"Total Amount", 0.0},
        {"EWAY BILL NUMBER", newEway}


    });


    double totalAmount = jsonObject1["Amount"].toDouble() +
                         jsonObject1["Commission"].toDouble() +
                         jsonObject1["Container"].toDouble() +
                         jsonObject1["Bag Levy"].toDouble() +
                         jsonObject1["Weight Levy"].toDouble();

    jsonObject1["CGST"] = totalAmount * 2.5 / 100;
    jsonObject1["SGST"] = totalAmount * 2.5 / 100;
    jsonObject1["Total Amount"] = totalAmount + (totalAmount * 5 / 100) + jsonObject1["Frieght"].toDouble();
    database->put(num, jsonObject1.toVariantMap());
}

void update::previousfunc()
{
    if (i > 0)
    {
        --i;
        makeupdate();
    }
    else
    {
        QMessageBox::information(this, "UPDATE", "THIS IS THE FIRST ENTRY ALREADY");
    }
}

void update::exitfunc()
{
    close();
}

void update::makeupdate(){
    QByteArray K1 = database->readData("");
    QJsonDocument K11 = QJsonDocument::fromJson(K1);
    QJsonObject K12 = K11.object();
    QStringList keys = K12.keys();
    int len = keys.length();
    if (i < len && i >= 0){
        QString num = keys[i];
        QJsonObject jsonObject = K12.value(num).toObject();
        QString name = jsonObject.value("Name").toString();
        QString date = jsonObject.value("Date").toString();
        QString bags = jsonObject.value("Bags").toString();
        QString rate = jsonObject.value("Rate").toString();
        QString weight = jsonObject.value("Weight").toString();
        QString Eway = jsonObject.value("EWAY BILL NUMBER").toString();
        QString freight = jsonObject.value("Frieght").toString();
        QString lot = jsonObject.value("Lot").toString();
        QString dc = jsonObject.value("DC").toString();
        QString lorry = jsonObject.value("Lorry").toString();
        QString grade = jsonObject.value("Grade").toString();
        QString tcode = jsonObject.value("Transporter Code").toString();

        ui->name->setText(name);
        ui->date->setText(date);
        ui->bags->setText(bags);
        ui->weight->setText(weight);
        ui->rate->setText(rate);
        ui->freight->setText(freight);
        ui->eway->setText(Eway);

        QSet<QString> oldset;
        // Insert elements into the set
        oldset.insert(name);
        oldset.insert(date);
        oldset.insert(bags);
        oldset.insert(weight);
        oldset.insert(rate);
        oldset.insert(freight);
        oldset.insert(Eway);
    }
}


void update::entryType()
{
    QString selectedEntryType = ui->entrytype->currentText();
    QString selectedLocation = ui->location->currentText();
    if (selectedEntryType == "INWARD ENTRY UPDATE")
    {
        if (selectedLocation == "WAREHOUSE")
        {
            //https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Warehouse
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Warehouse/";
            database->setDataRootUrl(url);

            makeupdate();
            // Handle  for inward entry update in warehouse
        }
        else if (selectedLocation == "KRISHNA MILL")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Krishna/";
            database->setDataRootUrl(url);
            makeupdate();
        }
        else if (selectedLocation == "ARWADE MILL")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Arwade/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "OTHER MILL")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Other/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "OFFICE")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Office/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "UNREG")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Unknown/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else{
            QMessageBox::information(this,"Error","incorrect option");
        }
    }
    else if (selectedEntryType == "OUTWARD ENTRY UPDATE")
    {
        //https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Warehouse
        if (selectedLocation == "WAREHOUSE")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Warehouse/";
            database->setDataRootUrl(url);

            makeupdate();
            // Handle actions for inward entry update in warehouse
        }
        else if (selectedLocation == "KRISHNA MILL")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Mill/Krishna/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "ARWADE MILL")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Mill/Arwade/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "OTHER MILL")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Mill/Other/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "OFFICE")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Office/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        else if (selectedLocation == "UNREG")
        {
            QString url = "https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Unknown/";
            database->setDataRootUrl(url);

            makeupdate();
        }
        // Handle actions for outward entry update
    }
    else{
        QMessageBox::information(this,"Error","incorrect option");

    }
}
