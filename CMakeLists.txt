cmake_minimum_required(VERSION 3.20)
project(fast_search LANGUAGES CXX)
set (VERSION_MAJOR 1)
set (VERSION_NINOR 2)

# 指定C++标准为C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True) # 确保必须支持此标准
set(CMAKE_CXX_EXTENSIONS OFF) # 防止使用非标准扩展（可选，推荐关闭以确保严格遵循ISO C++标准）

include(CheckFunctionExists)
include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(fast_search main.cpp)

install (TARGETS fast_search DESTINATION bin)

message (STATUS "compiler C   = ${CMAKE_C_COMPILER} ${FULL_C_FLAGS}")
message (STATUS "compiler CXX = ${CMAKE_CXX_COMPILER} ${FULL_CXX_FLAGS}")
message (STATUS "LINKER_FLAGS = ${FULL_EXE_LINKER_FLAGS}")
