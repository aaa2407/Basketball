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

void ball::draw(Z_buffer *buf, const camera_base *cam) const{
    _ball.draw(buf, cam);
}



double ball::radius() const{
    return _radius;
}

