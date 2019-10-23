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

target_link_libraries (arbitraje_src LINK_PUBLIC)

# ====== MAIN =======
include(GoogleTest)
add_executable(arbitraje ${MAIN})
target_link_libraries(arbitraje LINK_PUBLIC arbitraje_src)

# ====== TESTS ======
enable_testing()

file(GLOB_RECURSE TEST_FILES ${TEST_DIR}/*.cpp ${TEST_DIR}/*.h ${TEST_DIR}/*.hpp)

add_executable(arbitraje_test ${TEST_FILES})

target_include_directories(arbitraje_test PUBLIC ${TEST_DIR})
target_link_libraries(arbitraje_test LINK_PUBLIC arbitraje_src gtest gmock)


#add_executable(run_test src/ejercicio-1/algoritmos/Prim.cpp src/ejercicio-1/algoritmos/Prim.h test/ejercicio-1/algoritmos/PrimTest.cpp)
#target_link_libraries(run_test gtest gtest_main)

