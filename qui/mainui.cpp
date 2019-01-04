#include "mainui.h"
#include "ui_mainui.h"

mainUI::mainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUI)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    contentLayout = new QHBoxLayout;
    contentLayout->setMargin(0);
    ui->contentWidget->setLayout(contentLayout);
}

mainUI::~mainUI()
{
    delete ui;
}

void mainUI::mouseMoveEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);
    if(mousePress)
        this->move(pos()+(e->pos()-mousePoint));
}
void mainUI::mousePressEvent(QMouseEvent *e)
{
    QWidget::mousePressEvent(e);
    if(e->pos().y()<=30)
    {
        mousePress = true;
        mousePoint = e->pos();
    }

}
void mainUI::mouseReleaseEvent(QMouseEvent *e)
{
    QWidget::mouseReleaseEvent(e);
    mousePress = false;
}

void mainUI::on_closeButton_clicked()
{
    this->close();
}

void mainUI::on_maxButton_clicked()
{
    this->showMaximized();
}

void mainUI::on_miniButton_clicked()
{
    this->showMinimized();
}
