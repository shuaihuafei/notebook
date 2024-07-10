cmake_minimum_required(VERSION 3.10)
project(SerialCommunication)

set(CMAKE_CXX_STANDARD 11)

# 查找 Boost 库
find_package(Boost REQUIRED COMPONENTS system)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(serial_communication serial_communication.cpp)
    target_link_libraries(serial_communication ${Boost_LIBRARIES} pthread)
else()
    message(FATAL_ERROR "Boost not found!")
endif()
