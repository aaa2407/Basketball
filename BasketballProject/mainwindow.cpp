#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        scene = new QGraphicsScene(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        ui->gv->setScene(scene);
        draw = new drawingFrame(scene->width(), scene->height());
        draw->setPenColor(QColor(Qt::blue));
        _paral.setOutwardNormal(false);
        for (size_t i = 0; i < _paral.getPolygonCount(); i++)
        {
            polygon pol = _paral.getPolygon(i);
            point a = draw->new_vector(pol.normal());
            if (a*point(-1, 0, 0) < 0)
                draw->draw(pol);
            if (a*point(-1, 0, 0) == 0 && !_paral.outwardNormal())
                draw->draw(pol);
        }
        scene->addPixmap(draw->createPixmap());

        /*emit space.spos(point(20, 20, 50));
        emit space.ssecond_point(point(0, 0, 0));
        emit space.smax_z(100);
        emit space.sstart(50);*/
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
    delete draw;
    delete scene;
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    try
    {
        scene->clear();
        scene->setSceneRect(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        switch (event->key())
        {
            case Qt::Key_W:
                draw->upIncline(M_PI_2/12);
            break;
            case Qt::Key_S:
                draw->downIncline(M_PI_2/12);
            break;
            case Qt::Key_A:
                draw->rotate(-M_PI_2/12);
            break;
            case Qt::Key_D:
                draw->rotate(M_PI_2/12);
            break;

            case Qt::Key_8:
                draw->up(10);
            break;
            case Qt::Key_2:
                draw->down(10);
            break;
            case Qt::Key_4:
                draw->left(10);
            break;
            case Qt::Key_6:
                draw->right(10);
            break;
            case Qt::Key_9:
                draw->forward(10);
            break;
            case Qt::Key_3:
                draw->back(10);
            break;


            case Qt::Key_Plus:
                draw->increase(10);
            break;
            case Qt::Key_Minus:
                draw->decrease(10);
            break;

        }
        draw->clear();
        for (size_t i = 0; i < _paral.getPolygonCount(); i++)
        {
            polygon pol = _paral.getPolygon(i);
            point a = draw->new_vector(pol.normal());
            if (a*point(-1, 0, 0) < 0)
                draw->draw(pol);
            if (a*point(-1, 0, 0) == 0 && !_paral.outwardNormal())
                draw->draw(pol);
        }
        scene->addPixmap(draw->createPixmap());
    }
    catch(errorBase& error)
    {
        QMessageBox box;
        box.setText(error.what());
        box.show();
        box.exec();
    }
}
