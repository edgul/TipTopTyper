#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include <QWidget>

#include "ScreenWidget.h"
#include "GameStats.h"

namespace Ui {
class GameOverWidget;
}

class GameOverWidget : public ScreenWidget
{
    Q_OBJECT

public:
    explicit GameOverWidget(QWidget *parent = 0);
    ~GameOverWidget();

    void set_game_stats(GameStats *game_stats);

private slots:
    void on_button_again_clicked();

private:
    Ui::GameOverWidget *ui;
};

#endif // GAMEOVERWIDGET_H
