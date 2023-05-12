//
// Created by admin on 3/24/2023.
//

#include "parent_gyroscope.h"
#include <QTimer>
parent_gyroscope::parent_gyroscope(QGraphicsItem *parent) : QGraphicsItem(parent) {

    circle_arround = new circle_arround_qgi(this);
    circle_arround->setPos(140,140);
    circle_arround->setZValue(0);
    // set z value
    setZValue(2);
    // add image

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap("images:red_triangle.png"));
    pixmapItem->setParentItem(this);
    // set size of image
    pixmapItem->setScale(0.1);
    // get size of image scaled
    QSize size = pixmapItem->pixmap().size();



    pixmapItem->setPos(140-0.1*size.width()/2,0);
    pixmapItem->setZValue(1);
    QTimer *timer = new QTimer();
    timer->start(1000);







}

parent_gyroscope::~parent_gyroscope() {

}

QRectF parent_gyroscope::boundingRect() const {
    return QRectF(0,0,280,280);
}

void parent_gyroscope::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    // draw center of the circle that is like plane
    // set painter is z value greater than 1

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);

    painter->setPen(pen);
    painter->drawLine(40,140,240,140);













}
