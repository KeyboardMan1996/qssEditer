#ifndef QSSPROPERTY_H
#define QSSPROPERTY_H
#include <qlist.h>
/**
 * @brief The QssProperty class qss属性类
 * 用于存储qqs属性的信息
 */
class QssProperty
{
public:
    QssProperty();

    /**
     * @brief The ValueType enum 属性值的类型
     */
    enum ValueType{
        NO,     //错误类型 一般匹配失败时返回
        INT,    //数字型
        FILE_PATH,  //文件路径
        COLOR  //颜色
    };

    //属性代码
    QString property;
    //属性名称
    QString propertyName;
    //属性默认值
    QString defaultValue;
    //数据类型
    ValueType valueType;
    //子节点数据
    QList<QssProperty> subProperty;

    //获得属性名称
    QString getPropertyName(const QString &property);

    //获得属性默认值
    QString getDefaultValue(const QString &property);

    //获得数据类型
    ValueType getValueType(const QString &property);

    //获得所有信息
    bool getAll(QString property,QString &prName,QString &dfValue,ValueType &type);
};

#endif // QSSPROPERTY_H
