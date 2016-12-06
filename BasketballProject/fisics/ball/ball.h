#ifndef BALL_H
#define BALL_H

#include "fisics/aspace.h"
#include "objects/sphere/sphere.h"
#include "transform_matrix/transform_matrix.h"
#include "objects/composite/composite.h"
#include "fisics/ball/error_ball.h"

class ball : public aspace, public drawing_object
{
    Q_OBJECT
public:
    ball(sphere* _sphere);
    
    void draw(Z_buffer_base *, const camera_base *) const;

    void addPolygons(const composite& copy);

    double radius() const;

private slots:
    void move_ball();
    void move_ball_2(point);

protected:
    sphere* _ball;
};

#endif // BALL_H
