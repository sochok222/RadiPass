/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionCopy_User_Name;
    QAction *actionCopy_Password;
    QAction *actionUrl;
    QAction *actionAdd_Entry;
    QAction *actionEdit_Entry;
    QAction *actionDelete_Entry;
    QAction *actionDuplicate_Entry;
    QAction *actionChange_Language;
    QAction *actionChange_color_scheme;
    QAction *actionShow_Toolbar;
    QAction *actionConfigure_Columns;
    QWidget *centralwidget;
    QTableView *tableView;
    QListWidget *listWidget;
    QPushButton *newDatabaseButton;
    QPushButton *openDatabaseButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEntry;
    QMenu *menuViev;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 552);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionCopy_User_Name = new QAction(MainWindow);
        actionCopy_User_Name->setObjectName("actionCopy_User_Name");
        actionCopy_Password = new QAction(MainWindow);
        actionCopy_Password->setObjectName("actionCopy_Password");
        actionUrl = new QAction(MainWindow);
        actionUrl->setObjectName("actionUrl");
        actionAdd_Entry = new QAction(MainWindow);
        actionAdd_Entry->setObjectName("actionAdd_Entry");
        actionEdit_Entry = new QAction(MainWindow);
        actionEdit_Entry->setObjectName("actionEdit_Entry");
        actionDelete_Entry = new QAction(MainWindow);
        actionDelete_Entry->setObjectName("actionDelete_Entry");
        actionDuplicate_Entry = new QAction(MainWindow);
        actionDuplicate_Entry->setObjectName("actionDuplicate_Entry");
        actionChange_Language = new QAction(MainWindow);
        actionChange_Language->setObjectName("actionChange_Language");
        actionChange_color_scheme = new QAction(MainWindow);
        actionChange_color_scheme->setObjectName("actionChange_color_scheme");
        actionShow_Toolbar = new QAction(MainWindow);
        actionShow_Toolbar->setObjectName("actionShow_Toolbar");
        actionConfigure_Columns = new QAction(MainWindow);
        actionConfigure_Columns->setObjectName("actionConfigure_Columns");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(160, 30, 641, 361));
        tableView->setStyleSheet(QString::fromUtf8(""));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 30, 151, 361));
        newDatabaseButton = new QPushButton(centralwidget);
        newDatabaseButton->setObjectName("newDatabaseButton");
        newDatabaseButton->setGeometry(QRect(0, 0, 31, 29));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        newDatabaseButton->setIcon(icon);
        newDatabaseButton->setCheckable(false);
        openDatabaseButton = new QPushButton(centralwidget);
        openDatabaseButton->setObjectName("openDatabaseButton");
        openDatabaseButton->setGeometry(QRect(30, 0, 31, 29));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        openDatabaseButton->setIcon(icon1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuFile->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        menuEntry = new QMenu(menubar);
        menuEntry->setObjectName("menuEntry");
        menuViev = new QMenu(menubar);
        menuViev->setObjectName("menuViev");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEntry->menuAction());
        menubar->addAction(menuViev->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuEntry->addAction(actionCopy_User_Name);
        menuEntry->addAction(actionCopy_Password);
        menuEntry->addAction(actionUrl);
        menuEntry->addSeparator();
        menuEntry->addAction(actionAdd_Entry);
        menuEntry->addAction(actionEdit_Entry);
        menuEntry->addAction(actionDuplicate_Entry);
        menuEntry->addAction(actionDelete_Entry);
        menuViev->addAction(actionChange_Language);
        menuViev->addSeparator();
        menuViev->addAction(actionChange_color_scheme);
        menuViev->addAction(actionShow_Toolbar);
        menuViev->addSeparator();
        menuViev->addAction(actionConfigure_Columns);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionCopy_User_Name->setText(QCoreApplication::translate("MainWindow", "Copy User Name", nullptr));
        actionCopy_Password->setText(QCoreApplication::translate("MainWindow", "Copy Password", nullptr));
        actionUrl->setText(QCoreApplication::translate("MainWindow", "Url", nullptr));
        actionAdd_Entry->setText(QCoreApplication::translate("MainWindow", "Add Entry", nullptr));
        actionEdit_Entry->setText(QCoreApplication::translate("MainWindow", "Edit Entry", nullptr));
        actionDelete_Entry->setText(QCoreApplication::translate("MainWindow", "Delete Entry", nullptr));
        actionDuplicate_Entry->setText(QCoreApplication::translate("MainWindow", "Duplicate Entry", nullptr));
        actionChange_Language->setText(QCoreApplication::translate("MainWindow", "Change Language", nullptr));
        actionChange_color_scheme->setText(QCoreApplication::translate("MainWindow", "Change color scheme", nullptr));
        actionShow_Toolbar->setText(QCoreApplication::translate("MainWindow", "Show Toolbar", nullptr));
        actionConfigure_Columns->setText(QCoreApplication::translate("MainWindow", "Configure Columns", nullptr));
        newDatabaseButton->setText(QString());
        openDatabaseButton->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEntry->setTitle(QCoreApplication::translate("MainWindow", "Entry", nullptr));
        menuViev->setTitle(QCoreApplication::translate("MainWindow", "Viev", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
