//
// Created by admin on 5/12/2023. CAN ROLLAS
//

#ifndef CENG318_SPLASHSCREEN_H
#define CENG318_SPLASHSCREEN_H


#include <QTimer>
#include <QProgressBar>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QApplication>
#include <QPushButton>
#include <QObject>

class SplashScreen : public QWidget{
    /*
     * This class is used to display the splash screen
     * It will be displayed for 5 seconds. Runs some tests to check if the system is working properly.
     */
    Q_OBJECT
public:
    // constructor
    SplashScreen();
    // destructor
    ~SplashScreen() override;
    // create the loading bar definition. (QProgressBar)
    //void createLoadingBar();
    // create timeout definition. (QTimer)
    //void createTimeout();
    // create the splash screen definition. (QSplashScreen)
    //void createSplashScreen();




private:
    // create the loading bar. (QProgressBar)
    QProgressBar *loadingBar{};
    // create the timeout. (QTimer)
    QTimer *timeoutTimer;
    // oldPos is used to get the position of mouse
    QPointF* oldPos;
    // create override functions for mouse events
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    // create loadding counter integer.
    int loadingCounter = 0;

private slots:
    void updateLoadingBar();

};


#endif //CENG318_SPLASHSCREEN_H
