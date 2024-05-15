cmake_minimum_required(VERSION 3.24)
project(kolejka)

set(CMAKE_CXX_STANDARD 23)

add_executable(kolejka testownik.cpp Kolejka_lista.cpp Lista.cpp)
