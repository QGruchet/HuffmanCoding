/**
 * Mytextedit.cpp : You can found here all functions implemented for
 * the Mytextedit class.
 * Author : Quentin.
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

/**
 * *Description : clear default text.
 * @param event, not used.
 * */
void MyTextEdit::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event); // unused param.

    if(clicDellText) {
        clear();
        clicDellText = false;
    }
}

/**
 * *Description : set a new text info.
 * @param information, new text info.
 * */
void MyTextEdit::setInfo(QString information) {
    textInfo = information;
}

/**
 * *Description : get text info.
 * @return info.
 * */
QString MyTextEdit::info() const {
    return textInfo;
}

/**
 * *Description : set boolean if clic on textEdit dell the text.
 * @param newClicDellText, the new boolean.
 * */
void MyTextEdit::setClicDellText(bool newClicDellText) {
    clicDellText = newClicDellText;
}

/**
 * *Description : write text info in the textEdit.
 * */
void MyTextEdit::writeInfo() {
    setTextColor(Qt::darkGray);
    setText(textInfo);
    setTextColor(Qt::black);
}

/**
 * *Description : Destructor.
 * */
MyTextEdit::~MyTextEdit() {
    // Empty
}