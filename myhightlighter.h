#ifndef MYHIGHTLIGHTER_H
#define MYHIGHTLIGHTER_H
#include <QSyntaxHighlighter>
#include <qstring.h>
#include <qobject.h>
#include <qlist.h>

class myHightLighter:public QSyntaxHighlighter
{
public:
    myHightLighter(QTextDocument *parent);
    QList<QString> caseWords;
protected:
    void highlightBlock(const QString &text); //������������
private:
    void highlightCaseWord(const QString &word,const QString &text);    //�����ؼ���
    void highlightCaseWord(const QString &word,const QTextCharFormat &format,const QString &text);
};

#endif // MYHIGHTLIGHTER_H
