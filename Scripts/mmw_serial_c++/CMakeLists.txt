# cmake_minimum_required(VERSION 3.10)

# # 项目信息
# project(SerialPortCommunication)

# # 设置C++标准
# set(CMAKE_CXX_STANDARD 11)

# # 查找源文件
# file(GLOB SOURCES "mmw_serial.cpp")

# # 指定生成的可执行文件
# add_executable(${PROJECT_NAME} ${SOURCES})

# # 添加所需的库
# target_link_libraries(${PROJECT_NAME} PRIVATE pthread)

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
