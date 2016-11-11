#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "geom_operations/operations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        plane a(-1, -1, -1, 2);
        std::cout << a.value(0,0,0) << std::endl;
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
