cmake_minimum_required(VERSION 3.12)
project(tp2-modelado-con-grafos)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)


add_executable(run_test ejemplo/src/1-programacion_dinamica/FibonnachiTopDown.cpp ejemplo/src/1-programacion_dinamica/FibonnachiTopDown.h ejemplo/test/1-programacion_dinamica/FibonnchiTopDownTest.cpp src/ejercicio-1/algoritmos/Prim.cpp src/ejercicio-1/algoritmos/Prim.h test/ejercicio-1/algoritmos/PrimTest.cpp)
target_link_libraries(run_test gtest gtest_main)

