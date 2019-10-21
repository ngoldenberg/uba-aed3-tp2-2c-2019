cmake_minimum_required(VERSION 3.12)
project(tp2-modelado-con-grafos)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(FILES src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/AdyacencyMatrixGraph.cpp src/ejercicio-1/entities/AdyacencyMatrixGraph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/KruskalKindOfGraph.cpp src/ejercicio-1/entities/KruskalKindOfGraph.h src/ejercicio-1/algoritmos/MSTAlgorithm.h src/ejercicio-1/algoritmos/KruskalAlgorithm.cpp src/ejercicio-1/algoritmos/KruskalAlgorithm.h src/ejercicio-1/algoritmos/PrimAlgorithm.cpp src/ejercicio-1/algoritmos/PrimAlgorithm.h src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/Edge.cpp src/ejercicio-1/entities/Edge.h src/ejercicio-1/entities/Utils.h src/ejercicio-1/algoritmos/estructuras-auxiliares/DisjoinSet.h src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayDisjoinSet.cpp src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayDisjoinSet.h src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayCompressedDisjoinSet.cpp src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayCompressedDisjoinSet.h)
add_executable(run_test ${FILES} test/ejercicio-1/algoritmos/KruskalAlgorithmTest.cpp test/ejercicio-1/entities/KruskalKindOfGraphTest.cpp test/ejercicio-1/entities/AdyacencyMatrixGraphTest.cpp test/ejercicio-1/algoritmos/estructuras-auxiliares/DisjoinSetTest.cpp test/ejercicio-1/algoritmos/PrimAlgorithmTest.cpp)
add_executable(ejercicio-1-main src/ejercicio-1/executables/segmentation-main.cpp ${FILES})
target_link_libraries(run_test gtest gtest_main)

