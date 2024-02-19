// inward_data_option.cpp

#include "inward_data_option.h"
#include "ui_inward_data_option.h"
#include "datadisplaywindow.h"  // Make sure this line is here

inward_data_option::inward_data_option(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::inward_data_option)
{
    ui->setupUi(this);
    connect(ui->wh, &QPushButton::clicked, this, &inward_data_option::on_wh_clicked);
    connect(ui->arwade, &QPushButton::clicked, this, &inward_data_option::on_arwade_clicked);
    connect(ui->krishna, &QPushButton::clicked, this, &inward_data_option::on_krishna_clicked);
    connect(ui->others, &QPushButton::clicked, this, &inward_data_option::on_others_clicked);
    connect(ui->unreg, &QPushButton::clicked, this, &inward_data_option::on_unreg_clicked);
    connect(ui->office, &QPushButton::clicked, this, &inward_data_option::on_office_clicked);
    setWindowTitle("WareWise Inward Data Selection Platform");
}

inward_data_option::~inward_data_option()
{
    delete ui;
}

void inward_data_option::on_wh_clicked()
{
    emit warehouseSelected();
}

void inward_data_option::on_arwade_clicked()
{
    emit arwadeSelected();
}

void inward_data_option::on_krishna_clicked()
{
    emit krishnaSelected();
}

void inward_data_option::on_others_clicked()
{
    emit othersSelected();
}

void inward_data_option::on_unreg_clicked()
{
    emit unknownSelected();
}

void inward_data_option::on_office_clicked()
{
    emit officeSelected();
}
void inward_data_option::hidewindow(){
    hide();
}
