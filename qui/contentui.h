#ifndef CONTENTUI_H
#define CONTENTUI_H

#include <QWidget>
#include <QTabWidget>

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

private:
    Ui::contentUI *ui;
};

#endif // CONTENTUI_H
