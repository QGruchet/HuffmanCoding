#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "../lib/Tree.hpp"

class TreeWidget : public QWidget
{
    Q_OBJECT
private:
    ArbreB tree;

public:
    explicit TreeWidget(QWidget* parent = nullptr);
    void setTree(ArbreB);
    void draw(QPainter*, int, int);

protected:
    void paintEvent(QPaintEvent*);
};

#endif // TREEWIDGET2_H
