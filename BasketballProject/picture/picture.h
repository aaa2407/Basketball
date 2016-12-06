#ifndef _PICTURE_H
#define _PICTURE_H

#include <QFile>
#include <QImage>
#include <QRgb>
#include "matrix\matrix.h"
#include "rgb\rgb.h"

using namespace color;

class picture : public matrix<rgb>
{
public:
    picture(const QString& file = QString(""));

    void set(const QString& path);
    void clear();

    size_t width() const;
    size_t height() const;
    rgb getPixel(size_t x, size_t y) const;

    QString name() const;

private:
    QString _name;
    QString _path;
    array<array<rgb>> _map;
};

#endif // PICTURE_H
