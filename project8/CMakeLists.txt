cmake_minimum_required(VERSION 3.14)
project(project8)

set(CMAKE_CXX_STANDARD 11)

add_executable(project8 main.cpp test2.cpp reconstructMatrix.cpp subtractProductAndSum.cpp groupThePeople.cpp)

add_executable(project8test test.cpp)
add_executable(test2 test2.cpp)
add_executable(reconstructMatrix reconstructMatrix.cpp)
add_executable(subtractProductAndSum subtractProductAndSum.cpp)