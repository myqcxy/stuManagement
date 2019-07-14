#include "querystu.h"
#include "ui_querystu.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QStringList>

queryStu::queryStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryStu)
{
    ui->setupUi(this);
    if(this->readFromFile()){
        QMessageBox::critical(this,"错误","文件打开失败，请稍后重试！","确定");
        this->close();
    }

    this->model = new QStandardItemModel;
    initTable();
    this->ui->tableView->setModel(model);



}

queryStu::~queryStu()
{
    delete ui;
}
int queryStu::readFromFile()
{
    QFile file("stu.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return -1;

    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line = in.readLine();
      stu_lines.append(line);
    }
    for(QString l:stu_lines){
        qDebug()<<l;
    }
    file.close();
    return 0;
}

void queryStu::on_btn_search_clicked()
{
    int method = this->ui->cb_searchMethod->currentIndex();
    QString cnt = this->ui->le_searchContent->text();
    this->model->clear();
    initTable();
    this->doQuery(method,cnt);

}
void queryStu::doQuery(int index, QString cnt)
{

    int row = 0;
    for(QString line:stu_lines){
        QStringList l = line.split(":");
        switch (index) {
            case 0:
            if(cnt==l[0])
                displayTable(row++,l);
            break;
            case 1:
            if(cnt==l[1])
                displayTable(row++,l);
            break;
            case 2:
            if(cnt==l[4])
               displayTable(row++,l);
            break;

             default:break;
        }
    }
}
void queryStu::displayTable(int row, QStringList stu)
{
    int i = 0;
    for(;i<stu.length();i++){
        this->model->setItem(row,i,new QStandardItem(stu[i]));
    }
}
void queryStu::initTable()
{
    model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(4,new QStandardItem("学院"));
    model->setHorizontalHeaderItem(5,new QStandardItem("爱好"));
    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,100);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);

}
