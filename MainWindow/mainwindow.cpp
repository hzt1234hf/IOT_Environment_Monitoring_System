#include "mainwindow.h"
#include "linecharwidget.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include "math.h"
#include <QTime>
#include <ctime>
#include <QDateTime>
//数据库相关
#include <QSqlDatabase>
#include <QSqlQuery>
//TCP连接
#include <QtNetwork>
#include "clientserver.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tempd = 0;
    ui->setupUi(this);
    lastTailData = 0;

    //QMenu *editMenu = ui -> menuBar -> addMenu(tr("edit(&E)"));
    //QAction *action = editMenu -> addAction(QIcon(":/myImg/open.png"),tr("open"));
    //ui -> mainToolBar -> addAction(action);
    QSqlDatabase addData = QSqlDatabase::addDatabase("QMYSQL","data");//定义数据库类型
    addData.setHostName("localhost");
    addData.setDatabaseName("net_of_thing");
    addData.setUserName("ziteng");
    addData.setPassword("11170012");
    if(!addData.open()){
        qDebug()<<"Unable to open database";
    }else{
        qDebug()<<"Database connection established";
    }
    dataModel = new QSqlTableModel(this,addData);
    dataModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sqlDataShow = new QTableView();
    sqlDataShow->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sqlDataShow->setMaximumWidth(300);
    sqlDataShow->setMinimumHeight(600);
    sqlDataShow->setWindowTitle("SQL Data Show");
    QDateTime abc;
    addDataQuery = new QSqlQuery(addData);
    addDataQuery->exec("select * from light_intensity");
    while(addDataQuery->next()){//因为记录在第一个数据之前，所以必须先调用next()
        qDebug()<<addDataQuery->value(0).toInt()<<addDataQuery->value(1).toString();
        abc = QDateTime::fromString(addDataQuery->value(1).toString(),"yyyy-MM-ddThh:mm:ss");
        qDebug()<<abc;
    }

    sendData = new QByteArray();
    oudData = new QDataStream(sendData,QIODevice::WriteOnly);
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::LocalHost,6666)){
        server->close();
    }else{
        connect(server,SIGNAL(newConnection()),this,SLOT(receiveConn()));
    }
    tcpSendTimer = new QTimer(this);
    tcpSendTimer->start(1000);
    oudData->setVersion(QDataStream::Qt_4_0);
    (*oudData)<<(quint16)0;
    connect(tcpSendTimer,SIGNAL(timeout()),this,SLOT(tcpSendData()));
    /*
    QGridLayout * mainLayout = new QGridLayout(ui->centralWidget);
    mainLayout->setSpacing(6);
    mainLayout->setContentsMargins(11, 11, 11, 11);
    */

    //ui->LCWidget = new LineCharWidget(ui->centralWidget);//定义一个绘图类
    //ui->LCWidget ->resize(500,250);
    //ui->gridLayout_Main->addWidget(ui->LCWidget,0,0,2,2);

    Opened = false;
    ttyUSB_Timer = new QTimer(this);    //串口读取定时器
    dataAnal_Timer = new QTimer(this);  //数据分析定时器
    LCW_Timer = new QTimer(this);
    curTimer = new QDateTime();
    char intTemp[] = {0x7e,0x45};  //定义串口数据头数据
    dataHead = new QByteArray(intTemp,sizeof(intTemp));              //将char型头数据转换为QByteArray型数据
    qDebug()<<(*dataHead)[1]<<dataHead->size()<<dataHead->toHex();
    dataAnal = new QByteArray();
    databaseData = new DatabaseData[(1440/sizeof(DatabaseData))];   //初始化客户端数据库数据指针,留20字节给其他用,正好可以留90个数据结构体，90*16=1440
qDebug()<<sizeof(DatabaseData)<<(1440/sizeof(DatabaseData));

    ui->dataLight_OnOff->setStyleSheet("color:white;background-color: #CD1076");
    ui->dataCO2_OnOff->setStyleSheet("color:white;background-color: #EA9627");
    ui->dataTempe_OnOff->setStyleSheet("color:white;background-color: #445527");
    ui->dataHumid_OnOff->setStyleSheet("color:white;background-color: #E52627");

    connect(ui -> BTN_OpenttyUSB,SIGNAL(clicked()),this,SLOT(OpenClosettyUSB()));   //连接串口开关信号槽
    connect(ui -> serialBtnSend,SIGNAL(clicked()),this,SLOT(writettyUSB()));        //连接发送的信号槽
    connect(dataAnal_Timer,SIGNAL(timeout()),this,SLOT(dataTest_AddData()));        //连接定时添加随机数据信号槽

    connect(ui->dataLight_OnOff,SIGNAL(clicked(bool)),this,SLOT(dataLight_OnOff(bool)));//连接光照信号槽
    connect(ui->dataCO2_OnOff,SIGNAL(clicked(bool)),this,SLOT(dataCO2_OnOff(bool)));    //连接CO2信号槽
    connect(ui->dataTempe_OnOff,SIGNAL(clicked(bool)),this,SLOT(dataTempe_OnOff(bool)));//连接温度信号槽
    connect(ui->dataHumid_OnOff,SIGNAL(clicked(bool)),this,SLOT(dataHumid_OnOff(bool)));//连接温度信号槽

    connect(ui->pBtn_WindowOn_OFF,SIGNAL(clicked()),this,SLOT(openLight()));            //连接开启窗户步进电机信号槽
    connect(ui->pushButton_lightData,SIGNAL(clicked()),this,SLOT(showSQLLightData()));
    connect(ui->pushButton_co2Data,SIGNAL(clicked()),this,SLOT(showSQLCo2Data()));
    connect(ui->pushButton_tempeData,SIGNAL(clicked()),this,SLOT(showSQLTempeData()));
    connect(ui->pushButton_humidData,SIGNAL(clicked()),this,SLOT(showSQLHumidData()));
    LCW_Timer->start(1000);
    //dataAnal_Timer -> start(1000);       //200ms更新一次折线图
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::receiveConn(void){
    serverConn = server->nextPendingConnection();
    connect(serverConn,SIGNAL(readyRead()),this,SLOT(analTcpData()));
}
void MainWindow::analTcpData(void){
    QDataStream inData(serverConn);
    inData.setVersion(QDataStream::Qt_4_0);
    quint16 size;
    clientData data;
    inData >> size;
    inData >> data.type;
    inData >> data.data;
    ui->LCWidget->setTCPSend(ui->LCWidget->getDataLight(),true);
    qDebug()<<"123"<<data.type<<data.data;

}
void MainWindow::tcpSendData(void){
    if(sendData->size()-sizeof(quint16)>0){
        oudData->device()->seek(0);
        (*oudData)<<(quint16)(sendData->size()-sizeof(quint16));
        qDebug()<<"4554"<<(sendData->size()-sizeof(quint16));
        serverConn->write(*sendData);

        delete sendData;
        delete oudData;
        sendData = new QByteArray();
        oudData = new QDataStream(sendData,QIODevice::WriteOnly);
        oudData->setVersion(QDataStream::Qt_4_0);
        (*oudData)<<(quint16)0;
    }
}

void MainWindow::dataTest_AddData(){
    QTime time;
    time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    ui->LCWidget -> insertData(ui->LCWidget->getDataTempera(),qrand()%500,curTimer->currentDateTime());
    ui->LCWidget -> insertData(ui->LCWidget->getDataLight(),qrand()%1600,curTimer->currentDateTime());
    ui->LCWidget -> insertData(ui->LCWidget->getDataCO2(),qrand()%1600,curTimer->currentDateTime());
    ui->LCWidget -> insertData(ui->LCWidget->getDataHumid(),qrand()%1600,curTimer->currentDateTime());
    ui->lineEdit_Light->setText(QString::number(qrand()%500));
    ui->lineEdit_CO2->setText(QString::number(qrand()%1600));
    ui->lineEdit_Tempe->setText(QString::number(qrand()%1100));
    ui->lineEdit_Humid->setText(QString::number(qrand()%1100));

    int tempSColor = qrand()%500/10;
    if(tempSColor<0||tempSColor>50){
        ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: black");
    }else{
        if(tempSColor >35){
            ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: red");
        }else if(tempSColor >20){
            ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: yellow");
        }else{
            ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: green");
        }
    }

    tempSColor = qrand()%500/10;
    if(tempSColor<0||tempSColor>50000){
        ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: black");
    }else{
        if(tempSColor >40000){
            ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: red");
        }else if(tempSColor >30000){
            ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: yellow");
        }else{
            ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: green");
        }
    }

    tempSColor = qrand()%500/10;
    if(tempSColor<0||tempSColor>50000){
        ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: black");
    }else{
        if(tempSColor >40000){
            ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: red");
        }else if(tempSColor >30000){
            ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: yellow");
        }else{
            ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: green");
        }
    }
    //ui->pushButton_LightWarning->setPalette(pal);
}
void MainWindow::dataLight_OnOff(bool bol){
    ui->LCWidget->setLineOnOff(ui->LCWidget->getDataLight(),bol);
    ui->LCWidget->update();
}
void MainWindow::dataCO2_OnOff(bool bol){
    ui->LCWidget->setLineOnOff(ui->LCWidget->getDataCO2(),bol);
    ui->LCWidget->update();
}
void MainWindow::dataTempe_OnOff(bool bol){
    ui->LCWidget->setLineOnOff(ui->LCWidget->getDataTempera(),bol);
    ui->LCWidget->update();
}
void MainWindow::dataHumid_OnOff(bool bol){
    ui->LCWidget->setLineOnOff(ui->LCWidget->getDataHumid(),bol);
    ui->LCWidget->update();
}
void MainWindow::showSQLLightData(void){
    dataModel->setTable("light_data");
    dataModel->select();
    sqlDataShow->setModel(dataModel);
    sqlDataShow->show();
}
void MainWindow::showSQLCo2Data(void){
    dataModel->setTable("co2_data");
    dataModel->select();
    sqlDataShow->setModel(dataModel);
    sqlDataShow->show();
}
void MainWindow::showSQLTempeData(void){
    dataModel->setTable("tempera_data");
    dataModel->select();
    sqlDataShow->setModel(dataModel);
    sqlDataShow->show();
}
void MainWindow::showSQLHumidData(void){
    dataModel->setTable("humid_data");
    dataModel->select();
    sqlDataShow->setModel(dataModel);
    sqlDataShow->show();
}
void MainWindow::readttyUSB(){
    if( ttyUSB -> bytesAvailable() >= 15 )
    {
        //qDebug()<<"read"<<ttyUSB -> bytesAvailable()<<"bytes";
        QByteArray temp = ttyUSB -> readAll();

        if(0){//用于测试QByteArray数据到结构体数据
            char *tempc = temp.data();
            SerialData *tempmd = (SerialData*)tempc;
            qDebug()<<temp.toHex()<<(int)tempc[0]<<(int)tempc[1]<<tempmd->data<<tempmd->dataType;
        }

    qDebug()<<dataAnal->toHex();

        int dataCnt = temp.size()-1;
        int tempCnt = 0;
        char *tmpData;//
    /*新数据个数输出*/
    qDebug()<<dataCnt;
    /*新数据输出*/
    qDebug()<<temp.toHex();
        //将上一次输入数据的最后一个和这次数据第一个进行分析，
        if(lastTailData == 0x7d && tmpData[0] == 0x5e){
            temp.remove(0,1);//将0x7d 0x5e 数据还原为 0x7e
            tmpData = dataAnal->data();
            tmpData[dataAnal->size()-1] = 0x7e;

        }else if(lastTailData == 0x7d && tmpData[0] == 0x5d){
            temp.remove(0,1);//将0x7d 0x5d 数据还原为 0x7d
            tmpData = dataAnal->data();
            tmpData[dataAnal->size()-1] = 0x7d;
        }
        //将这次数据从第一个到倒数第二个进行匹配分析
        while(tempCnt < dataCnt){
            tmpData = temp.data();
            if(tmpData[tempCnt+1] == 0x5e && tmpData[tempCnt] == 0x7d){
                temp.remove(tempCnt,1);//将0x7d 0x5e 数据还原为 0x7e
                temp[tempCnt] = 0x7e;
                dataCnt = temp.size()-1;//更新字符总数
            }else if(tmpData[tempCnt+1] == 0x5d && tmpData[tempCnt] == 0x7d){
                temp.remove(tempCnt,1);//将0x7d 0x5e 数据还原为 0x7e
                temp[tempCnt] = 0x7d;
                dataCnt = temp.size()-1;//更新字符总数
            }
            tempCnt++;
        }
        lastTailData = temp[tempCnt-1];
    /*新数据还原后的输出*/
    qDebug()<<temp.toHex();

        (*dataAnal).append(temp);   //将新收到数据处理后加入到数据分析数组

        int headIndex;//

        while( (headIndex = dataAnal->indexOf(*dataHead)) != -1 ){

            tmpData = dataAnal->data(); //转换位char型数组
    qDebug()<<headIndex<<"--"<<(int)tmpData[headIndex];

            headIndex += DATAHEADLENGTH;    //跳过头数据
    qDebug()<<headIndex<<"--"<<(int)tmpData[headIndex];

            tempData = dataAnal->data();
            tempSerialData = (SerialData*)(tempData+headIndex);//将后续数据转换为数据结构体指针
            qDebug()<<(tempSerialData->data&0xff)<<((tempSerialData->data>>8)&0xff);
            //int swapData = (tempSerialData->data)>>8;
            //tempSerialData->data = (tempSerialData->data<<8)&0xff+swapData;
            switch( tempSerialData -> dataType ){//根据类型分析数据内容
                case 0:{

                }break;
                case 1:{
                    if(ui->LCWidget->getTCPSend(ui->LCWidget->getDataLight())){
                        (*oudData)<<(int)1;
                        (*oudData)<<tempSerialData->data;
                        (*oudData)<<curTimer->currentDateTime();
                    }
                    ui->LCWidget -> insertData(ui->LCWidget->getDataLight(),tempSerialData->data,curTimer->currentDateTime());
                    ui->lineEdit_Light->setText(QString::number(tempSerialData->data));
                //qDebug()<<"insert into net_of_thing.light_data values("+QString::number(tempSerialData->data)+",\'"+curTimer->currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\');";
                    addDataQuery->exec("insert into net_of_thing.light_data values("+QString::number(tempSerialData->data)+",\'"+curTimer->currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\');");
                    if(tempSerialData->data<0||tempSerialData->data>500){
                        ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: black");
                    }else{
                        if(tempSerialData->data >350){
                            ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: rgb(255,255,255)");
                        }else if(tempSerialData->data >200){
                            ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: rgb(160,160,160)");
                        }else{
                            ui->pushButton_LightWarning->setStyleSheet("color:blue;background-color: rgb(60,60,60)");
                        }
                    }
                }break;
                case 2:{
                    if(ui->LCWidget->getTCPSend(ui->LCWidget->getDataCO2())){
                        (*oudData)<<(int)2;
                        (*oudData)<<tempSerialData->data;
                        (*oudData)<<curTimer->currentDateTime();
                    }
                    ui->LCWidget -> insertData(ui->LCWidget->getDataCO2(),tempSerialData->data,curTimer->currentDateTime());
                    ui->lineEdit_CO2->setText(QString::number(tempSerialData->data));
                    addDataQuery->exec("insert into net_of_thing.co2_data values("+QString::number(tempSerialData->data)+",\'"+curTimer->currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\');");
                    if(tempSerialData->data<0||tempSerialData->data>5000){
                        ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: black");
                    }else{
                        if(tempSerialData->data >3000){
                            ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: red");
                        }else if(tempSerialData->data >1500){
                            ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: yellow");
                        }else{
                            ui->pushButton_CO2Warning->setStyleSheet("color:blue;background-color: black");
                        }
                    }
                }break;
                case 3:{
                    tempSerialData->data = -46.85 + 175.72*tempSerialData->data/65536;
                    if(ui->LCWidget->getTCPSend(ui->LCWidget->getDataTempera())){
                        (*oudData)<<(int)3;
                        (*oudData)<<tempSerialData->data;
                        (*oudData)<<curTimer->currentDateTime();
                    }
                    ui->LCWidget -> insertData(ui->LCWidget->getDataTempera(),tempSerialData->data,curTimer->currentDateTime());
                    ui->lineEdit_Tempe->setText(QString::number(tempSerialData->data));
                    addDataQuery->exec("insert into net_of_thing.tempera_data values("+QString::number(tempSerialData->data)+",\'"+curTimer->currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\');");
                    if(tempSerialData->data<0||tempSerialData->data>130){
                        ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: black");
                    }else{
                        if(tempSerialData->data >50){
                            ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: red");
                        }else if(tempSerialData->data >40){
                            ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: yellow");
                        }else{
                            ui->pushButton_TemperaWarning->setStyleSheet("color:blue;background-color: green");
                        }
                    }
                }break;
                case 4:{
                    tempSerialData->data = -6 + 125*tempSerialData->data/65536;
                    if(ui->LCWidget->getTCPSend(ui->LCWidget->getDataHumid())){
                        (*oudData)<<(int)4;
                        (*oudData)<<tempSerialData->data;
                        (*oudData)<<curTimer->currentDateTime();
                    }
                    ui->LCWidget -> insertData(ui->LCWidget->getDataHumid(),tempSerialData->data,curTimer->currentDateTime());
                    ui->lineEdit_Humid->setText(QString::number(tempSerialData->data));
                    addDataQuery->exec("insert into net_of_thing.humid_data values("+QString::number(tempSerialData->data)+",\'"+curTimer->currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\');");
                    if(tempSerialData->data<0||tempSerialData->data>119){
                        ui->pushButton_HumidWarning->setStyleSheet("color:blue;background-color: black");
                    }else{
                        if(tempSerialData->data <30){
                            ui->pushButton_HumidWarning->setStyleSheet("color:blue;background-color: red");
                        }else if(tempSerialData->data < 60){
                            ui->pushButton_HumidWarning->setStyleSheet("color:blue;background-color: yellow");
                        }else{
                            ui->pushButton_HumidWarning->setStyleSheet("color:blue;background-color: green");
                        }
                    }
                }break;
            }

            headIndex += DATALENGTH;        //跳过数据
    qDebug()<<headIndex<<"--"<<(int)tmpData[headIndex];

            headIndex += DATATAILLENGTH;    //跳过数据尾
    qDebug()<<headIndex<<"--"<<(int)tmpData[headIndex];

            QString tempStr = "Time:"+curTimer->currentDateTime().toString("yyyy.MM.dd hh:mm:ss ")+"Package:"+" type:"+QString::number(tempSerialData->dataType)+" data:"+QString::number(tempSerialData->data)+"\n";
            qDebug()<<tempStr;
            ui -> serialTextReceive -> moveCursor(QTextCursor::End);
            ui -> serialTextReceive -> insertPlainText(tempStr);   //显示到屏幕上
            ui -> serialTextReceive->moveCursor(QTextCursor::End);

            ui->LCWidget -> insertData(ui->LCWidget->getDataTest(),tempSerialData->data,curTimer->currentDateTime());


            dataAnal -> remove(0,headIndex);//删除处理过的数据
    qDebug()<<dataAnal->toHex();
        }

    }
}
void MainWindow::writettyUSB(){
    ttyUSB -> write( ui -> serialLineSend -> text().toAscii());
}
void MainWindow::openLight(void){
    unsigned int CRC = 0;
    //CRC必须计算除　头0x7e 、尾部CRC　、尾0x7e以外的数据
    char data[] = {0x7e,0x44,0x00,0x00,0xFF,0xFF,0x00,0x00,0x03,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x7e};//数据结构
    int j = 1;
    while(j<=13){
        caluCRC(CRC,data[j]);   //循环计算CRC
        j++;
    }
    data[15] = (CRC>>8)&0xFF;   //高位在后
    data[14] = CRC&0xFF;        //低位在前

    QByteArray *ta = new QByteArray(data,16);//为了输出调试
    qDebug()<<"CRC:"<<CRC<<ta->toHex();

    ttyUSB -> write(data,17);   //输出到串口
}
void MainWindow::caluCRC(unsigned int &crc,unsigned char data){
/*
    crc = ((crc ^ data)&0xFFFF) << 8;
    int i = 8;
    do{
      if (crc & 0x8000)
        crc = (crc << 1 ^ 0x1021)&0xFFFF;
      else
        crc = (crc << 1)&0xFFFF;
    }while (--i);
*/
    crc = (((crc >> 8)&0xFF) | (crc << 8))&0xFFFF;
    crc = (crc ^ data)&0xFFFF;
    crc = (crc ^ ((crc & 0xff) >> 4))&0xFFFF;
    crc = (crc ^ (crc << 12))&0xFFFF;
    crc = (crc ^ ((crc & 0xff) << 5))&0xFFFF;
}


void MainWindow::ttyUSBDataAnaylse(){

}
void MainWindow::OpenClosettyUSB(){
    if(!Opened)
    {
        ttyUSB = new Posix_QextSerialPort("/dev/" + ui -> UART1_comboBox_ttyUSB -> currentText(),QextSerialBase::Polling);//定义串口对象，指定串口名和查询模式，这里使用事件驱动PollingDriven
        //if((myCom->isOpen()))
        if( ttyUSB -> open(QIODevice::ReadWrite) )//以读写方式打开串口
        {
            //qDebug()<<"Success"<<"/dev/"+ ui -> UART1_comboBox_ttyUSB -> currentText();
            switch(ui -> UART1_comboBox_BaudRate -> currentIndex())
            {
                case 0: ttyUSB->setBaudRate(BAUD4800);break;
                case 1: ttyUSB->setBaudRate(BAUD9600);break;
                case 2: ttyUSB->setBaudRate(BAUD14400);break;
                case 3: ttyUSB->setBaudRate(BAUD19200);break;
                case 4: ttyUSB->setBaudRate(BAUD38400);break;
                case 5: ttyUSB->setBaudRate(BAUD57600);break;
                case 6: ttyUSB->setBaudRate(BAUD115200);break;
                default:ttyUSB->setBaudRate(BAUD57600);break;
            }//波特率设置，我们设置为57600
            qDebug()<<"BAUD"<<ui -> UART1_comboBox_BaudRate ->currentText();

            switch(ui -> UART1_comboBox_StopBit -> currentIndex())
            {
                case 0: ttyUSB->setStopBits(STOP_1);break;
                case 1: ttyUSB->setStopBits(STOP_1_5);break;
                case 2: ttyUSB->setStopBits(STOP_2);break;
                default: ttyUSB->setStopBits(STOP_1);break;
            }//停止位设置，我们设置为1位停止位
            qDebug()<<"StopBit"<<ui -> UART1_comboBox_StopBit -> currentText();

            switch(ui -> UART1_comboBox_ParityBit -> currentIndex())
            {
                case 0: ttyUSB->setParity(PAR_NONE);break;
                case 1: ttyUSB->setParity(PAR_EVEN);break;
                case 2: ttyUSB->setParity(PAR_ODD);break;
                default: ttyUSB->setParity(PAR_NONE);break;
            }//奇偶校验设置，我们设置为无校验
            qDebug()<<"PAR_"<<ui -> UART1_comboBox_StopBit -> currentText();

            ttyUSB -> setDataBits(DATA_8);		//数据位设置，我们设置为8位数据位
            ttyUSB -> setFlowControl(FLOW_OFF);	//数据流控制设置，我们设置为无数据流控制
            ttyUSB -> setTimeout(100);           //设置串口缓存更新时间
            ttyUSB_Timer -> start(200);         //延时为100ms
            //dataAnal_Timer -> start(1000);       //200ms更新一次折线图

            ttyUSB -> readAll();//用来清空串口接收缓冲区
            if(ui -> UART1_check_clrRecv -> isChecked())
                ui -> serialTextReceive -> clear();

            //connect(myCom,SIGNAL(readyRead()),this,SLOT(RX_Com()));//信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
            //connect(ui -> Btn_TX_Data,SIGNAL(clicked()),this,SLOT(TX_Com()));//信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作

            ui -> BTN_OpenttyUSB ->setText(tr("Close"));
            ui -> UART1_comboBox_ttyUSB -> setEnabled(false);
            ui -> UART1_comboBox_BaudRate -> setEnabled(false);
            ui -> UART1_comboBox_ParityBit -> setEnabled(false);
            ui -> UART1_comboBox_StopBit -> setEnabled(false);
            ui -> UART1_check_clrRecv -> setEnabled(false);
            ui -> serialBtnSend -> setEnabled(true);

            connect(ttyUSB_Timer,SIGNAL(timeout()),this,SLOT(readttyUSB()));                //连接定时器接收信号槽
            connect(LCW_Timer,SIGNAL(timeout()),ui->LCWidget,SLOT(update()));               //连接定时绘图信号槽

            LCW_Timer->start(400);

            Opened = true;
            ui->LCWidget->setOpenUpdate(Opened);
        }
        else
        {
            qDebug()<<"Open ttyUSBx Error!";
            QMessageBox::warning(this,tr("ERROR!"),tr("<br>Try To Open ttyUSBx Failed!<br>ttyUSBx not exist or ttyUSBx are busy!<br>"));
        }
    }
    else
    {
        ttyUSB -> close();
        LCW_Timer->stop();
        ttyUSB_Timer -> stop();         //关闭定时器

        disconnect(ttyUSB_Timer,SIGNAL(timeout()),this,SLOT(readttyUSB()));                //连接定时器接收信号槽
        disconnect(LCW_Timer,SIGNAL(timeout()),ui->LCWidget,SLOT(update()));               //连接定时绘图信号槽

        //dataAnal_Timer -> stop();
        ui -> UART1_comboBox_ttyUSB -> setEnabled(true);
        ui -> UART1_comboBox_BaudRate -> setEnabled(true);
        ui -> UART1_comboBox_ParityBit -> setEnabled(true);
        ui -> UART1_comboBox_StopBit -> setEnabled(true);
        ui -> UART1_check_clrRecv -> setEnabled(true);
        ui -> serialBtnSend -> setEnabled(false);
        ui -> BTN_OpenttyUSB ->setText(tr("Open"));

        Opened = false;
        ui->LCWidget->setOpenUpdate(Opened);
        ui->LCWidget->update();
    }
}
void MainWindow::temp(){
    QMessageBox::warning(this,tr("ERROR!"),tr("<br>Try To Open ttyUSBx Failed!<br>ttyUSBx not exist or ttyUSBx are busy!<br>"));

}
void MainWindow::resizeEvent(QResizeEvent *event){
    ui->LCWidget->setGeometry(ui->gridLayout_LCW->geometry());
    qDebug()<<"4456"<<ui->gridLayout_LCW->geometry();
    ui->LCWidget->setSizeInfo(ui->LCWidget->width(),ui->LCWidget->height(),20);
    qDebug()<<"6645"<<ui->LCWidget->x()<<ui->LCWidget->geometry()<<ui->LCWidget->height()<<ui->LCWidget->width()<<ui->LCWidget->frameGeometry().width();
}
