#ifndef BALL_H
#define BALL_H

#include "fisics/aspace.h"
#include "objects/sphere/sphere.h"
#include "transform_matrix/transform_matrix.h"

class ball : public aspace, public drawing_object
{
    Q_OBJECT
public:
    ball(const char* name = NULL, double radius = 15);
    
    void draw(Z_buffer_base *, const camera_base *) const;

    double radius() const;
    
private slots:
    void move_ball();
    void move_ball_2(point);

protected:
    double _radius;
    sphere _ball;    
};

#endif // BALL_H
