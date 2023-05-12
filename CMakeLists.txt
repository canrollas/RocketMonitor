cmake_minimum_required(VERSION 3.23)
project(CENG318)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        WebView
        REQUIRED)

add_executable(CENG318 main.cpp splash_screen/SplashScreen.cpp splash_screen/SplashScreen.h main_application/RocketMainWindow.cpp main_application/RocketMainWindow.h gyroscope_widget/GyroscopeWidget.cpp gyroscope_widget/GyroscopeWidget.h gyroscope_widget/gyroscope_console/GyroButtonsAndConsoles.cpp gyroscope_widget/gyroscope_console/GyroButtonsAndConsoles.h
        gyroscope_widget/circular_dashboard/attitude_widget.cpp
        gyroscope_widget/circular_dashboard/attitude_widget.h
        gyroscope_widget/circular_dashboard/circular_graphics_view.cpp
        gyroscope_widget/circular_dashboard/circular_graphics_view.h
        gyroscope_widget/circular_dashboard/circular_graphics_scene.cpp
        gyroscope_widget/circular_dashboard/circular_graphics_scene.h
        gyroscope_widget/circular_dashboard/graphics_items/circle_arround_qgi.cpp
        gyroscope_widget/circular_dashboard/graphics_items/circle_arround_qgi.h
        gyroscope_widget/circular_dashboard/graphics_items/heigh_of_gyro.cpp
        gyroscope_widget/circular_dashboard/graphics_items/heigh_of_gyro.h
        gyroscope_widget/circular_dashboard/graphics_items/parent_gyroscope.cpp
        gyroscope_widget/circular_dashboard/graphics_items/parent_gyroscope.h

        angle_widget/AngleWidget.cpp angle_widget/AngleWidget.h location_widget/MapApplication.cpp location_widget/MapApplication.h)
target_link_libraries(CENG318
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebView
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
