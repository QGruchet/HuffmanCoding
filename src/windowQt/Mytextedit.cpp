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
    // Empty
}

void MyTextEdit::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event); // unused param.

    clear(); // Clear information text.
}

void MyTextEdit::setInfo(QString information) {
    textInfo = information;
}

QString MyTextEdit::info() const {
    return textInfo;
}

void MyTextEdit::writeInfo() {
    setTextColor(Qt::gray);
    setText(textInfo);
    setTextColor(Qt::black);
}

MyTextEdit::~MyTextEdit()
{
    // Empty
}