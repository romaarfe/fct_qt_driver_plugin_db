cmake_minimum_required(VERSION 3.16)
project(exemploPlugin LANGUAGES CXX)

find_package(Qt6 COMPONENTS Core Sql REQUIRED)


if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/home/administrator/Formacao/Projeto/exemploPlugin")

# Inclua os arquivos do driver personalizado e o plugin em seu projeto
set(CUSTOM_DRIVER_SOURCES
    qsql_ciphersqlite.cpp
    qsql_ciphersqlite_driver.cpp
)

set(CUSTOM_DRIVER_HEADERS
    qsql_ciphersqlite.h
    qsql_ciphersqlite_driver.h
)

qt_standard_project_setup()

add_library(exemploPlugin MODULE ${CUSTOM_DRIVER_SOURCES} ${CUSTOM_DRIVER_HEADERS})
target_link_libraries(exemploPlugin PRIVATE Qt6::Sql Qt6::Core sqlcipher)

install(TARGETS exemploPlugin
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

