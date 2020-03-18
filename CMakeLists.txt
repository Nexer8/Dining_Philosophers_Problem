cmake_minimum_required(VERSION 3.15)
project(Dining_Philosophers_Problem)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED )

add_executable(Dining_Philosophers_Problem source/main.cpp source/Fork.cpp headers/Fork.h source/Philosopher.cpp headers/Philosopher.h source/Table.cpp headers/Table.h)
target_link_libraries(Dining_Philosophers_Problem pthread)