#ifndef OUTWARD_H
#define OUTWARD_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class outward;
}

class outward : public QMainWindow
{
    Q_OBJECT

public:
    explicit outward(QWidget *parent = nullptr);
    ~outward();
protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onInsertClicked();
    void onExitClicked();
    void onDashboardClicked();
private:
    Ui::outward *ui;
};

#endif // OUTWARD_H
