cmake_minimum_required(VERSION 3.16)

project(report LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

add_library(report STATIC
  report.cpp
  report.h
)

target_link_libraries(report PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

target_compile_definitions(report PRIVATE REPORT_LIBRARY)
