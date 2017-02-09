/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created: Sun Nov 21 17:20:54 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *lightList;
    QCheckBox *lightEnabled;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *posGroup;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLCDNumber *lightDistPosValue;
    QSlider *lightDistPosSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLCDNumber *lightXPosValue;
    QSlider *lightXPosSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLCDNumber *lightYPosValue;
    QSlider *lightYPosSlider;
    QGroupBox *attGroup;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLCDNumber *lightConstAttValue;
    QSlider *lightConstAttSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLCDNumber *lightLinearAttValue;
    QSlider *lightLinearAttSlider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLCDNumber *lightQuadAttValue;
    QSlider *lightQuadAttSlider;
    QGroupBox *colorGroup;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *lightAmbient;
    QRadioButton *lightDiffuse;
    QRadioButton *lightSpecular;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLCDNumber *lightRedValue;
    QSlider *lightRedSlider;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLCDNumber *lightGreenValue;
    QSlider *lightGreenSlider;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLCDNumber *lightBlueValue;
    QSlider *lightBlueSlider;
    QWidget *tab1;
    QGroupBox *groupBox_4;
    QComboBox *shaderList;
    QGroupBox *groupBox_5;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QLCDNumber *modelXPosValue;
    QSlider *modelXPosSlider;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QLCDNumber *modelYPosValue;
    QSlider *modelYPosSlider;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLCDNumber *modelZPosValue;
    QSlider *modelZPosSlider;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLCDNumber *materialShininessValue;
    QSlider *materialShininessSlider;
    QGroupBox *groupBox_6;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_14;
    QLCDNumber *cameraDistPosValue;
    QSlider *cameraDistPosSlider;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_15;
    QLCDNumber *cameraXPosValue;
    QSlider *cameraXPosSlider;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_16;
    QLCDNumber *cameraYPosValue;
    QSlider *cameraYPosSlider;

    void setupUi(QTabWidget *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QString::fromUtf8("ControlPanel"));
        ControlPanel->resize(375, 800);
        ControlPanel->setWindowOpacity(0);
        ControlPanel->setTabPosition(QTabWidget::North);
        ControlPanel->setTabShape(QTabWidget::Rounded);
        ControlPanel->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 191, 23));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lightList = new QComboBox(horizontalLayoutWidget);
        lightList->setObjectName(QString::fromUtf8("lightList"));

        horizontalLayout->addWidget(lightList);

        lightEnabled = new QCheckBox(horizontalLayoutWidget);
        lightEnabled->setObjectName(QString::fromUtf8("lightEnabled"));
        lightEnabled->setChecked(true);

        horizontalLayout->addWidget(lightEnabled);

        verticalLayoutWidget_4 = new QWidget(tab);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 60, 351, 411));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        posGroup = new QGroupBox(verticalLayoutWidget_4);
        posGroup->setObjectName(QString::fromUtf8("posGroup"));
        verticalLayoutWidget = new QWidget(posGroup);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 331, 169));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lightDistPosValue = new QLCDNumber(verticalLayoutWidget);
        lightDistPosValue->setObjectName(QString::fromUtf8("lightDistPosValue"));
        lightDistPosValue->setFrameShape(QFrame::NoFrame);
        lightDistPosValue->setFrameShadow(QFrame::Raised);
        lightDistPosValue->setSmallDecimalPoint(false);
        lightDistPosValue->setSegmentStyle(QLCDNumber::Flat);
        lightDistPosValue->setProperty("intValue", QVariant(0));

        horizontalLayout_2->addWidget(lightDistPosValue);


        verticalLayout->addLayout(horizontalLayout_2);

        lightDistPosSlider = new QSlider(verticalLayoutWidget);
        lightDistPosSlider->setObjectName(QString::fromUtf8("lightDistPosSlider"));
        lightDistPosSlider->setMaximum(1500);
        lightDistPosSlider->setSingleStep(50);
        lightDistPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(lightDistPosSlider);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lightXPosValue = new QLCDNumber(verticalLayoutWidget);
        lightXPosValue->setObjectName(QString::fromUtf8("lightXPosValue"));
        lightXPosValue->setFrameShape(QFrame::NoFrame);
        lightXPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(lightXPosValue);


        verticalLayout->addLayout(horizontalLayout_4);

        lightXPosSlider = new QSlider(verticalLayoutWidget);
        lightXPosSlider->setObjectName(QString::fromUtf8("lightXPosSlider"));
        lightXPosSlider->setMaximum(359);
        lightXPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(lightXPosSlider);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lightYPosValue = new QLCDNumber(verticalLayoutWidget);
        lightYPosValue->setObjectName(QString::fromUtf8("lightYPosValue"));
        lightYPosValue->setFrameShape(QFrame::NoFrame);
        lightYPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lightYPosValue);


        verticalLayout->addLayout(horizontalLayout_3);

        lightYPosSlider = new QSlider(verticalLayoutWidget);
        lightYPosSlider->setObjectName(QString::fromUtf8("lightYPosSlider"));
        lightYPosSlider->setMaximum(359);
        lightYPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(lightYPosSlider);


        verticalLayout_4->addWidget(posGroup);

        attGroup = new QGroupBox(verticalLayoutWidget_4);
        attGroup->setObjectName(QString::fromUtf8("attGroup"));
        verticalLayoutWidget_2 = new QWidget(attGroup);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 331, 169));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lightConstAttValue = new QLCDNumber(verticalLayoutWidget_2);
        lightConstAttValue->setObjectName(QString::fromUtf8("lightConstAttValue"));
        lightConstAttValue->setFrameShape(QFrame::NoFrame);
        lightConstAttValue->setFrameShadow(QFrame::Raised);
        lightConstAttValue->setSmallDecimalPoint(false);
        lightConstAttValue->setNumDigits(7);
        lightConstAttValue->setSegmentStyle(QLCDNumber::Flat);
        lightConstAttValue->setProperty("value", QVariant(0));
        lightConstAttValue->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(lightConstAttValue);


        verticalLayout_2->addLayout(horizontalLayout_5);

        lightConstAttSlider = new QSlider(verticalLayoutWidget_2);
        lightConstAttSlider->setObjectName(QString::fromUtf8("lightConstAttSlider"));
        lightConstAttSlider->setMinimum(1);
        lightConstAttSlider->setMaximum(100);
        lightConstAttSlider->setSingleStep(1);
        lightConstAttSlider->setOrientation(Qt::Horizontal);
        lightConstAttSlider->setTickInterval(0);

        verticalLayout_2->addWidget(lightConstAttSlider);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lightLinearAttValue = new QLCDNumber(verticalLayoutWidget_2);
        lightLinearAttValue->setObjectName(QString::fromUtf8("lightLinearAttValue"));
        lightLinearAttValue->setFrameShape(QFrame::NoFrame);
        lightLinearAttValue->setNumDigits(7);
        lightLinearAttValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lightLinearAttValue);


        verticalLayout_2->addLayout(horizontalLayout_6);

        lightLinearAttSlider = new QSlider(verticalLayoutWidget_2);
        lightLinearAttSlider->setObjectName(QString::fromUtf8("lightLinearAttSlider"));
        lightLinearAttSlider->setMaximum(100);
        lightLinearAttSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(lightLinearAttSlider);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lightQuadAttValue = new QLCDNumber(verticalLayoutWidget_2);
        lightQuadAttValue->setObjectName(QString::fromUtf8("lightQuadAttValue"));
        lightQuadAttValue->setFrameShape(QFrame::NoFrame);
        lightQuadAttValue->setNumDigits(7);
        lightQuadAttValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_7->addWidget(lightQuadAttValue);


        verticalLayout_2->addLayout(horizontalLayout_7);

        lightQuadAttSlider = new QSlider(verticalLayoutWidget_2);
        lightQuadAttSlider->setObjectName(QString::fromUtf8("lightQuadAttSlider"));
        lightQuadAttSlider->setMaximum(100);
        lightQuadAttSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(lightQuadAttSlider);


        verticalLayout_4->addWidget(attGroup);

        colorGroup = new QGroupBox(tab);
        colorGroup->setObjectName(QString::fromUtf8("colorGroup"));
        colorGroup->setGeometry(QRect(10, 480, 351, 251));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorGroup->sizePolicy().hasHeightForWidth());
        colorGroup->setSizePolicy(sizePolicy);
        verticalLayoutWidget_3 = new QWidget(colorGroup);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 331, 211));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lightAmbient = new QRadioButton(verticalLayoutWidget_3);
        lightAmbient->setObjectName(QString::fromUtf8("lightAmbient"));
        lightAmbient->setChecked(true);

        horizontalLayout_11->addWidget(lightAmbient);

        lightDiffuse = new QRadioButton(verticalLayoutWidget_3);
        lightDiffuse->setObjectName(QString::fromUtf8("lightDiffuse"));

        horizontalLayout_11->addWidget(lightDiffuse);

        lightSpecular = new QRadioButton(verticalLayoutWidget_3);
        lightSpecular->setObjectName(QString::fromUtf8("lightSpecular"));

        horizontalLayout_11->addWidget(lightSpecular);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        lightRedValue = new QLCDNumber(verticalLayoutWidget_3);
        lightRedValue->setObjectName(QString::fromUtf8("lightRedValue"));
        lightRedValue->setFrameShape(QFrame::NoFrame);
        lightRedValue->setFrameShadow(QFrame::Raised);
        lightRedValue->setSmallDecimalPoint(false);
        lightRedValue->setSegmentStyle(QLCDNumber::Flat);
        lightRedValue->setProperty("intValue", QVariant(0));

        horizontalLayout_8->addWidget(lightRedValue);


        verticalLayout_3->addLayout(horizontalLayout_8);

        lightRedSlider = new QSlider(verticalLayoutWidget_3);
        lightRedSlider->setObjectName(QString::fromUtf8("lightRedSlider"));
        lightRedSlider->setMaximum(255);
        lightRedSlider->setValue(0);
        lightRedSlider->setSliderPosition(0);
        lightRedSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(lightRedSlider);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        lightGreenValue = new QLCDNumber(verticalLayoutWidget_3);
        lightGreenValue->setObjectName(QString::fromUtf8("lightGreenValue"));
        lightGreenValue->setFrameShape(QFrame::NoFrame);
        lightGreenValue->setSegmentStyle(QLCDNumber::Flat);
        lightGreenValue->setProperty("intValue", QVariant(0));

        horizontalLayout_9->addWidget(lightGreenValue);


        verticalLayout_3->addLayout(horizontalLayout_9);

        lightGreenSlider = new QSlider(verticalLayoutWidget_3);
        lightGreenSlider->setObjectName(QString::fromUtf8("lightGreenSlider"));
        lightGreenSlider->setMaximum(255);
        lightGreenSlider->setValue(0);
        lightGreenSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(lightGreenSlider);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lightBlueValue = new QLCDNumber(verticalLayoutWidget_3);
        lightBlueValue->setObjectName(QString::fromUtf8("lightBlueValue"));
        lightBlueValue->setFrameShape(QFrame::NoFrame);
        lightBlueValue->setSegmentStyle(QLCDNumber::Flat);
        lightBlueValue->setProperty("intValue", QVariant(0));

        horizontalLayout_10->addWidget(lightBlueValue);


        verticalLayout_3->addLayout(horizontalLayout_10);

        lightBlueSlider = new QSlider(verticalLayoutWidget_3);
        lightBlueSlider->setObjectName(QString::fromUtf8("lightBlueSlider"));
        lightBlueSlider->setMaximum(255);
        lightBlueSlider->setValue(0);
        lightBlueSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(lightBlueSlider);

        ControlPanel->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        groupBox_4 = new QGroupBox(tab1);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 341, 71));
        shaderList = new QComboBox(groupBox_4);
        shaderList->setObjectName(QString::fromUtf8("shaderList"));
        shaderList->setGeometry(QRect(10, 30, 171, 22));
        groupBox_5 = new QGroupBox(tab1);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 100, 341, 291));
        verticalLayoutWidget_5 = new QWidget(groupBox_5);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 30, 321, 251));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_12 = new QLabel(verticalLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_15->addWidget(label_12);

        modelXPosValue = new QLCDNumber(verticalLayoutWidget_5);
        modelXPosValue->setObjectName(QString::fromUtf8("modelXPosValue"));
        modelXPosValue->setFrameShape(QFrame::NoFrame);
        modelXPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_15->addWidget(modelXPosValue);


        verticalLayout_5->addLayout(horizontalLayout_15);

        modelXPosSlider = new QSlider(verticalLayoutWidget_5);
        modelXPosSlider->setObjectName(QString::fromUtf8("modelXPosSlider"));
        modelXPosSlider->setMaximum(359);
        modelXPosSlider->setOrientation(Qt::Horizontal);
        modelXPosSlider->setTickPosition(QSlider::NoTicks);

        verticalLayout_5->addWidget(modelXPosSlider);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_13 = new QLabel(verticalLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_16->addWidget(label_13);

        modelYPosValue = new QLCDNumber(verticalLayoutWidget_5);
        modelYPosValue->setObjectName(QString::fromUtf8("modelYPosValue"));
        modelYPosValue->setFrameShape(QFrame::NoFrame);
        modelYPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_16->addWidget(modelYPosValue);


        verticalLayout_5->addLayout(horizontalLayout_16);

        modelYPosSlider = new QSlider(verticalLayoutWidget_5);
        modelYPosSlider->setObjectName(QString::fromUtf8("modelYPosSlider"));
        modelYPosSlider->setMaximum(359);
        modelYPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(modelYPosSlider);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(verticalLayoutWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_13->addWidget(label_11);

        modelZPosValue = new QLCDNumber(verticalLayoutWidget_5);
        modelZPosValue->setObjectName(QString::fromUtf8("modelZPosValue"));
        modelZPosValue->setFrameShape(QFrame::NoFrame);
        modelZPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_13->addWidget(modelZPosValue);


        verticalLayout_5->addLayout(horizontalLayout_13);

        modelZPosSlider = new QSlider(verticalLayoutWidget_5);
        modelZPosSlider->setObjectName(QString::fromUtf8("modelZPosSlider"));
        modelZPosSlider->setMaximum(359);
        modelZPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(modelZPosSlider);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_12->addWidget(label_10);

        materialShininessValue = new QLCDNumber(verticalLayoutWidget_5);
        materialShininessValue->setObjectName(QString::fromUtf8("materialShininessValue"));
        materialShininessValue->setFrameShape(QFrame::NoFrame);
        materialShininessValue->setSegmentStyle(QLCDNumber::Flat);
        materialShininessValue->setProperty("intValue", QVariant(0));

        horizontalLayout_12->addWidget(materialShininessValue);


        verticalLayout_5->addLayout(horizontalLayout_12);

        materialShininessSlider = new QSlider(verticalLayoutWidget_5);
        materialShininessSlider->setObjectName(QString::fromUtf8("materialShininessSlider"));
        materialShininessSlider->setMaximum(100);
        materialShininessSlider->setValue(0);
        materialShininessSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(materialShininessSlider);

        groupBox_6 = new QGroupBox(tab1);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 400, 341, 241));
        verticalLayoutWidget_6 = new QWidget(groupBox_6);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 30, 321, 191));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_14 = new QLabel(verticalLayoutWidget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_17->addWidget(label_14);

        cameraDistPosValue = new QLCDNumber(verticalLayoutWidget_6);
        cameraDistPosValue->setObjectName(QString::fromUtf8("cameraDistPosValue"));
        cameraDistPosValue->setFrameShape(QFrame::NoFrame);
        cameraDistPosValue->setSegmentStyle(QLCDNumber::Flat);
        cameraDistPosValue->setProperty("intValue", QVariant(0));

        horizontalLayout_17->addWidget(cameraDistPosValue);


        verticalLayout_6->addLayout(horizontalLayout_17);

        cameraDistPosSlider = new QSlider(verticalLayoutWidget_6);
        cameraDistPosSlider->setObjectName(QString::fromUtf8("cameraDistPosSlider"));
        cameraDistPosSlider->setMaximum(1500);
        cameraDistPosSlider->setSingleStep(50);
        cameraDistPosSlider->setValue(0);
        cameraDistPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(cameraDistPosSlider);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_15 = new QLabel(verticalLayoutWidget_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_18->addWidget(label_15);

        cameraXPosValue = new QLCDNumber(verticalLayoutWidget_6);
        cameraXPosValue->setObjectName(QString::fromUtf8("cameraXPosValue"));
        cameraXPosValue->setFrameShape(QFrame::NoFrame);
        cameraXPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_18->addWidget(cameraXPosValue);


        verticalLayout_6->addLayout(horizontalLayout_18);

        cameraXPosSlider = new QSlider(verticalLayoutWidget_6);
        cameraXPosSlider->setObjectName(QString::fromUtf8("cameraXPosSlider"));
        cameraXPosSlider->setMaximum(359);
        cameraXPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(cameraXPosSlider);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_16 = new QLabel(verticalLayoutWidget_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_19->addWidget(label_16);

        cameraYPosValue = new QLCDNumber(verticalLayoutWidget_6);
        cameraYPosValue->setObjectName(QString::fromUtf8("cameraYPosValue"));
        cameraYPosValue->setFrameShape(QFrame::NoFrame);
        cameraYPosValue->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_19->addWidget(cameraYPosValue);


        verticalLayout_6->addLayout(horizontalLayout_19);

        cameraYPosSlider = new QSlider(verticalLayoutWidget_6);
        cameraYPosSlider->setObjectName(QString::fromUtf8("cameraYPosSlider"));
        cameraYPosSlider->setMaximum(359);
        cameraYPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(cameraYPosSlider);

        ControlPanel->addTab(tab1, QString());

        retranslateUi(ControlPanel);

        ControlPanel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QTabWidget *ControlPanel)
    {
        ControlPanel->setWindowTitle(QApplication::translate("ControlPanel", "TabWidget", 0, QApplication::UnicodeUTF8));
        lightList->clear();
        lightList->insertItems(0, QStringList()
         << QApplication::translate("ControlPanel", "Light 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Light 8", 0, QApplication::UnicodeUTF8)
        );
        lightEnabled->setText(QApplication::translate("ControlPanel", "Enabled", 0, QApplication::UnicodeUTF8));
        posGroup->setTitle(QApplication::translate("ControlPanel", "Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ControlPanel", "Radius:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ControlPanel", "X Angle:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ControlPanel", "Y Angle:", 0, QApplication::UnicodeUTF8));
        attGroup->setTitle(QApplication::translate("ControlPanel", "Attenuation", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ControlPanel", "Constant term:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ControlPanel", "Linear term:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ControlPanel", "Quadratic term:", 0, QApplication::UnicodeUTF8));
        colorGroup->setTitle(QApplication::translate("ControlPanel", "Color", 0, QApplication::UnicodeUTF8));
        lightAmbient->setText(QApplication::translate("ControlPanel", "Ambient", 0, QApplication::UnicodeUTF8));
        lightDiffuse->setText(QApplication::translate("ControlPanel", "Diffuse", 0, QApplication::UnicodeUTF8));
        lightSpecular->setText(QApplication::translate("ControlPanel", "Specular", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ControlPanel", "Red:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ControlPanel", "Green:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ControlPanel", "Blue:", 0, QApplication::UnicodeUTF8));
        ControlPanel->setTabText(ControlPanel->indexOf(tab), QApplication::translate("ControlPanel", "Lighting", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("ControlPanel", "Shader", 0, QApplication::UnicodeUTF8));
        shaderList->clear();
        shaderList->insertItems(0, QStringList()
         << QApplication::translate("ControlPanel", "Flat shading", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Gouraud shading", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Phong shading", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlPanel", "Blinn-Phong shading", 0, QApplication::UnicodeUTF8)
        );
        groupBox_5->setTitle(QApplication::translate("ControlPanel", "Model and Material", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ControlPanel", "X angle:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ControlPanel", "Y angle:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ControlPanel", "Z angle:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ControlPanel", "Shininess:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("ControlPanel", "Camera", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ControlPanel", "Radius:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ControlPanel", "X angle", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ControlPanel", "Y angle:", 0, QApplication::UnicodeUTF8));
        ControlPanel->setTabText(ControlPanel->indexOf(tab1), QApplication::translate("ControlPanel", "Others", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
