#include <QApplication>
#include <QDir>
#include "splash_screen/SplashScreen.h"
#include "gyroscope_widget/gyroscope_console/GyroButtonsAndConsoles.h"
#include "gyroscope_widget/GyroscopeWidget.h"

int main(int argc, char *argv[]) {
    // add path variable to the project

    QDir::addSearchPath("images", R"(C:\Users\admin\CLionProjects\CENG318\images)");
    // run splash screen
    QApplication a(argc, argv);
    // create a splash screen object
    GyroscopeWidget splashScreen;


    // show the splash screen
    splashScreen.show();
    // run the application
    return QApplication::exec();


}
