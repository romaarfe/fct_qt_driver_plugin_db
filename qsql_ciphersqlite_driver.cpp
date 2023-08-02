#include "qsql_ciphersqlite_driver.h"


// Construtor para abrir a base de dados e inserir a palavra passe
void QSQLCIPHERDriver::openDb(const QString& filename, const QString& password)
{
    model = new QStandardItemModel();
    dbString = filename;

    // Abre a base de dados SQLite/SQLCipher com a chave de criptografia (password)
    sqlite3_open(dbString.toStdString().c_str(), &dbHandle);
    sqlite3_key(dbHandle, password.toStdString().c_str(), password.length());
}

// Para fechar a base de dados
void QSQLCIPHERDriver::closeDb()
{
    sqlite3_close(dbHandle);
}

// Para manipular o apontador para base de dados
sqlite3* QSQLCIPHERDriver::getDbHandle() const
{
    return dbHandle;
}

// Para de fato executar uma query
QPair<QStringList, QList<QList<QVariant>>> QSQLCIPHERDriver::executeQuery(const QString& query)
{
    // Criação de uma lista de nomes de colunas
    QStringList columnNames;

    // Criação de uma lista de listas (matriz) para armazenar os resultados da consulta
    QList<QList<QVariant>> results;

    // Prepara o statement
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(dbHandle, query.toStdString().c_str(), -1, &stmt, nullptr);

    // Busca os nomes das colunas no statement
    int columnCount = sqlite3_column_count(stmt);
    for (int i = 0; i < columnCount; i++)
    {
        const char* columnName = sqlite3_column_name(stmt, i);
        columnNames.append(QString::fromUtf8(columnName));
    }

    // Executa a query e faz fetch dos resultados
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        // Criação de uma lista para armazenar os valores de cada linha
        QList<QVariant> row;
        for (int i = 0; i < columnCount; i++)
        {
            int columnType = sqlite3_column_type(stmt, i);

            // Verifica o tipo de dado da coluna e adiciona na lista de valores da linha
            switch (columnType)
            {
            case SQLITE_INTEGER:
                row.append(sqlite3_column_int(stmt, i));
                break;
            case SQLITE_TEXT:
            {
                const char* text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
                row.append(QString::fromUtf8(text));
                break;
            }
            case SQLITE_FLOAT:
                row.append(sqlite3_column_double(stmt, i));
                break;
            case SQLITE_BLOB:
            {
                int dataSize = sqlite3_column_bytes(stmt, i);
                const void* blobData = sqlite3_column_blob(stmt, i);
                row.append(QByteArray(static_cast<const char*>(blobData), dataSize));
                break;
            }
            case SQLITE_NULL:
                row.append(QVariant());
                break;
            default:
                // Caso precise tratar outros tipos de dados
                row.append(QVariant());
                break;
            }
        }

        // Adiciona a lista de valores da linha na lista de resultados
        results.append(row);
    }

    // Finaliza o statement preparado
    sqlite3_finalize(stmt);

    // Retorna uma estrutura QPair com os nomes das colunas e os resultados da consulta
    return qMakePair(columnNames, results);
}

QStandardItemModel* QSQLCIPHERDriver::prepareModel(const QStringList& columnNames, const QList<QList<QVariant>>& results)
{
    // Criação de um novo modelo
    QStandardItemModel* model = new QStandardItemModel();

    // Configura os nomes das colunas no modelo
    model->setHorizontalHeaderLabels(columnNames);

    // Preenche o modelo com os dados vindos do resultado da query
    for (const QList<QVariant>& row : results)
    {
        QList<QStandardItem*> items;
        for (const QVariant& columnData : row)
        {
            // Cria um novo item do modelo e adiciona à lista de itens
            QStandardItem* item = new QStandardItem(columnData.toString());
            items.append(item);
        }

        // Adiciona uma nova linha ao modelo com os itens criados acima
        model->appendRow(items);
    }

    // Retorna o modelo preenchido com os dados da consulta
    return model;
}

QStandardItemModel* QSQLCIPHERDriver::prepareAndShowTable(const QString& filename, const QString& password, const QString& query)
{
    // Cria um novo objeto QSQLCipherClass
    dbCipher->openDb(filename, password);

    // Executa a consulta e obtém os resultados
    QPair<QStringList, QList<QList<QVariant>>> queryResult = dbCipher->executeQuery(query);
    const QStringList& columnNames = queryResult.first;
    const QList<QList<QVariant>>& results = queryResult.second;

    // Prepara o modelo a partir dos resultados da consulta
    QStandardItemModel* model = prepareModel(columnNames, results);

    // Retorna o modelo, se desejar usá-lo em outras partes do código
    return model;
}


QJsonDocument QSQLCIPHERDriver::convertModelToJson(QStandardItemModel* model)
{
    // Criação de um QJsonArray para armazenar os objetos JSON das linhas do modelo
    QJsonArray jsonArray;

    // Obtém o número de linhas e colunas do modelo
    const int rowCount = model->rowCount();
    const int columnCount = model->columnCount();

    // Ciclo pelas linhas do modelo
    for (int row = 0; row < rowCount; row++)
    {
        // Cria um objeto JSON para representar uma linha do modelo
        QJsonObject jsonObject;

        // Ciclo pelas colunas do modelo
        for (int col = 0; col < columnCount; col++)
        {
            // Obtém o índice do modelo para o campo atual (linha e coluna)
            QModelIndex index = model->index(row, col);

            // Obtém o nome do campo usando o cabeçalho da coluna
            QString fieldName = model->headerData(col, Qt::Horizontal).toString();

            // Obtém o valor do campo atual
            QVariant fieldValue = model->data(index);

            // Adiciona o campo e seu valor como uma propriedade no objeto JSON
            jsonObject[fieldName] = QJsonValue::fromVariant(fieldValue);
        }

        // Adiciona o objeto JSON da linha ao array JSON
        jsonArray.append(jsonObject);
    }

    // Cria um documento JSON a partir do array JSON
    QJsonDocument jsonDoc(jsonArray);

    // Retorna o documento JSON que contém os dados do modelo em formato JSON
    return jsonDoc;
}
