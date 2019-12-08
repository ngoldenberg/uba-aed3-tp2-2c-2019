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
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
# acá nombro los 3 mains que hay en el proyecto (borrar)
set(MAIN_2 ${SRC_DIR}/ejercicio-2/main.cpp)
set(MAIN_1 ${SRC_DIR}/ejercicio-1/executables/segmentation-main.cpp )
set(MAIN_1_time ${SRC_DIR}/ejercicio-1/executables/segmentation-main-time.cpp )
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

# ======= Include directories ========
include_directories(${SRC_DIR})

# =========== Executables ============
# ===== SOURCES =====
file(GLOB_RECURSE SOURCE_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.h ${SRC_DIR}/*.hpp)
# acá quiero omitir los mains de las fuentes del proyecto (borrar)
list(REMOVE_ITEM SOURCE_FILES ${MAIN_2} ${MAIN_1} ${MAIN_1_time})

add_library(sources ${SOURCE_FILES})

target_link_libraries (sources)

# ====== MAIN =======
include(GoogleTest)
# acá agrego todas las fuentes del proyecto y dejo los ejecutables (borrar)
add_executable(arbitraje ${MAIN_2})
target_link_libraries(arbitraje LINK_PUBLIC sources)

add_executable(ejercicio-1-main ${MAIN_1})
target_link_libraries(ejercicio-1-main LINK_PUBLIC sources)

add_executable(ejercicio-1-main-time ${MAIN_1_time})
target_link_libraries(ejercicio-1-main-time LINK_PUBLIC sources)

# ====== TESTS ======
enable_testing()

file(GLOB_RECURSE TEST_FILES ${TEST_DIR}/*.cpp ${TEST_DIR}/*.h ${TEST_DIR}/*.hpp)

# acá quiero correr todos los tests del proyecto (borrar)
add_executable(tests ${TEST_FILES})
target_include_directories(tests PUBLIC ${TEST_DIR})
target_link_libraries(tests LINK_PUBLIC sources gtest gmock)
gtest_discover_tests(tests)
