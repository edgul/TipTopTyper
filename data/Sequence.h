#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QString>

#define NUM_SEQUENCE_TYPES (4)

#define LIST_ALPHABETIC (0)
#define LIST_NUMERIC    (1)
#define LIST_SYMBOLS    (2)
#define LIST_BRACKETS   (3)

static QString alphabetic = "abcdefghijklmnopqrstuvwxyz";
static QString numeric = "1234567890";
static QString symbols = "~!@#$%^&*-_=+|/<>;:";
static QString brackets = "[]{}()";

enum SequenceType
{
    DICTIONARY,
    COMMON,
    RANDOM
};

class Sequence
{
public:
    Sequence();
    Sequence(QString seq);

    QString sequence;

    SequenceType sequence_type;

    static QString random_sequence(int list_enum, int length);

    static QString numeric_random();
    static QString numeric_increasing();
    static QString numeric_decreasing();
    static QString numeric_same();

};

#endif // SEQUENCE_H
