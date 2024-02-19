#ifndef DATADISPLAY1_H
#define DATADISPLAY1_H

// datadisplaywindow.h


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
#include "QScrollArea"

namespace Ui {
class datadisplay1;
}

class datadisplay1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit datadisplay1(QWidget *parent = nullptr);

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
    Ui::datadisplay1 *ui;
    QScrollArea *scrollArea;


signals:
    void hideprevwindow();
};




#endif // DATADISPLAY1_H
