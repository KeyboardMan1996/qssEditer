#include "primaryfaceui.h"
#include "ui_primaryfaceui.h"
#include "config/setting.h"
#include "config/versionsmanager.h"
#include <QDesktopServices>

PrimaryFaceUI::PrimaryFaceUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimaryFaceUI)
{
    ui->setupUi(this);
    manager = new VersionsManager;
    connect(manager,SIGNAL(finished()),this,SLOT(versionsTaskFinished()));

    ui->informTextEdit->setText(setting.getInform());
    ui->updataTextEdit->setText("暂时没有新版本");
    ui->insertButton->hide();

}

PrimaryFaceUI::~PrimaryFaceUI()
{
    delete ui;
}

void PrimaryFaceUI::versionsTaskFinished()
{
    setting.setInform(manager->inform);
    if(manager->updata)
    {
       ui->updataTextEdit->setText(manager->updataContent);
       ui->insertButton->show();
    }
    ui->informTextEdit->setText(manager->inform);

}

void PrimaryFaceUI::on_insertButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://anjztb.top/anqss")));
}

void PrimaryFaceUI::on_insertButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://anjztb.top/anqss")));
}
