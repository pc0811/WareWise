#ifndef DELETEDATA_H
#define DELETEDATA_H

#include <QMainWindow>
#include "skqtrealtimedatabase.h"
#include <QJsonObject>
namespace Ui {
class deletedata;
}

class deletedata : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletedata(QWidget *parent = nullptr);
    ~deletedata();
private slots :
    void deleteclicked();
    void nextclicked();
    void previousclicked();
    void firstclicked();
    void lastclicked();
    void delfromkey();
    void backtodb();
    void setRootUrlForWarehouse();
    void setRootUrlForArwade();
    void setRootUrlForKrishna();
    void setRootUrlForOthers();
    void setRootUrlForUnknown();
    void setRootUrlForOffice();
    void display(QString Value);
    QStringList setkeydata();
private:
    Ui::deletedata *ui;
    SKQtRealTimeDatabase database;
    int i = 0;
    QString lastval = "";
    QJsonObject inobj;
    QString entrytype = "";
    int checker = 0;

signals:
    void hideprevwindow();
};

#endif // DELETEDATA_H
