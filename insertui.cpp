#include "insertui.h"
#include "ui_insertui.h"
#include <qmessagebox.h>

InsertUI::InsertUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertUI)
{
    ui->setupUi(this);
    database = nullptr;
}
InsertUI::InsertUI(const Type &type):
    QWidget(0),
    ui(new Ui::InsertUI)
{
    ui->setupUi(this);
    this->database = nullptr;
    hideUI(type);

}
InsertUI::InsertUI(Database *database):
    QWidget(0),
    ui(new Ui::InsertUI)
{
    ui->setupUi(this);
    this->database = nullptr;
    setDatabase(database);
}
InsertUI::InsertUI(Database *database, const Type &type):
    QWidget(0),
    ui(new Ui::InsertUI)
{
    ui->setupUi(this);
    this->database = nullptr;
    hideUI(type);
    setDatabase(database);
}
InsertUI::~InsertUI()
{
    delete ui;
}
/*
 * 设置数据库连接
 * @database 数据库连接
 */
void InsertUI::setDatabase(Database *database)
{
    this->database = database;
}
void InsertUI::setType(const Type &type)
{
    this->type = type;
}
/*
 *隐藏多余的输入框
 */
void InsertUI::hideUI(const Type &type)
{
    setType(type);
    switch (type) {
    case CLASS_NAME:
        ui->TypeWidget->hide();
        ui->exampleWidget->hide();
        break;
    case ICO:
        ui->TypeWidget->hide();
        ui->exampleWidget->hide();
        break;
    case PROPERTIES:
        ui->TypeWidget->hide();
        break;
    case PSEUDO_STATES:
        ui->TypeWidget->hide();
        ui->exampleWidget->hide();
        break;
    case SUB_CONTROLS:
        ui->TypeWidget->hide();
        ui->exampleWidget->hide();
        break;
    case TYPE:
        break;
    default:
        break;
    }
}
/*
 * 插入类名
 */
bool InsertUI::insertClassName()
{
    QString caseWord = ui->caseWordLineEdit->text();
    QString contentE = ui->contentEPlainTextEdit->toPlainText();
    QString contentC = ui->contentCPlainTextEdit->toPlainText();
    if(database!=nullptr && caseWord != "")
    {
        database->insertClassName(caseWord,contentE,contentC);
        return true;
    }
    return false;
}
/*
 * 插入图标名称
 */
bool InsertUI::inserIco()
{
    QString caseWord = ui->caseWordLineEdit->text();
    QString contentE = ui->contentEPlainTextEdit->toPlainText();
    QString contentC = ui->contentCPlainTextEdit->toPlainText();
    if(database!=nullptr && caseWord != "")
    {
        database->insertIco(caseWord,contentE,contentC);
        return true;
    }
    return false;
}
/*
 * 插入属性
 */
bool InsertUI::insertProperties()
{
    QString caseWord = ui->caseWordLineEdit->text();
    QString contentE = ui->contentEPlainTextEdit->toPlainText();
    QString contentC = ui->contentCPlainTextEdit->toPlainText();
    QString example = ui->examplePlainTextEdit->toPlainText();
    if(database!=nullptr && caseWord != "")
    {
        database->insertProperties(caseWord,contentE,contentC,example);
        return true;
    }
    return false;
}
/*
 * 插入伪状态
 */
bool InsertUI::insertPseudoSates()
{
    QString caseWord = ui->caseWordLineEdit->text();
    QString contentE = ui->contentEPlainTextEdit->toPlainText();
    QString contentC = ui->contentCPlainTextEdit->toPlainText();
    if(database!=nullptr && caseWord != "")
    {
        database->insertPseudoStates(caseWord,contentE,contentC);
        return true;
    }
    return false;
}
/*
 * 插入控件名称
 */
bool InsertUI::insertSubControls()
{
    QString caseWord = ui->caseWordLineEdit->text();
    QString contentE = ui->contentEPlainTextEdit->toPlainText();
    QString contentC = ui->contentCPlainTextEdit->toPlainText();
    if(database!=nullptr && caseWord != "")
    {
        database->insertClassName(caseWord,contentE,contentC);
        return true;
    }
    return false;
}
/*
 * 插入类型值
 */
bool InsertUI::insertType()
{
    QString caseWord = ui->caseWordLineEdit->text();
    QString contentE = ui->contentEPlainTextEdit->toPlainText();
    QString contentC = ui->contentCPlainTextEdit->toPlainText();
    QString type = ui->typeLineEdit->text();
    QString example = ui->examplePlainTextEdit->toPlainText();
    if(database!=nullptr && caseWord != "")
    {
        database->insertType(caseWord,type,contentE,contentC,example);
        return true;
    }
    return false;
}
void InsertUI::on_pushButton_6_clicked()
{
    bool state = false;
    switch (this->type) {
    case CLASS_NAME:
        state = insertClassName();
        break;
    case ICO:
        state = inserIco();
        break;
    case PROPERTIES:
        state = insertProperties();
        break;
    case PSEUDO_STATES:
        state = insertPseudoSates();
        break;
    case SUB_CONTROLS:
        state = insertSubControls();
        break;
    case TYPE:
        state = insertType();
        break;
    default:
        QMessageBox mes;
        mes.setText("插入了未知类型。。。");
        mes.exec();
        break;
    }

    if(state == false)
    {
        QMessageBox  mes;
        mes.setText("数据库连接错误或者是输入的关键字为空");
        mes.exec();
        return;
    }
    QWidget *p = dynamic_cast<QWidget *>(this->parent()->parent());     //之所以两层parent是因为这个窗口要放在主ui中，而主ui包了两层widget
    p->close();
}
