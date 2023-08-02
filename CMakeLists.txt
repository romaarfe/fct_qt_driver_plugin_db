cmake_minimum_required(VERSION 3.16)
project(novaTentativaDriver LANGUAGES CXX)

find_package(Qt6 COMPONENTS Core Sql Widgets REQUIRED)

set(SQLITE_HAS_CODEC)
set(SQLCIPHER_CRYPTO_LIBTOMCRYPT)
set(SQLITE_ENABLE_COLUMN_METADATA)
set(SQLITE_OMIT_LOAD_EXTENSION)
set(SQLITE_OMIT_COMPLETE)
set(SQLITE_ENABLE_FTS3)
set(SQLITE_ENABLE_FTS3_PARENTHESIS)
set(SQLITE_ENABLE_FTS5)
set(SQLITE_ENABLE_JSON1)
set(SQLITE_ENABLE_RTREE)
set(SQLITE_ENABLE_SESSION)


set(SUBDIRS += sqlcipher libtomcrypt)

set(INCLUDEPATH +=  $$PWD/sqlcipher)
set(HEADERS +=  $$PWD/sqlcipher/sqlite3.h)
set(SOURCES +=  $$PWD/sqlcipher/sqlite3.c)
set(LIBS += $$PWD/sqlcipher/libsqlcipher.a)

set(INCLUDEPATH +=  $$PWD/libtomcrypt/src/headers)
set(LIBS += $$PWD/libtomcrypt/libcrypto.a)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "novaTentativa")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/home/administrator/Formacao/Projeto/novaTentativaDriver")

# Inclua os arquivos do driver personalizado e o plugin em seu projeto
set(CUSTOM_DRIVER_SOURCES
    qsql_sqlite.cpp
    smain.cpp
)

set(CUSTOM_DRIVER_HEADERS
    qsql_sqlite_p.h
)

qt_standard_project_setup()

add_library(novaTentativaDriver MODULE ${CUSTOM_DRIVER_SOURCES} ${CUSTOM_DRIVER_HEADERS})
target_link_libraries(novaTentativaDriver PRIVATE Qt6::Sql Qt6::Core Qt6::Widgets sqlcipher)
install(TARGETS novaTentativaDriver
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

