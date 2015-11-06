/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainWindow/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      59,   11,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     119,  115,   11,   11, 0x08,
     141,  115,   11,   11, 0x08,
     161,  115,   11,   11, 0x08,
     183,  115,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0writettyUSB()\0readttyUSB()\0"
    "ttyUSBDataAnaylse()\0OpenClosettyUSB()\0"
    "dataTest_AddData()\0temp()\0openLight()\0"
    "bol\0dataLight_OnOff(bool)\0dataCO2_OnOff(bool)\0"
    "dataTempe_OnOff(bool)\0dataHumid_OnOff(bool)\0"
    "showSQLLightData()\0showSQLCo2Data()\0"
    "showSQLTempeData()\0showSQLHumidData()\0"
    "analTcpData()\0receiveConn()\0tcpSendData()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->writettyUSB(); break;
        case 1: _t->readttyUSB(); break;
        case 2: _t->ttyUSBDataAnaylse(); break;
        case 3: _t->OpenClosettyUSB(); break;
        case 4: _t->dataTest_AddData(); break;
        case 5: _t->temp(); break;
        case 6: _t->openLight(); break;
        case 7: _t->dataLight_OnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->dataCO2_OnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->dataTempe_OnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->dataHumid_OnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->showSQLLightData(); break;
        case 12: _t->showSQLCo2Data(); break;
        case 13: _t->showSQLTempeData(); break;
        case 14: _t->showSQLHumidData(); break;
        case 15: _t->analTcpData(); break;
        case 16: _t->receiveConn(); break;
        case 17: _t->tcpSendData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
