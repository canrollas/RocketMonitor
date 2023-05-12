//
// Created by admin on 3/24/2023.
//

#include "attitude_widget.h"


attitude_widget::attitude_widget(QWidget *parent) {
    circular_view = new circular_graphics_view();
    // set the size of the widget
    circular_view->setBaseSize(800, 800);
    // set background color
    circular_view->setStyleSheet("background-color: black; border: 1px solid white; border-radius: 10px;");

}

attitude_widget::~attitude_widget() {


}
