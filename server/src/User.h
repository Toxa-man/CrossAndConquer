#ifndef USER_H
#define USER_H

#include <QTcpSocket>
#include "globals.h"

struct User
{
    QString name {};
    idT id {-1};
    bool isAuthorized {false};
};

#endif // USER_H
