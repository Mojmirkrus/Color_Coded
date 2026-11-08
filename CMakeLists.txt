cmake_minimum_required(VERSION 4.4)
project(Color_Coded C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Color_Coded main.c
        common/used_functions.c
        common/used_functions.h
)

target_link_libraries(Color_Coded PRIVATE ${CMAKE_SOURCE_DIR}/lib/libraylib.a)