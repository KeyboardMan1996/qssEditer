#include "database.h"
#include <QMessageBox>
#include <qvariant.h>
#include <QDebug>
#include <qfile.h>

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
void Database::insertClassName(const QString &name, const QString &content_e, const QString &content_c)
{
    QSqlQuery query(database);
    query.prepare("insert into ClassName(name,content_e,content_c) values(?,?,?)");
    query.bindValue(0,name.trimmed());
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);

    erroMessageBox(query,"插入类名");
}
/*
*插入图标名称
* @name 图标名称
* @content_e 英文介绍
* @content_c 中文介绍
*/
void Database::insertIco(const QString &name, const QString &content_e, const QString &content_c)
{
    QSqlQuery query(database);
    query.prepare("insert into Ico(name,content_e,content_c) values(?,?,?)");
    query.bindValue(0,name.trimmed());
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);

    erroMessageBox(query,"插入图标名称");
}
/*
*插入属性名称
* @name 属性名
* @content_e 英文介绍
* @content_c 中文介绍
* @example 示例
*/
void Database::insertProperties(const QString &name, const QString &content_e, const QString &content_c, const QString &example)
{
    QSqlQuery query(database);
    query.prepare("insert into Properties(name,content_e,content_c,example) values(?,?,?,?)");
    query.bindValue(0,name.trimmed());
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);
    query.bindValue(3,example);

    erroMessageBox(query,"插入属性名称");
}
/*
*插入伪状态
* @name 伪状态
* @content_e 英文介绍
* @content_c 中文介绍
*/
void Database::insertPseudoStates(const QString &name, const QString &content_e, const QString &content_c)
{
    QSqlQuery query(database);
    query.prepare("insert into PseudoStates(name,content_e,content_c) values(?,?,?)");
    query.bindValue(0,name.trimmed());
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);

    erroMessageBox(query,"插入伪状态");
}
/*
*插入子控件
* @name 子控件名称
* @content_e 英文介绍
* @content_c 中文介绍
*/
void Database::insertSubControls(const QString &name, const QString &content_e, const QString &content_c)
{
    QSqlQuery query(database);
    query.prepare("insert into SubControls(name,content_e,content_c) values(?,?,?)");
    query.bindValue(0,name.trimmed());
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);

    erroMessageBox(query,"插入子控件名");
}
/*
*插入属性值
* @name 值名称
* @type 值类型
* @content_e 英文介绍
* @content_c 中文介绍
* @examp 示例
*/
void Database::insertType(const QString &name, const QString &type, const QString &content_e, const QString &content_c, const QString &example)
{
    QSqlQuery query(database);
    query.prepare("insert into Type(name,content_e,content_c,type,example) values(?,?,?,?,?)");
    query.bindValue(0,name);
    query.bindValue(1,content_e);
    query.bindValue(2,content_c);
    query.bindValue(3,type);
    query.bindValue(4,example);

    erroMessageBox(query,"插入属性值");
}
/*
*更新数据库
* @from 表名
* @id 更新行的id
* @type 更新的列名
* @value 更新的值
*/
void Database::upDatabase(const QString &from, const int &id, const QString &type, const QString &value)
{
    QString sql("update %1 set %2=? where id=?");
    sql = sql.arg(from).arg(type);
    QSqlQuery query(database);
    query.prepare(sql);
    query.bindValue(0,value);
    query.bindValue(1,id);
    erroMessageBox(query,"更新");
}
/*
 * 通过id来删除某一行
 * @id ID
 */
void Database::deleteRowForID(int id,QString form)
{
    QString sql("delete from %1 where ID=?");
    sql = sql.arg(form);
    QSqlQuery query(database);
    query.prepare(sql);
    query.bindValue(0,id);
    erroMessageBox(query,"删除");
}
/*
*获取
* @from 表名
* @type 要获取的列名
*/
Values Database::selectOneValues(const QString &from, const QString &type)
{
    QString sql("select %1 from %2");
    sql =sql.arg(type).arg(from);
    QSqlQuery query(database);
    query.prepare(sql);

    if(erroMessageBox(query,"获取"))
    {
        Values values;
        while (query.next()) {
            values.append(query.value(0).toString());
        }
        return values;
    }
    Values v;
    return v;
}
/*
*数据库操作执行错误提示框
* @query
* @type 执行的操作类型
*/
bool Database::erroMessageBox(QSqlQuery &query, const QString &type)
{
    if(!query.exec())
    {
        QMessageBox message;
        QString erro("数据库操作错误:执行%1失败！\n错误信息:%2 !\nsql语句:%3 ");
        erro  = erro.arg(type).arg(query.lastError().text()).arg(query.lastQuery());
        message.setText(erro);
        message.exec();
        return false;
    }
    return true;
}
/*
*获取类名
* @rerun 类名集合
*/
Values Database::getClassNames()
{
    return selectOneValues("ClassName","name");
}
/*
*获取图标名称
*/
Values Database::getIcos()
{
    return selectOneValues("Ico","name");
}
/*
 * 获取属性值
 */
Values Database::getProperties()
{
    return selectOneValues("Properties","name");
}
/*
 * 获取伪状态
 */
Values Database::getPseudoStates()
{
    return selectOneValues("PseudoStates","name");
}
/*
 * 获取子控件名
 */
Values Database::getSubControls()
{
   return selectOneValues("SubControls","name");
}
/*
 * 获取属性值
 */
Values Database::getType()
{
    return selectOneValues("Type","name");
}
/*
 * 获取表内所有的值
 * @form 表名
 * @valuerlength 表内列的长度
 */
Values Database::selectFormValues(const QString &form, const int &valueLength)
{
    QString sql("select * from %1");
    sql = sql.arg(form);
    QSqlQuery query(database);
    query.prepare(sql);
    Values values;
    if(erroMessageBox(query,"获取表信息"))
    {
        while (query.next()) {
            for(int i = 0;i <valueLength;i++)
            {
                values.append(query.value(i).toString());
            }
        }
    }

    return values;
}
/*
 * 删除关键字中的多余空格
 */
void Database::deleteSpeas()
{
    {
        Values  va = this->selectFormValues("Type",2);
        for(int i = 0;i < va.size();i = i + 2)
        {
            upDatabase("type",va[i].toInt(),"name",va[i+1].trimmed());
        }
    }
    {
        Values  va = this->selectFormValues("ClassName",2);
        for(int i = 0;i < va.size();i = i + 2)
        {
            upDatabase("ClassName",va[i].toInt(),"name",va[i+1].trimmed());
        }
    }
    {
        Values  va = this->selectFormValues("Ico",2);
        for(int i = 0;i < va.size();i = i + 2)
        {
            upDatabase("Ico",va[i].toInt(),"name",va[i+1].trimmed());
        }
    }
    {
        Values  va = this->selectFormValues("Properties",2);
        for(int i = 0;i < va.size();i = i + 2)
        {
            upDatabase("Properties",va[i].toInt(),"name",va[i+1].trimmed());
        }
    }
    {
        Values  va = this->selectFormValues("PseudoStates",2);
        for(int i = 0;i < va.size();i = i + 2)
        {
            upDatabase("PseudoStates",va[i].toInt(),"name",va[i+1].trimmed());
        }
    }

    {
        Values  va = this->selectFormValues("SubControls",2);
        for(int i = 0;i < va.size();i = i + 2)
        {
            upDatabase("SubControls",va[i].toInt(),"name",va[i+1].trimmed());
        }
    }
}
