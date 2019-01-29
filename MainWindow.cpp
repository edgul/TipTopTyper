#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menu_widget = ui->page_menu;
    game_widget = ui->page_game;
    settings_widget = ui->page_settings;
    game_over_widget = ui->page_game_over;

    ui->stacked_widget->setCurrentIndex(SCREEN_MENU);

    connect(menu_widget, SIGNAL(change_screen(ScreenIndex)), this, SLOT(switch_screen(ScreenIndex)));
    connect(game_widget, SIGNAL(change_screen(ScreenIndex)), this, SLOT(switch_screen(ScreenIndex)));
    connect(settings_widget, SIGNAL(change_screen(ScreenIndex)), this, SLOT(switch_screen(ScreenIndex)));
    connect(game_over_widget, SIGNAL(change_screen(ScreenIndex)), this, SLOT(switch_screen(ScreenIndex)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::switch_screen(ScreenIndex screen_index)
{
    ui->stacked_widget->setCurrentIndex(screen_index);

    if (screen_index == SCREEN_GAME)
    {
        QString word_type = menu_widget->get_word_type();
        QString difficulty = menu_widget->get_difficulty();

        game_widget->start_game(word_type, difficulty);
    }
    else if (screen_index == SCREEN_GAME_OVER)
    {
        game_over_widget->set_game_stats(game_widget->game_stats);
    }
    else if (screen_index == SCREEN_MENU)
    {

    }
    else // settings
    {

    }

}
