#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlerror.h>
#include <QString>
#include <qlist.h>

typedef QList<QString> Values;     //定义值集合
class Database
{
public:
    Database();
    void insertClassName(const QString &name,const QString &content_e = "",const QString &content_c ="");
    void insertIco(const QString &name,const QString &content_e = "",const QString &content_c ="");
    void insertProperties(const QString &name,const QString &content_e = "",const QString &content_c = "",const QString &example = "");
    void insertPseudoStates(const QString &name,const QString &content_e = "",const QString &content_c ="");
    void insertSubControls(const QString &name,const QString &content_e = "",const QString &content_c ="");
    void insertType(const QString &name,const QString &type = "",const QString &content_e = "",const QString &content_c ="",const QString &example = "");
    void upDatabase(const QString &from,const int &id,const QString &type,const QString &value);
    void deleteRowForID(int id,QString form);
    Values selectOneValues(const QString &from,const QString &type);
    Values getClassNames();
    Values getIcos();
    Values getProperties();
    Values getPseudoStates();
    Values getSubControls();
    Values getType();
    Values selectFormValues(const QString &form,const int &valueLength);
private:
    bool erroMessageBox(QSqlQuery &query,const QString &type = "");
    QSqlDatabase database;
};

#endif // DATABASE_H
