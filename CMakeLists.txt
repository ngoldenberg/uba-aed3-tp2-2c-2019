cmake_minimum_required(VERSION 3.12)
project(tp2-modelado-con-grafos)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(FILES src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/AdyacencyMatrixGraph.cpp src/ejercicio-1/entities/AdyacencyMatrixGraph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/KruskalKindOfGraph.cpp src/ejercicio-1/entities/KruskalKindOfGraph.h src/ejercicio-1/algoritmos/MSTAlgorithm.h src/ejercicio-1/algoritmos/BellmanFordAlgorithm.cpp src/ejercicio-1/algoritmos/BellmanFordAlgorithm.h src/ejercicio-1/algoritmos/PrimAlgorithm.cpp src/ejercicio-1/algoritmos/PrimAlgorithm.h src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/Edge.cpp src/ejercicio-1/entities/Edge.h )
add_executable(run_test ${FILES} ejemplo/src/1-programacion_dinamica/FibonnachiTopDown.cpp ejemplo/src/1-programacion_dinamica/FibonnachiTopDown.h ejemplo/test/1-programacion_dinamica/FibonnchiTopDownTest.cpp test/ejercicio-1/algoritmos/KruskalAlgorithmTest.cpp test/ejercicio-1/entities/KruskalKindOfGraphTest.cpp test/ejercicio-1/entities/AdyacencyMatrixGraphTest.cpp)
add_executable(ejercicio-1-main src/ejercicio-1/executables/segmentation-main.cpp ${FILES} src/ejercicio-1/entities/Utils.h)
target_link_libraries(run_test gtest gtest_main)

