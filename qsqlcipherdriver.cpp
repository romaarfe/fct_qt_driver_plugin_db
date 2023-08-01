#include "qsqlcipherdriver.h"


class QSqlCipherResult : public QSqlResult
{
public:
    QSqlCipherResult(const QSqlDriver *driver)
        : QSqlResult(driver) {}
    ~QSqlCipherResult() {}

protected:
    QVariant data(int /* index */) { return QVariant(); }
    bool isNull(int /* index */) { return false; }
    bool reset(const QString & /* query */) { return false; }
    bool fetch(int /* index */) { return false; }
    bool fetchFirst() { return false; }
    bool fetchLast() { return false; }
    int size() { return 0; }
    int numRowsAffected() { return 0; }
    QSqlRecord record() const { return QSqlRecord(); }
};

class QSqlCipherDriver : public QSqlDriver
{
public:
    QSqlCipherDriver() {}
    ~QSqlCipherDriver() {}

    bool hasFeature(DriverFeature /* feature */) const { return false; }
    bool open(const QString & /* db */, const QString & /* user */,
              const QString & /* password */, const QString & /* host */,
              int /* port */, const QString & /* options */)
    { return false; }
    void close() {}
    QSqlResult *createResult() const { return new QSqlCipherResult(this); }
};
