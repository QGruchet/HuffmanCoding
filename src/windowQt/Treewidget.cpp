#include "Treewidget.hpp"

#include <QPainter>
#include <QDebug>

//
#include <cmath>

TreeWidget::TreeWidget(QWidget *parent)
    : QWidget(parent) 
{
    // Empty
}

void TreeWidget::setHuffmanTree(ArbreB tree) {
    huffmanTree = tree;
}

void drawData(QPainter* painter, Sommet* node, int centerX, int centerY, int radius) {
    QPen backupPen = painter->pen();
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 10));
    QString data;
    if(node->isLeaf()) {
        data = QString("(") + QString(node->getData().car) + QString(", ") + QString::number(node->getData().freq) + QString(")");
        painter->drawText(centerX+radius/4, centerY+radius/2, data);
    }
    else {
        data = QString::number(node->getData().freq);
        painter->drawText(centerX+radius/3, centerY+radius/2, data);
    }
    painter->setPen(backupPen);
}

void drawNode(QPainter* painter, Sommet* node, int centerX, int centerY, int gapX, int gapY, int depth, int radius) {
    if(node->isLeaf()) {
        painter->drawEllipse(centerX, centerY, radius+radius/2, radius);
    }
    else {
        painter->drawEllipse(centerX, centerY, radius, radius);
    }
    drawData(painter, node, centerX, centerY, radius);
    if(node->getRight()) {
        drawNode(painter, node->getRight(), centerX+(gapX/pow(2, depth-1)), centerY+gapY, gapX, gapY, depth+1, radius);
    }
    if(node->getLeft()) {
        drawNode(painter, node->getLeft(), centerX-(gapX/pow(2, depth-1)), centerY+gapY, gapX, gapY, depth+1, radius);
    }
    return;
}

void drawLink(QPainter* painter, Sommet* node, int centerX, int centerY, int gapX, int gapY, int depth, int radius) {
    if(node->getRight()) {
        painter->drawLine(centerX+radius/2, centerY+radius, centerX+(gapX/pow(2, depth-1))+radius/2, centerY+gapY);
        if(node->getRight()->getRight() || node->getRight()->getLeft()) {
            drawLink(painter, node->getRight(), centerX+(gapX/pow(2, depth-1)), centerY+gapY, gapX, gapY, depth+1, radius);
        }
    }
    if(node->getLeft()) {
        painter->drawLine(centerX+radius/2, centerY+radius, centerX-(gapX/pow(2, depth-1))+radius/2, centerY+gapY);
        if(node->getLeft()->getRight() || node->getLeft()->getLeft()) {
            drawLink(painter, node->getLeft(), centerX-(gapX/pow(2, depth-1)), centerY+gapY, gapX, gapY, depth+1, radius);
        }
    }
    return;
}

void TreeWidget::draw(QPainter* painter, int width, int height) {
    // setup
    int radius = 35;
    int gapX, gapY; gapX = gapY = 2*radius; 
    // width = x, height = y
    int posX = width/2, posY = radius;
    int centerX = posX - radius/2, centerY = posY - radius/2;

    painter->setPen(Qt::black);
    QColor myGreen(121,250,131);
    QColor myBrown(230,111,0);

    painter->setBrush(myGreen);
    painter->setPen(QPen(myGreen));
    int depht = huffmanTree.getRoot()->countDepth();
    depht-=3;
    while(depht) {
        gapX *= 2;
        depht--;
    }
    drawNode(painter, huffmanTree.getRoot(), centerX, centerY, gapX, gapY, 1, radius);

    painter->setPen(QPen(myBrown, 4));
    drawLink(painter, huffmanTree.getRoot(), centerX, centerY, gapX, gapY, 1, radius);
}

void TreeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event); // Unused parameter
    QPainter painter(this);
    draw(&painter, width(), height());
}
