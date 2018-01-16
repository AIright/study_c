cmake_minimum_required(VERSION 3.9)
project(study_c)

set(CMAKE_CXX_STANDARD 17)

# Add googletest directiories
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include Tests)

# Run UnitTests
#cxx_executable(DivisionWithoutRest Tests gtest_main
#        src/headers/DivisionWithoutRest.h)
#cxx_executable(Discount Tests gtest_main
#        src/headers/Discount.h)
#cxx_executable(EvenNumbers Tests gtest_main
#        src/headers/EvenNumbers.h)
#cxx_executable(SecondEntrance Tests gtest_main
#        src/headers/SecondEntrance.h)
#cxx_executable(MaxCommonDivisor Tests gtest_main
#        src/headers/MaxCommonDivisor.h)
#cxx_executable(BinaryNumber Tests gtest_main
#        src/headers/BinaryNumber.h)
#cxx_executable(Factorial Tests gtest_main
#        src/headers/Factorial.h)
#cxx_executable(Palindrom Tests gtest_main
#        src/headers/Palindrom.h)
#cxx_executable(Maximizator Tests gtest_main
#        src/headers/Maximizator.h)
#cxx_executable(MoveStrings Tests gtest_main
#        src/headers/MoveStrings.h)
#cxx_executable(Reverse Tests gtest_main
#        src/headers/Reverse.h)
#cxx_executable(Anagram Tests gtest_main
#        src/headers/Anagram.h)
#cxx_executable(CapitalsCountries Tests gtest_main
#        src/headers/CapitalsCountries.h)
cxx_executable(FinalTaskTesting Tests gtest_main
        src/headers/FinalTask.h)


set(SOURCE_FILES src/headers/)
add_executable(study_c ${SOURCE_FILES} main.cpp)



