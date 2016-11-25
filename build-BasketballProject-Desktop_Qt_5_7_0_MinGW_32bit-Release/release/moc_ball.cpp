/****************************************************************************
** Meta object code from reading C++ file 'ball.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BasketballProject/fisics/ball/ball.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ball.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ball_t {
    QByteArrayData data[5];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ball_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ball_t qt_meta_stringdata_ball = {
    {
QT_MOC_LITERAL(0, 0, 4), // "ball"
QT_MOC_LITERAL(1, 5, 9), // "move_ball"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "move_ball_2"
QT_MOC_LITERAL(4, 28, 5) // "point"

    },
    "ball\0move_ball\0\0move_ball_2\0point"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ball[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void ball::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ball *_t = static_cast<ball *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->move_ball(); break;
        case 1: _t->move_ball_2((*reinterpret_cast< point(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ball::staticMetaObject = {
    { &aspace::staticMetaObject, qt_meta_stringdata_ball.data,
      qt_meta_data_ball,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ball::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ball::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ball.stringdata0))
        return static_cast<void*>(const_cast< ball*>(this));
    if (!strcmp(_clname, "drawing_object"))
        return static_cast< drawing_object*>(const_cast< ball*>(this));
    return aspace::qt_metacast(_clname);
}

int ball::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = aspace::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
