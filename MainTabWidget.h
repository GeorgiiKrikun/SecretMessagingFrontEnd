#ifndef MAINTABWIDGET_H
#define MAINTABWIDGET_H

#include <QTabWidget>

class MainTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit MainTabWidget(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

signals:
};

#endif // MAINTABWIDGET_H
