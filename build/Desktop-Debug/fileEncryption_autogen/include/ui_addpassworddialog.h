/********************************************************************************
** Form generated from reading UI file 'addpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPASSWORDDIALOG_H
#define UI_ADDPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPasswordDialog
{
public:
    QLineEdit *title;
    QPushButton *writeButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label_3;
    QLineEdit *password;
    QLabel *label_4;
    QLineEdit *url;
    QLabel *label_5;
    QTextEdit *notes;
    QFrame *line;
    QPushButton *cancelButton;
    QDateTimeEdit *dateExpiresEdit;
    QCheckBox *checkBox;
    QFrame *line_2;

    void setupUi(QDialog *AddPasswordDialog)
    {
        if (AddPasswordDialog->objectName().isEmpty())
            AddPasswordDialog->setObjectName("AddPasswordDialog");
        AddPasswordDialog->resize(590, 519);
        title = new QLineEdit(AddPasswordDialog);
        title->setObjectName("title");
        title->setGeometry(QRect(140, 70, 421, 28));
        writeButton = new QPushButton(AddPasswordDialog);
        writeButton->setObjectName("writeButton");
        writeButton->setGeometry(QRect(340, 480, 111, 29));
        label = new QLabel(AddPasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 63, 20));
        label_2 = new QLabel(AddPasswordDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 120, 81, 20));
        username = new QLineEdit(AddPasswordDialog);
        username->setObjectName("username");
        username->setGeometry(QRect(140, 110, 421, 28));
        label_3 = new QLabel(AddPasswordDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 160, 71, 20));
        password = new QLineEdit(AddPasswordDialog);
        password->setObjectName("password");
        password->setGeometry(QRect(140, 150, 421, 28));
        label_4 = new QLabel(AddPasswordDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 200, 63, 20));
        url = new QLineEdit(AddPasswordDialog);
        url->setObjectName("url");
        url->setGeometry(QRect(140, 190, 421, 28));
        label_5 = new QLabel(AddPasswordDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 240, 63, 20));
        notes = new QTextEdit(AddPasswordDialog);
        notes->setObjectName("notes");
        notes->setGeometry(QRect(140, 240, 421, 121));
        line = new QFrame(AddPasswordDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 460, 591, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        cancelButton = new QPushButton(AddPasswordDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(460, 480, 111, 29));
        dateExpiresEdit = new QDateTimeEdit(AddPasswordDialog);
        dateExpiresEdit->setObjectName("dateExpiresEdit");
        dateExpiresEdit->setGeometry(QRect(140, 410, 194, 29));
        checkBox = new QCheckBox(AddPasswordDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(40, 410, 93, 26));
        line_2 = new QFrame(AddPasswordDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 50, 581, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        retranslateUi(AddPasswordDialog);

        QMetaObject::connectSlotsByName(AddPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPasswordDialog)
    {
        AddPasswordDialog->setWindowTitle(QCoreApplication::translate("AddPasswordDialog", "Dialog", nullptr));
        writeButton->setText(QCoreApplication::translate("AddPasswordDialog", "Ok", nullptr));
        label->setText(QCoreApplication::translate("AddPasswordDialog", "Titile: ", nullptr));
        label_2->setText(QCoreApplication::translate("AddPasswordDialog", "User Name:", nullptr));
        label_3->setText(QCoreApplication::translate("AddPasswordDialog", "Password: ", nullptr));
        label_4->setText(QCoreApplication::translate("AddPasswordDialog", "URL: ", nullptr));
        label_5->setText(QCoreApplication::translate("AddPasswordDialog", "Notes:", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddPasswordDialog", "Cancel", nullptr));
        checkBox->setText(QCoreApplication::translate("AddPasswordDialog", "Expires: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPasswordDialog: public Ui_AddPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPASSWORDDIALOG_H
