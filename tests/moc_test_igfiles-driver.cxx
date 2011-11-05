/****************************************************************************
** Meta object code from reading C++ file 'test_igfiles-driver.h'
**
** Created: Sat Jan 15 23:12:36 2011
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "test_igfiles-driver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_igfiles-driver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IgCollectionTest[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      33,   17,   17,   17, 0x08,
      62,   17,   17,   17, 0x08,
      93,   17,   17,   17, 0x08,
     126,   17,   17,   17, 0x08,
     155,   17,   17,   17, 0x08,
     182,   17,   17,   17, 0x08,
     232,   17,   17,   17, 0x08,
     263,   17,   17,   17, 0x08,
     298,   17,   17,   17, 0x08,
     326,   17,   17,   17, 0x08,
     346,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IgCollectionTest[] = {
    "IgCollectionTest\0\0initTestCase()\0"
    "testCreateSimpleCollection()\0"
    "testCreateSimpleAssociations()\0"
    "testCreateSimpleAssociations02()\0"
    "testNavigateOneAssociation()\0"
    "testNavigateAssociations()\0"
    "testCreateWriteReadWriteReadPrintNoAssociations()\0"
    "testCreateReadWriteReadPrint()\0"
    "testNavigateAssociationsOneToOne()\0"
    "testCollectionPerformance()\0"
    "testLinearAlgebra()\0cleanupTestCase()\0"
};

const QMetaObject IgCollectionTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IgCollectionTest,
      qt_meta_data_IgCollectionTest, 0 }
};

const QMetaObject *IgCollectionTest::metaObject() const
{
    return &staticMetaObject;
}

void *IgCollectionTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IgCollectionTest))
        return static_cast<void*>(const_cast< IgCollectionTest*>(this));
    return QObject::qt_metacast(_clname);
}

int IgCollectionTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: testCreateSimpleCollection(); break;
        case 2: testCreateSimpleAssociations(); break;
        case 3: testCreateSimpleAssociations02(); break;
        case 4: testNavigateOneAssociation(); break;
        case 5: testNavigateAssociations(); break;
        case 6: testCreateWriteReadWriteReadPrintNoAssociations(); break;
        case 7: testCreateReadWriteReadPrint(); break;
        case 8: testNavigateAssociationsOneToOne(); break;
        case 9: testCollectionPerformance(); break;
        case 10: testLinearAlgebra(); break;
        case 11: cleanupTestCase(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
