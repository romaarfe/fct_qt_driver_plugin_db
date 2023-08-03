#include <qsqldriverplugin.h>
#include <qstringlist.h>
#include "qsql_sqlite_p.h"

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

class QSQLCipherDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "sqlcipher.json")

public:
    QSQLCipherDriverPlugin();

    QSqlDriver* create(const QString &) Q_DECL_OVERRIDE;
};

// Construtor da classe QSQLCipherDriverPlugin que herda de QSqlDriverPlugin.
// Define metadados para o plugin.
QSQLCipherDriverPlugin::QSQLCipherDriverPlugin()
    : QSqlDriverPlugin()
{
}

// Cria um novo driver QSQLiteDriver quando o nome é "QSQLCIPHER".
// Retorna o driver recém-criado.
QSqlDriver* QSQLCipherDriverPlugin::create(const QString &name)
{
    if (name == "QSQLCIPHER"_L1) {
        QSQLiteDriver* driver = new QSQLiteDriver();
        return driver;
    }
    return 0;
}

QT_END_NAMESPACE

#include "smain.moc"
