#ifndef UPDATAUI_H
#define UPDATAUI_H
#include "insertui.h"

class UpDataUi:public InsertUI
{
public:
    UpDataUi(Database *database,const Type &type);
    int id;
    void setCaseWord(const QString &caseWord);
    void setContentC(const QString &content);
    void setContentE(const QString &content);
    void setExample(const QString &example);
    void setTYPE(const QString &type);
private slots:
    void on_pushButton_6_clicked();
};

#endif // UPDATAUI_H
