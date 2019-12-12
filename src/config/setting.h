#ifndef SETTING_H
#define SETTING_H
#include <QSettings>
#include <qfont.h>


class Setting
{
public:
    Setting();
    void init();
    QFont getFont();
    void setFont(const QFont &font);
    QString getVersions();
    void setVersions(QString versions);
    int getUpdataCount();
    void setUpdataCount(int count);
    void setInform(QString inform);
    QString getInform();
};

#endif // SETTING_H
