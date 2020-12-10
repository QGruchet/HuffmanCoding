/**
 * MyButton.cpp : You can found here all functions implemented for
 * the MyButton class.
 * Author : Quentin.
 **/

#include "Mybutton.hpp"

#include <QDebug>

/**
 * *Descirption : Constructor with parameter.
 * @param parent, the widget parent.
 * @param pathicon, the path for print the icon.
 * */
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