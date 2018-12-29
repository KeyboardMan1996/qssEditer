#include "myhightlighter.h"
#include <QRegularExpression>
myHightLighter::myHightLighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{

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

    for(int i = 0;i < caseWords.size();i++) //高亮关键字
    {
        highlightCaseWord(caseWords.at(i),text);
    }
}
/*
*高亮一个关键字
* @word 关键字
* @format 高亮规则
* &text 文本块
*/
void myHightLighter::highlightCaseWord(const QString &word,const QTextCharFormat &format,const QString &text)
{

    QRegularExpression regularExpression(word);    //创建正则表达式
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
