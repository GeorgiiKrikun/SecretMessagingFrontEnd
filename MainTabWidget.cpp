#include "MainTabWidget.h"

MainTabWidget::MainTabWidget(QWidget *parent)
    : QTabWidget(parent)
{}

void MainTabWidget::resizeEvent(QResizeEvent *event)
{
    QTabWidget::resizeEvent(event);
    QSize new_size  = this->size();
    if (new_size.width() > new_size.height())
    {
        setTabPosition(QTabWidget::West);
    }
    else
    {
        setTabPosition(QTabWidget::North);
    }

}
