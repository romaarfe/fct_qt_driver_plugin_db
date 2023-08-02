cmake_minimum_required(VERSION 3.16)

project(SQLCipherDBPlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Adicione o caminho para a pasta do Qt6 aqui:
set(Qt6_DIR "/home/administrator/Qt/6.5.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS Core Sql REQUIRED)

add_library(SQLCipherDBPlugin SHARED
    sqlcipherdbplugin.cpp
    sqlcipherdbdriver.cpp
    sqlcipherdbplugin.h
    sqlcipherdbdriver.h
)

target_link_libraries(SQLCipherDBPlugin PRIVATE Qt6::Core Qt6::Sql)

# Defina o caminho de instalação para os plugins de sqldrivers
set(QT_INSTALL_PLUGINS_DIR "/home/administrator/Qt/6.5.1/gcc_64/plugins" CACHE PATH "Plugins directory")

install(TARGETS SQLCipherDBPlugin
    LIBRARY DESTINATION ${QT_INSTALL_PLUGINS_DIR}/sqldrivers
)


