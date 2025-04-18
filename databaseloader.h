#ifndef DATABASELOADER_H
#define DATABASELOADER_H

#include <QtSql/QSqlDatabase>
#include <qsqltablemodel.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QTemporaryFile>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <QMessageBox>
#include <QTableView>
#include <QString>
#include <QDebug>
#include <QFile>

class DatabaseLoader
{
public:
    DatabaseLoader();

    static bool getRowId(QSqlTableModel *model, QTableView *tableView, QSqlDatabase *db, int &rowId);

    static bool loadDb(const QString encryptedDatabase, QByteArray &key, QSqlDatabase *db, std::vector<QString> &tables);
    static bool loadTemporaryDatabase(QSqlDatabase &db, QString &path, std::vector<QString> &tables);
    static bool hideData(QSqlTableModel *model, QTableView *tableView);
    static bool createAndFillDatabase(const QString databasePath, QByteArray &key, QSqlDatabase *db);
    static bool uploadDb(const QString encryptedDatabase, QByteArray &key, QSqlDatabase *db);
    static bool deleteTable(QSqlDatabase *db, const QString tablename);
    static QByteArray* decryptData(QByteArray *encryptedData, const QByteArray &key);
    static QByteArray* encryptData(QByteArray *data, const QByteArray &key);
    static bool checkMasterKey(QByteArray &masterKey);
    template<typename T>
    static bool deleteTemporaryFile(T &file);

private:
    void handleError(const QString &errorMessage);
};

#endif // DATABASELOADER_H
