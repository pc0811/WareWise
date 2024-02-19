#include <update.h>
#include "dashboard.h"
#include "ui_dashboard.h"
#include <QMessageBox>
#include <inward.h>
#include <outward.h>
#include "inward_data_option.h"
#include "datadisplaywindow.h"
#include "datadisplay1.h"
#include "ui_datadisplaywindow.h"
#include "datadisplaywindow1.h"
#include "deletedata.h"
dashboard::dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);
    connect(ui->inward, &QPushButton::clicked, this, &dashboard::onInwardClicked);
    connect(ui->outward, &QPushButton::clicked, this,&dashboard::onOutwardClicked);
    connect(ui->updinw_2, &QPushButton::clicked, this, &dashboard::onData_InwardClicked);
    connect(ui->updinw, &QPushButton::clicked, this, &dashboard::oninwardupdclicked);

    connect(ui->data_outward, &QPushButton::clicked, this, &dashboard::onData_OutwardClicked);
    connect(ui->exit, &QPushButton::clicked, this, &dashboard::onExitClicked);
    connect(ui->genreport, &QPushButton::clicked, this, &dashboard::onReportsClicked);

    setWindowTitle("WareWise Dashboard");
}
dashboard::~dashboard()
{
    delete ui;
}
void dashboard::oninwardupdclicked(){
    QMessageBox::information(this, "UPDATE", "INWARD WAREHOUSE/MILL UPDATE PLATFORM IS READY");

    deletedata *dashboard1 = new deletedata(this);

    // Show the dashboard window
    dashboard1->show();

    // Close the current main window
    this->close();

}
void dashboard::onInwardClicked(){
    QMessageBox::information(this, "Inward", "INWARD WAREHOUSE/MILL ENTRY PLATFORM IS READY");

    inward *dashboard1 = new inward(this);

    // Show the dashboard window
    dashboard1->show();

    // Close the current main window
    this->close();



}
void dashboard::onOutwardClicked(){
    QMessageBox::information(this, "Outward", "OUTWARD WAREHOUSE/MILL ENTRY PLATFORM IS READY");

    outward *dashboard2 = new outward(this);

    // Show the dashboard window
    dashboard2->show();

    // Close the current main window
    this->close();



}
void dashboard::onData_InwardClicked(){
    QMessageBox::information(this, "INWARD DATA DISPLAY", "INWARD DATA DISPLAY PLATFORM IS READY");


    DataDisplayWindow *d1 = new DataDisplayWindow(this);
    d1->show();
    this->close();


}
void dashboard::onData_OutwardClicked(){
    QMessageBox::information(this, "OUTWARD DATA DISPLAY", "OUTWARD DATA DISPLAY PLATFORM IS READY");

    datadisplay1 *dashboard1 = new datadisplay1(this);

    // Show the dashboard window
    dashboard1->show();

    // Close the current main window
    this->close();



}

void dashboard::onExitClicked(){
    QMessageBox::information(this, "EXIT", "Thank You for using WareWise , Have a nice day !");
    // Close the current main window
    this->close();



}
void dashboard::onReportsClicked(){
    QMessageBox::information(this, "SUMMARY REPORT DISPLAY", "SUMMARY DATA DISPLAY PLATFORM IS READY");

    DataDisplayWindow1 *dbw1 = new DataDisplayWindow1(this);
    dbw1->show();
    this->close();


}
