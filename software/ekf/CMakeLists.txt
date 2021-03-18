cmake_minimum_required(VERSION 3.10)
project(EKF)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} main.cpp ekf.cpp)
target_link_libraries(${PROJECT_NAME} m)