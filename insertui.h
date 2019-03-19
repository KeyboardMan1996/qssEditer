#ifndef INSERTUI_H
#define INSERTUI_H

#include <QWidget>
#include "database.h"

namespace Ui {
class InsertUI;
}
enum Type{
    CLASS_NAME = 0,
    ICO = 1,
    PROPERTIES = 2,
    PSEUDO_STATES = 3,
    SUB_CONTROLS = 4,
    TYPE = 5
};
class InsertUI : public QWidget
{
    Q_OBJECT

public:
    explicit InsertUI(QWidget *parent = 0);
    InsertUI(const Type &type);
    InsertUI(Database *database);
    InsertUI(Database *database,const Type &type);
    ~InsertUI();  
    void setDatabase(Database *database);
    void setType(const Type &type);
    void hideUI(const Type &type);
private slots:
    virtual void on_pushButton_6_clicked();

protected:
    Ui::InsertUI *ui;
    Database *database;
    Type type;
    bool insertClassName();
    bool inserIco();
    bool insertProperties();
    bool insertPseudoSates();
    bool insertSubControls();
    bool insertType();
signals:
    void meCloss();
};

#endif // INSERTUI_H
