#include "clientserver.h"
#include <QtNetwork>
ClientServer::ClientServer()
{
    serSigned = false;
    cliSigned = false;
    tcpServer = new QTcpServer();
    tcpClient = new QTcpSocket();
    TCP_Timer = new QTimer();

}

void ClientServer::setServer(QHostAddress host,quint16 port){
    if(!serSigned){
        if(!tcpServer->listen(host,port)){
            qDebug()<<tcpServer -> errorString();
            tcpServer->close();
        }else{
            serSigned = true;
            qDebug()<<"Listen Successful!";
        }
    }
}

void ClientServer::setClient(QHostAddress host,quint16 port){
    if(!cliSigned){
        tcpClient -> abort();
        tcpClient -> connectToHost(host,port);
        cliSigned = true;
        qDebug()<<"Connect Successful!";
    }
}
void ClientServer::setClientType(int type){
    clientType = type;
}
void ClientServer::setServerType(int type){
    serverType = type;
}
void ClientServer::ServerSendMsg(int dataType,int data,int len){
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<dataType;
    out<<data;
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    QTcpSocket *clientConn = tcpServer -> nextPendingConnection();
    QObject::connect(clientConn,SIGNAL(disconnected()),clientConn,SLOT(deleteLater()));
    clientConn -> write(block);
    clientConn -> disconnectFromHost();
}
void ClientServer::ServerSendMsg(QByteArray &block){

    QTcpSocket *clientConn = tcpServer -> nextPendingConnection();
    QObject::connect(clientConn,SIGNAL(disconnected()),clientConn,SLOT(deleteLater()));
    clientConn -> write(block);
    clientConn -> disconnectFromHost();
}
