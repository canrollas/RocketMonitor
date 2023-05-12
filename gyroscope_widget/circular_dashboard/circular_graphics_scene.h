//
// Created by admin on 3/22/2023.
//

#ifndef ROCKET_HMI_CIRCULAR_GRAPHICS_SCENE_H
#define ROCKET_HMI_CIRCULAR_GRAPHICS_SCENE_H


#include <QGraphicsScene>

class circular_graphics_scene : public QGraphicsScene{
    Q_OBJECT
public:
    explicit circular_graphics_scene(QGraphicsScene *parent = nullptr);
    ~circular_graphics_scene() override;
    // This is main class of the circular dashboard widget
    // It will be included GraphicalScene
    void addItemToScene(QGraphicsItem *item);
    void drawBackground(QPainter *painter, const QRectF &rect) override;


};


#endif //ROCKET_HMI_CIRCULAR_GRAPHICS_SCENE_H
