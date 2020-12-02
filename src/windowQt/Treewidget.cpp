#include "Treewidget.hpp"

#include <QPainter>
#include <QDebug>

//
#include <cmath>

TreeWidget::TreeWidget(QWidget *parent, ArbreB tree)
    : QWidget(parent)
{
    huffmanTree = tree;
}

void drawData(QPainter* painter, Sommet* node, int centerX, int centerY, int radius) {
    QPen backupPen = painter->pen();
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 10));
    QString data;
    if(node->getData().car == '\0') {
        data = QString::number(node->getData().freq);
    }
    else {
        data = QString("(") + QString(node->getData().car) + QString(", ") + QString::number(node->getData().freq) + QString(")");
    }
    qDebug() << data;
    painter->drawText(centerX+radius/3, centerY+radius/2, data);
    painter->setPen(backupPen);
}

void drawNode(QPainter* painter, Sommet* node, int centerX, int centerY, int gap, int depth, int radius) {
    painter->drawEllipse(centerX, centerY, radius, radius);
    drawData(painter, node, centerX, centerY, radius);
    if(node->getRight()) {
        drawNode(painter, node->getRight(), centerX+(gap/pow(2, depth-1)), centerY+gap, gap, depth+1, radius);
    }
    if(node->getLeft()) {
        drawNode(painter, node->getLeft(), centerX-(gap/pow(2, depth-1)), centerY+gap, gap, depth+1, radius);
    }
    return;
}

void drawLink(QPainter* painter, Sommet* node, int centerX, int centerY, int gap, int depth, int radius) {
    if(node->getRight()) {
        painter->drawLine(centerX+radius/2, centerY+radius, centerX+(gap/pow(2, depth-1))+radius/2, centerY+gap);
        if(node->getRight()->getRight() || node->getRight()->getLeft()) {
            drawLink(painter, node->getRight(), centerX+(gap/pow(2, depth-1)), centerY+gap, gap, depth+1, radius);
        }
    }
    if(node->getLeft()) {
        painter->drawLine(centerX+radius/2, centerY+radius, centerX-(gap/pow(2, depth-1))+radius/2, centerY+gap);
        if(node->getLeft()->getRight() || node->getLeft()->getLeft()) {
            drawLink(painter, node->getLeft(), centerX-(gap/pow(2, depth-1)), centerY+gap, gap, depth+1, radius);
        }
    }
    return;
}

void TreeWidget::draw(QPainter* painter, int width, int height) {
    // setup
    int radius = 50, gap = 2*radius;
    // width = x, height = y
    int posX = width/2, posY = height/3;
    int centerX = posX - radius/2, centerY = posY - radius/2;

    painter->setPen(Qt::black);
    QColor myGreen(121,250,131);
    QColor myBrown(230,111,0);

    painter->setBrush(myGreen);
    painter->setPen(QPen(myGreen));
    drawNode(painter, huffmanTree.getRoot(), centerX, centerY, gap, 1, radius);

    painter->setPen(QPen(myBrown, 4));
    drawLink(painter, huffmanTree.getRoot(), centerX, centerY, gap, 1, radius);
}

void TreeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event); // Unused parameter
    QPainter painter(this);
    draw(&painter, width(), height());
}
