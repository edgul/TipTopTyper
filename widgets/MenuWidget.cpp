#include "MenuWidget.h"
#include "ui_menuwidget.h"

#include "UserEditor.h"

MenuWidget::MenuWidget(QWidget *parent) :
    ScreenWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);

    set_back_button_visibility(false);

    connect(&user_editor, SIGNAL(update_current_user(User *)), this, SLOT(change_current_user(User *)));

}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::refresh()
{

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

void MenuWidget::on_button_save_user_settings_clicked()
{
    QString username = ui->lineedit_user->text();

    QString difficulty = get_difficulty();

    User * user = UserManager::instance->user_by_name(username);

    if (user != 0)
    {
        user->preferred_difficulty = difficulty;
    }

    UserManager::instance->save_users();
}

void MenuWidget::on_button_edit_users_clicked()
{
    user_editor.show();
}

void MenuWidget::update_ui_from_user(User *user)
{
    if (user != 0)
    {
        // update ui based on new user
        ui->lineedit_user->setText(user->name);

        if (user->preferred_difficulty == DIFFICULTY_EASY) ui->radio_easy->setChecked(true);
        else if (user->preferred_difficulty == DIFFICULTY_MEDIUM) ui->radio_medium->setChecked(true);
        else if (user->preferred_difficulty == DIFFICULTY_DIFFICULT) ui->radio_difficult->setChecked(true);

    }
}

void MenuWidget::change_current_user(User *user)
{
    update_ui_from_user(user);
}

void MenuWidget::on_lineedit_user_returnPressed()
{
    QString username = ui->lineedit_user->text();
    User * user = UserManager::instance->user_by_name(username);

    update_ui_from_user(user);
}
