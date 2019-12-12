#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "codeEdit/codeeditor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CodeEditor *editor = new CodeEditor;

    ui->mdiArea->addSubWindow(editor);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
