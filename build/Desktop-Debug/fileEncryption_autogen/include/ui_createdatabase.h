/********************************************************************************
** Form generated from reading UI file 'createdatabase.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDATABASE_H
#define UI_CREATEDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateDatabase
{
public:
    QPushButton *pushButton;
    QPushButton *saveButton;
    QPushButton *helpButton;
    QLineEdit *masterPassword;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *repeatMasterPassword;
    QFrame *line;
    QLabel *passState;

    void setupUi(QDialog *CreateDatabase)
    {
        if (CreateDatabase->objectName().isEmpty())
            CreateDatabase->setObjectName("CreateDatabase");
        CreateDatabase->resize(553, 339);
        pushButton = new QPushButton(CreateDatabase);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(450, 300, 83, 29));
        saveButton = new QPushButton(CreateDatabase);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(340, 300, 83, 29));
        helpButton = new QPushButton(CreateDatabase);
        helpButton->setObjectName("helpButton");
        helpButton->setGeometry(QRect(30, 300, 83, 29));
        masterPassword = new QLineEdit(CreateDatabase);
        masterPassword->setObjectName("masterPassword");
        masterPassword->setGeometry(QRect(190, 80, 341, 28));
        label = new QLabel(CreateDatabase);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 80, 121, 20));
        label_2 = new QLabel(CreateDatabase);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 130, 171, 20));
        repeatMasterPassword = new QLineEdit(CreateDatabase);
        repeatMasterPassword->setObjectName("repeatMasterPassword");
        repeatMasterPassword->setGeometry(QRect(190, 130, 341, 28));
        line = new QFrame(CreateDatabase);
        line->setObjectName("line");
        line->setGeometry(QRect(-40, 280, 621, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        passState = new QLabel(CreateDatabase);
        passState->setObjectName("passState");
        passState->setGeometry(QRect(190, 110, 341, 20));

        retranslateUi(CreateDatabase);

        QMetaObject::connectSlotsByName(CreateDatabase);
    } // setupUi

    void retranslateUi(QDialog *CreateDatabase)
    {
        CreateDatabase->setWindowTitle(QCoreApplication::translate("CreateDatabase", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateDatabase", "Cancel", nullptr));
        saveButton->setText(QCoreApplication::translate("CreateDatabase", "Save", nullptr));
        helpButton->setText(QCoreApplication::translate("CreateDatabase", "Help", nullptr));
        label->setText(QCoreApplication::translate("CreateDatabase", "Master password", nullptr));
        label_2->setText(QCoreApplication::translate("CreateDatabase", "Repeat Master password", nullptr));
        passState->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateDatabase: public Ui_CreateDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDATABASE_H
