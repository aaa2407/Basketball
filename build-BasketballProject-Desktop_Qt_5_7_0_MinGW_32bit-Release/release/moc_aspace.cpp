/****************************************************************************
** Meta object code from reading C++ file 'aspace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BasketballProject/fisics/aspace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_aspace_t {
    QByteArrayData data[7];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_aspace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_aspace_t qt_meta_stringdata_aspace = {
    {
QT_MOC_LITERAL(0, 0, 6), // "aspace"
QT_MOC_LITERAL(1, 7, 8), // "send_col"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "smove"
QT_MOC_LITERAL(4, 23, 5), // "move2"
QT_MOC_LITERAL(5, 29, 9), // "collision"
QT_MOC_LITERAL(6, 39, 14) // "calc_time_coll"

    },
    "aspace\0send_col\0\0smove\0move2\0collision\0"
    "calc_time_coll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aspace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void aspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        aspace *_t = static_cast<aspace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_col(); break;
        case 1: _t->smove(); break;
        case 2: _t->move2(); break;
        case 3: _t->collision(); break;
        case 4: _t->calc_time_coll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (aspace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&aspace::send_col)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (aspace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&aspace::smove)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject aspace::staticMetaObject = {
    { &apoint::staticMetaObject, qt_meta_stringdata_aspace.data,
      qt_meta_data_aspace,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *aspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *aspace::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_aspace.stringdata0))
        return static_cast<void*>(const_cast< aspace*>(this));
    return apoint::qt_metacast(_clname);
}

int aspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = apoint::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void aspace::send_col()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void aspace::smove()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
