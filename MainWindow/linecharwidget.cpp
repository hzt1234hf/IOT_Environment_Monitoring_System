#include "linecharwidget.h"
#include <QPainter>
#include <QPen>
#include"math.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QDateTime>

LineCharWidget::LineCharWidget(QWidget *parent) :
    QWidget(parent)
{
    painter = new QPainter();//设置
    painterLWText = new QPainter();//设置
    currentTimer = new QDateTime();

    LCW_DataPoiCnt = 0;
    LCW_DataCnt = 0;
    LCW_dataMax = 0;

    dataStructInit(&LCW_DataTest,54);
    dataStructInit(&LCW_DataLight,1);
    dataStructInit(&LCW_DataCO2,2);
    dataStructInit(&LCW_DataTempera,3);
    dataStructInit(&LCW_DataHumid,4);
    //LCW_DataTest.showSwitch = true;

    LCW_cntHP = 1;//中心比例初始化1

    openUpdate = false;
}
void LineCharWidget::paintEvent(QPaintEvent *event){
    int j;
    QDateTime tempTime;
    int currenMM,currenSS;

    painter->begin(this);

    //绘制底部时间轴
    painter->setPen(QPen(QBrush(QColor(51,204,102)),2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->setBrush(QBrush(QColor(51,204,102)));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRect(LCW_btnX,LCW_btnY,LCW_btnW,LCW_btnH);

    //绘制底部坐标
    j = 1;
    while(j <= dividCnt){
        painter->drawLine(QPoint((j-1)*LCW_ivX,LCW_btnY-10),QPoint((j-1)*LCW_ivX,LCW_btnY));
        j++;
    }
    if(openUpdate){
        //绘制坐标名称
        currenMM = QTime::currentTime().addSecs(-dividCnt+1).minute();
        currenSS = QTime::currentTime().addSecs(-dividCnt+1).second();
        //qDebug()<<"123"<<currenMM<<currenSS;
        painter->setPen(QPen(QBrush(QColor(255,255,255)),4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
        painter->setBrush(QBrush(QColor(255,255,255)));
        painter->setRenderHint(QPainter::Antialiasing);
        j = 1;
        while(j <= dividCnt){
            painter->drawText(QPoint((j-1)*LCW_ivX-10,LCW_btnY+LCWy/20),""+QString::number(currenMM)+":"+QString::number(currenSS));
            currenSS++;
            currenSS>=60?currenSS = 0,currenMM++:0;
            currenMM>=60?currenMM=0:0;
            j++;
        }
        //paintDataLine(&LCW_DataTest,QColor(128,0,255),QColor(128,0,255));
        paintDataLine(&LCW_DataTempera,QColor("#445527"),QColor("#EA9627"));
        paintDataLine(&LCW_DataLight,QColor("#CD1076"),QColor("#CD1076"));
        paintDataLine(&LCW_DataCO2,QColor("#EA9627"),QColor("#EA9627"));
        paintDataLine(&LCW_DataHumid,QColor("#E52627"),QColor("#E44627"));


    }
    painter->end();
}
void LineCharWidget::paintDataLine(LCW_struct *dataStruct,QColor penColor,QColor brushColor){
    if(!dataStruct->showSwitch)
        return;
    int currenMM,currenSS;
    int end,start;
    int tempData,tempData2;
    int tempMM,tempSS,tempMM2,tempSS2;
    int j;
    int tempCnt,tempCnt2;
    QDateTime currenDate;
    //绘制折线
    currenMM = QTime::currentTime().addSecs(-dividCnt+1).minute();
    currenSS = QTime::currentTime().addSecs(-dividCnt+1).second();
    painter->setPen(QPen(QBrush(penColor),2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->setBrush(QBrush(brushColor));
    painter->setRenderHint(QPainter::Antialiasing);
    end = dataStruct->currentData;
    if(dataStruct->countData<dividCnt){
        start = (dataStruct->currentData+DATACOUNT-dataStruct->countData)%DATACOUNT;
    }else{
        start = (dataStruct->currentData+DATACOUNT-dividCnt)%DATACOUNT;
    }
    j = start;
    //qDebug()<<start<<end<<j;
    //qDebug()<<dataStruct ->data[j]<<dataStruct ->time[j].toString("mm:ss");
    while(j != end){
        if(dataStruct ->time[j]<currenDate.currentDateTime().addSecs(-dividCnt)){
            j = (j+1)%DATACOUNT;
    //qDebug()<<dataStruct ->time[j].toString("mm:ss")<<currenDate.currentDateTime().addSecs(-dividCnt).toString("mm:ss");
            continue;
        }
        tempData = (int)dataStruct->data[j];
        tempMM = dataStruct ->time[j].toString("mm").toInt();
        tempSS = dataStruct ->time[j].toString("ss").toInt();
        tempCnt = (tempMM - currenMM)*60 + (tempSS - currenSS);
    //qDebug()<<currenMM<<currenSS<<tempMM<<tempSS<<tempCnt;
        painter->drawEllipse(QPoint(tempCnt*LCW_ivX,LCW_btnY - tempData*dataStruct->painteHP),3,3);
        painter->drawText(QPoint(tempCnt*LCW_ivX-10,LCW_btnY - tempData*dataStruct->painteHP - 10),QString::number(tempData));
        if(tempData > dataStruct->dataMax){
            dataStruct->dataMax = tempData;
        }
        if(((j+1)%DATACOUNT) == end){
            break;
        }
        tempData2 = (int)dataStruct->data[(j+1)%DATACOUNT];
        tempMM2 = dataStruct ->time[(j+1)%DATACOUNT].toString("mm").toInt();
        tempSS2 = dataStruct ->time[(j+1)%DATACOUNT].toString("ss").toInt();
        tempCnt2 = (tempMM2 - currenMM)*60 + (tempSS2 - currenSS);
    //qDebug()<<tempData<<tempMM<<tempSS;
        painter->drawLine(QPoint(tempCnt*LCW_ivX,LCW_btnY - tempData*dataStruct->painteHP),QPoint(tempCnt2*LCW_ivX,LCW_btnY - tempData2*dataStruct->painteHP));
        //painter->drawLine(QPoint((j-1)*LCW_ivX,LCW_btnY - tempData*dataStruct->painteHP),QPoint((j-1)*LCW_ivX,LCW_btnY));
        j = (j+1)%DATACOUNT;
    }
    dataStruct->painteHP = (float)LCW_btnY/dataStruct->dataMax/dataStruct->painteHP_value;

    //qDebug()<<"grfg"<<dataStruct->dataMax<<dataStruct->painteHP<<dataStruct->dataMax/(float)LCW_btnY;
    //qDebug()<<j<<dataStruct->countData<<dataStruct->currentData;

}

void LineCharWidget::insertData(LCW_struct * dataStruct,float data,QDateTime time){
    dataStruct->data[dataStruct->currentData] = data;
    dataStruct->time[dataStruct->currentData] = time;
    dataStruct->currentData = (dataStruct->currentData+1)%DATACOUNT;
    if(dataStruct->countData<DATACOUNT)
        dataStruct->countData++;
}
void LineCharWidget::setLineOnOff(LCW_struct * dataStruct,bool bol){
    dataStruct -> showSwitch = bol;
}

LCW_struct * LineCharWidget::getDataTest(){
    return &LCW_DataTest;
}
LCW_struct * LineCharWidget::getDataLight(){
    return &LCW_DataLight;
}
LCW_struct * LineCharWidget::getDataCO2(){
    return &LCW_DataCO2;
}
LCW_struct * LineCharWidget::getDataTempera(){
    return &LCW_DataTempera;
}
LCW_struct * LineCharWidget::getDataHumid(){
    return &LCW_DataHumid;
}
void LineCharWidget::dataStructInit(LCW_struct *dataStruct,int value){
    QTime time;
    time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000+value);
    dataStruct->showSwitch = false;
    dataStruct->countData = 0;
    dataStruct->currentData = 0;
    dataStruct->painteHP = 1;
    dataStruct->dataMax = 0;
    dataStruct->painteHP_value = qrand()%10/10.0+1.5;
    dataStruct->tcpSend = false;
    qDebug()<<dataStruct->painteHP_value;
}
bool LineCharWidget::getTCPSend(LCW_struct * dataStruct){
    return dataStruct->tcpSend;
}
void LineCharWidget::setTCPSend(LCW_struct * dataStruct,bool bol){
    dataStruct->tcpSend = bol;
}

void LineCharWidget::setSizeInfo(int px,int py,int divCnt){
    LCWx = px;
    LCWy = py;

    dividCnt = divCnt+1;
    LCW_ivX = px/divCnt;
    LCW_ivY = py/divCnt;

    LCW_btnX = 0;
    LCW_btnY = LCWy*9/10;
    LCW_btnH = LCWy/10;
    LCW_btnW = LCWx;
//qDebug()<<LCWy<<LCW_btnY<<LCW_btnH;
}
void LineCharWidget::setOpenUpdate(bool bol){
    openUpdate = bol;
}
