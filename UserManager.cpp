#include "UserManager.h"

#include <QDir>
#include <QList>
#include <QString>
#include <QFileInfo>

UserManager * UserManager::instance = 0;

UserManager::UserManager()
{
    db_path = "/temp";

    instance = this;

}

void UserManager::set_path(QString full_path)
{
    if (full_path != "")
    {
        db_path = full_path;
    }
}

User * UserManager::user_by_name(QString username)
{
    User * user = 0;

    if (users.contains(username))
    {
        user = users[username];
    }

    return user;
}

QList<User *> UserManager::get_users()
{
    return users.values();
}

void UserManager::load_users()
{
    qDeleteAll(users);

    QDir db_dir(db_path);
    QList<QFileInfo> files = db_dir.entryInfoList(QDir::Files);

    foreach (QFileInfo file, files)
    {
        QString filename = file.fileName();

        add_user(filename);
    }
}

void UserManager::save_users()
{
    foreach (User * user, users.values())
    {
        user->save_user_to_file(db_path);
    }
}

void UserManager::add_user(QString username)
{
    User * user = new User();
    user->name = username;
    user->load_user_from_file(db_path);

    users.insert(user->name, user);
}

void UserManager::add_new_user(QString username)
{
    add_user(username);

    save_users();
}

void UserManager::remove_user(QString username)
{
    if (users.contains(username))
    {
        User * user = users.take(username);
        QString full_path = db_path + "/" + user->name;

        QDir dir(full_path);
        if (dir.remove(full_path))
        {
            emit update_files();
        }
    }
}
