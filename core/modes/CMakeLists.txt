cmake_minimum_required(VERSION 3.16)

project(modes LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(modes STATIC
  modes.cpp
  modes.h
  mode.h
  modecipher.h
)

target_link_libraries(modes PUBLIC crypto)
target_link_libraries(modes PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(modes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(modes PRIVATE MODES_LIBRARY)
