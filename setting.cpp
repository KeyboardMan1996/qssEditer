#include "setting.h"
#include <qdebug.h>

Setting::Setting()
{

}
QFont Setting::getFont()
{
    QSettings setting("qssEditor","font");
    return QFont(setting.value("fontFamily").toString(),
                 setting.value("fontPointSzie").toInt(),
                 setting.value("fontWeight").toInt(),
                 setting.value("fontItalic").toBool());
}
void Setting::setFont(const QFont &font)
{
    QSettings setting("qssEditor","font");
    setting.setValue("fontFamily",font.family());
    setting.setValue("fontPointSzie",font.pointSize());
    setting.setValue("fontWeight",font.weight());
    setting.setValue("fontItalic",font.italic());
}
