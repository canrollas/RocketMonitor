//
// Created by admin on 5/12/2023.
//

#ifndef CENG318_GYROSCOPEWIDGET_H
#define CENG318_GYROSCOPEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include "gyroscope_console/GyroButtonsAndConsoles.h"
#include "circular_dashboard/circular_graphics_view.h"
#include <QLabel>
#include <QVBoxLayout>


class GyroscopeWidget: public QWidget {
    /*
     * This class is used to display the gyroscope widget
     * It will be displayed for 5 seconds. Runs some tests to check if the system is working properly.
     This class Consists of 3 Main Part .
     1) LAbel of Gyroscope ( It will be displayed on the top of the Gyroscope Widget )
     2) Gyroscope ( It will be displayed in under the label of Gyroscope )
     3) Buttons and consoles. ( It will be displayed in under the Gyroscope )
     */
    Q_OBJECT

public:
    // constructor
    GyroscopeWidget();
    // destructor
    ~GyroscopeWidget() override;


    QLabel *gyroscopeLabel;
    // Gyroscope Widget
    circular_graphics_view *gyroscopeWidget;
    // Buttons and Consoles
    GyroButtonsAndConsoles *buttonsAndConsoles;
private:
    // This function is used to initialize the user interface
    void init_ui();

};


#endif //CENG318_GYROSCOPEWIDGET_H
