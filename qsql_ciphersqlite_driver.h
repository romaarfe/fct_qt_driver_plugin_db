#ifndef QSQLCIPHERSQLITE_DRIVER_H
#define QSQLCIPHERSQLITE_DRIVER_H

#include <QtSql/qsqldriver.h>

#define SQLITE_HAS_CODEC

#include <iostream>
#include <sqlcipher/sqlite3.h>  // Inclui a biblioteca SQLite com suporte a SQLCipher
#include <QString>
#include <QDebug>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QList>
#include <QVariant>
#include <QTableView>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>
#include <QVariantList>

// Inclui a classe no namespace std para evitar ter que escrever std::
using namespace std;

class QSQLCIPHERDriver : public QSqlDriver
{
    Q_OBJECT
public:
    void openDb(const QString& filename, const QString& password);

    // Método para fechar a base de dados
    void closeDb();

    // Método para executar uma consulta SQL e obter os resultados
    QPair<QStringList, QList<QList<QVariant>>> executeQuery(const QString& query);

    // Método para executar uma consulta e mostrar o resultado numa tabela
    QStandardItemModel* prepareAndShowTable(const QString& databasePath, const QString& password, const QString& query);

    // Método para converter um modelo de dados em formato JSON
    QJsonDocument convertModelToJson(QStandardItemModel* model);


private:
    // Apontador para a base de dados SQLite/SQLCipher
    sqlite3* dbHandle;

    // Nome do ficheiro da base de dados SQLite/SQLCipher
    QString dbString;

    // Declaração um objeto da classe QSQLCipherClass
    QSQLCIPHERDriver *dbCipher;

    // Modelo de dados para armazenar os resultados da consulta
    QStandardItemModel* model;

    // Método interno para obter o apontador para a base de dados
    sqlite3* getDbHandle() const;

    // Método interno para preparar um modelo de dados a partir dos resultados da consulta
    QStandardItemModel* prepareModel(const QStringList& columnNames, const QList<QList<QVariant>>& results);
};

#endif // QSQLCIPHERSQLITE_DRIVER_H
