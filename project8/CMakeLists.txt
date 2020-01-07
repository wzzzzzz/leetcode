cmake_minimum_required(VERSION 3.14)
project(project8)

set(CMAKE_CXX_STANDARD 11)

add_executable(project8 main.cpp test2.cpp reconstructMatrix.cpp subtractProductAndSum.cpp groupThePeople.cpp getDecimalValue.cpp sequentialDigits.cpp maxSideLength.cpp findNumbers.cpp isPossibleDivide.cpp freqAlphabets.cpp xorQueries.cpp)

add_executable(project8test test.cpp)
add_executable(test2 test2.cpp)
add_executable(reconstructMatrix reconstructMatrix.cpp)
add_executable(subtractProductAndSum subtractProductAndSum.cpp)
add_executable(groupThePeople groupThePeople.cpp)
add_executable(getDecimalValue getDecimalValue.cpp)
add_executable(sequentialDigits sequentialDigits.cpp)
add_executable(maxSideLength maxSideLength.cpp)
add_executable(findNumbers findNumbers.cpp)
add_executable(isPossibleDivide isPossibleDivide.cpp)
add_executable(freqAlphabets freqAlphabets.cpp)
add_executable(xorQueries xorQueries.cpp)