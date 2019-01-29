#ifndef USER_H
#define USER_H

#include <QString>

#include "GameStats.h"

#define DIFFICULTY_EASY         "Easy"
#define DIFFICULTY_MEDIUM       "Medium"
#define DIFFICULTY_DIFFICULT    "Difficult"

#define WORD_TYPE_ALPHABETIC    "Alphabetic"
#define WORD_TYPE_NUMERIC       "Numeric"
#define WORD_TYPE_ALPHANUMERIC  "Alphanumeric"

class User
{
public:
    User();

    void save_user_to_file(QString file_path);
    void load_user_from_file(QString folder_path);

    QString name;

    QString preferred_difficulty;
    QString preferred_character_mode;

    QList<GameStats *> game_stats;

    int wins();
    int total_games();

    bool is_difficulty(QString diff);
};

#endif // USER_H
