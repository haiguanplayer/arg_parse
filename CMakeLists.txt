cmake_minimum_required(VERSION 2.8)

project (argparse)
set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE CPP_FILES  ./main.cpp ./src/*.cpp)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include/)
link_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_subdirectory(third_party/googletest EXCLUDE_FROM_ALL)
add_subdirectory(unittest)

add_executable(${PROJECT_NAME} ${CPP_FILES})
