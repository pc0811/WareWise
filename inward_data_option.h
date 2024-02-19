// inward_data_option.h

#ifndef INWARD_DATA_OPTION_H
#define INWARD_DATA_OPTION_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui
{
class inward_data_option;
}

class inward_data_option : public QMainWindow
{
    Q_OBJECT

public:
    inward_data_option(QWidget *parent = nullptr);
    ~inward_data_option();
    void hidewindow();


signals:
    void warehouseSelected();
    void arwadeSelected();
    void krishnaSelected();
    void othersSelected();
    void unknownSelected();
    void officeSelected();

private slots:
    void on_wh_clicked();
    void on_arwade_clicked();
    void on_krishna_clicked();
    void on_others_clicked();
    void on_unreg_clicked();
    void on_office_clicked();


private:
    Ui::inward_data_option *ui;
};

#endif // INWARD_DATA_OPTION_H
