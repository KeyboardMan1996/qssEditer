#ifndef BUTTONUI_H
#define BUTTONUI_H

#include <QWidget>

namespace Ui {
class buttonUI;
}

class buttonUI : public QWidget
{
    Q_OBJECT

public:
    explicit buttonUI(QWidget *parent = 0);
    ~buttonUI();

private:
    Ui::buttonUI *ui;
};

#endif // BUTTONUI_H
