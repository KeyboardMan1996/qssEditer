#ifndef MATCHWORDSTHREAD_H
#define MATCHWORDSTHREAD_H
#include <QThread>
#include <qobject.h>
#include <QMutex>
#include <QRegularExpression>
class MatchWordsThread:public QThread
{
    Q_OBJECT
public:
    MatchWordsThread();
    QList<QString> caseWords;
    void setMatchWord(const QString &word);
private:
        QMutex locke;
        QRegularExpression regularExpresion;
protected:
    void run();
signals:
    void matchCaseWordFinished(QList<QString>,QList<QString>);
};

#endif // MATCHWORDSTHREA_H
