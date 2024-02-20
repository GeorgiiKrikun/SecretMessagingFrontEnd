#include "Sidebar.h"

#include <QPushButton>
#include <QVBoxLayout>

Sidebar::Sidebar(QWidget *parent)
    : QFrame(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QPushButton* create_secret_button = new QPushButton("Create Secret", this);
    QPushButton* reveal_secret_button = new QPushButton("Reveal Secret", this);
    layout->addWidget(create_secret_button);
    layout->addWidget(reveal_secret_button);
    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer);
    setFrameStyle(QFrame::Box);
    QObject::connect(create_secret_button, &QPushButton::clicked,
                     this, &Sidebar::create_secret);

    QObject::connect(reveal_secret_button, &QPushButton::clicked,
                     this, &Sidebar::reveal_secret);
}
