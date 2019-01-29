#include "GameOverWidget.h"
#include "ui_gameoverwidget.h"

#include <QString>

GameOverWidget::GameOverWidget(QWidget *parent) :
    ScreenWidget(parent),
    ui(new Ui::GameOverWidget)
{
    ui->setupUi(this);
}

GameOverWidget::~GameOverWidget()
{
    delete ui;
}

void GameOverWidget::set_game_stats(GameStats * game_stats)
{
    int errors = game_stats->errors;
    int attempts = game_stats->attempts;
    int correct = attempts - errors;

    QString errors_string = QString("%1").arg(errors);
    QString correct_string = QString("%1").arg(correct);
    QString attempts_string = QString("/%1").arg(attempts);

    ui->label_correct->setText(correct_string);
    ui->label_errors->setText(errors_string);
    ui->label_total->setText(attempts_string);

    QString win_string;

    if (game_stats->win)
    {
        win_string = "You Win!";
    }
    else
    {
        win_string = "You lose.";
    }

    ui->label_title->setText(win_string);
}

void GameOverWidget::on_button_again_clicked()
{
    change_screen(SCREEN_GAME);
}
