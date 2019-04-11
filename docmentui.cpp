#include "docmentui.h"
#include "ui_docmentui.h"
#include "qstandarditemmodel.h"
#include "insertui.h"
#include "qui/mainui.h"
#include <qmessagebox.h>
#include "updataui.h"

DocmentUI::DocmentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocmentUI)
{
    ui->setupUi(this);

    this->database = new Database;
    this->on_comboBox_currentIndexChanged(0);


}

DocmentUI::~DocmentUI()
{
    delete ui;
}
/*
 * 显示表数据
 * @form 表名
 */
void DocmentUI::displayForm(const Type &form)
{
    Values values;
    int columu;
    QList<QString> heads;
    heads.append("ID");
    heads.append("关键字");
    heads.append("官方文档");
    heads.append("中文文档");
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
        heads.append("例子");
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
        heads.insert(2,"类型");
        heads.append("例子");
        break;
    default:
        QMessageBox mes;
        mes.setText("获取表数据错误：输入了未知类型");
        mes.exec();
        return;
        break;
    }
    QStandardItemModel *model = new QStandardItemModel();
    //将每一个数据放到表格中
    for(int row =0;row < values.size()/columu;row++)
    {
        for(int c = 0; c < columu; c++) {
             QStandardItem *item = new QStandardItem(values.at(row*columu + c));
             model->setItem(row, c, item);
             }
    }
    //设置表头
    for(int i = 0;i < heads.size();i++)
    {
        model->setHeaderData(i,Qt::Horizontal,heads.at(i));
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
    tableView->horizontalHeader();
    int miniRow = 0;    //小列的总宽度
    int maxRowCount = 0;    //比较宽的行的总数
    //获取表头列数
    /*
    自动适应原理
    先获得较短列的总长度。
    然后用总长度减去较短列的长度。
    之后将剩余长度平均分配给较长列。
    然后自动补齐最后列
    */
    for(int i = 0; i < tableView->horizontalHeader()->count(); i++)
    {
        if(tableView->columnWidth(i) < 40)
        {
            tableView->setColumnWidth(i, tableView->columnWidth(i)+40);  //多一些空余空间，不然每列内容很挤
        }
        if(tableView->columnWidth(i) < 200)
        {
            miniRow += tableView->columnWidth(i) + 10;       //取消横向滚动条
        }else {
            maxRowCount++;
        }
    }
    for(int i = 0;i < tableView->horizontalHeader()->count();i++)
    {
        if(tableView->columnWidth(i) > 200)
        {
            tableView->setColumnWidth(i, (tableView->width() - miniRow)/maxRowCount - 1);
        }
    }
    tableView->resizeRowsToContents();          //自适应行高度
     tableView->horizontalHeader()->setStretchLastSection(true); //自动补齐最后一列

}
/*
 * 插入数据按钮
 */
void DocmentUI::on_insertButton_clicked()
{
    InsertUI *insert = new InsertUI(database,Type(ui->comboBox->currentIndex()));
    mainUI *mainui = new mainUI;
    mainui->contentLayout->addWidget(insert);
    mainui->resize(300,500);
    mainui->show();
    //绑定窗口关闭信号刷新表格显示
    connect(insert,SIGNAL(meCloss()),this,SLOT(upDataDisplayForm()));
}
/*
 * 类型下拉选项框
 */
void DocmentUI::on_comboBox_currentIndexChanged(int index)
{
    displayForm(Type(index));
}
/*
 * 删除数据按钮
 */
void DocmentUI::on_insertButton_2_clicked()
{
    //获取选中行的引索
    int row =ui->tableView->currentIndex().row();
    if(row == -1)
        return;
    QAbstractItemModel *modl = ui->tableView->model();
    QModelIndex index = modl->index(row,0);
    int id = index.data().toInt();
    //获取表名
    QString form;

    switch (ui->comboBox->currentIndex()) {
    case 0:
        form = "ClassName";
        break;
    case 1:
        form = "Ico";
        break;
    case 2:
        form = "Properties";
        break;
    case 3:
        form = "PseudoStates";
        break;
    case 4:
        form = "SubControls";
        break;
    case 5:
        form ="Type";
    }
    //删除行
    database->deleteRowForID(id,form);
    //刷新表格显示
    upDataDisplayForm();
}
/*
 * 修改数据
 */
void DocmentUI::on_insertButton_3_clicked()
{
    //获取选中行的引索
    int row =ui->tableView->currentIndex().row();
    if(row == -1)
        return;
    QAbstractItemModel *modl = ui->tableView->model();
    QModelIndex index = modl->index(row,0);
    int id = index.data().toInt();

    UpDataUi *upDataUi = new UpDataUi(database,Type(ui->comboBox->currentIndex()));
    upDataUi->id = id;
    //获取表名并初始化值
    QString form;
    switch (ui->comboBox->currentIndex()) {
    case 0:
        form = "ClassName";
        upDataUi->setCaseWord(modl->index(row,1).data().toString());
        upDataUi->setContentE(modl->index(row,2).data().toString());
        upDataUi->setContentC(modl->index(row,3).data().toString());
        break;
    case 1:
        form = "Ico";
        upDataUi->setCaseWord(modl->index(row,1).data().toString());
        upDataUi->setContentE(modl->index(row,2).data().toString());
        upDataUi->setContentC(modl->index(row,3).data().toString());
        break;
    case 2:
        form = "Properties";
        upDataUi->setCaseWord(modl->index(row,1).data().toString());
        upDataUi->setContentE(modl->index(row,2).data().toString());
        upDataUi->setContentC(modl->index(row,3).data().toString());
        upDataUi->setExample(modl->index(row,4).data().toString());
        break;
    case 3:
        form = "PseudoStates";
        upDataUi->setCaseWord(modl->index(row,1).data().toString());
        upDataUi->setContentE(modl->index(row,2).data().toString());
        upDataUi->setContentC(modl->index(row,3).data().toString());
        break;
    case 4:
        form = "SubControls";
        upDataUi->setCaseWord(modl->index(row,1).data().toString());
        upDataUi->setContentE(modl->index(row,2).data().toString());
        upDataUi->setContentC(modl->index(row,3).data().toString());
        break;
    case 5:
        form ="Type";
        upDataUi->setCaseWord(modl->index(row,1).data().toString());
        upDataUi->setTYPE(modl->index(row,2).data().toString());
        upDataUi->setContentE(modl->index(row,3).data().toString());
        upDataUi->setContentC(modl->index(row,4).data().toString());
        upDataUi->setExample(modl->index(row,5).data().toString());
    }

    mainUI *mainui = new mainUI;
    mainui->contentLayout->addWidget(upDataUi);
    mainui->resize(300,600);
    mainui->show();
    //绑定窗口关闭信号刷新表格显示
    connect(upDataUi,SIGNAL(meCloss()),this,SLOT(upDataDisplayForm()));
}
/*
 * 刷新显示内容
 */
void DocmentUI::upDataDisplayForm()
{
    displayForm(Type(ui->comboBox->currentIndex()));
}
