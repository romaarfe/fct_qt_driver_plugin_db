#define SQLITE_HAS_CODEC    // Habilita o uso de codificação no SQLite (provavelmente para criptografia)

#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <sqlcipher/sqlite3.h>  // Inclui a biblioteca SQLite com suporte a codificação (provavelmente SQLCipher)
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");  // Adiciona uma base de dados SQLite com suporte a codificação (SQLCipher)

//    db.setDatabaseName("basedados.db"); // Define o nome da base de dados como "basedados.db"
//    db.open();  // Abre a conexão com a base de dados

//    QSqlQuery query;
//    query.exec("PRAGMA key = 'senha';");    // Define a chave de criptografia para a base de dados

//    if (!query.exec("CREATE TABLE IF NOT EXISTS tabela (id INT PRIMARY KEY, nome TEXT, idade INT)")) {
//        qDebug() << "Erro ao criar tabela!";
//    }

//    // Insere registros na tabela
//    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (1, 'Luke', 18)");
//    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (2, 'Leia', 18)");
//    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (3, 'Han', 25)");
//    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (4, 'Yoda', 800)");

    MainWindow w;
    w.show();

    return a.exec();    // Executa o loop de eventos da aplicação
}

