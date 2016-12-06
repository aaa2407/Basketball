#ifndef CAMERA_H
#define CAMERA_H

#include "base_camera.h"
#include "point\point.h"
#include "transform_matrix\transform_matrix.h"
#include "geom_operations\operations.h"
#include "math.h"

class camera : public camera_base
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
    double distanceCentre() const;
    transform_base get() const;
    transform_base getVector() const;

    const point& centre() const;
    const point& position() const;
    point vector() const;

    double x() const;
    double y() const;
    double z() const;

    double xc() const;
    double yc() const;
    double zc() const;

    int distance(double x, double y, double z) const;
    int distance(const point& copy) const;

private:
    point _centre;
    point _position;
};



#endif // CAMERA_H
