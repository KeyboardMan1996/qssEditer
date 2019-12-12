#include "setconstui.h"
#include "ui_setconstui.h"

setConstUI::setConstUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setConstUI)
{
    ui->setupUi(this);
}

setConstUI::~setConstUI()
{
    delete ui;
}
