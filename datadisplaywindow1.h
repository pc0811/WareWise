// datadisplaywindow.h

#ifndef DATADISPLAYWINDOW1_H
#define DATADISPLAYWINDOW1_H
class SKQtRealTimeDatabase;

#include "inward_data_option.h"
#include "skqtrealtimedatabase.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QScrollArea>


namespace Ui {
class DataDisplayWindow1;
}

class DataDisplayWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataDisplayWindow1(QWidget *parent = nullptr);

public slots:
    void display();
    void exportToCsv(const QString &filePath, QTableWidget *tableWidget);
    void downloadCsv();
    void setRootUrlForWarehouse();
    void setRootUrlForArwade();
    void setRootUrlForKrishna();
    void setRootUrlForOthers();
    void setRootUrlForUnknown();
    void setRootUrlForOffice();
    void options();
   // void insertRowToTableView(int row, const QString& date, const QString& dc, const QString& lorry,
                              //double totbagsIn, double totweightIn, double totamtIn,
                              //const QString& outdate, const QString& dispatchTo, const QString& outlorry,
                              //double totbagsOut, double totweightOut, double totamtOut);

private:
    QTableWidget *tableView;
    int lastRow;
    SKQtRealTimeDatabase *database1;  // Use unique_ptr for automatic memory management
    SKQtRealTimeDatabase * db2;
    QNetworkAccessManager networkManager;
    Ui::DataDisplayWindow1 *ui;
    QScrollArea *scrollArea;
    QString startDateString;
    QString endDateString;
    //double grandbagtotal = 0;
    //double grandweighttotal = 0;
    //double grandamounttotal = 0;
    //double grandoutbag= 0;
    //double grandoutweight = 0;
    //double grandoutamt = 0;


signals:
    void hideprevwindow();
};

#endif // DATADISPLAYWINDOW_H
