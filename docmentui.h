#ifndef DOCMENTUI_H
#define DOCMENTUI_H

#include <QWidget>
#include <QTableView>
#include <database.h>
#include "insertui.h"

namespace Ui {
class DocmentUI;
}

class DocmentUI : public QWidget
{
    Q_OBJECT

public:
    explicit DocmentUI(QWidget *parent = 0);
    ~DocmentUI();

private slots:
    void on_insertButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::DocmentUI *ui;
    Database *database;
    void SetTabViewColumnSpace(QTableView *tableView);
    void displayForm(const Type &form);
};

#endif // DOCMENTUI_H
