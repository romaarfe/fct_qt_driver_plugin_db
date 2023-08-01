#ifndef QSQLCIPHERSQLITE_H
#define QSQLCIPHERSQLITE_H

#include <QtSql/qsqldriverplugin.h>

class QSQLCIPHERDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "qsql_ciphersqlite.json")
public:
    QSqlDriver* create(const QString& name) override;
};

#endif // QSQLCIPHERSQLITE_H

