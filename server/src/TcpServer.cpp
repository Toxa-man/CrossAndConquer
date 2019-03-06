#include "TcpServer.h"

TcpServer::TcpServer()
{
}


void TcpServer::incomingConnection(qintptr handle)
{
    clients[handle].reset(new QTcpSocket);
}
