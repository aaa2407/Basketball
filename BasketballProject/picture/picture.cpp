#include "picture.h"

picture::picture(const QString& file)
{
    _path = QString("D:/Projects/Basketball/BasketballProject/images/");
    picture::set(file);
}

void picture::set(const QString& file)
{
    if (QFile(QString(_path + file)).exists())
    {
        QImage img(QString(_path + file));
        _map.setSize(img.height());
        for (size_t i = 0; i < _map.size(); i++)
        {
            _map[i].setSize(img.width());
        }
        for (int i = 0; i < img.height(); i++)
            for (int j = 0; j < img.width(); j++)
            {
                QRgb color = img.pixel(j, i);
                rgb col;
                col.red = qRed(color);
                col.green = qGreen(color);
                col.blue = qBlue(color);
                _map[i][j] = col;
            }
    }
}

void picture::clear()
{
    _map.setSize(0);
}

size_t picture::width() const
{
    return _map[0].size();
}

size_t picture::height() const
{
    return _map.size();
}

rgb picture::getPixel(size_t x, size_t y) const
{
    return _map[y][x];
}
