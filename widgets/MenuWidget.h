#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

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

    QString get_difficulty();
    QString get_word_type();

private slots:
    void on_button_play_clicked();
    void on_button_settings_clicked();

    void on_button_save_user_settings_clicked();

    void on_button_edit_users_clicked();

private:
    Ui::MenuWidget *ui;
};

#endif // MENUWIDGET_H
