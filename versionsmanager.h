#ifndef VERSIONSMANAGER_H
#define VERSIONSMANAGER_H
#include <qobject.h>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

class VersionsManager:public QObject
{
    Q_OBJECT
public:
    VersionsManager();
    ~VersionsManager();
    int updataCount;
    QString inform;
    QString updataContent;
    QString versions;
    bool updata;
public slots:
    void replyFinished(QNetworkReply *reply);
private:
    QNetworkAccessManager *networkManager;
signals:
    void finished();
};

#endif // VERSIONSMANAGER_H
