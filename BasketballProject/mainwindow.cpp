#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "drawing\z-buffer\z-buffer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        scene = new QGraphicsScene(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        ui->gv->setScene(scene);
        Z_buffer zbuf(scene->width(), scene->height());
        zbuf.setPixel(scene->width()-1, scene->height()-1, QColor(Qt::blue), 200);
        zbuf.setPixel(-2, 2, QColor(Qt::red), 300);
        QPixmap map = zbuf.createPixmap();
        scene->addPixmap(map);
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
