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
    QPalette pal = palette();
    pal.setColor(QPalette::Base, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(pal);
}

void MyTextEdit::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event); // unused param.

    if(clicDellText) {
        clear(); // Clear information text.
        clicDellText = false;
    }
}

void MyTextEdit::setInfo(QString information) {
    textInfo = information;
}

QString MyTextEdit::info() const {
    return textInfo;
}

void MyTextEdit::setClicDellText(bool newClicDellText) {
    clicDellText = newClicDellText;
}

void MyTextEdit::writeInfo() {
    setTextColor(Qt::darkGray);
    setText(textInfo);
    setTextColor(Qt::black);
}

MyTextEdit::~MyTextEdit()
{
    // Empty
}