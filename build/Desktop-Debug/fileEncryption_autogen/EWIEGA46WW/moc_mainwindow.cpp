/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "on_listWidget_currentTextChanged",
    "",
    "currentText",
    "customMenuRequested",
    "pos",
    "itemDoubleclicked",
    "QModelIndex",
    "index",
    "copyPassword",
    "copyUsername",
    "deleteTable",
    "deleteRow",
    "copyUrl",
    "openUrl",
    "editRow",
    "cfgColumns",
    "createTable",
    "addEntry",
    "createDatabase",
    "openDatabase"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    1 /* Private */,
       4,    1,  107,    2, 0x0a,    3 /* Public */,
       6,    1,  110,    2, 0x0a,    5 /* Public */,
       9,    0,  113,    2, 0x0a,    7 /* Public */,
      10,    0,  114,    2, 0x0a,    8 /* Public */,
      11,    0,  115,    2, 0x0a,    9 /* Public */,
      12,    0,  116,    2, 0x0a,   10 /* Public */,
      13,    0,  117,    2, 0x0a,   11 /* Public */,
      14,    0,  118,    2, 0x0a,   12 /* Public */,
      15,    0,  119,    2, 0x0a,   13 /* Public */,
      16,    0,  120,    2, 0x0a,   14 /* Public */,
      17,    0,  121,    2, 0x0a,   15 /* Public */,
      18,    0,  122,    2, 0x0a,   16 /* Public */,
      19,    0,  123,    2, 0x0a,   17 /* Public */,
      20,    0,  124,    2, 0x0a,   18 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_listWidget_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'customMenuRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'itemDoubleclicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'copyPassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'copyUsername'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'copyUrl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openUrl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cfgColumns'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_listWidget_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->customMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->itemDoubleclicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->copyPassword(); break;
        case 4: _t->copyUsername(); break;
        case 5: _t->deleteTable(); break;
        case 6: _t->deleteRow(); break;
        case 7: _t->copyUrl(); break;
        case 8: _t->openUrl(); break;
        case 9: _t->editRow(); break;
        case 10: _t->cfgColumns(); break;
        case 11: _t->createTable(); break;
        case 12: _t->addEntry(); break;
        case 13: _t->createDatabase(); break;
        case 14: _t->openDatabase(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
