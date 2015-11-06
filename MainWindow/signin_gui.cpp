#include "signin_gui.h"
#include "ui_signin_gui.h"
//数据库相关
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
Signin_GUI::Signin_GUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signin_GUI)
{
    ui->setupUi(this);
    connect(ui->pushButton_signin,SIGNAL(clicked()),this,SLOT(signIn()));
    connect(ui->pushButton_exit,SIGNAL(clicked()),this,SLOT(reject()));
}

Signin_GUI::~Signin_GUI()
{
    delete ui;
}

void Signin_GUI::signIn(void){
    QSqlQuery *addDataQuery;
    if(!QSqlDatabase::contains("userinfo")){//使用这种方式可以避免重定义问题
        QSqlDatabase addData = QSqlDatabase::addDatabase("QMYSQL","userinfo");//定义数据库类型
        addData.setHostName("localhost");
        addData.setDatabaseName("net_of_thing");
        addData.setUserName("ziteng");
        addData.setPassword("11170012");
        if(!addData.open()){
            qDebug()<<"Unable to open database";
        }else{
            qDebug()<<"Database connection established";
        }
        addDataQuery = new QSqlQuery(addData);
    }else{
        addDataQuery = new QSqlQuery(QSqlDatabase::database("userinfo"));
    }
    addDataQuery->exec("select * from userinfo");
    while(addDataQuery->next()){//因为记录在第一个数据之前，所以必须先调用next()
        qDebug()<<addDataQuery->value(0).toString()<<addDataQuery->value(1).toString();
        if(addDataQuery->value(0).toString() == ui->lineEdit_user->text() && addDataQuery->value(1).toString() == ui->lineEdit_password->text()){
            return accept();
        }
    }
    QMessageBox::warning(this,"Admin Sign In Failed","user or password is wrong or not exist!");
    QSqlDatabase::removeDatabase("userinfo");
}
