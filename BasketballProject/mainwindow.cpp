#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try
    {
        scene = new QGraphicsScene(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        ui->gv->setScene(scene);
        draw = new drawingShading(scene->width(), scene->height());
        _wall.set("BasketWall.jpg");
        _floor.set("BasketFloor.jpg");

        _paral = paral(400, 400, 230);
        _paral.setPolygonPicture(0, &_wall);
        _paral.setPolygonPicture(1, &_wall);
        _paral.setPolygonPicture(2, &_wall);
        _paral.setPolygonPicture(3, &_wall);
        _paral.setPolygonPicture(PARAL_FLOOR, &_floor);
        _paral.setPolygonPicturePos(PARAL_CEILING, 3);
        _paral.setPolygonPicturePos(PARAL_FLOOR, 3);
        _paral.setOutwardNormal(false);
        _paral.setPolygonColor(4, QColor(Qt::red));
        draw->decrease(400);
        draw->draw(_paral);

        scene->addPixmap(draw->createPixmap());

        for (size_t i = 0; i < _paral.getPolygonCount(); i++)
        {
            apolygon apol;
            polygon pol = _paral.getPolygon(i);
            for (size_t j = 0; j < pol.size(); j++)
            {
                 apol.add(pol[j]);
                 if (j == PARAL_FLOOR)
                     apol.set_koef(0.7);
                 else
                     apol.set_koef(0.95);
            }
            space.addPolygon(apol);
        }

        emit space.spos(point(20, 20, 50));
        emit space.ssecond_point(point(0, 0, 0));
        emit space.smax_z(100);
        emit space.sstart(50);
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
        draw->draw(_paral);
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
