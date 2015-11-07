/****************************************************************************
** Meta object code from reading C++ file 'datacompression.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataCompression/datacompression.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datacompression.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataCompression_t {
    QByteArrayData data[11];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataCompression_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataCompression_t qt_meta_stringdata_DataCompression = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DataCompression"
QT_MOC_LITERAL(1, 16, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "on_pushButton_Add_clicked"
QT_MOC_LITERAL(4, 67, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(5, 90, 26), // "on_pushButton_Exit_clicked"
QT_MOC_LITERAL(6, 117, 23), // "on_actionInfo_triggered"
QT_MOC_LITERAL(7, 141, 26), // "on_pushButton_Info_clicked"
QT_MOC_LITERAL(8, 168, 23), // "on_actionHelp_triggered"
QT_MOC_LITERAL(9, 192, 26), // "on_pushButton_Help_clicked"
QT_MOC_LITERAL(10, 219, 33) // "on_pushButton_Compression_cli..."

    },
    "DataCompression\0on_actionExit_triggered\0"
    "\0on_pushButton_Add_clicked\0"
    "on_actionAdd_triggered\0"
    "on_pushButton_Exit_clicked\0"
    "on_actionInfo_triggered\0"
    "on_pushButton_Info_clicked\0"
    "on_actionHelp_triggered\0"
    "on_pushButton_Help_clicked\0"
    "on_pushButton_Compression_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataCompression[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataCompression::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataCompression *_t = static_cast<DataCompression *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_pushButton_Add_clicked(); break;
        case 2: _t->on_actionAdd_triggered(); break;
        case 3: _t->on_pushButton_Exit_clicked(); break;
        case 4: _t->on_actionInfo_triggered(); break;
        case 5: _t->on_pushButton_Info_clicked(); break;
        case 6: _t->on_actionHelp_triggered(); break;
        case 7: _t->on_pushButton_Help_clicked(); break;
        case 8: _t->on_pushButton_Compression_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DataCompression::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DataCompression.data,
      qt_meta_data_DataCompression,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataCompression::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataCompression::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataCompression.stringdata0))
        return static_cast<void*>(const_cast< DataCompression*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DataCompression::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
