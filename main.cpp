#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Load an application style
    QFile styleFile( ":/DeepBox.qss");
    if (styleFile.open( QFile::ReadOnly )) {
        // Apply the loaded stylesheet
        QString style( styleFile.readAll() );
        a.setStyleSheet( style );
    } else {
        qErrnoWarning("Unable to open stylesheet file");
    }


    MainWindow w;
    w.show();
    return a.exec();
}
