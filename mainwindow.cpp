#include "mainwindow.h"
#include "CreateSecretWidget.h"
#include "RevealSecretWidget.h"
#include "Sidebar.h"
#include <QHBoxLayout>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hello World");
    _main_widget = new QWidget(this);
    setCentralWidget(_main_widget);

    _layout = new QHBoxLayout(_main_widget);

    _sidebar = new Sidebar(this);
    _layout->addWidget(_sidebar);

    _create_secret_widget = new CreateSecretWidget(this);
    _layout->addWidget(_create_secret_widget);

    _reveal_secret_widget = new RevealSecretWidget(this);
    _layout->addWidget(_reveal_secret_widget);
    _reveal_secret_widget->hide();

    _sidebar->connect(_sidebar, &Sidebar::create_secret, this, [&](){
        _create_secret_widget->show();
        _reveal_secret_widget->hide();
    });

    _sidebar->connect(_sidebar, &Sidebar::reveal_secret, this, [&](){
        _create_secret_widget->hide();
        _reveal_secret_widget->show();
    });
}

MainWindow::~MainWindow() {}
