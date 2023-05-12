//
// Created by admin on 3/22/2023.
//

#include "circular_graphics_view.h"
#include <QTimer>
circular_graphics_view::circular_graphics_view(QGraphicsView *parent) {
    gyroscope = new parent_gyroscope();
    scene = new circular_graphics_scene();
    setScene(scene);
    scene->addItem(gyroscope);
    // create text item for the widget that shows GYRO X,Y,Z and Attitude1, Attitude Rel, Attitude Sea Level
    QGraphicsTextItem *gyro_x = new QGraphicsTextItem("GYRO X");
    QGraphicsTextItem *gyro_y = new QGraphicsTextItem("GYRO Y");
    QGraphicsTextItem *gyro_z = new QGraphicsTextItem("GYRO Z");
    QGraphicsTextItem *attitude1 = new QGraphicsTextItem("Attitude");
    QGraphicsTextItem *attitude_rel = new QGraphicsTextItem("Attitude Rel");
    QGraphicsTextItem *attitude_sea_level = new QGraphicsTextItem("Attitude Sea Level");
    // set font size
    QFont font;
    font.setPixelSize(10);
    gyro_x->setFont(font);
    gyro_y->setFont(font);
    gyro_z->setFont(font);
    attitude1->setFont(font);
    attitude_rel->setFont(font);
    attitude_sea_level->setFont(font);
    // set color
    gyro_x->setDefaultTextColor(Qt::white);
    gyro_y->setDefaultTextColor(Qt::white);
    gyro_z->setDefaultTextColor(Qt::white);
    attitude1->setDefaultTextColor(Qt::white);
    attitude_rel->setDefaultTextColor(Qt::white);
    attitude_sea_level->setDefaultTextColor(Qt::white);
    // set position
    // gyros are uppper of the gyroscope item and attitude items are lower of the gyroscope item
    gyro_x->setPos(-30, 0);
    gyro_y->setPos(30, 0);
    gyro_z->setPos(90, 0);
    attitude1->setPos(-30, 290);
    attitude_rel->setPos(60, 290);
    attitude_sea_level->setPos(185, 290);
    // add items to the scene
    scene->addItem(gyro_x);
    scene->addItem(gyro_y);
    scene->addItem(gyro_z);
    scene->addItem(attitude1);
    scene->addItem(attitude_rel);
    scene->addItem(attitude_sea_level);
    // set the position of the gyroscope item
    gyroscope->setPos(0, 20);



    qInfo() << "circular_graphics_view::circular_graphics_view(QGraphicsView *parent) {";
    // smooth anti-aliasing
    setRenderHint(QPainter::Antialiasing);
    QTimer *timer = new QTimer();
    // set background color
    setStyleSheet("background-color: black; border: 0px solid white; border-radius: 10px;");
    timer->start(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_gyro_lines()));
    // disable move and resize
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // disable drag and drop of the widget
    setDragMode(QGraphicsView::NoDrag);
    // disable zooming
    setTransformationAnchor(QGraphicsView::NoAnchor);
    setResizeAnchor(QGraphicsView::NoAnchor);
    setInteractive(false);
    setMouseTracking(false);
    setFocusPolicy(Qt::NoFocus);
    setEnabled(false);


}

circular_graphics_view::~circular_graphics_view() {

}

void circular_graphics_view::rotate_gyro_lines() {

    gyroscope->circle_arround->setRotation(gyroscope->circle_arround->rotation() + 1);

    rotator_factor++;
    if (gyroscope->circle_arround->gyro_lines->swipe_factor == 19) {
        gyroscope->circle_arround->gyro_lines->swipe_factor = 0;
    } else
        gyroscope->circle_arround->gyro_lines->swipe_factor = gyroscope->circle_arround->gyro_lines->swipe_factor + 1;

}
