#include "SequenceStack.h"
#include "ui_sequencestack.h"

SequenceStack::SequenceStack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceStack)
{
    ui->setupUi(this);

    list_widget = ui->list_widget;

    refresh();
}

SequenceStack::~SequenceStack()
{
    delete ui;
}

void SequenceStack::add_sequence(QString text)
{
    sequences.append(text);
}

void SequenceStack::add_random_sequence()
{
    QString seq = Sequence::random_sequence(1,3);

    sequences.append(seq);
}

void SequenceStack::remove_sequence(int index)
{
    if (index >= 0 && index < sequences.length())
    {
        sequences.removeAt(index);
    }
}

void SequenceStack::refresh()
{
    list_widget->clear();

    foreach (QString seq, sequences)
    {
        list_widget->addItem(seq);
    }

}

void SequenceStack::empty_stack()
{
    sequences.clear();
}

bool SequenceStack::full()
{
    bool result = false;

    if (sequences.length() > stack_max)
    {
        result = true;
    }

    return result;
}

void SequenceStack::set_stack_limit(int limit)
{
    stack_max = limit;
}

int SequenceStack::seq_index(QString seq)
{
    int result = -1;

    for (int i = 0; i < sequences.length(); i++)
    {
        if (sequences[i] == seq)
        {
            result = i;
            break;
        }
    }

    return result;
}
