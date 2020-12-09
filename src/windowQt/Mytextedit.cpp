/**
 * Mytextedit.cpp : You can found here all functions implemented for
 * the Mytextedit class.
 * Author : Mickael.
 **/

#include "Mytextedit.hpp"

/**
 * *Description : default constructor.
 * @param parent = nullptr
 * */
MyTextEdit::MyTextEdit(QWidget *parent)
    : QTextEdit() 
{
    //
}

void MyTextEdit::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event); // unused param.

    clear(); // Clear information text.
}

void MyTextEdit::setInfo(QString information) {
    info = information;
}

void MyTextEdit::writeInfo() {
    setTextColor(Qt::gray);
    setText(info);
    setTextColor(Qt::black);
}

MyTextEdit::~MyTextEdit()
{
    // Empty
}