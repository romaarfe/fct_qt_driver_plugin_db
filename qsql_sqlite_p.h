#ifndef QSQL_SQLITE_H
#define QSQL_SQLITE_H

#include <QtSql/qsqldriver.h>

struct sqlite3; // Declaração avançada para a estrutura sqlite3

#ifdef QT_PLUGIN
#define Q_EXPORT_SQLDRIVER_SQLITE
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_SQL_EXPORT
#endif

QT_BEGIN_NAMESPACE

class QSqlResult;
class QSQLiteDriverPrivate; // Declaração avançada para a classe QSQLiteDriverPrivate

// Classe QSQLiteDriver, que herda de QSqlDriver
class Q_EXPORT_SQLDRIVER_SQLITE QSQLiteDriver : public QSqlDriver
{
    Q_DECLARE_PRIVATE(QSQLiteDriver) // Declaração avançada para uso da classe privada
    Q_OBJECT // Macro necessária para habilitar recursos de meta-objetos
    friend class QSQLiteResultPrivate; // Declaração de amizade com a classe QSQLiteResultPrivate
public:
    explicit QSQLiteDriver(QObject *parent = nullptr);  // Construtor
    explicit QSQLiteDriver(sqlite3 *connection, QObject *parent = nullptr); // Construtor alternativo
    ~QSQLiteDriver();   // Destrutor
    bool hasFeature(DriverFeature f) const override; // Verifica recursos suportados
    bool open(const QString & db,
                   const QString & user,
                   const QString & password,
                   const QString & host,
                   int port,
                   const QString & connOpts) override;  // Abre uma conexão com a base de dados
    void close() override;  // Fecha a conexão com a base de dados
    QSqlResult *createResult() const override;  // Cria um resultado para consultas
    bool beginTransaction() override;   // Inicia uma transação
    bool commitTransaction() override;  // Confirma uma transação
    bool rollbackTransaction() override;    // Desfaz uma transação
    QStringList tables(QSql::TableType) const override; // Lista as tabelas

    QSqlRecord record(const QString& tablename) const override; // Recupera o esquema da tabela
    QSqlIndex primaryIndex(const QString &table) const override; // Recupera o índice primário da tabela
    QVariant handle() const override;   // Recupera a alça de conexão
    QString escapeIdentifier(const QString &identifier, IdentifierType) const override; // Escapa um identificador

    bool subscribeToNotification(const QString &name) override; // Se inscreve para notificações
    bool unsubscribeFromNotification(const QString &name) override; // Cancela inscrição para notificações
    QStringList subscribedToNotifications() const override; // Recupera notificações inscritas
private Q_SLOTS:
    void handleNotification(const QString &tableName, qint64 rowid);    // Tratador para notificações
};

QT_END_NAMESPACE

#endif // QSQL_SQLITE_H
