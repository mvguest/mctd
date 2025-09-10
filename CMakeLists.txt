cmake_minimum_required(VERSION 3.30)

project(mctd)

add_executable(mctd src/main.c)

install(TARGETS mctd DESTINATION bin)
