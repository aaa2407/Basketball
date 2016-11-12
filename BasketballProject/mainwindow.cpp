#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "polygon/polygon.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        polygon arr;
        arr.add(point(0, 0, 0));
        arr.add(point(5, 0, 5));
        arr.add(point(5, 5, 10));
        arr.add(point(0, 10, 10));
        arr.add(point(0, 5, 5));
        std::cout << (operations::isInConvexPolygon(point(2.5, 2.5, 5), arr) ? "true" : "false") << std::endl;
        std::cout << arr.normal() << std::endl;
        arr.changeNormal();
        std::cout << arr.normal() << std::endl;

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
