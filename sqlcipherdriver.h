#ifndef SqlCipherDriver_H
#define SqlCipherDriver_H

#include <QtSql/QSqlDatabase>
#include <QString>
#include <QSqlQuery>

class SqlCipherDriver : public QSqlDatabase
{
public:
    bool open(const QString &connectionName, const QString &userName, const QString &password, const QString &databaseName);
    bool close();
    bool exec(const QString &query);
    QSqlRecord record(const QString &query);
};
#endif // SqlCipherDriver_H
