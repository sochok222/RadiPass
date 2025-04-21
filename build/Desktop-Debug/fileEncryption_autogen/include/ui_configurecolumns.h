/********************************************************************************
** Form generated from reading UI file 'configurecolumns.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURECOLUMNS_H
#define UI_CONFIGURECOLUMNS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigureColumns
{
public:
    QTableWidget *tableWidget;
    QPushButton *saveButton;

    void setupUi(QDialog *ConfigureColumns)
    {
        if (ConfigureColumns->objectName().isEmpty())
            ConfigureColumns->setObjectName("ConfigureColumns");
        ConfigureColumns->resize(643, 533);
        tableWidget = new QTableWidget(ConfigureColumns);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 30, 601, 401));
        saveButton = new QPushButton(ConfigureColumns);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(280, 460, 83, 29));

        retranslateUi(ConfigureColumns);

        QMetaObject::connectSlotsByName(ConfigureColumns);
    } // setupUi

    void retranslateUi(QDialog *ConfigureColumns)
    {
        ConfigureColumns->setWindowTitle(QCoreApplication::translate("ConfigureColumns", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("ConfigureColumns", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigureColumns: public Ui_ConfigureColumns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURECOLUMNS_H
