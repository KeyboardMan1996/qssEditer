#include "docmentui.h"
#include "ui_docmentui.h"
#include "qstandarditemmodel.h"
#include "insertui.h"
#include "qui/mainui.h"
#include <qmessagebox.h>

DocmentUI::DocmentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocmentUI)
{
    ui->setupUi(this);
//    QStandardItemModel *model = new QStandardItemModel(20, 10);
//      for (int row = 0; row < 20; ++row) {
//          for (int column = 0; column < 10; ++column) {
//              QStandardItem *item = new QStandardItem(QString("row %0,\n column %1").arg(row).arg(column));
//              model->setItem(row, column, item);
//          }
//      }

//      ui->tableView->setModel(model);
//      SetTabViewColumnSpace(ui->tableView);

      this->database = new Database;



}

DocmentUI::~DocmentUI()
{
    delete ui;
}
/*
 * 显示表数据
 * @form 表明
 */
void DocmentUI::displayForm(const Type &form)
{
    Values values;
    int columu;
    switch (form) {
    case CLASS_NAME:
         columu = 4;
         values = database->selectFormValues("ClassName",columu);
        break;
    case ICO:
        columu = 4;
        values = database->selectFormValues("Ico",columu);
        break;
    case PROPERTIES:
        columu = 5;
        values = database->selectFormValues("Properties",columu);
        break;
    case PSEUDO_STATES:
        columu = 4;
        values = database->selectFormValues("PseudoStates",columu);
        break;
    case SUB_CONTROLS:
        columu = 4;
        values = database->selectFormValues("SubControls",columu);
        break;
    case TYPE:
        columu = 6;
        values = database->selectFormValues("Type",columu);
        break;
    default:
        QMessageBox mes;
        mes.setText("获取表数据错误：输入了未知类型");
        mes.exec();
        return;
        break;
    }
    QStandardItemModel *model = new QStandardItemModel();
    for(int row =0;row < values.size()/columu;row++)
    {
        for(int c = 1; c < columu; c++) {
             QStandardItem *item = new QStandardItem(values.at(row*columu + c));
             model->setItem(row, c, item);
             }
    }
    ui->tableView->setModel(model);
    SetTabViewColumnSpace(ui->tableView);
}
/*
 * 更新tableView自适应宽度和高度
 */
void DocmentUI::SetTabViewColumnSpace(QTableView *tableView)
{
    //根据内容来确定列宽度
    tableView->resizeColumnsToContents();       //自适应列宽度
    tableView->resizeRowsToContents();          //自适应行高度
    tableView->horizontalHeader();

    //获取表头列数
    for(int i = 0; i < tableView->horizontalHeader()->count(); i++)
    {
        tableView->setColumnWidth(i, tableView->columnWidth(i) + 40);  //多一些空余控件，不然每列内容很挤
    }
    tableView->horizontalHeader()->setStretchLastSection(true);        //最后一列补全所有空白位置
}


void DocmentUI::on_insertButton_clicked()
{
    InsertUI *insert = new InsertUI(database,Type(ui->comboBox->currentIndex()));
    mainUI *mainui = new mainUI;
    mainui->contentLayout->addWidget(insert);
    mainui->resize(300,500);
    mainui->show();
}

void DocmentUI::on_comboBox_currentIndexChanged(int index)
{
    displayForm(Type(index));
}
