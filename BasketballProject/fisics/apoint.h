#ifndef APOINT_H
#define APOINT_H

#include <QTimer>
#include <QObject>
#include <math.h>

#include "point/point.h"
#include "geom_operations/operations.h"
#include "traject.h"

typedef enum{WAIT = 0, POS, POS_SEC, MAX_Z, FI, TAU, SPEED, MOVE= 10, STOP} estate;

class apoint: public QObject
{
    Q_OBJECT 
public:
    apoint();
    
    const point& position() const;
    const point& napr() const;
    estate state() const;

private slots:
    void pos(point p);
    void set_fi(double fi);
    void set_tau(double tau);
    void set_speed(double sp);
    void set_second_point(point p);
    void set_max_z(double max_z);
    void start(uint msec);
    void move();
    void stop();
    void reset();
    void back();
    void output();

signals:
    void spos(point pos);
    void sfi(double fi);
    void stau(double tau);
    void ssecond_point(point p);
    void smax_z(double max_z);
    void sstart(uint msec);
    void sstop();
    void sspeed(double sp);
    void sback();
    void sreset();
    void snadir();
    void new_colision();

private:
    estate _state;

protected:
    double _fi;
    double _tau;
    double _speed;
    point _second;
    double _max_z;

    size_t _msec;
    double _dtime;

    uint _max_count;
    double _min_z;
    QTimer _timer;
    traject _traj;
};

#endif // APOINT_H
