#ifndef QSSITEM_H
#define QSSITEM_H
#include <qstring.h>
#include <qlist.h>
#include "qssproperty.h"
/**
 * @brief The QssItem class 解析qss时存放数据类
 */
class QssItem
{
public:
    QssItem();

    //属性
    QString property;
    //属性值
    QString value;
    //单位
    QString unit;
    //子类型
    QList<QssItem> items;
    //值类型
    QssProperty::ValueType valueType;
    //属性中文别名
    QString propertyName;
    //属性默认值
    QString defaultValue;

    //生成qss代码
    QString getQssCode();


    //设置属性值
    void setValue(const QString &value);
    void setValue(const int &value);
};

#endif // QSSITEM_H
