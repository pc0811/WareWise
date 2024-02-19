

#include "outward_data_option.h"
#include "ui_outward_data_option.h"
#include "datadisplaywindow.h"  // Make sure this line is here

outward_data_option::outward_data_option(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::outward_data_option)
{
    ui->setupUi(this);
    connect(ui->wh, &QPushButton::clicked, this, &outward_data_option::on_wh_clicked);
    connect(ui->arwade, &QPushButton::clicked, this, &outward_data_option::on_arwade_clicked);
    connect(ui->krishna, &QPushButton::clicked, this, &outward_data_option::on_krishna_clicked);
    connect(ui->other, &QPushButton::clicked, this, &outward_data_option::on_others_clicked);
    connect(ui->unknown, &QPushButton::clicked, this, &outward_data_option::on_unreg_clicked);
    connect(ui->office, &QPushButton::clicked, this, &outward_data_option::on_office_clicked);
    setWindowTitle("WareWise Outward Data Selection Platform");
}

outward_data_option::~outward_data_option()
{
    delete ui;
}

void outward_data_option::on_wh_clicked()
{
    emit warehouseSelected();
}

void outward_data_option::on_arwade_clicked()
{
    emit arwadeSelected();
}

void outward_data_option::on_krishna_clicked()
{
    emit krishnaSelected();
}

void outward_data_option::on_others_clicked()
{
    emit othersSelected();
}

void outward_data_option::on_unreg_clicked()
{
    emit unknownSelected();
}

void outward_data_option::on_office_clicked()
{
    emit officeSelected();
}
void outward_data_option::hidewindow(){
    hide();
}
