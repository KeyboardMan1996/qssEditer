#ifndef SETCONSTUI_H
#define SETCONSTUI_H

#include <QWidget>

namespace Ui {
class setConstUI;
}

class setConstUI : public QWidget
{
    Q_OBJECT

public:
    explicit setConstUI(QWidget *parent = 0);
    ~setConstUI();

private:
    Ui::setConstUI *ui;
};

#endif // SETCONSTUI_H
