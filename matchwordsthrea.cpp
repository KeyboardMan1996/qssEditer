#include "matchwordsthrea.h"
#include <QMetaType>

MatchWordsThread::MatchWordsThread()
{

    caseWords.append("int");
    caseWords.append("widget");
    caseWords.append("if");
    caseWords.append("else");
    caseWords.append("while");
    caseWords.append("listwidget");
    qRegisterMetaType<QList<QString>>("QList<QString>");
}
MatchWordsThread::~MatchWordsThread()
{

}
/*
*设置要匹配的关键字，并开始匹配
* @word 关键字
*/
void MatchWordsThread::setMatchWord(const QString &word)
{
    locke.lock();     //锁定互斥锁
    regularExpresion.setPattern(word +".+");    //添加正则表达式
    locke.unlock();
    if(isRunning())
        quit();
    start();        //启动线程
}
/*
*新的线程方法
* 在新线程中匹配关键字
*/
void MatchWordsThread::run()
{
    QList<QString> vipCaseWords;   //完全匹配的关键字
    QList<QString> lowCaseWords;    //模糊匹配的关键字
    for(int i = 0; i < caseWords.size();i++)    //历遍关键字字典，并匹配
    {
        locke.lock();
        QRegularExpressionMatch match = regularExpresion.match(caseWords.at(i));
        locke.unlock();
        if(match.hasMatch())
        {
            if(match.capturedStart() == 0)
                vipCaseWords.append(caseWords.at(i));
            else {
                lowCaseWords.append(caseWords.at(i));
            }
        }

    }
     emit matchCaseWordFinished(vipCaseWords,lowCaseWords);
}
