#ifndef QSQLCIPHERDRIVERPLUGIN_H
#define QSQLCIPHERDRIVERPLUGIN_H

#include <QSqlDriverPlugin>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlResult>

class QSqlCipherDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QSqlDriverFactoryInterface_iid FILE "QSqlCipher.json")

public:
    explicit QSqlCipherDriverPlugin(QObject *parent = nullptr);

private:
    QSqlDriver *create(const QString &key) override;
};

#endif // QSQLCIPHERDRIVERPLUGIN_H
