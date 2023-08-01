#ifndef QSQLCIPHERSQLITE_DRIVER_H
#define QSQLCIPHERSQLITE_DRIVER_H

#include <QtSql/qsqldriver.h>

class QSQLCIPHERDriver : public QSqlDriver
{
    Q_OBJECT
public:
    explicit QSQLCIPHERDriver(QObject *parent = nullptr);
    bool hasFeature(DriverFeature feature) const override;
    bool open(const QString &db, const QString &user, const QString &password,
              const QString &host, int port, const QString &connOpts) override;
    void close() override;
    QSqlResult *createResult() const override;
    // ... adicione mais métodos conforme necessário ...

private:
         // ... adicione membros privados conforme necessário ...
};

#endif // QSQLCIPHERSQLITE_DRIVER_H
