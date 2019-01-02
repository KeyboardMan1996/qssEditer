#include "mainui.h"
#include "ui_mainui.h"
#include "QFontDialog"
#include <QColorDialog>
#include <QTextCursor>

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

void mainUI::on_pushButton_2_clicked()
{
    QFontDialog fontDialog;
    fontDialog.exec();
    QFont font = fontDialog.selectedFont();
    ui->codeEditer->setFont(font);
}

void mainUI::on_pushButton_clicked()
{
    QColorDialog color;
    color.exec();
    QColor c = color.selectedColor();
    QTextCursor cursor = ui->codeEditer->textCursor();
    if(c.alpha() == 255)
    {
        cursor.insertText(makeColorString(c,"RGB"));
    }else {
        cursor.insertText(makeColorString(c,"RGBA"));
    }
    ui->codeEditer->setTextCursor(cursor);
}

QString mainUI::makeColorString(const QColor &color, const QString type)
{
    if(type == "RGBA")
    { return QString("rgba(%1, %2, %3, %4)")
                .arg(color.red())
                .arg(color.green())
                .arg(color.blue())
                .arg(color.alpha());
    }
    if(type == "RGB")
    { return QString("rgba(%1, %2, %3)")
                .arg(color.red())
                .arg(color.green())
                .arg(color.blue());
    }
    if(type == "HEX")
    { return QString().sprintf("#%1%02X%02X%02X",
                               color.red(),
                               color.green(),
                               color.blue()).arg(color.alpha() != 255 ? QString().sprintf("%02X", color.alpha()) : QString()); }
    return "erro";
}

