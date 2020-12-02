#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "../lib/Tree.hpp"

class TreeWidget : public QWidget
{
    Q_OBJECT
private:
    ArbreB huffmanTree;

public:
    explicit TreeWidget(QWidget*, ArbreB);
    void draw(QPainter*, int, int);

protected:
    void paintEvent(QPaintEvent*);
};

#endif // TREEWIDGET2_H
