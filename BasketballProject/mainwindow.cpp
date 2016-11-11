#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "transform_matrix\transform_matrix_base.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        transform_base tr;
        std::cout << tr << std::endl;
    }
    catch(errorBase& error)
    {
        QMessageBox box;
        box.setText(error.what());
        box.show();
        box.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
