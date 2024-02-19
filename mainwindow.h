#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "skqtauth.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onSigninClicked();
    void onExitClicked();

    //void onSignupClicked();
    void onAuthSuccess();
    void onAuthError();

private:
    Ui::MainWindow *ui;
    QString qEmail;
    QString qPassword;
    SKQtAuth skQtAuth; // Declare SKQtAuth as a member

};
#endif // MAINWINDOW_H
