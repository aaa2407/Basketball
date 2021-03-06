#include "picture.h"

picture::picture(const QString& file)
{
    _path = QString("D:/Projects/Basketball/BasketballProject/images/");
    picture::set(file);
    _name = file;
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
    rgb c1 = _map[y][x];
    rgb c2 = _map[y+1][x];
    rgb c3 = _map[y][x+1];
    rgb c4 = _map[y+1][x+1];
    c1.blue = ((int)c1.blue +(int)c2.blue)/2;
    c1.red = ((int)c1.red  +(int)c2.red)/2;
    c1.green = ((int)c1.green +(int)c2.green)/2;
    c3.blue = ((int)c3.blue +(int)c4.blue)/2;
    c3.red = ((int)c3.red  +(int)c4.red)/2;
    c3.green = ((int)c3.green +(int)c4.green)/2;
    c1.blue = ((int)c1.blue +(int)c3.blue)/2;
    c1.red = ((int)c1.red  +(int)c3.red)/2;
    c1.green = ((int)c1.green +(int)c3.green)/2;
    return c1;
}

QString picture::name() const{
    return _name;
}
