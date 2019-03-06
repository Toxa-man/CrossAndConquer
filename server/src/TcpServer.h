#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QMap>
#include <QTcpSocket>

class TcpServer : public QTcpServer
{
public:
    TcpServer();

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) final;
private:
    QMap <qintptr, std::unique_ptr<QTcpSocket>> clients;
};

#endif // TCPSERVER_H
