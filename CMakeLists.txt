cmake_minimum_required(VERSION 3.6)
project(data-science)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic")

# Haupt-Executable: supermarkt
add_executable(data-science 
    src/main.cpp
    src/read_data.cpp
    src/statistik.cpp
    src/logging.cpp

)

add_subdirectory(pybind11)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

target_link_libraries(data-science PRIVATE Python3::Python)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/pybind11/include)

# pybind11_add_module(py_bindings
#     bindings/python_bindings.cpp
    
#     src/read_data.cpp
#     src/statistik.cpp
#     src/logging.cpp
# )

# target_link_libraries(py_bindings PRIVATE poppler-cpp)

target_include_directories(data-science PRIVATE
    inc/base
    inc/utils
)

target_link_libraries(data-science PRIVATE poppler-cpp)

target_compile_options(data-science PRIVATE -Wall -Wextra -pedantic)
