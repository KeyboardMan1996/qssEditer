#include "qssitem.h"

QssItem::QssItem()
{
   unit = "";
   property = "";
   value = "";
}
/**
 * @brief QssItem::getQssCode 生成qss代码
 * 如果属性值为默认值，则不生成代码。
 * @return qss代码
 */
QString QssItem::getQssCode()
{

    //如果属性值为默认值，则不生成qss代码
    if(this->value == this->defaultValue)
        return  "";
    QString qsscode;
    //如果item为空，则直接生成
    if(items.size() == 0)
    {
        qsscode = property + ":" + value + ";";
    }else {
    //否则由item生成qss代码
        for(int i = 0;i < items.size();i++)
        {
            //获取item的qss代码
            QssItem item = items.at(i);
            QString itemQssCode = item.getQssCode();
            //如果item的代码为空，则不生成代码
            if(itemQssCode == "")
                continue;
            qsscode = qsscode + property + "-" + itemQssCode + "\n";
        }
    }

    return qsscode;
}
/**
 * @brief QssItem::setValue 设置属性值
 * @param value 属性值
 */
void QssItem::setValue(const QString &value)
{
    this->value = value;
}

void QssItem::setValue(const int &value)
{
    //如果属性值为数字，则需要加上单位
    QString v = QString::number(value);
    this->value = v + unit;
}
