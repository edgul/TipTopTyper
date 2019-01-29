#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>
#include <QKeyEvent>

#include "Globals.h"

namespace Ui {
class ScreenWidget;
}

class ScreenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenWidget(QWidget *parent = 0);
    ~ScreenWidget();

    void set_back_button_visibility(bool visible);

signals:
    void change_screen(ScreenIndex screen_widget);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_button_back_clicked();

private:
    Ui::ScreenWidget *ui;
};

#endif // SCREENWIDGET_H
