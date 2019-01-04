#include "listwidgetui.h"
#include "ui_listwidgetui.h"

listWidgetUI::listWidgetUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listWidgetUI)
{
    ui->setupUi(this);
}

listWidgetUI::~listWidgetUI()
{
    delete ui;
}
