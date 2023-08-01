#ifndef SQLCIPHERDBDRIVER_H
#define SQLCIPHERDBDRIVER_H

#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

class SQLCipherDBDriver : public QSqlDriver
{
    Q_OBJECT

public:
    explicit SQLCipherDBDriver(QObject *parent = nullptr);

    bool open(const QString &db, const QString &user, const QString &password,
              const QString &host, int port, const QString &connOpts);
    void close();
    bool isOpen();
    QSqlQuery executeQuery(const QString &query);
};

#endif // SQLCIPHERDBDRIVER_H

