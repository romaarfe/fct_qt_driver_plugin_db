cmake_minimum_required(VERSION 3.14)

project(QSqlCipher LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

add_library(QSqlCipher SHARED
  qsqlcipherdriver.cpp
  qsqlcipherdriver.h
  QSqlCipher.json
)

target_link_libraries(QSqlCipher PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_compile_definitions(QSqlCipher PRIVATE QSQLCIPHER_LIBRARY)
