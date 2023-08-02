#include "sqlcipherdriver.h"

int main()
{
    SqlCipherDriver *driver = new SqlCipherDriver();
    driver->open("mydatabase", "root", "mypassword", "mydatabase");

    QSqlQuery query;
    query.prepare("INSERT INTO mytable (name, age) VALUES ('John Doe', 25)");
    query.exec();

    driver->close();

    return 0;
}
