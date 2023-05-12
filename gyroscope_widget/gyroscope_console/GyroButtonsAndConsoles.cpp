//
// Created by admin on 5/12/2023. CAN ROLLAS
//

#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include "GyroButtonsAndConsoles.h"

GyroButtonsAndConsoles::GyroButtonsAndConsoles() {
    // create start stop live preview button
    startStopLivePreviewButton = new QPushButton("Start/Stop");
    // create error simulation button
    errorSimulationButton = new QPushButton("Error Simulation");
    // create log into flight data button
    logIntoFlightDataButton = new QPushButton("Log into Flight Data");
    // create instrument diagnostic button
    instrumentDiagnosticButton = new QPushButton("Inst.Diagnostic");
    // create console output text edit
    consoleOutput = new QTextEdit();
    // create error indicator label
    errorIndicatorLabel = new QLabel("Error Indicator");
    // create error indicator line edit
    errorIndicatorLineEdit = new QLineEdit();

    // init_ui function is called to initialize the user interface
    // create a effect
    auto *effect = new QGraphicsDropShadowEffect();
    auto *effect2 = new QGraphicsDropShadowEffect();
    auto *effect3 = new QGraphicsDropShadowEffect();
    auto *effect4 = new QGraphicsDropShadowEffect();

    effect->setBlurRadius(40);
    effect->setOffset(0);
    effect->setColor("#40D0FB");
    effect2->setBlurRadius(40);
    effect2->setOffset(0);
    effect2->setColor("#40D0FB");
    effect3->setBlurRadius(40);
    effect3->setOffset(0);
    effect3->setColor("#40D0FB");
    effect4->setBlurRadius(40);
    effect4->setOffset(0);
    effect4->setColor("#40D0FB");

    // set effect to buttons
    startStopLivePreviewButton->setGraphicsEffect(effect);
    errorSimulationButton->setGraphicsEffect(effect2);
    logIntoFlightDataButton->setGraphicsEffect(effect3);
    instrumentDiagnosticButton->setGraphicsEffect(effect4);

    init_ui();

}

void GyroButtonsAndConsoles::init_ui() {
    // create grid layout for the widget
    auto *gridLayout = new QGridLayout();
    // set the grid layout to the widget
    setLayout(gridLayout);
    // First Column of the grid will be for buttons.
    // Second Column of the grid will be for consoles and bottom of the consoles indicator labels and line edits will be placed.

    gridLayout->addWidget(startStopLivePreviewButton, 0, 0);
    gridLayout->addWidget(errorSimulationButton, 1, 0);
    gridLayout->addWidget(logIntoFlightDataButton, 2, 0);
    gridLayout->addWidget(instrumentDiagnosticButton, 3, 0);
    gridLayout->addWidget(consoleOutput, 0, 1, 4, 1);
    gridLayout->addWidget(errorIndicatorLabel, 4, 0);
    gridLayout->addWidget(errorIndicatorLineEdit, 4, 1);
    // all widgets are set to the grid layout.

    // set backgrodund is transparent
    setAttribute(Qt::WA_TranslucentBackground);

    // disable editing of the console output
    consoleOutput->setReadOnly(true);
    // set error indicator line edit to be not editable
    errorIndicatorLineEdit->setReadOnly(true);
    // set line edit text
    errorIndicatorLineEdit->setText("No Error Occurred");
    // set text alignment of the error indicator line edit
    errorIndicatorLineEdit->setAlignment(Qt::AlignCenter);
    // set text alignment of the error indicator label
    errorIndicatorLabel->setAlignment(Qt::AlignCenter);
    // set style sheet this
    setStyleSheet("QPushButton{\n"
                  "    background-color: #1F1F1F;\n"
                  "    border: 0px solid rgb(0, 0, 0);\n"
                  "    border-radius: 4px;\n"
                  "    color: #40D0FB;\n"
                  "    height: 30px;\n"
                  "    /*\n"
                  "    add shadow to the button\n"
                  "     */\n"
                  "\n"
                  "\n"
                  "\n"
                  "}\n"
                  "QPushButton:hover{\n"
                  "    background-color: #3D3D3D;\n"
                  "}\n"
                  "QPushButton:pressed{\n"
                  "    background-color: #1F1F1F;\n"
                  "}\n"
                  "QTextEdit{\n"
                  "    background-color: #000000;\n"
                  "    border: 0px solid rgb(0, 0, 0);\n"
                  "    border-radius: 4px;\n"
                  "    /*\n"
                  "    Text color is set to #40D0FB\n"
                  "     */\n"
                  "    color: #40D0FB;\n"
                  "}\n"
                  "QLineEdit{\n"
                  "    background-color: #1F1F1F;\n"
                  "    border: 0px solid rgb(0, 0, 0);\n"
                  "    border-radius: 4px;\n"
                  "    /*\n"
                  "    Text color is set to #40D0FB\n"
                  "     */\n"
                  "    color: #40D0FB;\n"
                  "    height: 30px;\n"
                  "\n"
                  "}\n"
                  "QLabel{\n"
                  "    color: #FFFFFF;\n"
                  "}\n"
                  "");



}

void GyroButtonsAndConsoles::updateIncomingData(QString gyrox, QString gyroy, QString gyroz, QString altitude,
                                                QString relativeAltitude, QString seaLevelAltitıde,QString ErrorCode) {

    // update incoming data from the gyroscope.
    // count lines on the console output if it is more than 1000 lines delete the first line
    if (consoleOutput->document()->lineCount() > 1000) {
        QTextCursor cursor(consoleOutput->document());
        cursor.movePosition(QTextCursor::Start);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
    }
    // append the incoming data to the console output
    consoleOutput->append("Gyroscope X: " + gyrox + " Gyroscope Y: " + gyroy + " Gyroscope Z: " + gyroz + " Altitude: " +
                          altitude + " Relative Altitude: " + relativeAltitude + " Sea Level Altitude: " +
                          seaLevelAltitıde + " Error Code: " + ErrorCode);
    // if error code is 0 set the error indicator line edit text to be "No Error Occurred"
    if(ErrorCode == ""){
        errorIndicatorLineEdit->setText("No Error Occurred");
    }
    // if error code is 1 set the error indicator line edit text to be "Error Occurred"
    else {
        errorIndicatorLineEdit->setText("Error Occurred!:{ " + ErrorCode + " }");
    }



}

GyroButtonsAndConsoles::~GyroButtonsAndConsoles() = default;
