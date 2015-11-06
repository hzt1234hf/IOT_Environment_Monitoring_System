#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H

#include <QtNetwork>
#include "comDef.h"
class ClientServer
{
public:
    ClientServer();

    void setServer(QHostAddress host,quint16 port);
    void setClient(QHostAddress host, quint16 port);
    void setServerType(int type);
    void setClientType(int type);
    void ServerSendMsg(QByteArray &block);
    void ServerSendMsg(int dataType, int data, int len);

private:
    QTcpServer *tcpServer;      //TCP服务器端指针
    bool serSigned;             //TCP服务端连接标识
    QTcpSocket *tcpClient;      //TCP客户端指针
    bool cliSigned;             //TCP客户端连接标识
    int serverType,clientType;  //TCP客户/服务端信号类型
    QTimer *TCP_Timer;          //TCP计时器

private slots:

    //void newConnect();
    //void readMessage();
    //void displayError();
};

#endif // CLIENTSERVER_H
