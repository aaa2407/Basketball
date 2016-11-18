#include "apoint.h"

apoint::apoint() : _state(WAIT), _max_count(300), _min_z(-500)
{
    connect(this, SIGNAL(spos(point)), this, SLOT(pos(point)));
    connect(this, SIGNAL(sfi(double)), this, SLOT(set_fi(double)));
    connect(this, SIGNAL(stau(double)), this, SLOT(set_tau(double)));
    connect(this, SIGNAL(ssecond_point(point)), this, SLOT(set_second_point(point)));
    connect(this, SIGNAL(smax_z(double)), this, SLOT(set_max_z(double)));
    connect(this, SIGNAL(sspeed(double)), this, SLOT(set_speed(double)));
    connect(this, SIGNAL(sstart(uint)), this, SLOT(start(uint)));
    connect(this, SIGNAL(sstop()), this, SLOT(stop()));
    connect(this, SIGNAL(sreset()), this, SLOT(reset()));
    connect(this, SIGNAL(sback()), this, SLOT(back()));
    connect(this, SIGNAL(snadir()), this, SLOT(stop()));
    connect(&(this->_timer), SIGNAL(timeout()), this, SLOT(output()));
    connect(&(this->_timer), SIGNAL(timeout()), this, SLOT(move()));
}

const point& apoint::position() const
{
    return _traj.pos;
}

const point& apoint::napr() const
{
    return _traj.napr;
}

estate apoint::state() const
{
    return _state;
}


void apoint::pos(point p)
{
    if (_state == WAIT)
    {
        if (p.z() > -500)
        {
            _state = POS;
            _traj.pos = p;
        }
    }
}

void apoint::set_fi(double fi)
{
    if (_state == POS)
    {
        _state = FI;
        _fi = fi;
    }
}

void apoint::set_tau(double tau)
{
    if (_state == FI)
    {
        _state = TAU;
        _tau = tau;
    }
}

void apoint::set_speed(double sp)
{
    if (_state == TAU)
    {
        _state = SPEED;
        _speed = sp;
    }
}

void apoint::set_second_point(point p)
{
    if (_state == POS)
    {
        _state = POS_SEC;
        _second = p;
    }
}

void apoint::set_max_z(double max_z)
{
    if (_state == POS_SEC)
    {
        _state = MAX_Z;
        _max_z = max_z;
    }
}


void apoint::start(uint msec)
{
    if (_state == SPEED || _state == MAX_Z)
    {
        if (_state == SPEED)
        {
            _traj.napr = operations::nspeed(_fi, _tau, _speed);
        }
        else
        {
            _traj = set_traject(_traj.pos, _second, _max_z);
        }
        _state = MOVE;
        _msec = msec;
        _dtime = (double)_msec/1000;
        emit this->new_colision();
        _traj.napr.set_z(_traj.napr.z() - _G_*_dtime/2);
        _timer.start(_msec);
    }
}

void apoint::move()
{
    if (_state == MOVE)
    {
        _traj.pos.set_x(_traj.pos.x() + _traj.napr.x()*_dtime*_M_);
        _traj.pos.set_y(_traj.pos.y() + _traj.napr.y()*_dtime*_M_);
        _traj.pos.set_z(_traj.pos.z() + _traj.napr.z()*_dtime*_M_);
        _traj.napr.set_z(_traj.napr.z() - _G_*_dtime);
        _timer.start((int)_msec);

        if (_traj.pos.z() < _min_z)
        {
            emit this->sstop();
        }
        static uint i = 0;
        if (i >= _max_count)
        {
            emit this->sstop();
        }
        i++;

    }
}

void apoint::stop()
{
    if (_state == MOVE)
    {
        _timer.stop();
        _state = STOP;
    }
}

void apoint::reset()
{
    if (_state == STOP)
    {
        _state = WAIT;
        _fi = 0;
        _tau = 0;
        _speed = 0;
        _msec = 0;
    }
}

void apoint::back()
{
    if (_state == STOP)
    {
        _state = MOVE;
        _timer.start(_msec);
    }
}

void apoint::output()
{
    if (_state == MOVE)
    {
        static double t = 0;
        std::cout << t << "\t" << _traj.pos << "\t" << _traj.napr << std::endl;
        t += _dtime;
    }
}

