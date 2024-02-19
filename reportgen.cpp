// inward_data_option.cpp

#include "reportgen.h"
//#include "ui_inward_data_option.h"
#include "ui_reportgen.h"
#include "datadisplaywindow.h"  // Make sure this line is here

    ReportGen::ReportGen(QWidget *parent)
    : QMainWindow(parent),
ui(new Ui::ReportGen)
{
    ui->setupUi(this);
    connect(ui->wh, &QPushButton::clicked, this, &ReportGen::on_wh_clicked);
    connect(ui->arwade, &QPushButton::clicked, this, &ReportGen::on_arwade_clicked);
    connect(ui->krishna, &QPushButton::clicked, this, &ReportGen::on_krishna_clicked);
    connect(ui->other, &QPushButton::clicked, this, &ReportGen::on_others_clicked);
    connect(ui->unreg, &QPushButton::clicked, this, &ReportGen::on_unreg_clicked);
    connect(ui->office, &QPushButton::clicked, this, &ReportGen::on_office_clicked);
    setWindowTitle("WareWise Summary Report Platform");
}

ReportGen::~ReportGen()
{
    delete ui;
}

void ReportGen::on_wh_clicked()
{
    emit warehouseSelected1();
}

void ReportGen::on_arwade_clicked()
{
    emit arwadeSelected1();
}

void ReportGen::on_krishna_clicked()
{
    emit krishnaSelected1();
}

void ReportGen::on_others_clicked()
{
    emit othersSelected1();
}

void ReportGen::on_unreg_clicked()
{
    emit unknownSelected1();
}

void ReportGen::on_office_clicked()
{
    emit officeSelected1();
}
void ReportGen::hidewindow(){
    hide();
}
