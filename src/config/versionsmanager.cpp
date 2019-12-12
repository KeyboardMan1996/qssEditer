#include "versionsmanager.h"
#include <QDebug>
#include <QtNetwork/QNetworkRequest>
#include <qjsonobject.h>
#include <QJsonDocument>
#include <QByteArray>
#include "setting.h"

VersionsManager::VersionsManager()
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    networkManager->get(QNetworkRequest(QUrl("http://anjztb.top/mystery")));
    updata = false;
}

VersionsManager::~VersionsManager()
{
    delete networkManager;
}
/*
 * 完成网络请求槽
 * 博客挂了，这部分失效
 */
void VersionsManager::replyFinished(QNetworkReply *reply)
{
//    QString test = reply->readAll();
//    QString content = test.split("&(QAQ)$").at(1);

//    QJsonDocument jsonDoc(QJsonDocument::fromJson(content.toUtf8()));
//    QJsonObject json = jsonDoc.object();

//    this->versions = json["版本号"].toString();
//    this->updataCount = json["更新次数"].toString().toInt();
//    this->updataContent = "版本号：" + this->versions
//                        +"\n更新内容：" + json["更新内容"].toString();
//    this->inform = json["公告"].toString();
//    Setting seting;
//    if(seting.getUpdataCount()<updataCount)
//    {
//        qDebug()<<seting.getUpdataCount();
//        updata = true;
//    }

    emit finished();
}
