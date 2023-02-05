cmake_minimum_required(VERSION 3.20)
project(OOP_assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_assignment main.cpp packets.cpp packets.h rawEthernet.cpp rawEthernet.h ecpriFrame.cpp ecpriFrame.h)
