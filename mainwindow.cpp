#include "mainwindow.h"
#include "CreateSecretWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hello World");
    CreateSecretWidget* _create_secret_widget = new CreateSecretWidget(this);
    setCentralWidget(_create_secret_widget);
}

MainWindow::~MainWindow() {}
