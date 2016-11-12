#ifndef CAMERA_H
#define CAMERA_H

#include "base_camera.h"
#include "point\point.h"
#include "transform_matrix\transform_matrix.h"
#include "geom_operations\operations.h"
#include "math.h"

class camera : public BaseCamera
{
public:
    camera();
    bool upIncline(double);
    bool downIncline(double);
    void rotate(double);
    void increase(double);
    void decrease(double);

    void up(double);
    void down(double);
    void left(double);
    void right(double);
    void forward(double);
    void back(double);

    double incline() const;
    double rotate() const;
    double distance() const;

    transform_base get() const;

    const point& centre() const;
    const point& position() const;

private:
    point _centre;
    point _position;
};


#endif // CAMERA_H
