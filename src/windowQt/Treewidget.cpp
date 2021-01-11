/**
 * Treewidget.cpp : You can found here all functions implemented for
 * the Treewidget class.
 * Author : Quentin.
 **/

#include "Treewidget.hpp"

#include <QPainter>
#include <QDebug>

#include <cmath> // for pow

/**
 * *Description : default constructor.
 * @param parent = nullptr
 * */
TreeWidget::TreeWidget(QWidget *parent)
    : QWidget(parent) 
{
    // Empty
}

/**
 * *Description : set the tree for drawing it.
 * @param newTree
 * */
void TreeWidget::setTree(ArbreB newTree) {
    tree = newTree;
}

/**
 * *Description : Write informations in all nodes.
 * @param painter for draw.
 * @param node, for get informations.
 * @param centerX, coords in x where we write.
 * @param centerY, coords in y where we write.
 * @param raduis, the radius of the node.
 * */
void drawData(QPainter* painter, Sommet* node, int centerX, int centerY, 
                                                            int radius) {

    QPen backupPen = painter->pen();
    // Setup new pen.
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 10));
    
    // Write informations.
    QString data;
    if(node->isLeaf()) { // Write freq and char.
        data = QString("(") + QString(node->getData().car) + QString(", ") 
            + QString::number(node->getData().freq) + QString(")");
        painter->drawText(centerX+radius/4, centerY+radius/2+5, data);
    }
    else { // Write only freq.
        data = QString::number(node->getData().freq);
        painter->drawText(centerX+radius/3, centerY+radius/2+5, data);
    }


    painter->setPen(backupPen);
}

/**
 * *Description : Draw circle recursively we represent the node.
 * @param painter for draw.
 * @param node, for get informations.
 * @param centerX, coords in x where we write.
 * @param centerY, coords in y where we write.
 * @param gapX, the distance between nodes in x.
 * @param gapY, the distance between nodes in y.
 * @param depth, the depth of the tree.
 * @param raduis, the radius of the node.
 * */
void drawNode(QPainter* painter, Sommet* node, int centerX, int centerY,
                                int gapX, int gapY, int depth, int radius) {
    // Draw circle.
    if(node->isLeaf()) { // Draw ellispe, we write freq and char, take more place.
        painter->drawEllipse(centerX, centerY, radius+radius/2, radius);
    }
    else { // Draw circle, we write only freq.
        painter->drawEllipse(centerX, centerY, radius, radius);
    }

    // Write informations.
    drawData(painter, node, centerX, centerY, radius);
    
    // Recursif.
    if(node->getRight()) { // Go right.
        drawNode(painter, node->getRight(), centerX+(gapX/pow(2, depth-1)),
                                centerY+gapY, gapX, gapY, depth+1, radius);
    }
    if(node->getLeft()) { // Go left.
        drawNode(painter, node->getLeft(), centerX-(gapX/pow(2, depth-1)),
                centerY+gapY, gapX, gapY, depth+1, radius);
    }
    return;
}

/**
 * *Description : Draw line between nodes.
 * @param painter for draw.
 * @param node, for get informations.
 * @param centerX, coords in x where we write.
 * @param centerY, coords in y where we write.
 * @param gapX, the distance between nodes in x.
 * @param gapY, the distance between nodes in y.
 * @param depth, the depth of the tree.
 * @param raduis, the radius of the node.
 * */
void drawLink(QPainter* painter, Sommet* node, int centerX, int centerY,
                int gapX, int gapY, int depth, int radius) {
    
    if(node->getRight()) { // Go right.
        painter->drawLine(centerX+radius/2, centerY+radius,
            centerX+(gapX/pow(2, depth-1))+radius/2, centerY+gapY);
        
        // If node have child, draw line.
        if(node->getRight()->getRight() || node->getRight()->getLeft()) {
            drawLink(painter, node->getRight(), centerX+(gapX/pow(2, depth-1)),
                    centerY+gapY, gapX, gapY, depth+1, radius);
        }
    }
    if(node->getLeft()) { // Go left.
        painter->drawLine(centerX+radius/2, centerY+radius,
                        centerX-(gapX/pow(2, depth-1))+radius/2, centerY+gapY);
        
        // If node have child, draw line.
        if(node->getLeft()->getRight() || node->getLeft()->getLeft()) {
            drawLink(painter, node->getLeft(), centerX-(gapX/pow(2, depth-1)),
                    centerY+gapY, gapX, gapY, depth+1, radius);
        }
    }
    return;
}

/**
 * *Description : Draw tree.
 * @param painter for draw.
 * @param width the widht.
 * @param heigth the heigth.
 * */
void TreeWidget::draw(QPainter* painter, int width, int height) {
    
    // setup parameters for drawing.
    int radius = 35;
    int gapX, gapY; gapX = gapY = 2*radius; 

    int posX = width/2, posY = radius; // width = x, height = y.
    int centerX = posX - radius/2, centerY = posY - radius/2;

    // Setup pen.
    painter->setPen(Qt::black);
    QColor myGreen(121,250,131);
    QColor myBrown(230,111,0);

    // Setup drawing nodes.
    painter->setBrush(myGreen);
    painter->setPen(QPen(myGreen));
    int depht = tree.getRoot()->countDepth();
    
    // Init distance in x between two nodes.
    depht-=3;
    while(depht) {
        gapX *= 2;
        depht--;
    }
    drawNode(painter, tree.getRoot(), centerX, centerY, gapX, gapY, 1, radius);

    // Setup drawing link.
    painter->setPen(QPen(myBrown, 4));
    drawLink(painter, tree.getRoot(), centerX, centerY, gapX, gapY, 1, radius);
}

/**
 * *Description : main function paintEvent.
 * @param event, not used.
 * */
void TreeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event); // Unused parameter evite de raler lorsqu'il compil. pour ne pas voir que *event n'est pas utilise
    QPainter painter(this);
    draw(&painter, width(), height());
}

/**
 * *Description : destructor
 * */
TreeWidget::~TreeWidget() {
    //Empty
}