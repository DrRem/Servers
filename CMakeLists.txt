# cmake_minimum_required(VERSION <specify CMake version here>)
project(Servers)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        "C:/Program Files/MySQL/MySQL Server 8.0/include"
)

link_directories(
        "C:/Program Files/MySQL/MySQL Server 8.0/lib"
)

link_libraries(libmysql.lib)

link_libraries(ws2_32)

add_executable(Servers main.cpp SqlLinker.cpp SqlLinker.h Socks.cpp Socks.h)

target_link_libraries(libmysql.lib)


