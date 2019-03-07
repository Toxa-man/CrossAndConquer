#include "Lobby.h"

Lobby::Lobby(const User &host, idT id):
    state(WaitingForPlayers),
    id(id)
{
    users.push_back(host);
}

bool Lobby::requestToConnect(const User &client)
{
    if (state != WaitingForPlayers){
        return false;
    }
    users.push_back(client);
    state = GameRunning;
    return true;
}
