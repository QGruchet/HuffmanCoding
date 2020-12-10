#include "Myexitbutton.hpp"

#include <QDebug>

MyExitButton::MyExitButton(QWidget *parent)
    : QPushButton(parent)
{
    //
    QPixmap pixmap("src/windowQt/icons/close.png");
    QIcon buttonIcon(pixmap);
    setIcon(buttonIcon);
    int y = parent->height();
    int x = parent->width();
    int imgSize = x*40/100;
    setIconSize(QSize(imgSize, imgSize));
    setFixedSize(QSize(imgSize, imgSize));
    
    //
    setToolTip("Leave the application");
}

MyExitButton::~MyExitButton() {
    // Empty
}