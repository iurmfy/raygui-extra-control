cmake_minimum_required(VERSION 3.11)

project(raygui-extra-control C)

find_package(raylib 4.2.0 REQUIRED)

add_executable(raygui-extra-control test.c
        raygui_extra.h)
target_link_libraries(raygui-extra-control PUBLIC raylib)