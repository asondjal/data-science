cmake_minimum_required(VERSION 3.6)
project(data-science)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")

add_executable(data-science
    src/main.cpp
    src/read_data.cpp
    src/statistik.cpp
    src/logging.cpp
    src/arithmetic.cpp
)

target_include_directories(data-science PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(data-science PRIVATE poppler-cpp)
target_link_libraries(data-science PRIVATE tinyxml2)
target_compile_options(data-science PRIVATE -Wall -Wextra -pedantic)

add_executable(cpp_tests
    src/read_data.cpp
    src/statistik.cpp
    src/logging.cpp
    src/arithmetic.cpp

    cpp_tests/main.cpp
    cpp_tests/test_read_data.cpp
    cpp_tests/test_statistik.cpp
    cpp_tests/test_logging.cpp
    cpp_tests/test_arithmetic.cpp
)

target_compile_options(cpp_tests PRIVATE ${COVERAGE_COMPILE_FLAGS})
target_link_libraries(cpp_tests PRIVATE gcov)

target_include_directories(cpp_tests PRIVATE ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(cpp_tests PRIVATE
    poppler-cpp
    tinyxml2
)

target_compile_options(cpp_tests PRIVATE -Wall -Wextra -pedantic)

add_subdirectory(pybind11)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(data-science PRIVATE Python3::Python)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/pybind11/include)

pybind11_add_module(intersection
    bindings/python_bindings.cpp

    src/read_data.cpp
    src/statistik.cpp
    src/logging.cpp
)

target_link_libraries(intersection PRIVATE
    poppler-cpp
    tinyxml2
)
target_include_directories(intersection PRIVATE ${PROJECT_SOURCE_DIR}/inc)
