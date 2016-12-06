#ifndef LINE_H
#define LINE_H

#include "point/point.h"
#include "drawing/drawing_object.h"
#include "drawing/z-buffer_base/z_buffer_base.h"

typedef enum {SECOND_POINT, NAPR} einput_line;

class line : public drawing_object
{
public:
    line(const point& p1 = point(0,0,0), const point& p2 = point(0,0,1),
         einput_line state = SECOND_POINT);

    void set(const point& p1 = point(0,0,0), const point& p2 = point(0,0,1),
             einput_line state = SECOND_POINT);

    void set_point_1(const point& p);
    void set_point_2(const point& p);

    double length() const;

    const point& point_1() const;
    const point& point_2() const;
    point vector() const;

    void draw(Z_buffer_base *, const camera_base *) const;

protected:
    point _p1, _p2;
};

#endif // LINE_H
