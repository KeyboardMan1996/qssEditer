#include "contentui.h"
#include "ui_contentui.h"
#include <QWidget>
#include "codeEditUI.h"
#include "./docmentui.h"
#include "./listwidgetui.h"
#include "primaryfaceui.h"

contentUI::contentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contentUI)
{
    ui->setupUi(this);
    ui->tab->tabBar()->hide();
    codeEdit = new CodeEditUI;
    TestUI = new listWidgetUI;
    ui->tab->addTab(new PrimaryFaceUI,"");
    ui->tab->addTab(codeEdit,"");
    ui->tab->addTab(TestUI,"");
    ui->tab->addTab(new DocmentUI,"");
}

contentUI::~contentUI()
{
    delete ui;
}

void contentUI::on_pushButton_clicked()
{
    ui->tab->setCurrentIndex(0);
}

void contentUI::on_pushButton_2_clicked()
{
    ui->tab->setCurrentIndex(1);
}

void contentUI::on_pushButton_3_clicked()
{
    ui->tab->setCurrentIndex(2);
    TestUI->setStyleSheet(codeEdit->getStyle());
}

void contentUI::on_pushButton_4_clicked()
{
    ui->tab->setCurrentIndex(3);
}
