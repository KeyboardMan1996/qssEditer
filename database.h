#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlerror.h>
#include <QString>


class Database
{
public:
    Database();
    void insterClassName(const QString &name,const QString &content_e = "",const QString &content_c ="");
private:
    QSqlDatabase database;
};

#endif // DATABASE_H
