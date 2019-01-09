#include "codeEditUI.h"
#include "ui_codeEditUI.h"
#include "QFontDialog"
#include <QColorDialog>
#include <QTextCursor>
#include <QFileDialog>
#include <listwidgetui.h>
#include <QDesktopServices>
CodeEditUI::CodeEditUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodeEditUI)
{
    ui->setupUi(this);
    currentWidget = new listWidgetUI;
    currentWidget->setObjectName("miaomiaomiao");
    ui->widget->layout()->addWidget(currentWidget);

    ui->codeEditer->setFont(setting.getFont());

}

CodeEditUI::~CodeEditUI()
{
    delete ui;
}

void CodeEditUI::on_pushButton_2_clicked()
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

void CodeEditUI::on_pushButton_clicked()
{
    QColorDialog color;
    QColor c = color.getColor();
    if(!c.isValid())
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

QString CodeEditUI::makeColorString(const QColor &color, const QString type)
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


void CodeEditUI::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp *ico)"));
    if(fileName == "")
        return;
    QTextCursor cursor = ui->codeEditer->textCursor();
    cursor.insertText("url(" + fileName + ")");
    ui->codeEditer->setTextCursor(cursor);
}

void CodeEditUI::on_pushButton_3_clicked()
{
    currentWidget->setStyleSheet(ui->codeEditer->toPlainText());
}

void CodeEditUI::on_pushButton_6_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://anjztb.top/anqss")));
}

