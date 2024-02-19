#ifndef INWARD_H
#define INWARD_H

#include <QMainWindow>
#include "skqtrealtimedatabase.h"
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonArray>
#include "QLabel"
#include <QKeyEvent>

namespace Ui {
class inward;
}

class inward : public QMainWindow
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *event) override;
public:
    explicit inward(QWidget *parent = nullptr);
    ~inward();
private slots:
    void onInsertClicked();
    void onExitClicked();
    void onDashboardClicked();
    void  onnewInsertClicked();
    int gstcheck();
    int localcheck();


private:
    Ui::inward *ui;
    QString depositUrl = "";
    QString postUrl ="";
    double freight = 0 ;
    QJsonObject jsonObject;
    SKQtRealTimeDatabase database;
    QString name = "";
    QString dep = "";
    QString dcNumber = "";
    QLabel *labelResult;
    QString message ="";
    int check=0;
    int gstcheck1  =0;

};

#endif // INWARD_H
