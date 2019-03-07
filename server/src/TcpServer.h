#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QMap>
#include <QTcpSocket>
#include <set>
#include <random>

#include "globals.h"
#include <functional>
#include "User.h"
#include "Lobby.h"

namespace  Protocol{
//first byte: type of message
enum messageType : quint8 {Auth, LobbyList, LobbyCreate, LobbyInfo, GameInfo};
}

class TcpServer : public QTcpServer
{
public:
    TcpServer();
    void sendCommand();
protected:
    void incomingConnection(qintptr handle) final;
private:
    QMap <qintptr, std::unique_ptr<QTcpSocket>> clients;
//    std::set<User, std::function<bool(const User&, const User &)>> users;
    QVector<User> users;
    QVector<Lobby> lobbies;
    std::mt19937 gen;
    bool authAttempt(QTcpSocket *sock);
private slots:
    void readData();
};

#endif // TCPSERVER_H
