#ifndef CONTENTUI_H
#define CONTENTUI_H

#include <QWidget>
#include <QTabWidget>
#include <qui/codeEditUI.h>
#include <listwidgetui.h>
namespace Ui {
class contentUI;
}

class contentUI : public QWidget
{
    Q_OBJECT

public:
    explicit contentUI(QWidget *parent = 0);
    ~contentUI();
    QTabWidget *tabWidget;
    CodeEditUI *codeEdit;
    listWidgetUI *TestUI;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:

    Ui::contentUI *ui;
};

#endif // CONTENTUI_H
