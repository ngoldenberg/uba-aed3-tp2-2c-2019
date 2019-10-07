cmake_minimum_required(VERSION 3.12)
project(tp2-modelado-con-grafos)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(FILES src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.cpp src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/AdyacencyMatrixGraph.cpp src/ejercicio-1/entities/AdyacencyMatrixGraph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/BellmanKindOfGraph.cpp src/ejercicio-1/entities/BellmanKindOfGraph.h)
add_executable(run_test ejemplo/src/1-programacion_dinamica/FibonnachiTopDown.cpp ejemplo/src/1-programacion_dinamica/FibonnachiTopDown.h ejemplo/test/1-programacion_dinamica/FibonnchiTopDownTest.cpp test/ejercicio-1/algoritmos/PrimTest.cpp src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.cpp src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h)
add_executable(ejercicio-1-main src/ejercicio-1/executables/segmentation-main.cpp ${FILES})
target_link_libraries(run_test gtest gtest_main)

