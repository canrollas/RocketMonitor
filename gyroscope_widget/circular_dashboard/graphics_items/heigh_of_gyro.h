//
// Created by admin on 3/24/2023.
//

#ifndef ROCKET_HMI_HEIGH_OF_GYRO_H
#define ROCKET_HMI_HEIGH_OF_GYRO_H


#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QPainter>
class heigh_of_gyro: public QGraphicsItem {

public:
    // This class basically draws a circle around the widget.
    explicit heigh_of_gyro(QGraphicsItem *parent = nullptr,int radius = 100);
    ~heigh_of_gyro() override;
    // This is main class of the circular dashboard widget
    // It will be included GraphicalScene

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int start_point_x = 0;
    int start_point_y = 0;
    int length_bold = 80;
    int length_thin = 40;
    int radius = 0;
    int swipe_factor = 0;

};


#endif //ROCKET_HMI_HEIGH_OF_GYRO_H
