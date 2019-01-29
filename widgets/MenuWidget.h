#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

#include "ScreenWidget.h"

#define DIFFICULTY_EASY         "Easy"
#define DIFFICULTY_MEDIUM       "Medium"
#define DIFFICULTY_DIFFICULT    "Difficult"

#define WORD_TYPE_ALPHABETIC    "Alphabetic"
#define WORD_TYPE_NUMERIC       "Numeric"
#define WORD_TYPE_ALPHANUMERIC  "Alphanumeric"

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

private:
    Ui::MenuWidget *ui;
};

#endif // MENUWIDGET_H
