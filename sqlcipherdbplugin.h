#ifndef SQLCIPHERDBPLUGIN_H
#define SQLCIPHERDBPLUGIN_H

#include <QtPlugin>
#include <QtSql/QSqlDriverPlugin>

class SQLCipherDBPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.example.SQLCipherDBPlugin")

public:
    QSqlDriver *create(const QString &name) override;
};

#endif // SQLCIPHERDBPLUGIN_H
