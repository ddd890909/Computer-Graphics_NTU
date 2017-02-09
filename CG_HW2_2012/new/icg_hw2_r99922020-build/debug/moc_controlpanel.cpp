/****************************************************************************
** Meta object code from reading C++ file 'controlpanel.h'
**
** Created: Sun Nov 21 17:14:36 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../icg_hw2_r99922020/controlpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlPanel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      29,   13,   13,   13, 0x05,
      44,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   60,   13,   13, 0x08,
     104,   98,   13,   13, 0x08,
     128,   13,   13,   13, 0x08,
     149,   13,   13,   13, 0x08,
     171,   13,   13,   13, 0x08,
     185,   13,   13,   13, 0x08,
     199,   13,   13,   13, 0x08,
     220,  214,   13,   13, 0x08,
     260,  254,   13,   13, 0x08,
     300,  254,   13,   13, 0x08,
     342,  254,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ControlPanel[] = {
    "ControlPanel\0\0lightChanged()\0"
    "modelChanged()\0cameraChanged()\0checked\0"
    "updateLightColorControl(bool)\0index\0"
    "updateLightControl(int)\0updateModelControl()\0"
    "updateCameraControl()\0setLight(int)\0"
    "setModel(int)\0setCamera(int)\0state\0"
    "on_lightEnabled_stateChanged(int)\0"
    "value\0on_lightQuadAttSlider_valueChanged(int)\0"
    "on_lightLinearAttSlider_valueChanged(int)\0"
    "on_lightConstAttSlider_valueChanged(int)\0"
};

const QMetaObject ControlPanel::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_ControlPanel,
      qt_meta_data_ControlPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel))
        return static_cast<void*>(const_cast< ControlPanel*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: lightChanged(); break;
        case 1: modelChanged(); break;
        case 2: cameraChanged(); break;
        case 3: updateLightColorControl((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: updateLightControl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: updateModelControl(); break;
        case 6: updateCameraControl(); break;
        case 7: setLight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: setModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: setCamera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_lightEnabled_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_lightQuadAttSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: on_lightLinearAttSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_lightConstAttSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ControlPanel::lightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ControlPanel::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ControlPanel::cameraChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
