#include "setting.h"
#include <qdebug.h>

Setting::Setting()
{

}
/*
 * 初始化设置
 */
void Setting::init()
{
    setVersions("0.2");
    setUpdataCount(2);
}
/*
 * 获取设置的字体
 */
QFont Setting::getFont()
{
    QSettings setting("qssEditor","font");
    return QFont(setting.value("fontFamily").toString(),
                 setting.value("fontPointSzie").toInt(),
                 setting.value("fontWeight").toInt(),
                 setting.value("fontItalic").toBool());
}
/*
 * 设置字体
 */
void Setting::setFont(const QFont &font)
{
    QSettings setting("qssEditor","font");
    setting.setValue("fontFamily",font.family());
    setting.setValue("fontPointSzie",font.pointSize());
    setting.setValue("fontWeight",font.weight());
    setting.setValue("fontItalic",font.italic());
}

/*
 * 设置版本号
 */
void Setting::setVersions(QString versions)
{
    QSettings setting("qssEditor","VN");
    setting.setValue("versions",versions);
}
/*
 * 获取版本号
 */
QString Setting::getVersions()
{
    QSettings setting("qssEditor","VN");
    return setting.value("versions").toString();
}

/*
 * 设置更新次数
 */
void Setting::setUpdataCount(int count)
{
    QSettings setting("qssEditor","VN");
    setting.setValue("conut",count);
}

/*
 * 获取更新次数
 */
int Setting::getUpdataCount()
{
    QSettings setting("qssEditor","VN");
    return setting.value("conut").toInt();
}

/*
 * 获取公告
 */
QString Setting::getInform()
{
    QSettings setting("qssEditor","Inform");
    return setting.value("inform").toString();
}

/*
 * 设置公告
 */

void Setting::setInform(QString inform)
{
    QSettings setting("qssEditor","Inform");
    setting.setValue("inform",inform);
}












