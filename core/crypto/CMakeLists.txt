cmake_minimum_required(VERSION 3.16)

project(crypto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(crypto STATIC
  crypto.cpp
  crypto.h
)

target_compile_definitions(crypto PRIVATE CRYPTO_LIBRARY)
