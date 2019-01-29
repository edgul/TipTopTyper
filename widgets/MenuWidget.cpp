#include "MenuWidget.h"
#include "ui_menuwidget.h"

#define DIFFICULTY_EASY         "Easy"
#define DIFFICULTY_MEDIUM       "Medium"
#define DIFFICULTY_DIFFICULT    "Difficult"

#define WORD_TYPE_ALPHABETIC    "Alphabetic"
#define WORD_TYPE_NUMERIC       "Numeric"
#define WORD_TYPE_ALPHANUMERIC  "Alphanumeric"

MenuWidget::MenuWidget(QWidget *parent) :
    ScreenWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);

    set_back_button_visibility(false);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

QString MenuWidget::get_difficulty()
{
    QString difficulty = DIFFICULTY_DIFFICULT;

    if (ui->radio_easy->isChecked())
    {
        difficulty = DIFFICULTY_EASY;
    }
    else if ( ui->radio_medium->isChecked())
    {
        difficulty = DIFFICULTY_MEDIUM;
    }

    return difficulty;
}

QString MenuWidget::get_word_type()
{
    QString word_type = WORD_TYPE_ALPHANUMERIC;

    if (ui->radio_alphabetic->isChecked())
    {
        word_type = WORD_TYPE_ALPHABETIC;
    }
    else if ( ui->radio_numeric->isChecked())
    {
        word_type = WORD_TYPE_NUMERIC;
    }

    return word_type;
}

void MenuWidget::on_button_play_clicked()
{
    emit change_screen(SCREEN_GAME);
}

void MenuWidget::on_button_settings_clicked()
{
    emit change_screen(SCREEN_SETTINGS);
}