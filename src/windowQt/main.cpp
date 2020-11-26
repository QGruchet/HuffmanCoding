#include "Mainwindow.hpp"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    int sizeX = app.desktop()->width();
    int sizeY = app.desktop()->height();
    if(sizeX > 1920) {
        sizeX = 1920;
    }
    if(sizeY > 1080) {
        sizeY = 1080;
    }
    MainWindow w(nullptr, sizeX, sizeY);
    w.show();
    return app.exec();
}
