#include "sqlcipherdriver.h"

bool SqlCipherDriver::open(const QString &connectionName, const QString &userName, const QString &password, const QString &databaseName)
{
    // Open the connection to the database.
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(databaseName);

    // Return true if the connection was successful.
    return db.open();
}

bool SqlCipherDriver::close()
{
    // Close the connection to the database.
    return QSqlDatabase::removeDatabase(this->connectionName());
}

bool SqlCipherDriver::exec(const QString &query)
{
    // Execute the query against the database.
    return db.exec(query);
}

QSqlRecord SqlCipherDriver::record(const QString &query)
{
    // Return a record of the results of the query.
    return db.record(query);
}
