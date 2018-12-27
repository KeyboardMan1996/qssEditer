#include "myhightlighter.h"
#include <QRegularExpression>
myHightLighter::myHightLighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{

}

void myHightLighter::highlightBlock(const QString &text)
{
//    QTextCharFormat myClassFormat;
//    myClassFormat.setFontWeight(QFont::Bold);
//    myClassFormat.setForeground(Qt::darkMagenta);

//    QRegularExpression regularExpression("int\\s+.+;");
//    QRegularExpressionMatchIterator i = regularExpression.globalMatch(text);

//    while(i.hasNext())
//    {
//        QRegularExpressionMatch match = i.next();
//        setFormat(match.capturedStart(),match.capturedLength(),myClassFormat);

//    }

//    for(int i = 0;i < caseWords.size();i++) //高亮关键字
//    {
//        highlightCaseWord(caseWords.at(i),text);
//    }
    QTextCharFormat multiLineCommentFormat;
     multiLineCommentFormat.setForeground(Qt::red);

     QRegularExpression startExpression("/\\*");
     QRegularExpression endExpression("\\*/");

     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = text.indexOf(startExpression);

     while (startIndex >= 0) {
        QRegularExpressionMatch endMatch;
        int endIndex = text.indexOf(endExpression, startIndex, &endMatch);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + endMatch.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(startExpression,
                                  startIndex + commentLength);
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

    QRegularExpression regularExpression(word);
    QRegularExpressionMatchIterator i = regularExpression.globalMatch(text);

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
