cmake_minimum_required(VERSION 3.12)
project(tp2-modelado-con-grafos)

# ======= Compilation options ========
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

# ========== Main variables ==========
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src/ejercicio_2)
set(MAIN ${SRC_DIR}/main.cpp)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test/ejercicio_2)
#set(EXTERNAL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# ======= Include directories ========
include_directories(${SRC_DIR})

# =========== Executables ============
# ===== SOURCES =====
file(GLOB_RECURSE SOURCE_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.h ${SRC_DIR}/*.hpp)
list(REMOVE_ITEM SOURCE_FILES ${MAIN})

add_library(arbitraje_src ${SOURCE_FILES})

target_link_libraries (arbitraje_src)

# ====== MAIN =======
include(GoogleTest)
add_executable(arbitraje ${MAIN})
target_link_libraries(arbitraje LINK_PUBLIC arbitraje_src)

# ====== TESTS ======
enable_testing()

file(GLOB_RECURSE TEST_FILES ${TEST_DIR}/*.cpp ${TEST_DIR}/*.h ${TEST_DIR}/*.hpp)

#add_executable(arbitraje_test ${TEST_FILES})
#target_include_directories(arbitraje_test PUBLIC ${TEST_DIR})
#target_link_libraries(arbitraje_test LINK_PUBLIC arbitraje_src gtest gmock)
#gtest_discover_tests(arbitraje_test)


set(FILES src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/AdyacencyMatrixGraph.cpp src/ejercicio-1/entities/AdyacencyMatrixGraph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/KruskalKindOfGraph.cpp src/ejercicio-1/entities/KruskalKindOfGraph.h src/ejercicio-1/algoritmos/MSTAlgorithm.h src/ejercicio-1/algoritmos/KruskalAlgorithm.cpp src/ejercicio-1/algoritmos/KruskalAlgorithm.h src/ejercicio-1/algoritmos/PrimAlgorithm.cpp src/ejercicio-1/algoritmos/PrimAlgorithm.h src/ejercicio-1/algoritmos/Segmentation.cpp src/ejercicio-1/algoritmos/Segmentation.h src/ejercicio-1/entities/Graph.h src/ejercicio-1/entities/TreeGraph.cpp src/ejercicio-1/entities/TreeGraph.h src/ejercicio-1/entities/Edge.cpp src/ejercicio-1/entities/Edge.h src/ejercicio-1/entities/Utils.h src/ejercicio-1/algoritmos/estructuras-auxiliares/DisjoinSet.h src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayDisjoinSet.cpp src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayDisjoinSet.h src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayCompressedDisjoinSet.cpp src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayCompressedDisjoinSet.h)
add_executable(run_test ${FILES} test/ejercicio-1/algoritmos/KruskalAlgorithmTest.cpp test/ejercicio-1/entities/KruskalKindOfGraphTest.cpp test/ejercicio-1/entities/AdyacencyMatrixGraphTest.cpp test/ejercicio-1/algoritmos/estructuras-auxiliares/DisjoinSetTest.cpp test/ejercicio-1/algoritmos/SegmentationTest.cpp test/ejercicio-1/algoritmos/PrimAlgorithmTest.cpp)
add_executable(ejercicio-1-main src/ejercicio-1/executables/segmentation-main.cpp ${FILES})
target_link_libraries(run_test gtest gtest_main)
