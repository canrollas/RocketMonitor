//
// Created by admin on 5/12/2023.
//

#ifndef CENG318_ROCKETMAINWINDOW_H
#define CENG318_ROCKETMAINWINDOW_H

#include <QPushButton>
#include <QMainWindow>


class RocketMainWindow : public QMainWindow {
    /*
     * This class is used to display the main window of the application
     */
Q_OBJECT

public:
    // constructor
    RocketMainWindow();

    // destructor
    ~RocketMainWindow() override;

private:
    // create init_ui definition to initialize the user interface
    void init_ui();

    // create label layer => It includes Labels brand and buttons select boxes etc.
    void createFirstLayer();

    // create gyroscope layer => It includes gyroscope and accelerometer
    void createGyroscopeLayer();

    // create Location layer => It includes location and map
    void createLocationLayer();

    // create Velocity and Acceleration layer => It includes velocity and acceleration
    void createVelocityAndAccelerationLayer();

    // create 4part basic layer  it includes celcius, pressure, humidity and clock
    void create4PartBasicLayer();

    // create ignition layer => It includes ignition button
    void createIgnitionLayer();
    /*
     * According to our design. Label layer is the first layer. It includes labels, buttons, select boxes etc.
     * Label layer covers all horizontal area of the window. but height is 10% of the window.
     * Gyroscope is under the label layer. It covers ...
     * For basic explanation: We Will give relative coordinate starts and stops.
        All Window Width = 1920px All Window Height = 1080px
        When we create a grid system, Gyroscope layer will be 1/3 of the window width and 9/10 of the window height.
        When we create a grid system, Location layer will be 2/3 of the window width and 9/10 of the window height.
        When we create a grid system, Velocity and Acceleration layer will be 1/3 of the window width and 1/10 of the window height.
        When we create a grid system, 4PartBasic layer will be 2/3 of the window width and 1/10 of the window height.
        When we create a grid system, Ignition layer will be 1/3 of the window width and 1/10 of the window height.
     */





};


#endif //CENG318_ROCKETMAINWINDOW_H
