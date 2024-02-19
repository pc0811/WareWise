#include "datadisplaywindow.h"
#include "inward_data_option.h"
#include "ui_datadisplaywindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include "dashboard.h"
#include "iostream"
#include <QScrollArea>
#include "reportgen.h"
#include "QFont"

DataDisplayWindow::DataDisplayWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::DataDisplayWindow),
    database(new SKQtRealTimeDatabase(this)),
    lastRow(-1)
{
    ui->setupUi(this);
    setWindowTitle("INWARD DATA DISPLAY WINDOW");

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
    tableView->setColumnCount(20);
    tableView->setHorizontalHeaderLabels({"AccesKey","Lot Number", "Name", "Date", "DC No.", "Lorry", "Bags", "Grade", "Weight", "Rate", "Amount", "Commission", "Container", "Bag Levy", "Weight Levy", "CGST", "SGST", "TOTAL AMOUNT", "Freight", "Transporter"});

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
    connect(downloadCsvButton, &QPushButton::clicked, this, &DataDisplayWindow::downloadCsv);
    connect(optionsButton, &QPushButton::clicked, this, &DataDisplayWindow::options);

    // Connect signals from inward_data_option to setRootUrl functions
    inward_data_option *inwardDataOption = new inward_data_option(this);
    connect(inwardDataOption, &inward_data_option::warehouseSelected, this, &DataDisplayWindow::setRootUrlForWarehouse);
    connect(inwardDataOption, &inward_data_option::arwadeSelected, this, &DataDisplayWindow::setRootUrlForArwade);
    connect(inwardDataOption, &inward_data_option::krishnaSelected, this, &DataDisplayWindow::setRootUrlForKrishna);
    connect(inwardDataOption, &inward_data_option::othersSelected, this, &DataDisplayWindow::setRootUrlForOthers);
    connect(inwardDataOption, &inward_data_option::unknownSelected, this, &DataDisplayWindow::setRootUrlForUnknown);
    connect(inwardDataOption, &inward_data_option::officeSelected, this, &DataDisplayWindow::setRootUrlForOffice);
    connect(this, &DataDisplayWindow::hideprevwindow, inwardDataOption, &inward_data_option::hidewindow);

    inwardDataOption->show();
}

void DataDisplayWindow::options()
{
    dashboard *in1 = new dashboard(this);
    in1->show();
    this->hide();
}

void DataDisplayWindow::display()
{
    QString prevdc =  "";
    QString tempdc = "";
    tableView->clearContents();
    tableView->setRowCount(0);
    QByteArray K1 = database->readData("");
    QJsonDocument K11 = QJsonDocument::fromJson(K1);
    QJsonObject K12 = K11.object();
    QStringList keys = K12.keys();
    double totbags = 0;
    double totweight = 0;
    double totamt = 0;
    double agg_amt = 0;

    int len = keys.length();
    for (int i=0;i<len;i++){
        QString num = keys[i];
        QJsonObject jsonObject = K12.value(num).toObject();
        if(i==0){
            tempdc=jsonObject.value("DC").toString();
        }
        QString dc = jsonObject.value("DC").toString();


        if (dc != tempdc) {
            int row = tableView->rowCount();
            tableView->insertRow(row);
            double avg = (totamt * 100) / totweight;

            for (int col = 0; col < tableView->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem();
                tableView->setItem(row, col, item);

                // Set the font for the entire row to bold
                QFont boldFont;
                boldFont.setBold(true);
                item->setFont(boldFont);

                // Set text for specific columns
                if (col == 5) {
                    item->setText("TOTAL:::");
                } else if (col == 6) {
                    item->setText(QString::number(totbags, 'f', 2));
                } else if (col == 8) {
                    item->setText(QString::number(totweight, 'f', 2));
                } else if (col == 9) {
                    item->setText(QString::number(avg, 'f', 2));
                } else if (col == 10) {
                    item->setText(QString::number(totamt, 'f', 2));
                } else if (col == 17) {
                    item->setText(QString::number(agg_amt, 'f', 2));
                } else {
                    // For other columns, set text to NULL or empty
                    item->setText("");
                }
            }

            tempdc = dc;
            totbags = 0;
            totweight = 0;
            totamt = 0;
            agg_amt = 0;

            // Leave the next row
            tableView->insertRow(row + 1);
        }
        QString lot = jsonObject.value("Lot").toString();
        QString name = jsonObject.value("Name").toString();
        QString date = jsonObject.value("Date").toString();
        QString grade = jsonObject.value("Grade").toString();
        QString lorry = jsonObject.value("Lorry").toString();
        QString transporter = jsonObject.value("Transporter Code").toString();
        double bags = jsonObject.value("Bags").toDouble();
        totbags += bags;
        double weight = jsonObject.value("Weight").toDouble();
        totweight += weight;
        double rate = jsonObject.value("Rate").toDouble();
        double amount = jsonObject.value("Amount").toDouble();
        totamt += amount;
        double commission = jsonObject.value("Commission").toDouble();
        double container = jsonObject.value("Container").toDouble();
        double bagLevy = jsonObject.value("Bag Levy").toDouble();
        double weightLevy = jsonObject.value("Weight Levy").toDouble();
        double cgst = jsonObject.value("CGST").toDouble();
        double sgst = jsonObject.value("SGST").toDouble();
        double freight = jsonObject.value("Freight").toDouble();
        double totalAmount = jsonObject.value("Total Amount").toDouble();
        agg_amt += totalAmount;

        // Add a new row to the table
        int row = tableView->rowCount();
        tableView->insertRow(row);
        //lastRow = row;

        // Populate the table with data
        tableView->setItem(row, 0, new QTableWidgetItem(num));

        tableView->setItem(row, 1, new QTableWidgetItem(lot));
        tableView->setItem(row, 2, new QTableWidgetItem(name));
        tableView->setItem(row, 3, new QTableWidgetItem(date));
        tableView->setItem(row, 4, new QTableWidgetItem(dc));
        tableView->setItem(row, 7, new QTableWidgetItem(grade));
        tableView->setItem(row, 5, new QTableWidgetItem(lorry));
        tableView->setItem(row, 19, new QTableWidgetItem(transporter));
        tableView->setItem(row, 6, new QTableWidgetItem(QString::number(bags,'f',0)));
        tableView->setItem(row, 8, new QTableWidgetItem(QString::number(weight,'f',2)));
        tableView->setItem(row, 9, new QTableWidgetItem(QString::number(rate,'f',2)));
        tableView->setItem(row, 10, new QTableWidgetItem(QString::number(amount,'f',2)));
        tableView->setItem(row, 11, new QTableWidgetItem(QString::number(commission,'f',2)));
        tableView->setItem(row, 12, new QTableWidgetItem(QString::number(container,'f',2)));
        tableView->setItem(row, 13, new QTableWidgetItem(QString::number(bagLevy,'f',2)));
        tableView->setItem(row, 14, new QTableWidgetItem(QString::number(weightLevy,'f',2)));
        tableView->setItem(row, 15, new QTableWidgetItem(QString::number(cgst,'f',2)));
        tableView->setItem(row, 16, new QTableWidgetItem(QString::number(sgst,'f',2)));
        tableView->setItem(row, 18, new QTableWidgetItem(QString::number(freight,'f',2)));
        tableView->setItem(row, 17, new QTableWidgetItem(QString::number(totalAmount,'f',2)));
        if(i==len-1){
            int row = tableView->rowCount();
            tableView->insertRow(row);
            double avg = (totamt * 100) / totweight;

            for (int col = 0; col < tableView->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem();
                tableView->setItem(row, col, item);

                // Set the font for the entire row to bold
                QFont boldFont;
                boldFont.setBold(true);
                item->setFont(boldFont);

                // Set text for specific columns
                if (col == 5) {
                    item->setText("TOTAL:::");
                } else if (col == 6) {
                    item->setText(QString::number(totbags, 'f', 2));
                } else if (col == 8) {
                    item->setText(QString::number(totweight, 'f', 2));
                } else if (col == 9) {
                    item->setText(QString::number(avg, 'f', 2));
                } else if (col == 10) {
                    item->setText(QString::number(totamt, 'f', 2));
                } else if (col == 17) {
                    item->setText(QString::number(agg_amt, 'f', 2));
                } else {
                    // For other columns, set text to NULL or empty
                    item->setText("");
                }
            }

            tempdc = dc;
            totbags = 0;
            totweight = 0;
            totamt = 0;
            agg_amt = 0;

            // Leave the next row
            tableView->insertRow(row + 1);
            //leave the next row
          }



        }
    }
void DataDisplayWindow::exportToCsv(const QString &filePath, QTableWidget *tableWidget){
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
                        row.append(item->text());
                    else{
                    }
                        //row.append("ERROR: No item at row " + QString::number(i) + ", column " + QString::number(j));
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

void DataDisplayWindow::downloadCsv(){

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
