#include "qssproperty.h"

QssProperty::QssProperty()
{

}
/**
 * @brief QssProperty::getPropertyName 获取属性名称
 * @param property  属性代码
 * @return  属性名称 返回空说明匹配失败
 */
QString QssProperty::getPropertyName(const QString &property)
{
    QString prName,dfValue,pr = property;
    ValueType type;
    if(getAll(pr,prName,dfValue,type))
        return prName;
    return  "";
}
/**
 * @brief QssProperty::getDefaultValue  返回默认值
 * @param property  属性代码
 * @return  默认值 返回空说明匹配失败
 */
QString QssProperty::getDefaultValue(const QString &property)
{
    QString prName,dfValue,pr = property;
    ValueType type;
    if(getAll(pr,prName,dfValue,type))
        return dfValue;
    return  "";
}
/**
 * @brief QssProperty::getValueType 获取数据类型
 * @param property  属性代码
 * @return 数据类型 返回ValueType::NO 表示匹配失败
 */
QssProperty::ValueType QssProperty::getValueType(const QString &property)
{
    QString prName,dfValue,pr = property;
    ValueType type;
    if(getAll(pr,prName,dfValue,type))
        return type;
    return  ValueType::NO;
}
/**
 * @brief QssProperty::getAll   获取qss代码的所有属性
 * @param property qss代码
 * @param prName   返回的qss的名称
 * @param dfValue   返回qss的默认值
 * @param TYpe  返回qss的数据类型
 * @return  返回获取数据是否成功
 */
bool QssProperty::getAll(QString property, QString &prName, QString &dfValue, QssProperty::ValueType &type)
{
    //如果属性为空则返回失败
    if(property == "")
        return false;

    //使用-分割属性
    QStringList cutProperty = property.split("-");
    //如果第一个属性与this的属性不匹配则返回false
    if(this->property != cutProperty.at(1))
        return false;
    //判断是否还有子节点属性，如果有则用子节点的属性匹配
    if(cutProperty.size() > 1)
    {
        //如果this没有子节点属性则直接返回false
        if(subProperty.size() == 0)
            return false;
        //寻找匹配的子节点属性
        for(int i = 0;i < subProperty.size();i++)
        {
            QssProperty pr = subProperty.at(i);
            //去掉主节点属性
            property.remove(cutProperty.at(1));
            //如果匹配成功则返回
            if(pr.getAll(property,prName,dfValue,type))
                return true;
        }

    }else {
        //如果没有子节点，说明匹配成功
        prName = this->propertyName;
        dfValue = this->defaultValue;
        type = this->valueType;
        return  true;
    }

    return false;
}
