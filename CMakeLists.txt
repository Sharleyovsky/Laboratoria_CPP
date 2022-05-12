cmake_minimum_required(VERSION 3.20)
project(Laboratoria_CPP2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Laboratoria_CPP2
        factorial.cpp)

add_executable(RandomArray_LAB2
        randomArray.cpp)

add_executable(RandomVector_LAB2
        randomVector.cpp)

add_executable(BisectionMethod bisection.cpp)

add_executable(BubbleSort bubble-sort.cpp)