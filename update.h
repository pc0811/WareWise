#ifndef UPDATE_H
#define UPDATE_H

#include <QMainWindow>
#include <QComboBox>
#include "skqtrealtimedatabase.h"
namespace Ui {
     class update;
}

class update : public QMainWindow
{
    Q_OBJECT

public:
    explicit update(QWidget *parent = nullptr);
    ~update();
private slots:
    void entryType();
    void makeupdate();
    void nextfunc();
    void executeupdation();
    void previousfunc();
    void exitfunc();
signals :
    void nextButton();
    void updatevals();
    void prevButton();
    void exitbut();
    void buttonClickedSignal();
private:
    Ui::update *ui;
    QComboBox *entrytype;
    QComboBox *location;
    SKQtRealTimeDatabase *database;
    void updateUI(int index, const QMap<QString, QVariantMap>& dataMap);

    QStringList keys; // Declare keys as a member variable
    int i;
    QString num ;   // Declare i as a member variable
    QMap<QString, QVariantMap> dataMap;
    int buttonClickResult;
    // Declare keysCopy at class level



};


#endif // UPDATE_H

