#include "qsql_ciphersqlite.h"
#include "qsql_ciphersqlite_driver.h" // Aqui, incluiremos o arquivo do driver personalizado

QSqlDriver* QSQLCIPHERDriverPlugin::create(const QString& name)
{
    if (name.toUpper() == "QSQLCIPHER")
    {
        return driver;
    }
    return nullptr;
}
