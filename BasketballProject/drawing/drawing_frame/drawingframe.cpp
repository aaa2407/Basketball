#include "drawingframe.h"

drawingFrame::drawingFrame(size_t width, size_t height, size_t max_depth, QColor back)
    : drawing3Dbase(width, height, max_depth, back)
{ }

void drawingFrame::draw(const polygon& pol)
{
    if (pol.size() == 0)
        return;
    if (pol.size() == 1)
    {
        drawing3Dbase::draw(pol[0]);
        return;
    }
    if (pol.size() == 2)
    {
        drawing3Dbase::draw(pol[0], pol[1]);
        return;
    }
    for (size_t i = 1; i < pol.size(); i++)
        for (size_t j = 0; j < i; j++)
            drawing3Dbase::draw(pol[j], pol[i]);
}

void drawingFrame::draw(const object_base& obj)
{
    drawing3Dbase::draw(obj);
}

