#ifndef MATCHWORDSTHREAD_H
#define MATCHWORDSTHREAD_H
#include <QThread>
#include <qobject.h>
#include <QMutex>
#include <QRegularExpression>
#include <qtextcursor.h>
class MatchWordsThread:public QThread
{
    Q_OBJECT
public:
    MatchWordsThread();
    ~MatchWordsThread();
    QList<QString> caseWords;
    void setMatchWord(const QString &blockText);
private:
        QMutex locke;
        QRegularExpression regularExpresion;
        QTextCursor cursor;
        QString blockText;
protected:
    void run();
signals:
    void matchCaseWordFinished(QList<QString> vipCaseWords,QList<QString> lowCaseWords,int caseWordSize);
    void hideListWidget();
};

#endif // MATCHWORDSTHREA_H
