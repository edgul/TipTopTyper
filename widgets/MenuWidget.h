#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

#include "UserEditor.h"
#include "ScreenWidget.h"
#include "User.h"

namespace Ui {
class MenuWidget;
}

class MenuWidget : public ScreenWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = 0);
    ~MenuWidget();

    void refresh();

    QString get_difficulty();
    QString get_word_type();

    void update_ui_from_user(User *user);

private slots:
    void on_button_play_clicked();
    void on_button_settings_clicked();

    void on_button_save_user_settings_clicked();

    void on_button_edit_users_clicked();

    void change_current_user(User * user);

    void on_lineedit_user_returnPressed();

private:
    Ui::MenuWidget *ui;

    UserEditor user_editor;

};

#endif // MENUWIDGET_H
