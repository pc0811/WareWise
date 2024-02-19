#include "deletedata.h"
#include "ui_deletedata.h"
#include "reportgen.h"
#include "QMessageBox"
#include "dashboard.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>
deletedata::deletedata(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deletedata)
    ,database(new SKQtRealTimeDatabase(this))

{
    ui->setupUi(this);
    entrytype = "";

    connect(ui->del, &QPushButton::clicked, this, &deletedata::deleteclicked);
    //connect(ui->update, &QPushButton::clicked, this, &deletedata::updateclicked);
    connect(ui->next, &QPushButton::clicked, this, &deletedata::nextclicked);
    connect(ui->prev, &QPushButton::clicked, this, &deletedata::previousclicked);
    connect(ui->start, &QPushButton::clicked, this, &deletedata::firstclicked);
    connect(ui->end, &QPushButton::clicked, this, &deletedata::lastclicked);
    connect(ui->DEL2, &QPushButton::clicked, this, &deletedata::delfromkey);
    connect(ui->db, &QPushButton::clicked, this, &deletedata::backtodb);
    ReportGen *inwardDataOption = new ReportGen(this);
    connect(inwardDataOption, &ReportGen::warehouseSelected1, this, &deletedata::setRootUrlForWarehouse);
    connect(inwardDataOption, &ReportGen::arwadeSelected1, this, &deletedata::setRootUrlForArwade);
    connect(inwardDataOption, &ReportGen::krishnaSelected1, this, &deletedata::setRootUrlForKrishna);
    connect(inwardDataOption, &ReportGen::othersSelected1, this, &deletedata::setRootUrlForOthers);
    connect(inwardDataOption, &ReportGen::unknownSelected1, this, &deletedata::setRootUrlForUnknown);
    connect(inwardDataOption, &ReportGen::officeSelected1, this, &deletedata::setRootUrlForOffice);
    connect(this, &deletedata::hideprevwindow, inwardDataOption, &ReportGen::hidewindow);
    inwardDataOption->show();


}
void deletedata::backtodb(){
    dashboard *in1 = new dashboard(this);
    in1->show();
    this->hide();

}

deletedata::~deletedata()
{
    delete ui;
}
QStringList deletedata::setkeydata(){
    if(database.readData("").isEmpty()){
        QMessageBox::information(this,"ERROR","NO DATA FOUND");
        deletedata *in1 = new deletedata(this);
        in1->show();
        this->hide();
        QStringList nill = {};
        return nill;
    }
    else{
        QByteArray inwdb = database.readData("");
        QJsonDocument injson = QJsonDocument::fromJson(inwdb);
        inobj = injson.object();
        QStringList keysinw = inobj.keys();
        return keysinw;
    }


}
void deletedata::display(QString Value){

    ui->l1->clear();    ui->l2->clear(); ui->l3->clear();
    QJsonObject jsonObject = inobj.value(Value).toObject();
    QString M1 ="";    QString M2 =""; QString M3 ="";
    QString dc = jsonObject.value("DC").toString();
    QString name = jsonObject.value("Name").toString();
    QString date = jsonObject.value("Date").toString();
    QString lorry = jsonObject.value("Lorry").toString();
    double bags = jsonObject.value("Bags").toDouble();
    double weight = jsonObject.value("Weight").toDouble();
    double rate = jsonObject.value("Rate").toDouble();
    double cgst = jsonObject.value("CGST").toDouble();
    if(cgst==0.0){
        M1 = M1+"Srno.="+QString::number(i+1)+" GST => NO ";
    }
    else{
        M1 = M1+"Srno.="+QString::number(i+1)+" GST => YES ";

    }
    M1 += "DC = " +dc + " Party Name : "+name;
    M2 += "Lorry = "+lorry + " Date =>" +date;
    M3 += "Bags = "+QString::number(bags)+" Weight = "+QString::number(weight)+" Rate => "+QString::number(rate);
    ui->l1->setText(M1);ui->l2->setText(M2);ui->l3->setText(M3);

}
void deletedata::nextclicked(){
    QStringList lastkey = setkeydata();
    i = lastkey.indexOf(lastval);
    if(lastval==lastkey.last()){
        QMessageBox::information(this,"ERROR","ALREADY THE LAST ENTERED DATA");


    }
    else{
        i=i+1;
        lastval = lastkey[i];
        display(lastval);

    }


}
void deletedata::delfromkey(){
    QString inputValue = QInputDialog::getText(this, "Input Dialog", "Enter Access Key:", QLineEdit::Normal, "");
    QStringList lastkey = setkeydata();
    if(lastkey.contains(inputValue)){
        lastval = inputValue;
        deleteclicked();
    }




}
void deletedata::previousclicked(){
    QStringList lastkey = setkeydata();
    i = lastkey.indexOf(lastval)    ;
    if(lastval==lastkey.first()){
        QMessageBox::information(this,"ERROR","ALREADY THE FIRST ENTERED DATA");


    }
    else{
        i=i-1;
        lastval = lastkey[i];
        display(lastval);

    }


}
void deletedata::deleteclicked(){
    QStringList lastkey = setkeydata();
    //int num = lastkey.length();
    bool ok = (lastval==lastkey.first());
    QString currdel = lastval;
    if(ok){
        nextclicked();
    }
    else{
        previousclicked();

    }
    database.deleteData(currdel);
    QMessageBox::information(this,"SUCCESS","DATA DELETED");

}
void deletedata::firstclicked(){
    QStringList lastkey = setkeydata();
    lastval = lastkey.first();
    display(lastval);
    i=1;

}
void deletedata::lastclicked(){
    QStringList lastkey = setkeydata();
    lastval = lastkey.last();
    i=lastkey.length()-1;

    display(lastval);

}
void deletedata::setRootUrlForWarehouse()
{
    database.setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Warehouse/");



    emit hideprevwindow();
    QStringList lastkey = setkeydata();
    lastval = lastkey.last();
    i=lastkey.length()-1;
    display(lastval);

}

void deletedata::setRootUrlForArwade()
{
    database.setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Arwade");



    emit hideprevwindow();
    QStringList lastkey = setkeydata();
     lastval = lastkey.last();
    i=lastkey.length()-1;

    display(lastval);
}

void deletedata::setRootUrlForKrishna()
{
    database.setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Krishna");



    emit hideprevwindow();
    QStringList lastkey = setkeydata();
     lastval = lastkey.last();
    i=lastkey.length()-1;

    display(lastval);
}

void deletedata::setRootUrlForOthers()
{
    database.setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Mill/Other");




    emit hideprevwindow();
    QStringList lastkey = setkeydata();
     lastval = lastkey.last();
    i=lastkey.length()-1;

    display(lastval);
}

void deletedata::setRootUrlForUnknown()
{
    database.setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Unknown");




    emit hideprevwindow();
    QStringList lastkey = setkeydata();
     lastval = lastkey.last();
    i=lastkey.length()-1;

    display(lastval);
}


void deletedata::setRootUrlForOffice()
{
    database.setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Inward/Office");




    emit hideprevwindow();
    QStringList lastkey = setkeydata();
     lastval = lastkey.last();
    i=lastkey.length()-1;

    display(lastval);
}


