#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <QTimer>
#include <QList>

#include "Sequence.h"

class GameStats
{
public:
    GameStats();

    QList<Sequence> sequences;

    QTimer timer;

    bool win;

    int errors;
    int attempts;

};

#endif // GAMESTATS_H
