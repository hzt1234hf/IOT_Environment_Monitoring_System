#ifndef LINECHARWIDGET_H
#define LINECHARWIDGET_H

#include <QWidget>
#include <QDateTime>
#define DATACOUNT 50
typedef struct LCW_struct{
    bool showSwitch;
    float data[DATACOUNT];
    QDateTime time[DATACOUNT];
    int currentData;
    int countData;

    float painteHP;
    float dataMax;
    float painteHP_value;

    bool tcpSend;
}LCW_struct;

class LineCharWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LineCharWidget(QWidget *parent = 0);

    LCW_struct LCW_DataTest;    //测试数据
    LCW_struct LCW_DataLight;   //光照数据
    LCW_struct LCW_DataCO2;     //CO2数据
    LCW_struct LCW_DataTempera; //温度数据
    LCW_struct LCW_DataHumid;   //湿度数据

    int LCW_DataCnt;
    int LCW_DataPoiCnt;

    void setSizeInfo(int px,int py,int divCnt);
    void insertData(LCW_struct * dataStruct,float data,QDateTime time);
    void setLineOnOff(LCW_struct * dataStruct,bool bol);
    LCW_struct *getDataTest(void);
    LCW_struct *getDataLight(void);
    LCW_struct *getDataCO2(void);
    LCW_struct *getDataTempera(void);
    LCW_struct *getDataHumid(void);

    bool getTCPSend(LCW_struct * dataStruct);
    void setTCPSend(LCW_struct * dataStruct,bool bol);

    void setOpenUpdate(bool bol);
private:
    int *temp,i;
    QPainter *painter;  //折线图绘制指针
    QPainter *painterLWText;
    //QPen *pen;
/*******************************************************/
    int LCWx,LCWy;//绘图QWidget长 宽

    int LCW_ivX,LCW_ivY,dividCnt;//x轴和y轴的间隙和分割次数

    int LCW_btnX,LCW_btnY;//底部矩形框坐标
    int LCW_btnW,LCW_btnH;//底部矩形框长宽
    int LCW_cenH,LCW_cneW;//中心矩形框长宽
    float LCW_cntHP;//中心矩形框比例
    int LCW_dataMax;
    QDateTime *currentTimer;

    bool openUpdate;

    void paintDataLine(LCW_struct *dataStruct,QColor penColor,QColor brushColor);
    void dataStructInit(LCW_struct *dataStruct, int value);
protected:
    void paintEvent(QPaintEvent *event);
signals:
    
public slots:
    
};

#endif // LINECHARWIDGET_H
