#include "contentui.h"
#include "ui_contentui.h"
#include <QWidget>
#include "codeEditUI.h"
#include "./docmentui.h"

contentUI::contentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contentUI)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->addTab(new QWidget,"");
    ui->tabWidget->addTab(new CodeEditUI,"");
    ui->tabWidget->addTab(new DocmentUI,"");
}

contentUI::~contentUI()
{
    delete ui;
}

void contentUI::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void contentUI::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void contentUI::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}
