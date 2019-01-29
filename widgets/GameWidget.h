#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QKeyEvent>

#include "ScreenWidget.h"
#include "GameStats.h"
#include "SequenceStack.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public ScreenWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

    void start_game(QString game_word_type, QString game_difficulty);
    void game_over(bool win);

    void refresh();

    GameStats * game_stats;

private slots:
    void add_word();

    void update_timer();

    void game_timer_timeout();

private:
    Ui::GameWidget *ui;

    SequenceStack * sequence_stack;

    int overflow_limit;

    QString get_guess();

    void guess_word();

    QString word_type;

    void keyPressEvent(QKeyEvent *event);

    QTimer time_timer;
    QTimer word_timer;
    QTimer game_timer;

};

#endif // GAMEWIDGET_H
