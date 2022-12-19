/****************************************************************************
** Meta object code from reading C++ file 'bookclassifymanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LibraryManager/bookclassifymanager.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookclassifymanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_BookClassifyManager_t {
    uint offsetsAndSizes[18];
    char stringdata0[20];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[28];
    char stringdata4[28];
    char stringdata5[28];
    char stringdata6[25];
    char stringdata7[28];
    char stringdata8[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_BookClassifyManager_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_BookClassifyManager_t qt_meta_stringdata_BookClassifyManager = {
    {
        QT_MOC_LITERAL(0, 19),  // "BookClassifyManager"
        QT_MOC_LITERAL(20, 24),  // "on_AddpushButton_clicked"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 27),  // "on_SearchpushButton_clicked"
        QT_MOC_LITERAL(74, 27),  // "on_ModifypushButton_clicked"
        QT_MOC_LITERAL(102, 27),  // "on_CanclepushButton_clicked"
        QT_MOC_LITERAL(130, 24),  // "on_AllpushButton_clicked"
        QT_MOC_LITERAL(155, 27),  // "on_DeletepushButton_clicked"
        QT_MOC_LITERAL(183, 25)   // "on_SurepushButton_clicked"
    },
    "BookClassifyManager",
    "on_AddpushButton_clicked",
    "",
    "on_SearchpushButton_clicked",
    "on_ModifypushButton_clicked",
    "on_CanclepushButton_clicked",
    "on_AllpushButton_clicked",
    "on_DeletepushButton_clicked",
    "on_SurepushButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_BookClassifyManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BookClassifyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BookClassifyManager.offsetsAndSizes,
    qt_meta_data_BookClassifyManager,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_BookClassifyManager_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BookClassifyManager, std::true_type>,
        // method 'on_AddpushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SearchpushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ModifypushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CanclepushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_AllpushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DeletepushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SurepushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BookClassifyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BookClassifyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_AddpushButton_clicked(); break;
        case 1: _t->on_SearchpushButton_clicked(); break;
        case 2: _t->on_ModifypushButton_clicked(); break;
        case 3: _t->on_CanclepushButton_clicked(); break;
        case 4: _t->on_AllpushButton_clicked(); break;
        case 5: _t->on_DeletepushButton_clicked(); break;
        case 6: _t->on_SurepushButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *BookClassifyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BookClassifyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BookClassifyManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BookClassifyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
