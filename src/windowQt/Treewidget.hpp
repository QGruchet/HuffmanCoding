#ifndef TREEWIDGET_HPP
#define TREEWIDGET_HPP

#include <QWidget>
#include "../lib/Tree.hpp"

class TreeWidget : public QWidget
{
    Q_OBJECT
private:
    /* Data */
    ArbreB tree;

public:
    /* Constructor */
    explicit TreeWidget(QWidget* parent = nullptr);

    /* Functions */
    void setTree(ArbreB);
    void draw(QPainter*, int, int);

    /* Destructor */
    ~TreeWidget();

protected:
    /* paint */ 
    void paintEvent(QPaintEvent*);
};

#endif // TREEWIDGET_HPP
