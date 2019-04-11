#include "myhightlighter.h"
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
myHightLighter::myHightLighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{
    Database data;
    ClassNames = data.getClassNames();
    typeNames = data.getType();
    subControlNames = data.getSubControls();
    propertieNames = data.getProperties();
    pseudoStateNames = data.getPseudoStates();
    icoNames = data.getIcos();
}

void myHightLighter::highlightBlock(const QString &text)
{
    QTextCharFormat myClassFormat;
    myClassFormat.setFontWeight(QFont::Bold);
    myClassFormat.setForeground(Qt::darkMagenta);

    QRegularExpression regularExpression("int\\s+.+;");
    QRegularExpressionMatchIterator i = regularExpression.globalMatch(text);

    while(i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        setFormat(match.capturedStart(),match.capturedLength(),myClassFormat);

    }

    for(int i = 0;i < ClassNames.size();i++) //高亮qt类名
    {
        highlightCaseWord(ClassNames.at(i),text);
    }
    for(int i = 0;i < propertieNames.size();i++) //高亮属性
    {
        QTextCharFormat f;
        f.setFontWeight(QFont::Bold);
        f.setForeground(QColor("#EE2C2C"));
        highlightCaseWord(propertieNames.at(i),f,text);
    }
/*    for(int i = 0;i < icoNames.size();i++)  //高亮图标名
    {
        QTextCharFormat f;
        f.setFontWeight(QFont::Bold);
        f.setForeground(QColor("#836FFF"));
        highlightCaseWord(icoNames.at(i),f,text);
    }
    for(int i = 0;i < typeNames.size();i++) //高亮类型名称
    {
        QTextCharFormat f;
        f.setFontWeight(QFont::Bold);
        f.setForeground(QColor("#8B3E2F"));
        highlightCaseWord(typeNames.at(i),f,text);
    }
    for(int i = 0;i < subControlNames.size();i++)   //高亮子控件名称
    {
        QTextCharFormat f;
        f.setFontWeight(QFont::Bold);
        f.setForeground(QColor("#CD00CD"));
        highlightCaseWord(subControlNames.at(i),f,text);
    }
    for(int i = 0;i < pseudoStateNames.size();i++)
    {
        QTextCharFormat f;
        f.setFontWeight(QFont::Bold);
        f.setForeground(QColor("#EE9A49"));
        highlightCaseWord(pseudoStateNames.at(i),f,text);
    }*/
}
/*
*高亮一个关键字
* @word 关键字
* @format 高亮规则
* &text 文本块
*/
void myHightLighter::highlightCaseWord(const QString &word,const QTextCharFormat &format,const QString &text)
{

    QRegularExpression regularExpression("\\b" + word +"\\b",QRegularExpression::CaseInsensitiveOption);    //创建正则表达式
    QRegularExpressionMatchIterator i = regularExpression.globalMatch(text);    //匹配正则表达式

    while(i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        setFormat(match.capturedStart(),match.capturedLength(),format);

    }

}
/*
*高亮一个关键字
* @word 关键字
* &text 文本块
*/
void myHightLighter::highlightCaseWord(const QString &word, const QString &text)
{
    QTextCharFormat myClassFormat;
    myClassFormat.setFontWeight(QFont::Bold);
    myClassFormat.setForeground(Qt::blue);
    highlightCaseWord(word,myClassFormat,text);
}
