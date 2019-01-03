#ifndef SETTING_H
#define SETTING_H
#include <QSettings>
#include <qfont.h>


class Setting
{
public:
    Setting();
    QFont getFont();
    void setFont(const QFont &font);
};

#endif // SETTING_H
