//
// Created by admin on 5/12/2023.
//


#include "GyroscopeWidget.h"

GyroscopeWidget::GyroscopeWidget() {
    // call to setStyleSheet function to set the background color of the Gyroscope Widget
    setStyleSheet("background-color: #383838;");
    // call init_ui function to initialize the user interface
    // create label of gyroscope
    gyroscopeLabel = new QLabel("Gyroscope and attitude");
    // create gyroscope
    // set label style sheet
    gyroscopeLabel->setStyleSheet("color: white; font-size: 15px;");
    // center the label
    gyroscopeLabel->setAlignment(Qt::AlignCenter);

    gyroscopeWidget = new circular_graphics_view();
    // create buttons and consoles
    buttonsAndConsoles = new GyroButtonsAndConsoles();


    init_ui();


}

GyroscopeWidget::~GyroscopeWidget() = default;

void GyroscopeWidget::init_ui() {
    // create a vertical layout
    auto *verticalLayout = new QVBoxLayout();
    // add label to the vertical layout
    verticalLayout->addWidget(gyroscopeLabel);
    // add gyroscope to the vertical layout
    verticalLayout->addWidget(gyroscopeWidget);
    // add buttons and consoles to the vertical layout
    // set the sizes of gyroscope widget
    gyroscopeWidget->setBaseSize(800, 800);
    verticalLayout->addWidget(buttonsAndConsoles);
    // set the layout of the Gyroscope Widget
    setLayout(verticalLayout);


}

