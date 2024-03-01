#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "skqtauth.h"
#include "QString"
#include "QMessageBox"
#include "dashboard.h"
#include "skqtrealtimedatabase.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    skQtAuth(this)  // Create SKQtAuth instance as a member of MainWindow
{
    ui->setupUi(this);

    connect(ui->signin, &QPushButton::clicked, this, &MainWindow::onSigninClicked);
    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    //connect(ui->signup, &QPushButton::clicked, this, &MainWindow::onSignupClicked);
    setWindowTitle("WareWise Version 1.0");


    // Set the API key during program initialization
    QString apiKey = "YOUR API KEY";
    skQtAuth.setApiKey(apiKey);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSigninClicked(){
    qEmail = ui->email->text();
    qPassword = ui->passkey->text();

    // Connect SKQtAuth signals to MainWindow slots
    connect(&skQtAuth, &SKQtAuth::successAuth, this, &MainWindow::onAuthSuccess);
    connect(&skQtAuth, &SKQtAuth::errorAuth, this, &MainWindow::onAuthError);

    // Use the existing SKQtAuth instance for sign-in
    skQtAuth.signInUser(qEmail, qPassword);
}



void MainWindow::onAuthSuccess() {
    // Handle successful authentication here
    QMessageBox::information(this, "Success", "Authentication successful");

    dashboard *dashboard1 = new dashboard(this);

    // Show the dashboard window
    dashboard1->show();

    // Close the current main window



}
void MainWindow::onExitClicked(){
    QMessageBox::information(this, "EXIT", "Thank You for using WareWise , Have a nice day !");
    // Close the current main window
    this->close();
}
void MainWindow::onAuthError() {
    // Handle authentication error here
    QMessageBox::warning(this, "Error", "Authentication failed");
}

