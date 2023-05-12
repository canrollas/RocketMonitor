//
// Created by admin on 3/24/2023.
//

#ifndef ROCKET_HMI_ATTITUDE_WIDGET_H
#define ROCKET_HMI_ATTITUDE_WIDGET_H


#include <QWidget>
#include "circular_graphics_view.h"

class attitude_widget : public QWidget {
    Q_OBJECT
public:
    explicit attitude_widget(QWidget *parent = nullptr);
    ~attitude_widget() override;
    circular_graphics_view *circular_view;

    // This is main class of the circular dashboard widget
    // It will be included GraphicalScene
};


#endif //ROCKET_HMI_ATTITUDE_WIDGET_H
