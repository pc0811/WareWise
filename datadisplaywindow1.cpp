#include "datadisplaywindow1.h"
#include "inward_data_option.h"
#include "ui_datadisplaywindow1.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <iostream>
#include <QScrollArea>
#include <QDateEdit>
#include <QDate>
#include "dashboard.h"
#include <QDebug>
#include <stack>
#include <reportgen.h>
DataDisplayWindow1::DataDisplayWindow1(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::DataDisplayWindow1),
    database1(new SKQtRealTimeDatabase(this)),
    db2(new SKQtRealTimeDatabase(this)),
    lastRow(-1)
{
    ui->setupUi(this);
    setWindowTitle("SUMMARY DATA DISPLAY WINDOW");

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
    tableView->setHorizontalHeaderLabels({"IN-Date", "IN-DC", "IN-Lorry", "IN-Bags", "CF AVG","AVG RATE","IN-Weight", "IN-Value", "OUT-Date", "Out-Loc", "PARTY NAME","Out-Lorry", "Out-Bags", "Out-Weight","Out-Rate","OUT-Value"});

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
    connect(downloadCsvButton, &QPushButton::clicked, this, &DataDisplayWindow1::downloadCsv);
    connect(optionsButton, &QPushButton::clicked, this, &DataDisplayWindow1::options);

    // Connect signals from inward_data_option to setRootUrl functions
    ReportGen *inwardDataOption = new ReportGen(this);
    connect(inwardDataOption, &ReportGen::warehouseSelected1, this, &DataDisplayWindow1::setRootUrlForWarehouse);
    connect(inwardDataOption, &ReportGen::arwadeSelected1, this, &DataDisplayWindow1::setRootUrlForArwade);
    connect(inwardDataOption, &ReportGen::krishnaSelected1, this, &DataDisplayWindow1::setRootUrlForKrishna);
    connect(inwardDataOption, &ReportGen::othersSelected1, this, &DataDisplayWindow1::setRootUrlForOthers);
    connect(inwardDataOption, &ReportGen::unknownSelected1, this, &DataDisplayWindow1::setRootUrlForUnknown);
    connect(inwardDataOption, &ReportGen::officeSelected1, this, &DataDisplayWindow1::setRootUrlForOffice);
    connect(this, &DataDisplayWindow1::hideprevwindow, inwardDataOption, &ReportGen::hidewindow);

    inwardDataOption->show();
}

void DataDisplayWindow1::options()
{
    dashboard *in1 = new dashboard(this);
    in1->show();
    this->hide();
}



void DataDisplayWindow1::display()
{
    QString date;
    QString lorry;
    QString dc;
    double grandbagtotal = 0;
    double grandweighttotal = 0;
    double grandamounttotal = 0;
    double grandoutbag = 0;
    double grandoutweight = 0;
    double grandoutamt = 0;

    QByteArray inwdb = database1->readData("");
    QJsonDocument injson = QJsonDocument::fromJson(inwdb);
    QJsonObject inobj = injson.object();
    QByteArray outwdb = db2->readData("");
    QJsonDocument outjson = QJsonDocument::fromJson(outwdb);
    QJsonObject outobj = outjson.object();
    QStringList keysinw = inobj.keys();
    QStringList keysout = outobj.keys();
    int leninw = keysinw.length();
    int lenout = keysout.length(); // outward
    double totbags = 0;
    double totweight = 0;
    double totamt = 0;
    QString tempdc = "";

    // Clear the existing data in the table
    tableView->clearContents();
    double cfavg =0;
    tableView->setRowCount(0);

    int row = 0;
    //QString tempdc = ""; // Initialize tempdc before the loop

    for (int i = 0; i < leninw; ++i) {
        QString num = keysinw[i];
        QJsonObject jsonObject = inobj.value(num).toObject();
        dc = jsonObject.value("DC").toString();


        if (i == 0) {
            tempdc = dc;
        }



        if (dc != tempdc) {
            // Insert data into the table

            tableView->insertRow(row);
            tableView->setItem(row, 0, new QTableWidgetItem(date));
            tableView->setItem(row, 1, new QTableWidgetItem(tempdc)); // Use tempdc here
            tableView->setItem(row, 2, new QTableWidgetItem(lorry));
            tableView->setItem(row, 3, new QTableWidgetItem(QString::number(totbags, 'f', 2)));
            cfavg = (grandamounttotal+totamt)*100/(grandweighttotal+totweight);
            tableView->setItem(row, 4, new QTableWidgetItem(QString::number(cfavg, 'f', 2)));

            tableView->setItem(row, 6, new QTableWidgetItem(QString::number(totweight, 'f', 2)));
            tableView->setItem(row, 5, new QTableWidgetItem(QString::number((totamt * 100) / totweight, 'f', 2)));
            tableView->setItem(row, 7, new QTableWidgetItem(QString::number(totamt, 'f', 2)));

            grandbagtotal += totbags;
            grandweighttotal += totweight;
            grandamounttotal += totamt;

            //tempdc = dc;
            cfavg = 0;
            totbags = 0;
            totweight = 0;
            totamt = 0;
            tempdc = dc;
            ++row; // Increment row for each inward row
        }


        //date = jsonObject.value("Date").toString();
        //lorry = jsonObject.value("Lorry").toString();
        dc = jsonObject.value("DC").toString();

        date = jsonObject.value("Date").toString();
        lorry = jsonObject.value("Lorry").toString();
        double bags = jsonObject.value("Bags").toDouble();
        totbags += bags;
        double weight = jsonObject.value("Weight").toDouble();
        totweight += weight;
        double amount = jsonObject.value("Amount").toDouble();
        totamt += amount;



        if (i == leninw - 1) {
            // Insert last row of inward data into the table
            tableView->insertRow(row);
            tableView->setItem(row, 0, new QTableWidgetItem(date));
            tableView->setItem(row, 1, new QTableWidgetItem(tempdc)); // Use tempdc here
            tableView->setItem(row, 2, new QTableWidgetItem(lorry));
            tableView->setItem(row, 3, new QTableWidgetItem(QString::number(totbags, 'f', 2)));
            cfavg = (grandamounttotal+totamt)*100/(grandweighttotal+totweight);
            tableView->setItem(row, 4, new QTableWidgetItem(QString::number(cfavg, 'f', 2)));

            tableView->setItem(row, 6, new QTableWidgetItem(QString::number(totweight, 'f', 2)));
            tableView->setItem(row, 5, new QTableWidgetItem(QString::number((totamt * 100) / totweight, 'f', 2)));
            tableView->setItem(row, 7, new QTableWidgetItem(QString::number(totamt, 'f', 2)));
            grandbagtotal += totbags;
            grandweighttotal += totweight;
            grandamounttotal += totamt;

            tempdc = dc;
            totbags = 0;
            cfavg= 0;
            totweight = 0;
            totamt = 0;
            ++row;  // Increment row for the last inward row
        }
    }

    row = 0; // Reset row variable for outward data

    for (int rowiter = 0; rowiter < lenout; ++rowiter) {
        QString keynum = keysout[rowiter];
        QJsonObject js1 = outobj.value(keynum).toObject();

        QString outdate = js1.value("Date").toString();
        QString outlorry = js1.value("Lorry").toString();
        QString dispatchTo = js1.value("Dispatch").toString();
        QString partyname = js1.value("Name").toString();
        double outbags = js1.value("Bags").toDouble();
        double outweight = js1.value("Weight").toDouble();
        double outamt = js1.value("Amount").toDouble();
        double avg1 = (outamt * 100) / outweight;

        // Insert outward data into the table
        //tableView->insertRow(row);
        tableView->setItem(row, 8, new QTableWidgetItem(outdate));
        tableView->setItem(row, 9, new QTableWidgetItem(dispatchTo));
        tableView->setItem(row, 10, new QTableWidgetItem(partyname));
        tableView->setItem(row, 11, new QTableWidgetItem(outlorry));
        tableView->setItem(row, 12, new QTableWidgetItem(QString::number(outbags, 'f', 2)));
        tableView->setItem(row, 13, new QTableWidgetItem(QString::number(outweight, 'f', 2)));
        tableView->setItem(row, 14, new QTableWidgetItem(QString::number(avg1, 'f', 2)));
        tableView->setItem(row, 15, new QTableWidgetItem(QString::number(outamt, 'f', 2)));

        grandoutbag += outbags;
        grandoutweight += outweight;
        grandoutamt += outamt;

        ++row;  // Increment row for each outward row
    }

    // Insert "TOTAL:::" row into the table
    int totalRow = tableView->rowCount();
    tableView->insertRow(totalRow);

    for (int col = 0; col < tableView->columnCount(); ++col) {
        QTableWidgetItem *item = new QTableWidgetItem();
        tableView->setItem(totalRow, col, item);
        QFont boldFont;
        boldFont.setBold(true);

        if (col == 2 || col == 11) {
            item->setText("TOTAL:::");
        } else if (col == 3) {
            item->setText(QString::number(grandbagtotal, 'f', 2));
        } else if (col == 5) {
            item->setText(QString::number((grandamounttotal * 100 / grandweighttotal), 'f', 2));
        } else if (col == 6) {
            item->setText(QString::number(grandweighttotal, 'f', 2));
        } else if (col == 7) {
            item->setText(QString::number(grandamounttotal, 'f', 2));
        } else if (col == 12) {
            item->setText(QString::number(grandoutbag, 'f', 2));
        } else if (col == 14) {
            item->setText(QString::number((grandoutamt * 100 / grandoutweight), 'f', 2));
        } else if (col == 13) {
            item->setText(QString::number(grandoutweight, 'f', 2));
        } else if (col == 15) {
            item->setText(QString::number(grandoutamt, 'f', 2));
        } else {
            item->setText("");
        }

        item->setFont(boldFont);
    }
    QFont boldFont;
    boldFont.setBold(true);

    // Increment row for comparison, cumulative summary, and balance/shortages rows
    int comparisonRow = tableView->rowCount();
    tableView->insertRow(comparisonRow);
    //Cumulative summary
    tableView->setItem(comparisonRow, 8, new QTableWidgetItem("CUMULATIVE SUMMARY"));
    comparisonRow +=1;
    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 6, new QTableWidgetItem("Inward"));
    tableView->setItem(comparisonRow, 9, new QTableWidgetItem("Outward"));
    comparisonRow +=1;

    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 5, new QTableWidgetItem("Total Bags"));
    tableView->setItem(comparisonRow, 6, new QTableWidgetItem(QString::number(grandbagtotal, 'f', 2)));
    tableView->setItem(comparisonRow, 9, new QTableWidgetItem("Total Bags"));
    tableView->setItem(comparisonRow, 10, new QTableWidgetItem(QString::number(grandoutbag, 'f', 2)));
    comparisonRow +=1;

    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 5, new QTableWidgetItem("Total Weight"));
    tableView->setItem(comparisonRow, 6, new QTableWidgetItem(QString::number(grandweighttotal, 'f', 2)));
    tableView->setItem(comparisonRow, 9, new QTableWidgetItem("Total Weight"));
    tableView->setItem(comparisonRow, 10, new QTableWidgetItem(QString::number(grandoutweight, 'f', 2)));
    comparisonRow +=1;

    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 5, new QTableWidgetItem("Total Amount"));
    tableView->setItem(comparisonRow, 6, new QTableWidgetItem(QString::number(grandamounttotal, 'f', 2)));
    tableView->setItem(comparisonRow, 9, new QTableWidgetItem("Total Amount"));
    tableView->setItem(comparisonRow, 10, new QTableWidgetItem(QString::number(grandoutamt, 'f', 2)));
    comparisonRow +=1;

    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 5, new QTableWidgetItem("AVG RATE"));
    tableView->setItem(comparisonRow, 6, new QTableWidgetItem(QString::number((grandamounttotal * 100 / grandweighttotal), 'f', 2)));
    tableView->setItem(comparisonRow, 9, new QTableWidgetItem("AVG RATE"));
    tableView->setItem(comparisonRow, 10, new QTableWidgetItem(QString::number((grandoutamt * 100 / grandoutweight), 'f', 2)));
    comparisonRow +=1;

    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 8, new QTableWidgetItem("BALANCE/SHORTAGES"));
    comparisonRow +=1;

    tableView->insertRow(comparisonRow);
    tableView->setItem(comparisonRow, 5, new QTableWidgetItem("BAGS"));
    tableView->setItem(comparisonRow, 6, new QTableWidgetItem(QString::number((grandbagtotal-grandoutbag), 'f', 2)));
    tableView->setItem(comparisonRow, 8, new QTableWidgetItem("WEIGHT"));
    tableView->setItem(comparisonRow, 9, new QTableWidgetItem(QString::number((grandweighttotal-grandoutweight), 'f', 2)));
    tableView->setItem(comparisonRow, 11, new QTableWidgetItem("AMOUNT"));
    tableView->setItem(comparisonRow, 12, new QTableWidgetItem(QString::number((grandoutamt-grandamounttotal), 'f', 2)));
    comparisonRow +=1;









}


void DataDisplayWindow1::exportToCsv(const QString &filePath, QTableWidget *tableWidget)
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
                QTableWidgetItem *item = tableWidget->item(i, j);
                if (item)
                {
                    // Handle empty cells
                    QString text = item->text().isEmpty() ? " " : item->text();
                    row.append(text);
                }
                else
                {
                    // Handle empty cells
                    row.append(" ");
                }
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


void DataDisplayWindow1::downloadCsv()
{

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
    database->setDataRootUrl("YOUR DATABASE LINK FOR WAREHOUSE");
    emit hideprevwindow();
    display();
}



void datadisplay1::setRootUrlForOthers()
{
    database->setDataRootUrl("YOUR DATABASE LINK FOR OTHER LOC
        ");
    emit hideprevwindow();
    display();
}
