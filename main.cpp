#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserEditor user_editor;

    MainWindow w;
    w.show();

    return a.exec();
}
