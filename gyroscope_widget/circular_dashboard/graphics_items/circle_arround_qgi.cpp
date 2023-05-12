//
// Created by admin on 3/22/2023.
//


#include "circle_arround_qgi.h"

circle_arround_qgi::circle_arround_qgi(QGraphicsItem *parent): QGraphicsItem(parent){
    // set flags
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    // declare variables for the circle
    int circle_x = 0;
    int circle_y = 0;
    // create pen for the circle
    circle_pen = new QPen();
    circle_pen->setWidth(3);
    circle_pen->setColor(Qt::GlobalColor::yellow);
    // create brush for the circle
    gyro_lines = new heigh_of_gyro(this, circle_radius);
    // create effect for the circle
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(10);
    effect->setOffset(0);
    effect->setColor(Qt::GlobalColor::yellow);
    this->setGraphicsEffect(effect);




}

circle_arround_qgi::~circle_arround_qgi() {
    // destructor
    delete circle_pen;


}

QRectF circle_arround_qgi::boundingRect() const {
    // This function is used to draw the circle
    return QRectF( -1.2*circle_radius, -1.2*circle_radius, 2.4*circle_radius, 2.4*circle_radius);
}

void circle_arround_qgi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    // draw line to the center of the circle left to right
    // set to white
    QPen *line_pen = new QPen();
    line_pen->setColor(Qt::GlobalColor::green);
    line_pen->setWidth(2);
    painter->setPen(*line_pen);
    painter->setBrush(Qt::NoBrush);

    painter->drawEllipse(-1.2*circle_radius, -1.2*circle_radius, 2.4*circle_radius, 2.4*circle_radius);
    painter->drawEllipse(-circle_radius, -circle_radius, 2*circle_radius, 2*circle_radius);
    painter->setPen(*circle_pen);
    for (int i = 36; i <= 144; i += 18) {
        // print the lines to the center of the circle
        painter->drawLine(circle_radius * cos(-i * 3.14 / 180), circle_radius * sin(-i * 3.14 / 180), (circle_radius-10) * cos(-i * 3.14 / 180), (circle_radius-10) * sin(-i * 3.14 / 180));
        // paint the text to the circle for the angles.
        // angles are -57 to 57 degrees
        // draw text with angle rotate te painter and restore the painter
        painter->save();
        painter->setPen(Qt::GlobalColor::white);
        painter->translate((circle_radius+10) * cos(-i * 3.14 / 180), (circle_radius+5) * sin(-i * 3.14 / 180));
        painter->rotate(-i + 90);
        // disable the effect for the text
        painter->setRenderHint(QPainter::TextAntialiasing, false);
        painter->drawText(0, 0, QString::number(-i + 90));
        painter->restore();


    }
    // draw the circle
    painter->setPen(*circle_pen);


    painter->drawLine(-circle_radius/2, 0, circle_radius/2, 0);















}
