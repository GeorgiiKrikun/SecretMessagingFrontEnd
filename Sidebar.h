#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QFrame>

class Sidebar : public QFrame
{
    Q_OBJECT
public:
    explicit Sidebar(QWidget *parent = nullptr);

signals:
    void create_secret();
    void reveal_secret();
};

#endif // SIDEBAR_H
