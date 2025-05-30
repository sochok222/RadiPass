#ifndef EDITTABLE_H
#define EDITTABLE_H

#include <QDialog>
#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QIcon>
#include <QTranslator>
#include <QSqlDatabase>
#include <QListWidget>
#include <QSqlQuery>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <QStandardItemModel>
#include <QDataWidgetMapper>
#include <QStandardPaths>
#include <QDirIterator>
#include <QStandardItem>

namespace Ui {
class EditTable;
}

class EditTable : public QDialog
{
    Q_OBJECT

public:
    explicit EditTable(QWidget *parent = nullptr, QSqlDatabase *db = nullptr, const QString tableName = "", QListWidget *listWidget = nullptr, QString theme = "");
    ~EditTable();

private:
    Ui::EditTable *ui;
    void closeEvent(QCloseEvent *event) override;
    QSqlDatabase *db;
    QVector<QString> iconNames = {"entry", "trash", "key", "url", "user", "settings", "bitcoin", "card", "game", "house", "money", "net", "office", "pc", "programming"};
    bool isNameChanged = false;
    bool isIconChanged = false;
    void saveChanges();
    QString tableName;
    QListWidget *listWidget;
    void loadIcons();
    void showMsgBox(const QString text);
    QStandardItemModel *model;
    QDataWidgetMapper *mapper;
    QString theme;

public slots:
    void iconChanged() {isIconChanged = true;};
    void textChanged() {isNameChanged = true;};
    void setConnections();
private slots:
    void on_addTableButton_clicked();
    void on_buttonCancel_clicked();
};



#endif // EDITTABLE_H
