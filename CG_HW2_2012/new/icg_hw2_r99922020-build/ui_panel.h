/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created: Wed Nov 17 15:27:34 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QGroupBox *groupBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QComboBox *comboBox;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(250, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Panel->sizePolicy().hasHeightForWidth());
        Panel->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(Panel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 351));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 100, 46, 22));
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(80, 100, 46, 22));
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(20, 160, 46, 22));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 80, 22));
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(80, 160, 46, 22));
        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(150, 160, 46, 22));
        spinBox_6 = new QSpinBox(groupBox);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(20, 200, 46, 22));
        spinBox_7 = new QSpinBox(groupBox);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(90, 200, 46, 22));
        spinBox_8 = new QSpinBox(groupBox);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(160, 200, 46, 22));
        spinBox_9 = new QSpinBox(groupBox);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setGeometry(QRect(20, 260, 46, 22));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(120, 30, 85, 19));
        groupBox_2 = new QGroupBox(Panel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 370, 231, 111));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        groupBox_3 = new QGroupBox(Panel);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 500, 231, 81));

        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QApplication::translate("Panel", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Panel", "Lighting", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Panel", "CheckBox", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Panel", "Material", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Panel", "Camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
