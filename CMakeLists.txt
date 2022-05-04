cmake_minimum_required(VERSION 3.22)
project(BookShop)

set(CMAKE_CXX_STANDARD 23)

add_executable(BookShop main.cpp DataBase.cpp DataBase.h Book.cpp Book.h)

target_link_libraries(BookShop mysqlclient)
