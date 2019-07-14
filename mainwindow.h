#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <addstu.h>
#include <QMainWindow>
#include <querystu.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
    addStu a;

};

#endif // MAINWINDOW_H
