#ifndef CODEEDITUI_H
#define CODEEDITUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <setting.h>

namespace Ui {
class CodeEditUI;
}

class CodeEditUI : public QWidget
{
    Q_OBJECT

public:
    explicit CodeEditUI(QWidget *parent = 0);
    ~CodeEditUI();
    QHBoxLayout *contentLayout;
private:
    QPoint mousePoint;
    QString makeColorString(const QColor &color, const QString type);
    QWidget *currentWidget;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Setting setting;    //软件配置
    Ui::CodeEditUI *ui;
};

#endif // MAINUI_H
