#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <setting.h>

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
    QString makeColorString(const QColor &color, const QString type);
    QWidget *currentWidget;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void on_closeButton_clicked();

    void on_maxButton_clicked();

    void on_miniButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

private:
    Setting setting;    //软件配置
    Ui::mainUI *ui;
};

#endif // MAINUI_H
