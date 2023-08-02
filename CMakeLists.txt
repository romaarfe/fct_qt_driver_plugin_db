cmake_minimum_required(VERSION 3.5)

project(novoTesteDriver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH /home/administrator/Qt)
set(Qt6_DIR /home/administrator/Qt/6.5.1/gcc_64/lib/cmake/Qt6)

set(CMAKE_MODULE_PATH /home/administrator/sqlitebrowser/cmake)
find_package(Qt6 REQUIRED COMPONENTS Core Sql)

find_package(SQLCipher REQUIRED)

add_executable(novoTesteDriver sqlcipherdriver.h main.cpp
    sqlcipherdriver.cpp)

target_link_libraries(novoTesteDriver Qt6::Core Qt6::Sql sqlcipher)

include_directories(database.cfg)
