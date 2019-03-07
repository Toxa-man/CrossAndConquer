#ifndef LOBBY_H
#define LOBBY_H

#include <QVector>
#include <User.h>
#include "Field.h"


class Lobby
{
public:
    enum State {WaitingForPlayers, GameRunning, GameFinished} ;
    Lobby(const User& host, idT id);
    bool requestToConnect(const User& client);
private:
    QVector<User> users;
    State state;
    std::unique_ptr<Field> field {};
    idT id;
};

#endif // LOBBY_H
