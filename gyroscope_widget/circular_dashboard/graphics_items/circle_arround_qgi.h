//
// Created by admin on 3/22/2023.
//

#ifndef ROCKET_HMI_CIRCLE_ARROUND_QGI_H
#define ROCKET_HMI_CIRCLE_ARROUND_QGI_H


#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include "heigh_of_gyro.h"

class circle_arround_qgi : public  QGraphicsItem {

public:
    // This class basically draws a circle around the widget.
    explicit circle_arround_qgi(QGraphicsItem *parent = nullptr);
    ~circle_arround_qgi() override;
    // This is main class of the circular dashboard widget
    // It will be included GraphicalScene
    int circle_radius = 100;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPen *circle_pen;
    QBrush *circle_brush;
    heigh_of_gyro *gyro_lines;
    // make item is movable


};


#endif //ROCKET_HMI_CIRCLE_ARROUND_QGI_H
