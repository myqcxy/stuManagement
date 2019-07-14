#include "addstu.h"
#include "ui_addstu.h"
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>


addStu::addStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStu)
{
    ui->setupUi(this);
}

addStu::~addStu()
{
    delete ui;
}

void addStu::on_btn_add_clicked()
{
    QString name = this->ui->le_name->text();
    QString id = this->ui->le_number->text();
    QString sex = this->ui->sexGroup->checkedButton()->text();
    QList<QAbstractButton *> ins_list = this->ui->insGroup->buttons();
    QString ins = "";
    for(QAbstractButton * btn : ins_list){
        if(btn->isChecked()){
            ins += btn->text()+",";
        }
    }
    if(ins.length()>0){
        ins = ins.remove(ins.length()-1,1);
    }
    QString age = this -> ui->cb_age->currentText();
    QString yx = this->ui->cb_yx->currentText();
    QString content = name+ "\n"+id+ "\n" + sex + "\n" +age+ "\n" + yx+"\n" + ins;

    if(name.length()<1 || id.length()<1){
        QMessageBox::warning(this,"警告","输入信息有误，清检查！","确定");
    }else{
        int ret = QMessageBox::information(this,"确认信息",content,"确认","取消");
        if(ret == 0){
            saveToFile(content.replace("\n",":")+"\n");
            clearAddStuInterface();
        }
    }

}
void addStu::saveToFile(QString cnt){
    QFile file("stu.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)){
        QMessageBox::critical(this,"错误","文件未能打开，写入信息失败","确认");
         return;
    }
    QTextStream out(&file);
    out <<cnt;
    file.close();

}

void addStu::clearAddStuInterface(){
    this->ui->le_name->clear();
    this->ui->le_number->clear();
    this->ui->rbtn_male->setChecked(true);
    this->ui->cb_age->setCurrentIndex(0);
    this->ui->cb_yx->setCurrentIndex(0);
    for(QAbstractButton * btn:this->ui->insGroup->buttons()){
        btn->setChecked(false);
    }
    this->ui->le_name->setFocus();
}


void addStu::on_btn_cancal_clicked()
{
    this->close();
}
