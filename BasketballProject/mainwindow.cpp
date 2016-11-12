#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mutable_array/marray.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        marray<int> a;
        a.add(1);
        a.add(2);
        a.add(3);
        int r = a.del(1);
        std::cout << r << std::endl;
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
    delete scene;
    delete ui;
}
