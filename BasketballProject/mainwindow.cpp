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
    ui->actionHelp->setIcon(QIcon(path+"help.png"));
    ui->actionStart->setIcon(QIcon(path+"start.png"));
    ui->actionStop->setIcon(QIcon(path+"stop.png"));
    ui->actionReset->setIcon(QIcon(path+"reset.png"));
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
        torus* tor = new torus("Ring", 30, 3, 24, 4, point(-70, 0, 73), QColor(Qt::red));
        basket->add(tor);
        basket->transform(TransformMatrix::move(425, 0, 0));

        comp.setName("Basketball");
        comp.add(par);
        comp.add(basket);
        comp.draw(buf, &cam);

        _sphere = new sphere("Ball", 12, 8, 16);
        _sphere->setColor(QColor(255, 128, 0));
        _sphere->draw(det, &cam);
        _ball = new ball(_sphere);
        _ball->addPolygons(comp);
        _ball->addPolygonSignal(tor->createCirclePolygon(), "Goal");

        map = buf->createPixmap();
        scene->addPixmap(map);
        scene->addPixmap(det->createPixmap());
        connect(_ball, SIGNAL(smove()), this, SLOT(basket_draw()));
        connect(_ball, SIGNAL(send_msg(const char*)), this, SLOT(message(const char*)));
        setStatusLabel();
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
        ui->statusBar->showMessage("GOAL");
    }
}

void MainWindow::redraw(){
    try
    {
        scene->setSceneRect(0, 0, ui->gv->width()-3, ui->gv->height()-3);
        buf->clear();
        det->clear();
        comp.draw(buf, &cam);
        switch (_ball->state()){
            case WAIT: draw_pos(); break;
            case POS: draw_sec_pos(); break;
            case POS_SEC: draw_traject(); break;
            default: _ball->draw(det, &cam); break;
        }
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

void MainWindow::on_actionRotate_triggered(){
    cam.rotate(M_PI_2/12);
    this->redraw();
}

void MainWindow::on_actionRotate2_triggered(){
    cam.rotate(-M_PI_2/12);
    this->redraw();
}

void MainWindow::on_actionIncline_up_triggered(){
    cam.upIncline(M_PI_2/12);
    this->redraw();
}

void MainWindow::on_actionIncline_down_triggered(){
    cam.downIncline(M_PI_2/12);
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

void MainWindow::keyPressEvent(QKeyEvent* event){
    if (_ball->state() == WAIT || _ball->state() == POS)
    {
        switch(event->key()){
            case Qt::Key_1: pos.incX(5); break;
            case Qt::Key_2: pos.decX(5); break;
            case Qt::Key_4: pos.incY(5); break;
            case Qt::Key_5: pos.decY(5); break;
            case Qt::Key_7: pos.incZ(5); break;
            case Qt::Key_8: pos.decZ(5); break;
            case 16777220:  setup_position(); break;
            case 16777221:  setup_position(); break;
            default: break;
        }
        if (_ball->state() == WAIT)
            draw_pos();
        if (_ball->state() == POS)
            draw_sec_pos();
    }
    else if (_ball->state() == POS_SEC){
        switch(event->key()){
            case Qt::Key_9:
                pos.incZ(5);
            break;
            case Qt::Key_6:
                if (min + 4 < pos.z())
                    pos.decZ(5);
            break;
            case 16777220:  setup_position(); break;
            case 16777221:  setup_position(); break;
            default: break;
        }
        draw_traject();
    }
    else {
        switch(event->key()){
            case 16777220:  setup_position(); break;
            case 16777221:  setup_position(); break;
            default: break;
        }
    }
}

void MainWindow::setup_position() {
    double z1;
    double z2;
    switch(_ball->state()){
        case WAIT:
            emit _ball->spos(pos);
            _sphere_2 = new sphere("Second", _ball->radius(), 5, 10, pos);
            _sphere_2->drawing = FRAME;

        break;
        case POS:
            emit _ball->ssecond_point(pos);
            z1 = _ball->position().z();
            z2 = pos.z();
            if (z1 < z2)
                z1 = z2;
            z1 += 5;
            min = z1;
            pos2 = pos;
            pos.set_z(z1);
            delete _sphere_2;
            draw_traject();
        break;
        case POS_SEC:
            emit _ball->smax_z(pos.z());
        break;
        case MAX_Z:
            emit _ball->sstart(20);
        break;
        case SPEED:
            emit _ball->sstart(20);
        break;
        case MOVE:
            emit _ball->sstop();
        break;
        case STOP:
            emit _ball->sback();
        break;
        default: break;
    }
    setStatusLabel();
}

void MainWindow::draw_pos(){
    point p = pos - _sphere->centre();
    det->clear();
    _sphere->transform(TransformMatrix::move(p.x(), p.y(), p.z()));
    _sphere->draw(det, &cam);
    scene->clear();
    scene->addPixmap(map);
    scene->addPixmap(det->createPixmap());
}

void MainWindow::draw_sec_pos(){
    det->clear();
    _sphere->draw(det, &cam);
    point p = pos - _sphere_2->centre();
    _sphere_2->transform(TransformMatrix::move(p.x(), p.y(), p.z()));
    _sphere_2->draw(det, &cam);
    scene->clear();
    scene->addPixmap(map);
    scene->addPixmap(det->createPixmap());
}

void MainWindow::draw_traject(){
    try{
        det->clear();
        _sphere->draw(det, &cam);
        point p1 = _sphere->centre();
        point p2 = pos2;
        double max = pos.z();
        traject traj = set_traject(p1, p2, max);
        marray<point> arr;
        for (size_t t = 0; t < 1000; t += 20){
            arr.add(point_at_time(traj, t));
        }
        std::cout << arr.size() << std::endl;
        for (size_t i = 0; i < arr.size() - 1; i++){
            line _line(arr[i], arr[i+1]);
            std::cout << i << "\t" << _line.point_1() << "\t" << _line.point_2() << std::endl;
            _line.draw(det, &cam);
        }
        std::cout << "!!!" << std::endl;
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

void MainWindow::setStatusLabel(){
    QString str = "";
    switch(_ball->state()){
        case WAIT: ui->statusBar->showMessage(str + "Установите начальное положение мяча"); break;
        case POS: ui->statusBar->showMessage(str + "Установите точку, через которую пролетит мяч"); break;
        case POS_SEC: ui->statusBar->showMessage(str + "Установите максимальную высоту полета мяча"); break;
        case SPEED: ui->statusBar->showMessage(str + "Нажмите \"Enter\""); break;
        case MAX_Z: ui->statusBar->showMessage(str + "Нажмите \"Enter\""); break;
        case MOVE: ui->statusBar->showMessage(str + "MOVE"); break;
        case STOP: ui->statusBar->showMessage(str + "STOP"); break;
        default: ui->statusBar->showMessage(""); break;
    }
}

void MainWindow::on_actionStart_triggered()
{
    if (_ball->state() == MAX_Z || _ball->state() == SPEED) {
        emit _ball->sstart(20);
    }
    if (_ball->state() == STOP) {
        emit _ball->sback();
    }
    setStatusLabel();
}

void MainWindow::on_actionStop_triggered()
{
    emit _ball->sstop();
}

void MainWindow::on_actionReset_triggered()
{
    emit _ball->sreset();
    redraw();
    setStatusLabel();
    pos = point(0, 0, 0);
}

void MainWindow::on_actionHelp_triggered()
{

}
