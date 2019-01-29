#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <QWidget>
#include <QTimer>

#include "Sequence.h"
#include "QListWidget"

namespace Ui {
class SequenceStack;
}

class SequenceStack : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceStack(QWidget *parent = 0);
    ~SequenceStack();

    void add_sequence(QString text);

    int seq_index(QString seq);
    void add_random_sequence();
    void remove_sequence(int index);

    QList<QString> sequences;

    void refresh();

    void empty_stack();

    bool full();
    void set_stack_limit(int limit);

private:
    Ui::SequenceStack * ui;

    QListWidget * list_widget;

    int stack_max;


};

#endif // SEQUENCESTACK_H
