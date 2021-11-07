# 声明编译要求cmake最低版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# 添加源文件
SET(SOURCE main.cpp)

# 添加一个可执行程序,名称和工程名称保持一致
ADD_EXECUTABLE(comtest1 ${SOURCE})
set_target_properties(comtest1 PROPERTIES FOLDER "com")