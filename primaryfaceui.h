#ifndef PRIMARYFACEUI_H
#define PRIMARYFACEUI_H

#include <QWidget>
#include "versionsmanager.h"
#include "setting.h"
namespace Ui {
class PrimaryFaceUI;
}

class PrimaryFaceUI : public QWidget
{
    Q_OBJECT

public:
    explicit PrimaryFaceUI(QWidget *parent = 0);
    ~PrimaryFaceUI();
    VersionsManager *manager;
    Setting setting;

private:
    Ui::PrimaryFaceUI *ui;
public slots:
    void versionsTaskFinished();
private slots:
    void on_insertButton_clicked();
    void on_insertButton_2_clicked();
};

#endif // PRIMARYFACEUI_H
