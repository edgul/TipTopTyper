#include "ScreenWidget.h"
#include "ui_screenwidget.h"

ScreenWidget::ScreenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
}

ScreenWidget::~ScreenWidget()
{
    delete ui;
}

void ScreenWidget::set_back_button_visibility(bool visible)
{
    ui->button_back->setVisible(visible);
}

void ScreenWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        emit change_screen(SCREEN_MENU);
    }
}

void ScreenWidget::on_button_back_clicked()
{
    emit change_screen(SCREEN_MENU);
}
