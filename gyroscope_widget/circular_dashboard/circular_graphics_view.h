//
// Created by admin on 3/22/2023.
//

#ifndef ROCKET_HMI_CIRCULAR_GRAPHICS_VIEW_H
#define ROCKET_HMI_CIRCULAR_GRAPHICS_VIEW_H


#include <QGraphicsView>
#include "circular_graphics_scene.h"
#include "graphics_items/circle_arround_qgi.h"
#include "graphics_items/parent_gyroscope.h"

class circular_graphics_view : public QGraphicsView{
    Q_OBJECT
public:
    explicit circular_graphics_view(QGraphicsView *parent = nullptr);
    ~circular_graphics_view() override;
    circular_graphics_scene *scene;
    parent_gyroscope *gyroscope;
    // This is main class of the circular dashboard widget
    // It will be included GraphicalScene
    int rotator_factor = 1;

private slots:
    void rotate_gyro_lines();
};


#endif //ROCKET_HMI_CIRCULAR_GRAPHICS_VIEW_H
