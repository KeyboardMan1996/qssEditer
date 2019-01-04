#ifndef LISTWIDGETUI_H
#define LISTWIDGETUI_H

#include <QWidget>

namespace Ui {
class listWidgetUI;
}

class listWidgetUI : public QWidget
{
    Q_OBJECT

public:
    explicit listWidgetUI(QWidget *parent = 0);
    ~listWidgetUI();

private:
    Ui::listWidgetUI *ui;
};

#endif // LISTWIDGETUI_H
