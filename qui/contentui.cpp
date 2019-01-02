#include "contentui.h"
#include "ui_contentui.h"

contentUI::contentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contentUI)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable(true);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),ui->tabWidget,SLOT(deleteTab(int)));
    tabWidget = ui->tabWidget;
}

contentUI::~contentUI()
{
    delete ui;
}
