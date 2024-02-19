#ifndef REPORTGEN_H
#define REPORTGEN_H

#include <QMainWindow>

namespace Ui {
class ReportGen;
}

class ReportGen : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReportGen(QWidget *parent = nullptr);
    ~ReportGen();
    void hidewindow();

signals:
    void warehouseSelected1();
    void arwadeSelected1();
    void krishnaSelected1();
    void othersSelected1();
    void unknownSelected1();
    void officeSelected1();
private slots:
    void on_wh_clicked();
    void on_arwade_clicked();
    void on_krishna_clicked();
    void on_others_clicked();
    void on_unreg_clicked();
    void on_office_clicked();
private:
    Ui::ReportGen *ui;
};

#endif // REPORTGEN_H
