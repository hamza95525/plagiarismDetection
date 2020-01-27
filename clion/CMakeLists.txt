cmake_minimum_required(VERSION 3.15)
project(oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym)

set(CMAKE_CXX_STANDARD 14)

add_executable(plikExe src/main.cpp headers/Compare.h includes/Includes.h src/Compare.cpp)
