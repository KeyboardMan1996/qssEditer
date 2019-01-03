#include "mainui.h"
#include "ui_mainui.h"
#include "QFontDialog"
#include <QColorDialog>
#include <QTextCursor>
#include <QFileDialog>
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

    currentWidget = new QWidget;

    ui->codeEditer->setFont(setting.getFont());

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
    QFontDialog fontDialog(setting.getFont());
    bool ok;
    QFont font = fontDialog.getFont(&ok,this);  //获取字体
    if(ok)  //如果用户点击确定按钮
    {
        ui->codeEditer->setFont(font);
        setting.setFont(font);
    }

}

void mainUI::on_pushButton_clicked()
{
    QColorDialog color;
    QColor c = color.getColor();
    if(c.isValid())
        return;
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
    { return QString("rgb(%1, %2, %3)")
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


void mainUI::on_comboBox_currentIndexChanged(int index)
{
  //  ui->widget->layout()->removeWidget(currentWidget);
   // delete currentWidget;
}

void mainUI::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp *ico)"));
    if(fileName == "")
        return;
    QTextCursor cursor = ui->codeEditer->textCursor();
    cursor.insertText("url(" + fileName + ")");
    ui->codeEditer->setTextCursor(cursor);
}
