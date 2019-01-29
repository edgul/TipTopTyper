#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>

#include "ScreenWidget.h"

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public ScreenWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();

private:
    Ui::SettingsWidget *ui;

    // letters
    // CAPS letters
    // numbers
    // symbols
};

#endif // SETTINGSWIDGET_H
