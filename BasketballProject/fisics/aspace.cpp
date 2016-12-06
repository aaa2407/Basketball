#include "aspace.h"


aspace::aspace()
{
    _count = 0;
    connect(&(this->_timer), SIGNAL(timeout()), this, SLOT(move2()));
    connect(this, SIGNAL(new_colision()), this, SLOT(calc_time_coll()));
    connect(this, SIGNAL(new_colision()), this, SLOT(calc_time_message()));
    connect(this, SIGNAL(send_col()), this, SLOT(collision()));
    ok = true;
}


const polygon &aspace::getPolygon(size_t index) const
{
    return _pol[index]._pol;
}

size_t aspace::getCountPolygon() const {
    return _pol.size();
}

void aspace::addPolygon(const apolygon &copy){
    if (this->state() == WAIT) {
        _pol.add(copy);
    }
}

void aspace::addPolygonSignal(const polygon &copy, const char *msg){
    if (this->state() == WAIT) {
        mpolygon pol;
        pol._pol = copy;
        pol._message = (char*) msg;
        _mpol.add(pol);
    }
}

void aspace::clearAllPolygons()
{
    if (this->state() == WAIT)
    {
        _pol.clear();
        _mpol.clear();
    }
}

size_t aspace::collision_next() const{
    return _num_nearest;
}

void aspace::move2()
{
    if (this->state() == MOVE)
    {
        _time -= _dtime;
        if (_time <= 0 && ok) {
            emit send_col();
        }
        for (size_t i = 0; i < _mpol.size(); i++)
            if (_mpol[i]._time > 0){
                _mpol[i]._time -= _dtime;
                if (_mpol[i]._time <= 0) {
                    emit send_msg(_mpol[i]._message);
                    _mpol[i]._time = -300;
                }
            }
        emit this->smove();
    }
}

void aspace::collision()
{
    if (this->state() == MOVE)
    {
        point p1 = operations::reflation_napr(_traj.napr, _pol[_num_nearest]._pol.normal())*_pol[_num_nearest]._koef;
        point p2 = _pol[_num_nearest]._pol.get_plane().reflaction(_traj.pos);
        _traj.napr = p1;
        _traj.pos = p2;
        emit this->new_colision();
        if (ok)
            _time += _dtime;
    }
}

void aspace::calc_time_coll()
{
    if (this->state() == MOVE)
    {
        _time = -1;
        for (size_t i = 0; i < _pol.size(); i++)
        {
            double time = time_to(_pol[i]._pol, _traj);
            if (time >= 0)
            {
                if (time < _time || _time < 0)
                {
                    _num_nearest = i;
                    _time = time;
                }
            }
        }
        if (_time == -1)
            ok = false;
        else
            ok = true;
    }
}

void aspace::calc_time_message(){
    if (this->state() == MOVE)
    {
        for (size_t i = 0; i < _mpol.size(); i++)
        {
            _mpol[i]._time = -300;
            double time = time_to(_mpol[i]._pol, _traj);
            if (time >= 0)
                _mpol[i]._time = time;
        }
    }
}
