#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "camera\camera.h"
#include "point\point.h"
#include "polygon\polygon.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        //point p(100, 0, 0);
        camera cam;
        cam.increase(100);
        cam.rotate(M_PI_4);
        cam.upIncline(M_PI_4);
        cam.left(20);
        polygon pol;
        pol.add(point(3, 0, 10));
        pol.add(point(-13, 0, 5));
        pol.add(point(0, 0, -10));
        point n = pol.normal();
        cout << n << endl;
        for (int i = 0; i < 13; i++)
        {
            cout << cam.rotate()/M_PI << "*PI\t\t" << n*cam.vector() << endl;
            cam.rotate(M_PI_2/3);
        }
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
