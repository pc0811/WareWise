#ifndef OUTWARD_DATA_OPTION_H
#define OUTWARD_DATA_OPTION_H

#include <QMainWindow>

namespace Ui {
class outward_data_option;
}

class outward_data_option : public QMainWindow
{
    Q_OBJECT

public:
    explicit outward_data_option(QWidget *parent = nullptr);
    ~outward_data_option();
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
    Ui::outward_data_option *ui;
};

#endif // OUTWARD_DATA_OPTION_H
