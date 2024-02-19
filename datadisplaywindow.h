// datadisplaywindow.h

#ifndef DATADISPLAYWINDOW_H
#define DATADISPLAYWINDOW_H
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
class DataDisplayWindow;
}

class DataDisplayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataDisplayWindow(QWidget *parent = nullptr);

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

private:
    QTableWidget *tableView;
    int lastRow;
    SKQtRealTimeDatabase *database;
    QNetworkAccessManager networkManager;
    Ui::DataDisplayWindow *ui;
    QScrollArea *scrollArea;


signals:
    void hideprevwindow();
};

#endif // DATADISPLAYWINDOW_H
