#include "GameWidget.h"
#include "ui_gamewidget.h"

#include "MenuWidget.h"

#define STACK_MAX (10)

#define UPDATE_TIMER_INTERVAL       (300)
#define GAME_END_MILLI_SECONDS      (60000)

#define WORD_INTERVAL_MILLI_SECONDS_EASY      (2000)
#define WORD_INTERVAL_MILLI_SECONDS_MEDIUM    (1500)
#define WORD_INTERVAL_MILLI_SECONDS_DIFFICULT (1000)

GameWidget::GameWidget(QWidget *parent) :
    ScreenWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    game_stats = 0;

    sequence_stack = ui->sequence_stack;

    sequence_stack->set_stack_limit(STACK_MAX);

    set_back_button_visibility(false);

    connect(&time_timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    connect(&word_timer, SIGNAL(timeout()), this, SLOT(add_word()));
    connect(&game_timer, SIGNAL(timeout()), this, SLOT(game_timer_timeout()));
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::start_game(QString game_word_type, QString game_difficulty)
{
    sequence_stack->empty_stack();

    // TODO: clear the typing region

    word_type = game_word_type;

    int word_timeout = WORD_INTERVAL_MILLI_SECONDS_DIFFICULT;
    if (game_difficulty == DIFFICULTY_EASY)
    {
        word_timeout = WORD_INTERVAL_MILLI_SECONDS_EASY;
    }
    else if (game_difficulty == DIFFICULTY_MEDIUM)
    {
        word_timeout = WORD_INTERVAL_MILLI_SECONDS_MEDIUM;
    }

    if (game_stats != nullptr)
    {
        delete game_stats;
    }

    game_stats = new GameStats();

    ui->line_edit_input->setFocus();

    // start timers
    time_timer.start(UPDATE_TIMER_INTERVAL);
    word_timer.start(word_timeout);
    game_timer.start(GAME_END_MILLI_SECONDS);

}

void GameWidget::game_over(bool win)
{
    time_timer.stop();
    word_timer.stop();
    game_timer.stop();

    game_stats->win = win;

    // switch to end screen
    change_screen(SCREEN_GAME_OVER);
}

void GameWidget::refresh()
{
    // update timer
    int remaining_time_ms = game_timer.remainingTime();

    double remaining_time_s = (double) remaining_time_ms / 1000;
    QString remaining_time_string = QString("%1").arg(remaining_time_s);

    ui->label_time->setText(remaining_time_string);

    if (sequence_stack->full())
    {
        game_over(false);
    }

    sequence_stack->refresh();
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        guess_word();
    }
}

void GameWidget::guess_word()
{
    QString guess = ui->line_edit_input->text();

    int index = sequence_stack->seq_index(guess);

    // correct guess
    if (index != -1)
    {
        sequence_stack->remove_sequence(index);
    }
    else // incorrect
    {
        game_stats->errors++;
    }

    game_stats->attempts++;

    ui->line_edit_input->clear();

    refresh();
}

void GameWidget::add_word()
{
    QString seq_text;
    if (word_type == WORD_TYPE_NUMERIC)
    {
        seq_text = Sequence::numeric_random();
    }
    else if (word_type == WORD_TYPE_ALPHABETIC)
    {
        seq_text = Sequence::alphabetic();
    }
    else if (word_type == WORD_TYPE_ALPHANUMERIC)
    {
        seq_text = Sequence::alphanumeric();
    }

    sequence_stack->add_sequence(seq_text);

    refresh();
}

void GameWidget::update_timer()
{
    refresh();
}

void GameWidget::game_timer_timeout()
{
    game_over(true);
}

void GameWidget::on_button_quit_clicked()
{
    game_over(false);
}
