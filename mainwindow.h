#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class RevealSecretWidget;
class CreateSecretWidget;
class Sidebar;
class QHBoxLayout;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* _main_widget;
    QHBoxLayout* _layout;
    Sidebar* _sidebar;
    CreateSecretWidget* _create_secret_widget;
    RevealSecretWidget* _reveal_secret_widget;
};
#endif // MAINWINDOW_H
