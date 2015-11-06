#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "linecharwidget.h"
#include "posix_qextserialport.h"
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

#include <QMainWindow>
#include <QDateTime>
#include <QtNetwork>
#include "comDef.h"
#include <sys/time.h>
typedef struct SerialData{
    int dataType  : 16;
    unsigned int data      : 16;
}SerialData;
typedef struct clientData{
    int type;
    int data;
}clientData;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    int *num;
    ~MainWindow();
    void caluCRC(unsigned int &crc, unsigned char data);
    //void setCRC(unsigned int *crc,unsigned int data);
    //unsigned int * getCRC(void);

private:
    Ui::MainWindow *ui;
    int tempd;
    LineCharWidget * LCWidget;
    QTimer *LCW_Timer; //周期绘图

    Posix_QextSerialPort * ttyUSB;  //串口指针变量
    QTimer *ttyUSB_Timer;           //串口周期读缓存定时器指针变量

#define DATALENGTH  3       //数据长度
#define DATAHEADLENGTH  10  //数据头长度
#define DATATAILLENGTH  3   //数据尾长度
    QTimer *dataAnal_Timer; //数据周期处理定时器指针变量
    QByteArray *dataAnal;   //数据处理指针变量
    QByteArray *dataHead;   //信号头指针变量
    int dataHeadLen;        //信号头长度变量
    char *tempData;         //数据数组指针变量
    SerialData *tempSerialData; //数据结构体指针变量
    char lastTailData;      //上次数据最后一个数据
    QDateTime *curTimer;

    //QSqlDatabase *addData;

    bool Opened;    //串口开关标志变量

    QSqlQuery *addDataQuery;
    DatabaseData *databaseData;   //数据库数据指针变量
    QSqlTableModel *dataModel;
    QTableView *sqlDataShow;

    QTcpServer *server;
    QTcpSocket *serverConn;
    QTimer *tcpSendTimer; //
    QByteArray *sendData;
    QDataStream *oudData;

protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void writettyUSB();
    void readttyUSB();
    void ttyUSBDataAnaylse();
    void OpenClosettyUSB();
    void dataTest_AddData();
    void temp();

    void openLight(void);

    void dataLight_OnOff(bool bol);
    void dataCO2_OnOff(bool bol);
    void dataTempe_OnOff(bool bol);
    void dataHumid_OnOff(bool bol);

    void showSQLLightData(void);
    void showSQLCo2Data(void);
    void showSQLTempeData(void);
    void showSQLHumidData(void);

    void analTcpData(void);
    void receiveConn(void);
    void tcpSendData(void);
};

#endif // MAINWINDOW_H
