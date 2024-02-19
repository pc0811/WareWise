#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QLabel>
namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
private slots:
    void onInwardClicked();
    void onOutwardClicked();
    void onData_InwardClicked();
    void onData_OutwardClicked();
    void onExitClicked();
    void onReportsClicked();
    void oninwardupdclicked();

private:
    Ui::dashboard *ui;
    QLabel *inwardLabel;

};

#endif // DASHBOARD_H
