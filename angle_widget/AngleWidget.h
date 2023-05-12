//
// Created by admin on 5/12/2023.
//

#ifndef CENG318_ANGLEWIDGET_H
#define CENG318_ANGLEWIDGET_H


#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class AngleWidget {
    // This class will display the angle of the rocket.
public:
    // constructor
    AngleWidget();
    // destructor
    ~AngleWidget();
    // This function will display the angle of the rocket.
    void displayAngle();
private:
    // Create X,y,z labels
    // Create X,y,z values they will be displayed on line edits

    QLabel *x_label;
    QLabel *y_label;
    QLabel *z_label;

    QLineEdit *x_value;
    QLineEdit *y_value;
    QLineEdit *z_value;

    // create 3 buttons Error simulation, Log into flight data, Instrument diagnostic
    QPushButton *error_simulation_button;
    QPushButton *log_into_flight_data_button;
    QPushButton *instrument_diagnostic_button;

    // create error indicator label and line edit
    QLabel *error_indicator_label;
    QLineEdit *error_indicator_line_edit;


};


#endif //CENG318_ANGLEWIDGET_H
