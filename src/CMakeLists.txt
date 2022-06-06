cmake_minimum_required(VERSION 3.5)

project(HSPass VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        uppercheckbox.cpp
        uppercheckbox.h
        checkbox.h
        checkbox.cpp
        symbcheckbox.h
        symbcheckbox.cpp
        numcheckbox.h
        numcheckbox.cpp
        lowercheckbox.h
        lowercheckbox.cpp
        button.h
        button.cpp
        generatebutton.h
        generatebutton.cpp
        copybutton.h
        copybutton.cpp
        dropdownlist.h
        dropdownlist.cpp
        passlendropdownlist.h
        passlendropdownlist.cpp
        checkboxfactory.h
        checkboxfactory.cpp
        buttonfactory.h
        buttonfactory.cpp
        dropdownlistfactory.h
        dropdownlistfactory.cpp
        inputfieldfactory.h
        inputfieldfactory.cpp
        widget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(HSPass
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET HSPass APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(HSPass SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(HSPass
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(HSPass PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(HSPass PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HSPass)
endif()
