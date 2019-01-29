#include "User.h"

#include <QFile>
#include <QTextStream>
#include <iostream>

#define PARSER_ID_DIFFICULTY "DIFFICULTY"
#define PARSER_DELIMITER     ":"

User::User()
{
    name = "";

    preferred_character_mode = WORD_TYPE_ALPHABETIC;

    preferred_difficulty = DIFFICULTY_MEDIUM;
}

void User::save_user_to_file(QString folder_path)
{
    if (name != "")
    {
        QString full_path = folder_path + "/" + name;

        QFile file(full_path);
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            out << PARSER_ID_DIFFICULTY << PARSER_DELIMITER << preferred_difficulty << "\n";

            file.close();
        }
    }
}

void User::load_user_from_file(QString folder_path)
{
    QString full_path = folder_path + "/" + name;

    QFile file(full_path);
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                QString line = in.readLine();

                if (line.contains(PARSER_ID_DIFFICULTY))
                {
                    int delimiter_index = line.indexOf(PARSER_DELIMITER);

                    QString value = line.mid(delimiter_index+1, -1);

                    if (is_difficulty(value))
                    {
                        preferred_difficulty = value;
                    }
                    else
                    {
                        std::cout << "Error: Loading preferred difficulty" << std::endl;
                    }
                }
            }

            file.close();
        }
    }
}

bool User::is_difficulty(QString diff)
{
    bool result  = false;
    if (diff == DIFFICULTY_EASY) result = true;
    if (diff == DIFFICULTY_MEDIUM) result = true;
    if (diff == DIFFICULTY_DIFFICULT) result = true;
    return result;
}
