#include "database.h"
#include <QMessageBox>
#include <qvariant.h>

Database::Database()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("./caseWord.db");
    database.setUserName("root");
    database.setPassword("zndhnhsrm?");
    if(!database.open())
    {
        QMessageBox msgbox;
        msgbox.setText("数据库打开失败");
        msgbox.exec();
    }
}
/*
*插入类名
* @name 类名
* @content_e 英文介绍
* @content_c 中文介绍
*/
void Database::insterClassName(const QString &name, const QString &content_e, const QString &content_c)
{
    QSqlQuery query(database);
    query.prepare("insert into ClassName(name,content_e,content_c) values(?,?,?)");
    query.bindValue(0,name);
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);

    if(!query.exec())
    {
        QMessageBox message;
        QString erro = query.lastError().text() + query.executedQuery();
        message.setText("插入类名失败，错误信息:" + erro);
        message.exec();
    }
}
