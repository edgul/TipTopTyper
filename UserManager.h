#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>
#include <QMap>
#include <QObject>
#include "User.h"

class UserManager : public QObject
{
    Q_OBJECT
public:
    UserManager();

    void set_path(QString full_path);

    QList<User *> get_users();
    void load_users();
    void save_users();

    void add_user(QString username);
    void add_new_user(QString username);
    void remove_user(QString username);

signals:
    void update_files();
    void update_file(QString filename);

private:

    QString db_path;

    QMap<QString, User *> users;

};

#endif // USERMANAGER_H
