//
// Created by admin on 5/12/2023.
//

#ifndef CENG318_GYROBUTTONSANDCONSOLES_H
#define CENG318_GYROBUTTONSANDCONSOLES_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>

class GyroButtonsAndConsoles: public QWidget{
    // This class is used to display the buttons and consoles of the gyroscope widget

public:
    // constructor
    GyroButtonsAndConsoles();
    // destructor
    ~GyroButtonsAndConsoles() override;
    // create a function to update incoming data from the gyroscope.
    void updateIncomingData(QString gyrox, QString gyroy,QString gyroz,QString altitude,QString relativeAltitude,QString seaLevelAltitıde,QString ErrorCode);


private:
    // Start Stop Live Preview Button
    QPushButton *startStopLivePreviewButton;
    // Error Simulation Button
    QPushButton *errorSimulationButton;
    // Log into Flight Data Button
    QPushButton *logIntoFlightDataButton;
    // Instrument Diagnostic Button
    QPushButton *instrumentDiagnosticButton;
    // Text Edit for console output. ( It is not editable )
    QTextEdit *consoleOutput;
    // Error indicatior label
    QLabel *errorIndicatorLabel;
    // Error indicator line edit
    QLineEdit *errorIndicatorLineEdit;


    void init_ui();
};


#endif //CENG318_GYROBUTTONSANDCONSOLES_H
