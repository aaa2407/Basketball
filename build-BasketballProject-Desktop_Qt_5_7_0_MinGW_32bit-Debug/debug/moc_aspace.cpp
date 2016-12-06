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
    QByteArrayData data[10];
    char stringdata0[93];
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
QT_MOC_LITERAL(3, 17, 8), // "send_msg"
QT_MOC_LITERAL(4, 26, 11), // "const char*"
QT_MOC_LITERAL(5, 38, 5), // "smove"
QT_MOC_LITERAL(6, 44, 5), // "move2"
QT_MOC_LITERAL(7, 50, 9), // "collision"
QT_MOC_LITERAL(8, 60, 14), // "calc_time_coll"
QT_MOC_LITERAL(9, 75, 17) // "calc_time_message"

    },
    "aspace\0send_col\0\0send_msg\0const char*\0"
    "smove\0move2\0collision\0calc_time_coll\0"
    "calc_time_message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aspace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
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
        case 1: _t->send_msg((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: _t->smove(); break;
        case 3: _t->move2(); break;
        case 4: _t->collision(); break;
        case 5: _t->calc_time_coll(); break;
        case 6: _t->calc_time_message(); break;
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
            typedef void (aspace::*_t)(const char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&aspace::send_msg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (aspace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&aspace::smove)) {
                *result = 2;
                return;
            }
        }
    }
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void aspace::send_col()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void aspace::send_msg(const char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void aspace::smove()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
