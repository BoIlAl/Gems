/****************************************************************************
** Meta object code from reading C++ file 'GemBonus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GemBonus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GemBonus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AbstractGemBonus_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractGemBonus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractGemBonus_t qt_meta_stringdata_AbstractGemBonus = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AbstractGemBonus"
QT_MOC_LITERAL(1, 17, 8), // "activate"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10) // "SimpleGem*"

    },
    "AbstractGemBonus\0activate\0\0SimpleGem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractGemBonus[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void AbstractGemBonus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AbstractGemBonus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activate((*reinterpret_cast< SimpleGem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SimpleGem* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AbstractGemBonus::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AbstractGemBonus.data,
    qt_meta_data_AbstractGemBonus,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AbstractGemBonus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractGemBonus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractGemBonus.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AbstractGemBonus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_GemBonusRepaint_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GemBonusRepaint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GemBonusRepaint_t qt_meta_stringdata_GemBonusRepaint = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GemBonusRepaint"
QT_MOC_LITERAL(1, 16, 8), // "activate"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10) // "SimpleGem*"

    },
    "GemBonusRepaint\0activate\0\0SimpleGem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GemBonusRepaint[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void GemBonusRepaint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GemBonusRepaint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activate((*reinterpret_cast< SimpleGem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SimpleGem* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GemBonusRepaint::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractGemBonus::staticMetaObject>(),
    qt_meta_stringdata_GemBonusRepaint.data,
    qt_meta_data_GemBonusRepaint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GemBonusRepaint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GemBonusRepaint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GemBonusRepaint.stringdata0))
        return static_cast<void*>(this);
    return AbstractGemBonus::qt_metacast(_clname);
}

int GemBonusRepaint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractGemBonus::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_GemBonusBomb_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GemBonusBomb_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GemBonusBomb_t qt_meta_stringdata_GemBonusBomb = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GemBonusBomb"
QT_MOC_LITERAL(1, 13, 8), // "activate"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10) // "SimpleGem*"

    },
    "GemBonusBomb\0activate\0\0SimpleGem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GemBonusBomb[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void GemBonusBomb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GemBonusBomb *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activate((*reinterpret_cast< SimpleGem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SimpleGem* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GemBonusBomb::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractGemBonus::staticMetaObject>(),
    qt_meta_stringdata_GemBonusBomb.data,
    qt_meta_data_GemBonusBomb,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GemBonusBomb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GemBonusBomb::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GemBonusBomb.stringdata0))
        return static_cast<void*>(this);
    return AbstractGemBonus::qt_metacast(_clname);
}

int GemBonusBomb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractGemBonus::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
