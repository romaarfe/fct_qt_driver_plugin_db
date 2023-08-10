/****************************************************************************
** Meta object code from reading C++ file 'qsql_sqlite_p.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../novaTentativaDriver/qsql_sqlite_p.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsql_sqlite_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
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
struct qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS = QtMocHelpers::stringData(
    "QSQLiteDriver",
    "handleNotification",
    "",
    "tableName",
    "rowid"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[14];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS_t qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QSQLiteDriver"
        QT_MOC_LITERAL(14, 18),  // "handleNotification"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 9),  // "tableName"
        QT_MOC_LITERAL(44, 5)   // "rowid"
    },
    "QSQLiteDriver",
    "handleNotification",
    "",
    "tableName",
    "rowid"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSQLiteDriverENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong,    3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject QSQLiteDriver::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlDriver::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSQLiteDriverENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QSQLiteDriver, std::true_type>,
        // method 'handleNotification'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>
    >,
    nullptr
} };

void QSQLiteDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSQLiteDriver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleNotification((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *QSQLiteDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSQLiteDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSQLiteDriverENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QSqlDriver::qt_metacast(_clname);
}

int QSQLiteDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlDriver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
