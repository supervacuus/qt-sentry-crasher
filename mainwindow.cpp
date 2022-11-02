#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

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

void MainWindow::on_pushButton_clicked()
{
    //void *p = (void*) 10;
    //memset(p, 1, 100);
    auto volatile bad_ptr = (double *)(-9ll); // Unaligned and near end-of-page
    bad_ptr[0] = (6.022141e23 / 0) + bad_ptr[1];
}
