/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "buttonCallback",
    "",
    "buttonId",
    "clearMatrix",
    "updateMatrix",
    "brightnessChanged",
    "value",
    "connectButtonClicked",
    "animateRandom",
    "animation1",
    "animation2",
    "animation3",
    "animation4",
    "startAnimation",
    "shiftLeftEnabled",
    "shiftRightEnabled",
    "interval",
    "shiftLeft",
    "shiftRight",
    "setMatrix"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x08,    1 /* Private */,
       4,    0,  101,    2, 0x08,    3 /* Private */,
       5,    0,  102,    2, 0x08,    4 /* Private */,
       6,    1,  103,    2, 0x08,    5 /* Private */,
       8,    0,  106,    2, 0x08,    7 /* Private */,
       9,    0,  107,    2, 0x08,    8 /* Private */,
      10,    0,  108,    2, 0x08,    9 /* Private */,
      11,    0,  109,    2, 0x08,   10 /* Private */,
      12,    0,  110,    2, 0x08,   11 /* Private */,
      13,    0,  111,    2, 0x08,   12 /* Private */,
      14,    3,  112,    2, 0x08,   13 /* Private */,
      18,    0,  119,    2, 0x08,   17 /* Private */,
      19,    0,  120,    2, 0x08,   18 /* Private */,
      20,    1,  121,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Int,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'buttonCallback'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clearMatrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateMatrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'brightnessChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'connectButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animateRandom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animation1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animation2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animation3'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animation4'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'shiftLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shiftRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setMatrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->buttonCallback((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->clearMatrix(); break;
        case 2: _t->updateMatrix(); break;
        case 3: _t->brightnessChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->connectButtonClicked(); break;
        case 5: _t->animateRandom(); break;
        case 6: _t->animation1(); break;
        case 7: _t->animation2(); break;
        case 8: _t->animation3(); break;
        case 9: _t->animation4(); break;
        case 10: _t->startAnimation((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 11: _t->shiftLeft(); break;
        case 12: _t->shiftRight(); break;
        case 13: _t->setMatrix((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
