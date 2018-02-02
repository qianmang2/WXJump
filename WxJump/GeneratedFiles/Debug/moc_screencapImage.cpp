/****************************************************************************
** Meta object code from reading C++ file 'screencapImage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screencapImage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screencapImage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScreencapImage_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScreencapImage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScreencapImage_t qt_meta_stringdata_ScreencapImage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ScreencapImage"
QT_MOC_LITERAL(1, 15, 15), // "screencapfinish"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "picInitFinish"
QT_MOC_LITERAL(4, 46, 4), // "Mat&"
QT_MOC_LITERAL(5, 51, 5) // "image"

    },
    "ScreencapImage\0screencapfinish\0\0"
    "picInitFinish\0Mat&\0image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScreencapImage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    1,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void ScreencapImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScreencapImage *_t = static_cast<ScreencapImage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->screencapfinish(); break;
        case 1: _t->picInitFinish((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ScreencapImage::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScreencapImage::screencapfinish)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ScreencapImage::*_t)(Mat & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScreencapImage::picInitFinish)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ScreencapImage::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ScreencapImage.data,
      qt_meta_data_ScreencapImage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScreencapImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreencapImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScreencapImage.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ScreencapImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ScreencapImage::screencapfinish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ScreencapImage::picInitFinish(Mat & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
