#ifndef USER_H
#define USER_H

#include <QString>

#include "GameStats.h"

class User
{
public:
    User();

    QString name;
    QString password;

    QList<GameStats *> game_stats;

    int wins();
    int total_games();
};

#endif // USER_H
