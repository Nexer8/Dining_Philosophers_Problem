cmake_minimum_required(VERSION 3.15)
project(Dining_Philosophers_Problem)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED )
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Dining_Philosophers_Problem source/main.cpp headers/Fork.h source/Philosopher.cpp headers/Philosopher.h source/Table.cpp headers/Table.h headers/Parameters.h source/Visualizer.cpp headers/Visualizer.h)
target_link_libraries(Dining_Philosophers_Problem pthread ${CURSES_LIBRARIES})