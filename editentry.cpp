#include "editentry.h"
#include "ui_editentry.h"
#include <qsqlerror.h>

EditEntry::EditEntry(QWidget *parent, QTableView *tableView, QSqlDatabase *db, QSqlTableModel *model)
    : QDialog(parent)
    , ui(new Ui::EditEntry)
    , tableView(tableView)
    , db(db)
    , model(model)
{
    ui->setupUi(this);
    setup();
}

EditEntry::~EditEntry()
{
    delete ui;
}

void EditEntry::setup()
{
    if(tableView == nullptr || db == nullptr)
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Something went wrong");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    QSqlQuery query(*db);

    QString table = model->tableName();
    QString getId = QString("SELECT id FROM %1 LIMIT 1 OFFSET %2").arg(table).arg(tableView->currentIndex().row());

    if(!query.exec(getId))
    {
        QMessageBox msg;
        msg.setInformativeText("Can't load data from database");
        msg.setText("Try again, please");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
        this->close();
    }
    QString id;
    if(query.next())
        id = query.value(0).toString();

    QString loadData = QString("SELECT * FROM %1 WHERE id = %2").arg(table).arg(id);
    if(!query.exec(loadData))
    {
        QMessageBox msg;
        msg.setInformativeText("Can't load data from database");
        msg.setText("Try again, please");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
        this->close();
    }
    if(query.next())
    {
        ui->title->setText(query.value(1).toString());
        ui->username->setText(query.value(2).toString());
        ui->password->setText(query.value(3).toString());
        ui->url->setText(query.value(4).toString());
        ui->notes->setText(query.value(5).toString());
    }
}

bool EditEntry::atLeastOneNotEmpty()
{
    if(!ui->title->text().isEmpty() || !ui->username->text().isEmpty() || !ui->password->text().isEmpty() || !ui->url->text().isEmpty() || !ui->notes->toPlainText().isEmpty())
        return true;
    return false;
}


void EditEntry::on_writeButton_clicked()
{
    if(atLeastOneNotEmpty())
    {
        QSqlQuery query(*db);
        QString table = model->tableName();

        QString getId = QString("SELECT id FROM %1 LIMIT 1 OFFSET %2").arg(table).arg(tableView->currentIndex().row());
        query.prepare(getId);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
        query.next();
        QString id = query.value(0).toString();

        QString statements[] = {QString("UPDATE "+table+" SET Title='%1' WHERE id == "+id).arg(ui->title->text()),
                                QString("UPDATE "+table+" SET [User Name]='%1' WHERE id == "+id).arg(ui->username->text()),
                                QString("UPDATE "+table+" SET Password='%1' WHERE id == "+id).arg(ui->password->text()),
                                QString("UPDATE "+table+" SET URL='%1' WHERE id == "+id).arg(ui->url->text()),
                                QString("UPDATE "+table+" SET Notes='%1' WHERE id == "+id).arg(ui->notes->toPlainText()),};

        for(QString &statement : statements)
        {
            if(!query.exec(statement))
            {
                QMessageBox msg;
                msg.setText("Can't edit this row");
                msg.setStandardButtons(QMessageBox::Ok);
                msg.exec();
                break;
            }
        }
        this->destroy();
    }else{
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setText("At least one field must not be empty");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}
