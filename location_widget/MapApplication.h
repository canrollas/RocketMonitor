//
// Created by admin on 5/12/2023.
//

#ifndef CENG318_MAPAPPLICATION_H
#define CENG318_MAPAPPLICATION_H

#include <QtWebEngineWidgets>
#include <QWidget>

class MapApplication : public QWidget{
    /*
     * This class will display the location of the rocket.
     * It will be included in the Map Widget.
     * Qt WebEngine provides functionality for rendering regions of dynamic web content.
     * It is based on the Chromium browser.
     *
     */

public:
    // constructor
    MapApplication();
    // destructor
    ~MapApplication() override;
    // This function will display the location of the rocket.
    void displayLocation();
private:
    QWebEngineView* webView;

};


#endif //CENG318_MAPAPPLICATION_H
