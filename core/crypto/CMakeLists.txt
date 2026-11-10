cmake_minimum_required(VERSION 3.16)

project(crypto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(crypto STATIC
  crypto.cpp
  crypto.h
  iblockcipher.h
  cipherfactory.h
  algorithm.h
)

target_link_libraries(crypto PUBLIC Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(crypto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})