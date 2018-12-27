#include "casewordhintwidget.h"
#include "ui_casewordhintwidget.h"

CaseWordHintWidget::CaseWordHintWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseWordHintWidget)
{
    ui->setupUi(this);
}

CaseWordHintWidget::~CaseWordHintWidget()
{
    delete ui;
}
