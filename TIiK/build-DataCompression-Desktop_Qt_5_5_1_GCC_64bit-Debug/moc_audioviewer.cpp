/****************************************************************************
** Meta object code from reading C++ file 'audioviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataCompression/audioviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audioviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AudioViewer_t {
    QByteArrayData data[7];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioViewer_t qt_meta_stringdata_AudioViewer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AudioViewer"
QT_MOC_LITERAL(1, 12, 26), // "on_pushButton_Exit_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 32), // "on_pushButton_StartPause_clicked"
QT_MOC_LITERAL(4, 73, 26), // "on_pushButton_Stop_clicked"
QT_MOC_LITERAL(5, 100, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(6, 133, 5) // "value"

    },
    "AudioViewer\0on_pushButton_Exit_clicked\0"
    "\0on_pushButton_StartPause_clicked\0"
    "on_pushButton_Stop_clicked\0"
    "on_horizontalSlider_valueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void AudioViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioViewer *_t = static_cast<AudioViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_Exit_clicked(); break;
        case 1: _t->on_pushButton_StartPause_clicked(); break;
        case 2: _t->on_pushButton_Stop_clicked(); break;
        case 3: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AudioViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AudioViewer.data,
      qt_meta_data_AudioViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AudioViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AudioViewer.stringdata0))
        return static_cast<void*>(const_cast< AudioViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int AudioViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
