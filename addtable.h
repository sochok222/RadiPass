#ifndef ADDTABLE_H
#define ADDTABLE_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>
#include <QString>
#include <QAbstractItemModel>
#include <QModelIndex>


namespace Ui {
class AddTable;
}

class AddTable : public QDialog
{
    Q_OBJECT

public:
    explicit AddTable(QWidget *parent = nullptr, QSqlDatabase *db = nullptr, std::vector<QString> *tables = nullptr);
    ~AddTable();

private slots:
    void on_addTableButton_clicked();

private:
    Ui::AddTable *ui;
    QSqlDatabase *db;
    std::vector<QString> *tables;
};

#endif // ADDTABLE_H
