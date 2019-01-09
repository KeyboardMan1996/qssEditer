#include "docmentui.h"
#include "ui_docmentui.h"
#include "qstandarditemmodel.h"

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

      database = new Database;
      Values values = database->selectFormValues("ClassName",4);
      QStandardItemModel *model = new QStandardItemModel();
      for(int row =0;row < values.size();row++)
      {
          for(int column = 1; column < 4; ++column) {
               QStandardItem *item = new QStandardItem(values.at(column));
               model->setItem(row, column, item);
               }
      }
      ui->tableView->setModel(model);
      SetTabViewColumnSpace(ui->tableView);


}

DocmentUI::~DocmentUI()
{
    delete ui;
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
