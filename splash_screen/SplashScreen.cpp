//
// Created by admin on 5/12/2023.
//

#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    // create the loading bar. (QProgressBar)
    loadingBar = new QProgressBar(this);

    this->setFixedSize(450, 450);
    this->setWindowTitle("Splash Screen");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // This line is used to make screen can be dragged by mouse
    this->setMouseTracking(true);


    // set background image of splash screen in upper directory named falcon.png
    QPixmap pixmap(R"(C:\Users\admin\CLionProjects\CENG318\images\splash_background.png)");
    // set the background image of splash screen and make image fits the size of splash screen
    pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    // make only image can be seen not the background of window
    this->setMask(pixmap.mask());
    // create timer to show the progress of loading

    // set the loading bar to the center of the screen
    loadingBar->setGeometry(0, 0, 300, 20);
    loadingBar->move(80, 350);
    loadingBar->setStyleSheet("QProgressBar {border: 2px solid grey; border-radius: 5px; padding: 1px}"
                              "QProgressBar::chunk {background-color: #4FCCFE;}"
                              // Text is centered in the progress bar
                                "QProgressBar{text-align: center;}"
                              );
    // create the timeout. (QTimer)
    timeoutTimer = new QTimer(this);
    // set timeout to 100 milliseconds
    timeoutTimer->setInterval(100);
    // connect the timeout to the function
    connect(timeoutTimer, &QTimer::timeout, this, &SplashScreen::updateLoadingBar);
    // start the timer
    timeoutTimer->start();

    oldPos = nullptr;


}

SplashScreen::~SplashScreen() = default;


/*
 * *****************************************
 * MOUSE MOVE EVENTS FOR DRAGGING THE SCREEN
 * *****************************************
 */

void SplashScreen::mousePressEvent(QMouseEvent *event) {
    // if the mouse is pressed, get the position of mouse
    oldPos = new QPointF(event->globalPosition());

}

void SplashScreen::mouseMoveEvent(QMouseEvent *event) {
    // if the mouse is pressed and moved, get the position of mouse
    if (!oldPos)
        return;
    const QPointF delta = event->globalPosition() - *oldPos;
    // move the screen to the new position
    move(x() + delta.x(), y() + delta.y());
    // update the position of mouse
    *oldPos = event->globalPosition();
}

void SplashScreen::mouseReleaseEvent(QMouseEvent *event) {
    // if the mouse is released, get the position of mouse
    oldPos = nullptr;
}

/*
 * *****************************************
 * END OF MOUSE MOVE EVENTS
 * *****************************************
 */






/*
 * *****************************************
 * PROGRESS BAR FUNCTIONS
 * *****************************************
 */

void SplashScreen::updateLoadingBar() {


    loadingCounter++;
    loadingBar->setValue(loadingCounter);
    // You can chekc your tests in here.
    // TODO: ADD YOUR TESTS HERE TO PROGRAM IS WORKING OR NOT
    //-----------------------------------------------
    if (loadingCounter == 100) {
        timeoutTimer->stop();
        this->close();
    }
}

/*
 * *****************************************
 * END OF PROGRESS BAR FUNCTIONS
 * *****************************************
 */