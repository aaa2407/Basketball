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
        buf = new Z_buffer(scene->width(), scene->height());
        buf->set(scene->width(), scene->height());
        det = new Z_buffer_Detachment(buf);
        cam.decrease(800);
        cam.upIncline(M_PI_2/3);
        cam.rotate(M_PI_4*3);
        _floor.set("BasketFloor.jpg");
        _wall.set("wall.jpg");
        
        par = new paral("Room", 900, 600, 400);
        par->setPolygonPicture(0, &_wall);
        par->setPolygonPicture(1, &_wall);
        par->setPolygonPicture(2, &_wall);
        par->setPolygonPicture(3, &_wall);
        par->setPolygonPicture(4, &_floor);
        par->setPolygonPicture(5, &_wall);
        par->setObjectColor(QColor(Qt::red));
        par->setOutwardNormal(false);
        par->drawing = TEXTURE;


        //torus *_torus = new torus("Torus", 24, 4, 20, 6);
        //_torus->drawing = FRAME;
        composite *basket = new composite("Basket");
        basket->add(new paral("Post", point(-5, -5, -200), point(5, 5, 75)));
        basket->add(new paral("Post2", point(5, 5, 75), point(-25, -5, 85)));
        basket->add(new paral("Shield", 5, 150, 100, point(-27.5, -5, 100)));
        basket->add(new paral("Festerner", point(-30, -3, 70), point(-35, 3, 73)));
        basket->add(new torus("Ring", 24, 4, 24, 4, point(-63, 0,73)));
        basket->transform(TransformMatrix::move(425, 0, 0));
        comp.add(par);
        comp.add(basket);

        _ball = new ball("Ball", 15);
        emit _ball->spos(point(50, 50, 0));
        emit _ball->ssecond_point(point(427-63, 0, 73));
        emit _ball->smax_z(120);
        connect(_ball, SIGNAL(smove()), this, SLOT(basket_draw()));
        comp.draw(buf, &cam);
        map = buf->createPixmap();
        _ball->draw(det, &cam);
        point a(0, 0, 300);
        a.draw(det, &cam);
        scene->addPixmap(map);
        scene->addPixmap(det->createPixmap());
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
    delete this->scene;
    delete ui;
}

void MainWindow::basket_draw(){
    det->clear();
    _ball->draw(det, &cam);
    scene->clear();
    scene->addPixmap(map);
    scene->addPixmap(det->createPixmap());
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
                cam.upIncline(M_PI_2/12);
            break;
            case Qt::Key_S:
                cam.downIncline(M_PI_2/12);
            break;
            case Qt::Key_A:
                cam.rotate(M_PI_2/12);
            break;
            case Qt::Key_D:
                cam.rotate(-M_PI_2/12);
            break;

            case Qt::Key_8:
                cam.up(10);
            break;
            case Qt::Key_2:
                cam.down(10);
            break;
            case Qt::Key_4:
                cam.left(10);
            break;
            case Qt::Key_6:
                cam.right(10);
            break;
            case Qt::Key_9:
                cam.forward(10);
            break;
            case Qt::Key_3:
                cam.back(10);
            break;


            case Qt::Key_Plus:
                cam.increase(10);
            break;
            case Qt::Key_Minus:
                cam.decrease(10);
            break;

        }
        buf->clear();
        det->clear();
        _ball->draw(det, &cam);
        comp.draw(buf, &cam);
        map = buf->createPixmap();
        scene->clear();
        scene->addPixmap(map);
        scene->addPixmap(det->createPixmap());
    }
    catch(errorBase& error)
    {
        QMessageBox box;
        box.setText(error.what());
        box.show();
        box.exec();
    }
}

void MainWindow::on_pushButton_clicked()
{
    emit _ball->sstart(20);
}
