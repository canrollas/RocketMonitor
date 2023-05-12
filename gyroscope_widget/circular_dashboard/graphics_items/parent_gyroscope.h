//
// Created by admin on 3/24/2023.
//

#ifndef ROCKET_HMI_PARENT_GYROSCOPE_H
#define ROCKET_HMI_PARENT_GYROSCOPE_H


#include <QGraphicsItem>
#include "circle_arround_qgi.h"

class parent_gyroscope : public QGraphicsItem{

    // It will hold all the graphics items of the gyroscope
    // It will be included GraphicalScene
public:
    explicit parent_gyroscope(QGraphicsItem *parent = nullptr);
    ~parent_gyroscope() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    // declare all cricle
    circle_arround_qgi *circle_arround;
private slots:

    void rotate_gyro_lines();

};


#endif //ROCKET_HMI_PARENT_GYROSCOPE_H
