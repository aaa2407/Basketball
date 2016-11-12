#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "camera\camera.h"
#include "point\point.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        point p(100, 0, 0);
        camera cam;
        cam.increase(100);
        cam.rotate(M_PI_4);
        cam.upIncline(M_PI_4);
        p = point(p.toArray()*cam.get());
        cout << p << endl;
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
