#include <QtSql>
#include <QCoreApplication>
#include <QPluginLoader>

// Importar o plugin QSQLCIPHERDriverPlugin
//Q_IMPORT_PLUGIN(QSQLCIPHERDriverPlugin)

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Carregar o driver personalizado QSQLCIPHER usando QPluginLoader
    QPluginLoader pluginLoader("/home/administrator/Qt/6.5.1/gcc_64/plugins/sqldrivers/qsql_ciphersqlite.so"); // Substitua pelo caminho real para o arquivo do seu plugin
    if (pluginLoader.load()) {
        qDebug() << "Driver personalizado QSQLCIPHER carregado com sucesso.";

        // Criar uma base de dados usando o driver personalizado QSQLCIPHER
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");
        QString databaseName = "mydatabase.db"; // Nome do arquivo da base de dados
        QString password = "senha"; // Substitua pela senha do banco de dados

        db.setDatabaseName(databaseName);
        db.setPassword(password);

        // Abrir a conexão com a base de dados
        if (db.open()) {
            qDebug() << "Base de dados criada com sucesso.";

            // ... continue com suas operações no banco de dados ...
        } else {
            qCritical() << "Falha ao abrir a conexão com o banco de dados:" << db.lastError().text();
        }
    } else {
        qCritical() << "Falha ao carregar o driver personalizado QSQLCIPHER:" << pluginLoader.errorString();
    }

    return a.exec();
}

