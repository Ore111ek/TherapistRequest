#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_continue_row_start_btn_clicked()
{
    row_form = new ContinueRow();
    row_form->show();
}


void MainWindow::on_sort_game_strt_btn_clicked()
{
    sort_form = new SortForm();
    sort_form->show();
}

