#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "array\array.h"
using std::cout;
using std::endl;

typedef float real;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    array<float> arr(4);
    arr[0] = 1;
    arr[1] = 3;
    cout << arr << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
