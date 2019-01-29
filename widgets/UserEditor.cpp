#include "UserEditor.h"
#include "ui_UserEditor.h"

#include <QInputDialog>

UserEditor * UserEditor::instance = 0;

UserEditor::UserEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserEditor)
{
    ui->setupUi(this);

    setWindowTitle("User Editor");

    ui->lineedit_user_folder->setText("/home/ed/TipTopTyper/Users");

    connect(&user_manager, SIGNAL(update_files()), this, SLOT(refresh_user_list()));

    instance = this;
}

UserEditor::~UserEditor()
{
    delete ui;
}

void UserEditor::refresh()
{
    // update rightside with selected user info
    User * user = user_by_name(selected_username());

    if (user != 0)
    {
        ui->label_user->setText(user->name);
        ui->label_difficulty->setText(user->preferred_difficulty);
    }
}

void UserEditor::on_button_ok_clicked()
{
    User * user = user_by_name(selected_username());

    if (user != 0)
    {
        emit user_selected(user);
    }

    hide();
}

void UserEditor::refresh_user_list()
{
    ui->list_widget_users->clear();

    QList<User *> users = user_manager.get_users();

    foreach (User * user, users)
    {
        ui->list_widget_users->addItem(user->name);
    }
}

void UserEditor::on_button_load_users_clicked()
{
    QString folder_name = ui->lineedit_user_folder->text();

    user_manager.set_path(folder_name);

    user_manager.load_users();

    refresh_user_list();
}

void UserEditor::on_list_widget_users_itemSelectionChanged()
{
    refresh();
}

User * UserEditor::user_by_name(QString username)
{
    if (username == "") return 0;

    QList<User *> users = user_manager.get_users();

    User * selected_user = 0;
    foreach (User * user, users)
    {
        if (user->name == username)
        {
            selected_user = user;
            break;
        }
    }

    return selected_user;
}

QString UserEditor::selected_username()
{
    QList<QListWidgetItem *> items = ui->list_widget_users->selectedItems();

    QString selected_username = "";

    if (items.size() > 0)
    {
        selected_username = items[0]->text();
    }

    return selected_username;
}

void UserEditor::on_button_remove_user_clicked()
{
    QString username = selected_username();

    user_manager.remove_user(username);
}

void UserEditor::on_button_add_new_user_clicked()
{
    QString title = "Enter new username";
    QString label = "Username:";
    QString new_username = QInputDialog::getText(this, title, label);

    if (new_username != "")
    {
        user_manager.add_new_user(new_username);
    }
}
