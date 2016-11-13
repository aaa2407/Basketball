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
        polygon pol1;
        pol1.add(point(55, -25, -25));
        pol1.add(point(55,  25, -25));
        pol1.add(point(55,  25,  25));
        pol1.add(point(55, -25,  25));
        if (pol1.get_plane().value(point(0, 0, 0)) > 0)
            pol1.changeNormal();
        draw->setPenColor(QColor(Qt::blue));
        draw->draw(pol1);
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
        polygon pol1;
        pol1.add(point(-55, 25, -25));
        pol1.add(point(-55, 25,  25));
        pol1.add(point( 55, 25,  25));
        pol1.add(point( 55, 25, -25));
        polygon pol2;
        pol2.add(point(-55, -25, -25));
        pol2.add(point( 55, -25,  -25));
        pol2.add(point( 55, -25,  25));
        pol2.add(point( -55, -25, 25));
        polygon pol3;
        pol3.add(point(-55, 25, -25));
        pol3.add(point(-55, 25,  25));
        pol3.add(point(-55, -25,  25));
        pol3.add(point(-55, -25, -25));
        polygon pol4;
        pol4.add(point( 55, -25, -25));
        pol4.add(point( 55, -25,  25));
        pol4.add(point( 55,  25,  25));
        pol4.add(point( 55,  25, -25));
        polygon pol5;
        pol5.add(point(-55, -25,  25));
        pol5.add(point(-55,  25,  25));
        pol5.add(point( 55, -25,  25));
        pol5.add(point( 55,  25,  25));
        polygon pol6;
        pol6.add(point(-55, -25, -25));
        pol6.add(point( 55, -25, -25));
        pol6.add(point( 55,  25, -25));
        pol6.add(point(-55,  25, -25));
        plane p1 = pol1.get_plane();
        plane p2 = pol2.get_plane();
        plane p3 = pol3.get_plane();
        plane p4 = pol4.get_plane();
        plane p5 = pol5.get_plane();
        plane p6 = pol6.get_plane();
        if (p1.value(point(0, 0, 0)) < 0)
        {
            pol1.changeNormal();
            p1.negation();
        }
        if (p2.value(point(0, 0, 0)) < 0)
        {
            pol2.changeNormal();
            p2.negation();
        }
        if (p3.value(point(0, 0, 0)) < 0)
        {
            pol3.changeNormal();
            p3.negation();
        }
        if (p4.value(point(0, 0, 0)) < 0)
        {
            pol4.changeNormal();
            p4.negation();
        }
        if (p5.value(point(0, 0, 0)) < 0)
        {
            pol5.changeNormal();
            p5.negation();
        }
        if (p6.value(point(0, 0, 0)) < 0)
        {
            pol6.changeNormal();
            p6.negation();
        }
        point a1 = draw->new_point(pol1.normal());
        point a2 = draw->new_point(pol2.normal());
        point a3 = draw->new_point(pol3.normal());
        point a4 = draw->new_point(pol4.normal());
        point a5 = draw->new_point(pol5.normal());
        point a6 = draw->new_point(pol6.normal());
        a1.normalization();
        a2.normalization();
        a3.normalization();
        a4.normalization();
        a5.normalization();
        a6.normalization();

        draw->setPenColor(QColor(Qt::blue));
        if (a1*point(-1, 0, 0) < 0)
            draw->draw(pol1);
        if (a2*point(-1, 0, 0) < 0)
            draw->draw(pol2);
        if (a3*point(-1, 0, 0) < 0)
            draw->draw(pol3);
        if (a4*point(-1, 0, 0) < 0)
            draw->draw(pol4);
        if (a5*point(-1, 0, 0) < 0)
            draw->draw(pol5);
        if (a6*point(-1, 0, 0) < 0)
            draw->draw(pol6);
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
