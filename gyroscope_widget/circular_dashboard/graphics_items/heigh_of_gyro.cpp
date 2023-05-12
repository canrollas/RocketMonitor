//
// Created by admin on 3/24/2023.
//

#include "heigh_of_gyro.h"


heigh_of_gyro::heigh_of_gyro(QGraphicsItem *parent,int radius) :  QGraphicsItem(parent){
    // This class basically draws a circle around the widget.
    this->radius = radius;

}

heigh_of_gyro::~heigh_of_gyro() {

}

QRectF heigh_of_gyro::boundingRect() const {
    return QRectF( 0, 0, 100, 100);
}

void heigh_of_gyro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // draw lines horizontal
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    swipe_factor = swipe_factor % 20;

    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0){
            start_point_x = -(length_thin)/2 ;

            start_point_y = -radius  + (i+1) *20 + swipe_factor;
            painter->drawLine(start_point_x,start_point_y,-start_point_x,start_point_y);

        }


        else{
            start_point_x = -(length_bold)/2;

            start_point_y = -radius  + (i+1) *20 + swipe_factor;
            painter->drawLine(start_point_x,start_point_y,-start_point_x,start_point_y);

        }



    }



}
