//
// Created by admin on 3/22/2023.
//

#include "circular_graphics_scene.h"


circular_graphics_scene::circular_graphics_scene(QGraphicsScene *parent) {


}

void circular_graphics_scene::addItemToScene(QGraphicsItem *item) {
    this->addItem(item);

}

void circular_graphics_scene::drawBackground(QPainter *painter, const QRectF &rect) {

    QGraphicsScene::drawBackground(painter, rect);
}

circular_graphics_scene::~circular_graphics_scene() = default;
