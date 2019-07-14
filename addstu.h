#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class addStu;
}

class addStu : public QDialog
{
    Q_OBJECT

public:
    explicit addStu(QWidget *parent = nullptr);
    ~addStu();
    void clearAddStuInterface();
    void saveToFile(QString);
private slots:
    void on_btn_add_clicked();



    void on_btn_cancal_clicked();

private:
    Ui::addStu *ui;

};

#endif // ADDSTU_H
