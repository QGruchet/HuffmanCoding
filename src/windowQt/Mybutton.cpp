#include "Mybutton.hpp"

#include <QDebug>

MyButton::MyButton(QWidget *parent, QString pathicon)
    : QPushButton(parent)
{
    QPixmap pixmap(pathIcon = pathicon);
    QIcon buttonIcon(pixmap);
    setIcon(buttonIcon);
    int y = parent->height();
    int x = parent->width();
    int imgSize = x*40/100;
    setIconSize(QSize(imgSize, imgSize));
    setFixedSize(QSize(imgSize, imgSize));
}

MyButton::~MyButton() {
    // Empty
}