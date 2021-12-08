cmake_minimum_required(VERSION 3.5)

project(CShell VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -ggdb3 -fpermissive)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(Boost_USE_STATIC_LIBS ON)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread )# asio is header only no library, random is for example
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_SOURCES
        # main.cpp
        # display.cpp
        # display.h
        # display.ui
        display.ui
        display.cpp
        file_io.cpp
        utils.h
        utils.cpp
        main.cpp
        misc.h
        misc.cpp
        painter.h
        painter.cpp
        component.h
        component.cpp
        classifier.h
        expression.h
        classifier.cpp
        expression.cpp
        cfile.cpp
        # TEST123.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CShell
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CShell APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CShell SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CShell
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CShell PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(CShell PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CShell)
endif()

execute_process(COMMAND echo valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=${PROJECT_SOURCE_DIR}/valgrind-out.txt ${PROJECT_BINARY_DIR}/${PROJECT_NAME})