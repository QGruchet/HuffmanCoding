/**
 * main.cpp : You can found here all functions implemented for
 * the main class.
 * Author : Quentin.
 **/

#include "Mainwindow.hpp"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Setup size.
    int sizeX = app.desktop()->width();
    int sizeY = app.desktop()->height();
    if(sizeX > 1920) {
        sizeX = 1920;
    }
    if(sizeY > 1080) {
        sizeY = 1080;
    }

    // Start main window.
    MainWindow w;
    w.setWidth(sizeX); w.setHeight(sizeY);
    w.setup();
    w.show();

    //
    return app.exec();
}
