cmake_minimum_required(VERSION 3.10)

# 项目信息
project(SerialPortCommunication)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找源文件
file(GLOB SOURCES "*.cpp")

# 指定生成的可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 添加所需的库
target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
