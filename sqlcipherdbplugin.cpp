#include "sqlcipherdbplugin.h"
#include "sqlcipherdbdriver.h"

QSqlDriver *SQLCipherDBPlugin::create(const QString &name)
{
    if (name == QLatin1String("SQLCipherDB")) {
        SQLCipherDBDriver *driver;
        return driver;
    }
    return nullptr;
}
