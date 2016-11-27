#include "ball.h"

ball::ball(const char* name, double radius){
    _ball = sphere(name, radius);
    _radius = radius;
    connect(this, SIGNAL(smove()), this, SLOT(move_ball()));
    connect(this, SIGNAL(spos(point)), this, SLOT(move_ball_2(point)));
}

void ball::move_ball(){
    point p = this->position() - _ball.centre();
    _ball.transform(TransformMatrix::move(p.x(), p.y(), p.z()));
}

void ball::move_ball_2(point p2){
    point p = p2 - _ball.centre();
    _ball.transform(TransformMatrix::move(p.x(), p.y(), p.z()));
}

void ball::draw(Z_buffer_base *buf, const camera_base *cam) const{
    _ball.draw(buf, cam);
}

double ball::radius() const{
    return _radius;
}

void  ball::addPolygons(const composite& copy){
    marray<polygon> arr = copy.createParallelObject(this->radius());
    for (size_t i = 0; i < arr.size(); i++){
        apolygon pol;
        pol._pol  = arr[i];
        pol._koef = 0.7;
        this->addPolygon(pol);
    }
}
