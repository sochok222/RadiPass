#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql/qsqldatabase.h>
#include "addpassworddialog.h"
#include "configurecolumns.h"
#include <QtSql/QSqlDatabase>
#include <QContextMenuEvent>
#include "databaseloader.h"
#include "createdatabase.h"
#include <QDesktopServices>
#include <QtSql/QSqlDriver>
#include "ui_mainwindow.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include "celldelegate.h"
#include "opendatabase.h"
#include <QScopedPointer>
#include <QTemporaryFile>
#include <openssl/rand.h>
#include <QStandardPaths>
#include <QTemporaryFile>
#include <QSqlTableModel>
#include <openssl/evp.h>
#include <QActionGroup>
#include <QProgressBar>
#include "editentry.h"
#include <QCloseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QVBoxLayout>
#include "addtable.h"
#include <windows.h>
#include <QSettings>
#include <QThread>
#include <QAction>
#include <QBuffer>
#include <thread>
#include <chrono>
#include <QDebug>
#include <QFile>
#include <QMenu>
#include <QDir>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QByteArray MasterKey = "");
    ~MainWindow();

private slots:
    void on_addDataButton_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_addTableButton_clicked();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_configureColumnsButton_clicked();

private:
    Ui::MainWindow *ui;
    bool decryptDatabaseToMemory(const QString &key, QSqlDatabase &memoryDb, const QString &encryptedFilePath, QByteArray &rtrn);
    QByteArray encryptDatabase(const QString &filePath, const QByteArray &data, const QString &key);
    bool createEncryptedDatabase(const QString &dbPath, const QString &key);
    bool createAndPopulateDatabase(const QString &dbPath);
    void closeEvent(QCloseEvent *event) override;
    void configureColumns();
    void copyText(const QString text);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel *model;
    QString currentTable;
    std::vector<QString> tables;
    QSettings settings = QSettings("AlexRadik", "RadiPass");
    QByteArray key = 0;
    CellDelegate *maskColumn = new CellDelegate;
    bool isChanged = false;
    QScopedPointer<QMenu> mainContextMenu;
    QScopedPointer<QMenu> subMenuUrl;
    QScopedPointer<QAction> actionCopyUsername;
    QScopedPointer<QAction> actionCopyPassword;
    QScopedPointer<QAction> actionDelete;
    QScopedPointer<QAction> actionEdit;
    QScopedPointer<QAction> actionAdd;

public slots:
    void customMenuRequested(QPoint pos);
    void itemDoubleclicked(const QModelIndex &index);
    void copyPassword();
    void copyUsername();
    void deleteRow();
    void editRow();
    void deleteTable();

private: // Context menu attributes
};
#endif // MAINWINDOW_H
