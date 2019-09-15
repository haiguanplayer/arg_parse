cmake_minimum_required(VERSION 3.12)

project (argparse)
set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE CPP_FILES  ./main.cpp ./src/*.cpp)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include/)
link_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_executable(${PROJECT_NAME} ${CPP_FILES})
