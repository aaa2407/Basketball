#ifndef ASPACE_H
#define ASPACE_H

#include "apoint.h"
#include "apolygon.h"

class aspace : public apoint
{
    Q_OBJECT
public:
    aspace();

    const polygon& getPolygon(size_t index) const;
    size_t getCountPolygon() const;

    void addPolygon(const apolygon &copy);
    void addPolygonSignal(const polygon& copy, const char* msg);
    void clearAllPolygons();

    size_t collision_next() const;

signals:
    void send_col();
    void send_msg(const char*);
    void smove();

private slots:
    void move2();

public slots:
    void collision();
    void calc_time_coll();
    void calc_time_message();

private:
    bool ok;
    double _time;
    size_t _count;
    size_t _num_nearest;
    marray<apolygon> _pol;
    marray<mpolygon> _mpol;
};

#endif // ASPACE_H
