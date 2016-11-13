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
        drawing3Dbase::draw(pol[0], _pen);
        return;
    }
    if (pol.size() == 2)
    {
        drawing3Dbase::draw(pol[0], pol[1], _pen);
        return;
    }
    for (size_t i = 1; i < pol.size(); i++)
        for (size_t j = 0; j < i; j++)
            drawing3Dbase::draw(pol[j], pol[i], _pen);
}

void drawingFrame::setPenColor(QColor pen)
{
    _pen = pen;
}
