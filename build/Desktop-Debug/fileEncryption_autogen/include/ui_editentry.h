/********************************************************************************
** Form generated from reading UI file 'editentry.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITENTRY_H
#define UI_EDITENTRY_H

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

class Ui_EditEntry
{
public:
    QLabel *label;
    QDateTimeEdit *dateExpiresEdit;
    QPushButton *writeButton;
    QLineEdit *url;
    QCheckBox *checkBox;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QFrame *line_2;
    QLineEdit *title;
    QLineEdit *password;
    QPushButton *cancelButton;
    QLineEdit *username;
    QFrame *line;
    QLabel *label_5;
    QTextEdit *notes;

    void setupUi(QDialog *EditEntry)
    {
        if (EditEntry->objectName().isEmpty())
            EditEntry->setObjectName("EditEntry");
        EditEntry->resize(577, 481);
        label = new QLabel(EditEntry);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 63, 20));
        dateExpiresEdit = new QDateTimeEdit(EditEntry);
        dateExpiresEdit->setObjectName("dateExpiresEdit");
        dateExpiresEdit->setGeometry(QRect(140, 370, 194, 29));
        writeButton = new QPushButton(EditEntry);
        writeButton->setObjectName("writeButton");
        writeButton->setGeometry(QRect(340, 440, 111, 29));
        url = new QLineEdit(EditEntry);
        url->setObjectName("url");
        url->setGeometry(QRect(140, 150, 421, 28));
        checkBox = new QCheckBox(EditEntry);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(40, 370, 93, 26));
        label_3 = new QLabel(EditEntry);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 120, 71, 20));
        label_2 = new QLabel(EditEntry);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 80, 81, 20));
        label_4 = new QLabel(EditEntry);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 160, 63, 20));
        line_2 = new QFrame(EditEntry);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 10, 581, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        title = new QLineEdit(EditEntry);
        title->setObjectName("title");
        title->setGeometry(QRect(140, 30, 421, 28));
        password = new QLineEdit(EditEntry);
        password->setObjectName("password");
        password->setGeometry(QRect(140, 110, 421, 28));
        cancelButton = new QPushButton(EditEntry);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(460, 440, 111, 29));
        username = new QLineEdit(EditEntry);
        username->setObjectName("username");
        username->setGeometry(QRect(140, 70, 421, 28));
        line = new QFrame(EditEntry);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 420, 591, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_5 = new QLabel(EditEntry);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 200, 63, 20));
        notes = new QTextEdit(EditEntry);
        notes->setObjectName("notes");
        notes->setGeometry(QRect(140, 200, 421, 121));

        retranslateUi(EditEntry);

        QMetaObject::connectSlotsByName(EditEntry);
    } // setupUi

    void retranslateUi(QDialog *EditEntry)
    {
        EditEntry->setWindowTitle(QCoreApplication::translate("EditEntry", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditEntry", "Titile: ", nullptr));
        writeButton->setText(QCoreApplication::translate("EditEntry", "Ok", nullptr));
        checkBox->setText(QCoreApplication::translate("EditEntry", "Expires: ", nullptr));
        label_3->setText(QCoreApplication::translate("EditEntry", "Password: ", nullptr));
        label_2->setText(QCoreApplication::translate("EditEntry", "User Name:", nullptr));
        label_4->setText(QCoreApplication::translate("EditEntry", "URL: ", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditEntry", "Cancel", nullptr));
        label_5->setText(QCoreApplication::translate("EditEntry", "Notes:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditEntry: public Ui_EditEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITENTRY_H
