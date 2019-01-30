#ifndef USEREDITOR_H
#define USEREDITOR_H

#include <QWidget>
#include <QListWidgetItem>
#include "UserManager.h"

namespace Ui {
class UserEditor;
}

class UserEditor : public QWidget
{
    Q_OBJECT

public:
    explicit UserEditor(QWidget *parent = 0);
    ~UserEditor();

    void refresh();

signals:
    void update_current_user(User * username);

private slots:
    void on_button_ok_clicked();
    void on_button_load_users_clicked();

    void on_list_widget_users_itemSelectionChanged();

    void on_button_remove_user_clicked();

    void refresh_user_list();

    void on_button_add_new_user_clicked();

private:
    Ui::UserEditor * ui;

    User * user_by_name(QString username);

    QString selected_username();
};

#endif // USEREDITOR_H
