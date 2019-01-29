#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Globals.h"

#include "GameWidget.h"
#include "MenuWidget.h"
#include "SettingsWidget.h"
#include "GameOverWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow * ui;

    GameWidget * game_widget;
    MenuWidget * menu_widget;
    SettingsWidget * settings_widget;
    GameOverWidget * game_over_widget;

private slots:
    void switch_screen(ScreenIndex screen_index);
};

#endif // MAINWINDOW_H
