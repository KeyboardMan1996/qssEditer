#ifndef DOCMENTUI_H
#define DOCMENTUI_H

#include <QWidget>
#include <QTableView>
#include <database.h>

namespace Ui {
class DocmentUI;
}

class DocmentUI : public QWidget
{
    Q_OBJECT

public:
    explicit DocmentUI(QWidget *parent = 0);
    ~DocmentUI();

private:
    Ui::DocmentUI *ui;
    Database *database;
    void SetTabViewColumnSpace(QTableView *tableView);
};

#endif // DOCMENTUI_H
