/********************************************************************************
** Form generated from reading UI file 'addtable.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTABLE_H
#define UI_ADDTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddTable
{
public:
    QPushButton *addTableButton;
    QLineEdit *nameEdit;
    QLabel *label;

    void setupUi(QDialog *AddTable)
    {
        if (AddTable->objectName().isEmpty())
            AddTable->setObjectName("AddTable");
        AddTable->resize(732, 402);
        addTableButton = new QPushButton(AddTable);
        addTableButton->setObjectName("addTableButton");
        addTableButton->setGeometry(QRect(270, 230, 83, 29));
        nameEdit = new QLineEdit(AddTable);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(260, 140, 291, 28));
        label = new QLabel(AddTable);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 140, 91, 20));

        retranslateUi(AddTable);

        QMetaObject::connectSlotsByName(AddTable);
    } // setupUi

    void retranslateUi(QDialog *AddTable)
    {
        AddTable->setWindowTitle(QCoreApplication::translate("AddTable", "Dialog", nullptr));
        addTableButton->setText(QCoreApplication::translate("AddTable", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("AddTable", "table name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTable: public Ui_AddTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTABLE_H
