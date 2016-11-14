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

    void addPolygon(const apolygon& copy);
    void clearPolygons();

signals:
    void send_col();
    void smove();

private slots:
    void move2();

public slots:
    void collision();
    void calc_time_coll();

private:
    bool ok;
    double _time;
    size_t _count;
    size_t _num_nearest;
    marray<apolygon> _pol;
};

#endif // ASPACE_H
