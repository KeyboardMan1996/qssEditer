#ifndef MYHIGHTLIGHTER_H
#define MYHIGHTLIGHTER_H
#include <QSyntaxHighlighter>
#include <qstring.h>
#include <qobject.h>
#include <qlist.h>
#include "database.h"

class myHightLighter:public QSyntaxHighlighter
{
public:
    myHightLighter(QTextDocument *parent);
    Values icoNames;        //图标名称
    Values ClassNames;      //类名
    Values typeNames;       //类型名称
    Values subControlNames; //子控件名称
    Values pseudoStateNames;    //伪状态名称
    Values propertieNames;  //属性名称

protected:
    void highlightBlock(const QString &text); //高亮规则设置
private:
    void highlightCaseWord(const QString &word,const QString &text);    //高亮关键字
    void highlightCaseWord(const QString &word,const QTextCharFormat &format,const QString &text);
};

#endif // MYHIGHTLIGHTER_H
