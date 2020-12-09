/**
 * Tiltewidget.cpp : You can found here the Tiltewidget class.
 * Author : Mickael.
 * */

#ifndef TILTEWIDGET_HPP
#define TILTEWIDGET_HPP

#include <QObject>
#include <QWidget>

class TilteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TilteWidget(QWidget*, int, int);
    
private:
    int widgetWidth, widgetHeight; // sizeX, sizeY

protected:
    void paintEvent(QPaintEvent*);

};

#endif // TILTEWIDGET_HPP
