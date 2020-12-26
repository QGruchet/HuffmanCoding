/**
 * Titlewidget.cpp : You can found here the Titlewidget class.
 * Author : Quentin.
 * */

#ifndef TITLEWIDGET_HPP
#define TITLEWIDGET_HPP

#include <QObject>
#include <QWidget>
#include <QPalette>

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget*, int, int);
    
private:
    int widgetWidth, widgetHeight; // sizeX, sizeY

protected:
    void paintEvent(QPaintEvent*);

};

#endif // TILTEWIDGET_HPP
