#include "datadisplay1.h"
#include "outward_data_option.h"
#include "ui_datadisplay1.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include "dashboard.h"
#include "QScrollArea"

datadisplay1::datadisplay1(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::datadisplay1),
    database(new SKQtRealTimeDatabase(this))
{
    ui->setupUi(this);
    setWindowTitle("Outward DATA DISPLAY WINDOW");

    // Create a central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create a vertical layout for the central widget
    QVBoxLayout *centralLayout = new QVBoxLayout(centralWidget);

    // Create buttons
    QPushButton *downloadCsvButton = new QPushButton("Download CSV", this);
    QPushButton *optionsButton = new QPushButton("Options", this);

    // Add buttons to the layout
    centralLayout->addWidget(downloadCsvButton);
    centralLayout->addWidget(optionsButton);

    // Create a QTableWidget
    tableView = new QTableWidget(this);
    tableView->setColumnCount(16);
    tableView->setHorizontalHeaderLabels({"Lot", "Name", "Dispatch to","Date", "DC", "Grade", "Lorry", "Transporter Code", "Bags", "Weight", "Rate", "Amount", "CGST", "SGST", "Frieght", "Total Amount"});

    // Add the table to the layout with a stretch factor
    centralLayout->addWidget(tableView, 1); // Stretch factor set to 1

    // Set the horizontal header resize mode
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    scrollArea = new QScrollArea(this);
    scrollArea->setWidget(tableView);
    scrollArea->setWidgetResizable(true);

    // Add the QScrollArea to the layout with a stretch factor
    centralLayout->addWidget(scrollArea, 1);

    // Connect signals to slots
    connect(downloadCsvButton, &QPushButton::clicked, this, &datadisplay1::downloadCsv);
    connect(optionsButton, &QPushButton::clicked, this, &datadisplay1::options);

    // Connect signals from inward_data_option to setRootUrl functions
    outward_data_option *outwardDataOption = new outward_data_option(this);
    connect(outwardDataOption, &outward_data_option::warehouseSelected, this, &datadisplay1::setRootUrlForWarehouse);
    connect(outwardDataOption, &outward_data_option::arwadeSelected, this, &datadisplay1::setRootUrlForArwade);
    connect(outwardDataOption, &outward_data_option::krishnaSelected, this, &datadisplay1::setRootUrlForKrishna);
    connect(outwardDataOption, &outward_data_option::othersSelected, this, &datadisplay1::setRootUrlForOthers);
    connect(outwardDataOption, &outward_data_option::unknownSelected, this, &datadisplay1::setRootUrlForUnknown);
    connect(outwardDataOption, &outward_data_option::officeSelected, this, &datadisplay1::setRootUrlForOffice);
    connect(this, &datadisplay1::hideprevwindow, outwardDataOption, &outward_data_option::hidewindow);

    outwardDataOption->show();
}

void datadisplay1::options(){
    dashboard *in1 = new dashboard(this);
    in1->show();
    this->hide();


}

void datadisplay1::display()
{
    // Clear existing rows in the table
    tableView->clearContents();
    tableView->setRowCount(0);
    QByteArray K1 = database->readData("");
    QJsonDocument K11 = QJsonDocument::fromJson(K1);
    QJsonObject K12 = K11.object();
    QStringList keys = K12.keys();
    int len = keys.length();
    for (int i=0;i<len;i++){
        QString num = keys[i];
        QJsonObject jsonObject = K12.value(num).toObject();
        QString lot = jsonObject.value("Lot").toString();
        QString name = jsonObject.value("Name").toString();
        QString dispatchTo = jsonObject.value("Dispatch").toString();
        QString date = jsonObject.value("Date").toString();
        QString dc = jsonObject.value("DC").toString();
        QString grade = jsonObject.value("Grade").toString();
        QString lorry = jsonObject.value("Lorry").toString();
        QString transporter = jsonObject.value("Transporter Code").toString();
        double bags = jsonObject.value("Bags").toInt();
        double weight = jsonObject.value("Weight").toDouble();
        double rate = jsonObject.value("Rate").toDouble();
        double amount = jsonObject.value("Amount").toDouble();
        double cgst = jsonObject.value("CGST").toDouble();
        double sgst = jsonObject.value("SGST").toDouble();
        double freight = jsonObject.value("Frieght").toDouble();
        double totalAmount = jsonObject.value("Total Amount").toDouble();
        //QString ewayBillNumber = jsonObject.value("EWAY BILL NUMBER").toString();

        // Add a new row to the table
        int row = tableView->rowCount();
        tableView->insertRow(row);
        lastRow = row;

        // Populate the table with data
        tableView->setItem(row, 0, new QTableWidgetItem(lot));
        tableView->setItem(row, 1, new QTableWidgetItem(name));
        tableView->setItem(row, 2, new QTableWidgetItem(dispatchTo));
        tableView->setItem(row, 3, new QTableWidgetItem(date));
        tableView->setItem(row, 4, new QTableWidgetItem(dc));
        tableView->setItem(row, 5, new QTableWidgetItem(grade));
        tableView->setItem(row, 6, new QTableWidgetItem(lorry));
        tableView->setItem(row, 7, new QTableWidgetItem(transporter));
        tableView->setItem(row, 8, new QTableWidgetItem(QString::number(bags,'f',2)));
        tableView->setItem(row, 9, new QTableWidgetItem(QString::number(weight,'f',2)));
        tableView->setItem(row, 10, new QTableWidgetItem(QString::number(rate,'f',2)));
        tableView->setItem(row, 11, new QTableWidgetItem(QString::number(amount,'f','2')));
        tableView->setItem(row, 12, new QTableWidgetItem(QString::number(cgst,'f',2)));
        tableView->setItem(row, 13, new QTableWidgetItem(QString::number(sgst,'f',2)));
        tableView->setItem(row, 14, new QTableWidgetItem(QString::number(freight,'f',2)));
        tableView->setItem(row, 15, new QTableWidgetItem(QString::number(totalAmount,'f',2)));


    }
}
void datadisplay1::exportToCsv(const QString &filePath, QTableWidget *tableWidget)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        // Writing header
        QStringList header;
        for (int i = 0; i < tableWidget->columnCount(); ++i)
        {
            header.append(tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString());
        }
        stream << header.join(",") << "\n";

        // Writing data
        for (int i = 0; i < tableWidget->rowCount(); ++i)
        {
            QStringList row;
            for (int j = 0; j < tableWidget->columnCount(); ++j)
            {
                row.append(tableWidget->item(i, j)->text());
            }
            stream << row.join(",") << "\n";
        }

        file.close();
        QMessageBox::information(nullptr, "Success", "CSV file saved successfully!");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to save CSV file!");
    }
}
void datadisplay1::downloadCsv(){

    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString suggestedFileName = "defWAREWISE.csv";

    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save CSV File", QDir(desktopPath).filePath(suggestedFileName), "CSV Files (*.csv)");
    if (!filePath.isEmpty())
    {
        exportToCsv(filePath, tableView);
    }
}
void datadisplay1::setRootUrlForWarehouse()
{
    database->setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Warehouse/");
    emit hideprevwindow();
    display();
}

void datadisplay1::setRootUrlForArwade()
{
    database->setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Mill/Arwade/");
    emit hideprevwindow();
    display();
}

void datadisplay1::setRootUrlForKrishna()
{
    database->setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Mill/Krishna/");
    emit hideprevwindow();
    display();
}

void datadisplay1::setRootUrlForOthers()
{
    database->setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Mill/Other/");
    emit hideprevwindow();
    display();
}

void datadisplay1::setRootUrlForUnknown()
{
    database->setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Unknown/");
    emit hideprevwindow();
    display();
}

void datadisplay1::setRootUrlForOffice()
{
    database->setDataRootUrl("https://suresh-kumar-satish-kumar-default-rtdb.asia-southeast1.firebasedatabase.app/Outward/Office/");
    emit hideprevwindow();
    display();
}
