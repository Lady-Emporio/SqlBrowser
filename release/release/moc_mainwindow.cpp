/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Browser_t {
    QByteArrayData data[12];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Browser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Browser_t qt_meta_stringdata_Browser = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Browser"
QT_MOC_LITERAL(1, 8, 14), // "action_Sql_All"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 21), // "action_Sql_only_table"
QT_MOC_LITERAL(4, 46, 22), // "action_Sql_all_for_all"
QT_MOC_LITERAL(5, 69, 14), // "closeAndUpdate"
QT_MOC_LITERAL(6, 84, 15), // "action_Settings"
QT_MOC_LITERAL(7, 100, 10), // "action_SQL"
QT_MOC_LITERAL(8, 111, 12), // "action_Model"
QT_MOC_LITERAL(9, 124, 19), // "action_size_default"
QT_MOC_LITERAL(10, 144, 20), // "action_sql_text_size"
QT_MOC_LITERAL(11, 165, 23) // "action_return_text_size"

    },
    "Browser\0action_Sql_All\0\0action_Sql_only_table\0"
    "action_Sql_all_for_all\0closeAndUpdate\0"
    "action_Settings\0action_SQL\0action_Model\0"
    "action_size_default\0action_sql_text_size\0"
    "action_return_text_size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Browser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

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
    QMetaType::Void,

       0        // eod
};

void Browser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Browser *_t = static_cast<Browser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->action_Sql_All(); break;
        case 1: _t->action_Sql_only_table(); break;
        case 2: _t->action_Sql_all_for_all(); break;
        case 3: _t->closeAndUpdate(); break;
        case 4: _t->action_Settings(); break;
        case 5: _t->action_SQL(); break;
        case 6: _t->action_Model(); break;
        case 7: _t->action_size_default(); break;
        case 8: _t->action_sql_text_size(); break;
        case 9: _t->action_return_text_size(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Browser::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Browser.data,
      qt_meta_data_Browser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Browser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Browser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Browser.stringdata0))
        return static_cast<void*>(const_cast< Browser*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Browser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
struct qt_meta_stringdata_SqlBrowser_t {
    QByteArrayData data[3];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SqlBrowser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SqlBrowser_t qt_meta_stringdata_SqlBrowser = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SqlBrowser"
QT_MOC_LITERAL(1, 11, 6), // "runSql"
QT_MOC_LITERAL(2, 18, 0) // ""

    },
    "SqlBrowser\0runSql\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqlBrowser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SqlBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SqlBrowser *_t = static_cast<SqlBrowser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runSql(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SqlBrowser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SqlBrowser.data,
      qt_meta_data_SqlBrowser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SqlBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqlBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SqlBrowser.stringdata0))
        return static_cast<void*>(const_cast< SqlBrowser*>(this));
    return QWidget::qt_metacast(_clname);
}

int SqlBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_saveMdiSub_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_saveMdiSub_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_saveMdiSub_t qt_meta_stringdata_saveMdiSub = {
    {
QT_MOC_LITERAL(0, 0, 10) // "saveMdiSub"

    },
    "saveMdiSub"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_saveMdiSub[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void saveMdiSub::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject saveMdiSub::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_saveMdiSub.data,
      qt_meta_data_saveMdiSub,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *saveMdiSub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *saveMdiSub::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_saveMdiSub.stringdata0))
        return static_cast<void*>(const_cast< saveMdiSub*>(this));
    return QMdiSubWindow::qt_metacast(_clname);
}

int saveMdiSub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
