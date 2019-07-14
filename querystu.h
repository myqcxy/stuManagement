#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include <QList>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class queryStu;
}

class queryStu : public QDialog
{
    Q_OBJECT

public:
    explicit queryStu(QWidget *parent = nullptr);
    ~queryStu();
    int readFromFile();
    void doQuery(int,QString);
    void displayTable(int,QStringList);
    void initTable();
private slots:
    void on_btn_search_clicked();

private:
    Ui::queryStu *ui;
    QList<QString> stu_lines;
    QStandardItemModel *model;
};

#endif // QUERYSTU_H
