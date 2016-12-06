#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString path("D:/Projects/Basketball/BasketballProject/images/");
    ui->actionRotate->setIcon(QIcon(path+"rotate.png"));
    ui->actionRotate2->setIcon(QIcon(path+"rotate2.png"));
    ui->actionIncline_up->setIcon(QIcon(path+"incline.png"));
    ui->actionIncline_down->setIcon(QIcon(path+"incline2.png"));
    ui->actionScale_plus->setIcon(QIcon(path+"scale.png"));
    ui->actionScale_minus->setIcon(QIcon(path+"scale2.png"));
    try
    {
        scene = new QGraphicsScene(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        ui->gv->setScene(scene);
        buf = new Z_buffer(scene->width(), scene->height());
        buf->set(scene->width(), scene->height());
        det = new Z_buffer_Detachment(buf);
        cam.decrease(600);
        cam.upIncline(M_PI_2/3);
        cam.rotate(M_PI_2);
        _floor.set("BasketFloor.jpg");
        _wall.set("wall.jpg");
        _wall2.set("wall2.jpg");
        _shield.set("shield.jpg");

        composite *basket = new composite("Basket");
        par = new paral("Room", 900, 600, 400, point(0, 0, 0), QColor(Qt::green));
        par->setPolygonPicture(0, &_wall2);
        par->setPolygonPicture(1, &_wall2);
        par->setPolygonPicture(2, &_wall);
        par->setPolygonPicture(3, &_wall);
        par->setPolygonPicture(4, &_floor);
        par->setPolygonPicture(5, &_wall);
        par->setOutwardNormal(false);
        par->drawing = TEXTURE;

        double min = par->minZ();
        double height = 275;
        double length = 28;
        double swidth = 5;
        basket->add(new paral("Post", point(-5, -5, min), point(5, 5, height + min), QColor(Qt::blue)));
        basket->add(new paral("Post2", point(5, 5, height + min), point(5 - length, -5, height + min + 10), QColor(Qt::blue)));
        basket->add(new paral("Shield", swidth, 150, 100, point(5 - length - swidth/2, -5, 100), QColor(Qt::gray)));
        basket->findObject("Shield")->setPolygonPicture(0, &_shield);
        basket->add(new paral("Festerner", point(-30, -3, 70), point(-35, 3, 73)));
        torus* tor = new torus("Ring", 30, 3, 24, 6, point(-70, 0, 73), QColor(Qt::red));
        basket->add(tor);
        basket->transform(TransformMatrix::move(425, 0, 0));

        comp.setName("Basketball");
        comp.add(par);
        comp.add(basket);
        comp.draw(buf, &cam);


        sphere *sph = new sphere("Ball", 12, 8, 16);
        sph->setColor(QColor(255, 128, 0));
        _ball = new ball(sph);
        _ball->addPolygons(comp);
        _ball->addPolygonSignal(tor->createCirclePolygon(), "Goal");
        emit _ball->spos(point(0, 0, 0));
        emit _ball->ssecond_point(point(350, 0, 73));
        emit _ball->smax_z(170);

        map = buf->createPixmap();
        _ball->draw(det, &cam);
        scene->addPixmap(map);
        scene->addPixmap(det->createPixmap());
        connect(_ball, SIGNAL(smove()), this, SLOT(basket_draw()));
        connect(_ball, SIGNAL(send_msg(const char*)), this, SLOT(message(const char*)));
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
    try{
        det->clear();
        _ball->draw(det, &cam);
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

void MainWindow::message(const char *msg){
    if (msg == (const char*)"Goal"){
        ui->label->setText(QString(msg));
    }
}

void MainWindow::redraw(){
    try
    {
        scene->clear();
        scene->setSceneRect(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        buf->clear();
        det->clear();
        comp.draw(buf, &cam);
        _ball->draw(det, &cam);
        map = buf->createPixmap();
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

void MainWindow::on_pushButton_2_clicked()
{
    emit _ball->sstop();
}

void MainWindow::on_pushButton_3_clicked()
{
    emit _ball->sback();
}

void MainWindow::on_actionRotate_triggered(){
    cam.rotate(M_PI_2/6);
    this->redraw();
}

void MainWindow::on_actionRotate2_triggered(){
    cam.rotate(-M_PI_2/6);
    this->redraw();
}

void MainWindow::on_actionIncline_up_triggered(){
    cam.upIncline(M_PI_2/6);
    this->redraw();
}

void MainWindow::on_actionIncline_down_triggered(){
    cam.downIncline(M_PI_2/6);
    this->redraw();
}

void MainWindow::on_actionScale_plus_triggered(){
    cam.decrease(30);
    this->redraw();
}

void MainWindow::on_actionScale_minus_triggered(){
    cam.increase(30);
    this->redraw();
}
