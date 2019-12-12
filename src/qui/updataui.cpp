#include "updataui.h"
#include "ui_insertui.h"
UpDataUi::UpDataUi(Database *database,const Type &type)
    :InsertUI::InsertUI(database,type)
{
   // connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(buttonClickd()));
    id = 999999;
}
/*
 * 更新数据
 */
void UpDataUi::on_pushButton_6_clicked()
{
    switch (type) {
    case CLASS_NAME:
        database->upDatabase("ClassName",id,"name",ui->caseWordLineEdit->text());
        database->upDatabase("ClassName",id,"content_e",ui->contentEPlainTextEdit->toPlainText());
        database->upDatabase("ClassName",id,"content_c",ui->contentCPlainTextEdit->toPlainText());
        break;
    case ICO:
        database->upDatabase("Ico",id,"name",ui->caseWordLineEdit->text());
        database->upDatabase("Ico",id,"content_e",ui->contentEPlainTextEdit->toPlainText());
        database->upDatabase("Ico",id,"content_c",ui->contentCPlainTextEdit->toPlainText());
        break;
    case PROPERTIES:
        database->upDatabase("Properties",id,"name",ui->caseWordLineEdit->text());
        database->upDatabase("Properties",id,"content_e",ui->contentEPlainTextEdit->toPlainText());
        database->upDatabase("Properties",id,"content_c",ui->contentCPlainTextEdit->toPlainText());
        database->upDatabase("Properties",id,"example",ui->examplePlainTextEdit->toPlainText());
        break;
    case PSEUDO_STATES:
        database->upDatabase("PseudoStates",id,"name",ui->caseWordLineEdit->text());
        database->upDatabase("PseudoStates",id,"content_e",ui->contentEPlainTextEdit->toPlainText());
        database->upDatabase("PseudoStates",id,"content_c",ui->contentCPlainTextEdit->toPlainText());
        break;
    case SUB_CONTROLS:
        database->upDatabase("SubControls",id,"name",ui->caseWordLineEdit->text());
        database->upDatabase("SubControls",id,"content_e",ui->contentEPlainTextEdit->toPlainText());
        database->upDatabase("SubControls",id,"content_c",ui->contentCPlainTextEdit->toPlainText());
        break;
    case TYPE:
        database->upDatabase("Type",id,"name",ui->caseWordLineEdit->text());
        database->upDatabase("Type",id,"content_e",ui->contentEPlainTextEdit->toPlainText());
        database->upDatabase("Type",id,"content_c",ui->contentCPlainTextEdit->toPlainText());
        database->upDatabase("Type",id,"example",ui->examplePlainTextEdit->toPlainText());
        database->upDatabase("Type",id,"type",ui->typeLineEdit->text());
        break;
    }
    QWidget *p = dynamic_cast<QWidget *>(this->parent()->parent());     //之所以两层parent是因为这个窗口要放在主ui中，而主ui包了两层widget
    p->close();
    emit meCloss();
}
void UpDataUi::setCaseWord(const QString &caseWord)
{
    ui->caseWordLineEdit->setText(caseWord);
}
void UpDataUi::setContentC(const QString &content)
{
    ui->contentCPlainTextEdit->setPlainText(content);
}
void UpDataUi::setContentE(const QString &content)
{
    ui->contentEPlainTextEdit->setPlainText(content);
}
void UpDataUi::setExample(const QString &example)
{
    ui->examplePlainTextEdit->setPlainText(example);
}
void UpDataUi::setTYPE(const QString &type)
{
    ui->typeLineEdit->setText(type);
}
