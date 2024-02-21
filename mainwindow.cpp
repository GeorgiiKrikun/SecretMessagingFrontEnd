#include "mainwindow.h"
#include "CreateSecretWidget.h"
#include "RevealSecretWidget.h"
#include "MainTabWidget.h"
#include <QHBoxLayout>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hello World");
    _main_widget = new MainTabWidget(this);
    setCentralWidget(_main_widget);
    _create_secret_widget = new CreateSecretWidget(this);
    _reveal_secret_widget = new RevealSecretWidget(this);
    _main_widget->addTab(_create_secret_widget, "Create Secret");
    _main_widget->addTab(_reveal_secret_widget, "Reveal Secret");


}

MainWindow::~MainWindow() {}
