﻿#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>

namespace Ui {
class mainUI;
}

class mainUI : public QWidget
{
    Q_OBJECT

public:
    explicit mainUI(QWidget *parent = 0);
    ~mainUI();
    QHBoxLayout *contentLayout;
private:
    bool mousePress;
    QPoint mousePoint;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void on_closeButton_clicked();

    void on_maxButton_clicked();

    void on_miniButton_clicked();

private:
    Ui::mainUI *ui;
};

#endif // MAINUI_H
