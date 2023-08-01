#include "mainwindow.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Carregar o plugin do SQLCipherDB
    QCoreApplication::addLibraryPath("/home/administrator/Qt/6.5.1/gcc_64/plugins/sqldrivers"); // Altere para o caminho correto onde o plugin foi construído
    QSqlDatabase::addDatabase("QSQLCIPHER");

    // Abrir conexão com o banco de dados SQLCipherDB
    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen()) {
        qDebug() << "Connected to SQLCipherDB!";
    } else {
        qDebug() << "Failed to connect to SQLCipherDB!";
    }

    // Executar uma consulta
    QSqlQuery query("SELECT * FROM tabela"); // Substitua pela consulta desejada
    if (query.exec()) {
        while (query.next()) {
            // Ler e processar os resultados da consulta
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }

    // Fechar a conexão com o banco de dados SQLCipherDB
    db.close();

    return a.exec();
}
