/********************************************************************************
** Form generated from reading UI file 'opendatabase.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENDATABASE_H
#define UI_OPENDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OpenDatabase
{
public:
    QFrame *line;
    QLabel *label;
    QLabel *databasePathLabel;
    QLineEdit *passwordLine;
    QLabel *label_2;
    QFrame *line_2;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *helpButton;
    QLabel *passwordCheckLabel;

    void setupUi(QDialog *OpenDatabase)
    {
        if (OpenDatabase->objectName().isEmpty())
            OpenDatabase->setObjectName("OpenDatabase");
        OpenDatabase->resize(639, 246);
        line = new QFrame(OpenDatabase);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 70, 651, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(OpenDatabase);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 201, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        databasePathLabel = new QLabel(OpenDatabase);
        databasePathLabel->setObjectName("databasePathLabel");
        databasePathLabel->setGeometry(QRect(10, 50, 631, 20));
        passwordLine = new QLineEdit(OpenDatabase);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setGeometry(QRect(150, 110, 301, 31));
        label_2 = new QLabel(OpenDatabase);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 120, 111, 20));
        line_2 = new QFrame(OpenDatabase);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(-10, 180, 651, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        okButton = new QPushButton(OpenDatabase);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(400, 200, 111, 29));
        cancelButton = new QPushButton(OpenDatabase);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(520, 200, 111, 29));
        helpButton = new QPushButton(OpenDatabase);
        helpButton->setObjectName("helpButton");
        helpButton->setGeometry(QRect(10, 200, 111, 29));
        passwordCheckLabel = new QLabel(OpenDatabase);
        passwordCheckLabel->setObjectName("passwordCheckLabel");
        passwordCheckLabel->setGeometry(QRect(150, 150, 231, 20));

        retranslateUi(OpenDatabase);

        QMetaObject::connectSlotsByName(OpenDatabase);
    } // setupUi

    void retranslateUi(QDialog *OpenDatabase)
    {
        OpenDatabase->setWindowTitle(QCoreApplication::translate("OpenDatabase", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("OpenDatabase", "Enter Master Key", nullptr));
        databasePathLabel->setText(QCoreApplication::translate("OpenDatabase", "Path", nullptr));
        label_2->setText(QCoreApplication::translate("OpenDatabase", "Master Password", nullptr));
        okButton->setText(QCoreApplication::translate("OpenDatabase", "Ok", nullptr));
        cancelButton->setText(QCoreApplication::translate("OpenDatabase", "Cancel", nullptr));
        helpButton->setText(QCoreApplication::translate("OpenDatabase", "Help", nullptr));
        passwordCheckLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenDatabase: public Ui_OpenDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENDATABASE_H
