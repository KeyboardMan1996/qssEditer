#include "buttonui.h"
#include "ui_buttonui.h"

buttonUI::buttonUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buttonUI)
{
    ui->setupUi(this);
}

buttonUI::~buttonUI()
{
    delete ui;
}
