#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "real_matrix\real_matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        rmatrix m(3, 2, 1.2);
        m *= 2;
        std::cout << m << std::endl;
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
