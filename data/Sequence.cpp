#include "Sequence.h"

#include <QList>

Sequence::Sequence()
{
    sequence = random_sequence(1, 3);

}

Sequence::Sequence(QString seq)
{
    sequence = seq;

}

QString Sequence::random_sequence(int list_enum, int length)
{
    QString char_list;
    if (list_enum == LIST_ALPHABETIC)
    {
        char_list = alphabetic;
    }
    else if (list_enum == LIST_NUMERIC)
    {
        char_list = numeric;
    }
    else if (list_enum == LIST_SYMBOLS)
    {
        char_list = symbols;
    }
    else // (list_enum == LIST_BRACKETS)
    {
        char_list = brackets;
    }

    QString result;
    for (int i = 0; i < length; i++)
    {
        int random_number = qrand() % char_list.length();

        result += char_list[random_number];

    }

    return result;
}

QString Sequence::numeric_random()
{
    QString result;

    int numeric_choice = qrand() % 3; // possible numeric functions

    if (numeric_choice == 0)
    {
        result = numeric_increasing();
    }
    else if (numeric_choice == 1)
    {
        result = numeric_decreasing();
    }
    else
    {
        result = numeric_same();
    }

    return result;
}
