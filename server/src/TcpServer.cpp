#include "TcpServer.h"

TcpServer::TcpServer():
        gen(std::random_device{}())
{
}

void TcpServer::incomingConnection(qintptr handle)
{
//    std::uniform_int_distribution<idT> dist(0);
//    idT playerId = -1;
//    do
//    {
//        playerId = dist(gen);
//    } while (clients.contains(playerId));
    clients[handle] = std::make_unique<QTcpSocket>();
    clients[handle]->setSocketDescriptor(handle);
    connect(clients[handle].get(), &QTcpSocket::readyRead, this, &TcpServer::readData);
}

bool TcpServer::authAttempt(QTcpSocket *sock)
{
    QDataStream stream(sock);
    QString name;
    stream >> name;
    if (std::find_if(users.begin(), users.end(), [&name](const User& user) {return user.name == name;}) != users.end()){
        return false;
    }
    std::uniform_int_distribution<idT> dist(0);
    idT playerId = -1;
    do
    {
        playerId = dist(gen);
    } while (std::find_if(users.begin(), users.end(), [playerId](const User& user) {return user.id == playerId;}) != users.end());
    users.push_back({name, playerId, true});
    return true;
}

void TcpServer::readData()
{
    auto sock = (QTcpSocket*)sender();
    QDataStream stream(sock);
    quint8 type;
    stream >> type;
    switch (type) {
    case Protocol::Auth:
        if (authAttempt(sock)){
            //send success

        } else {
            //send fail
        }
        break;
    }
}
