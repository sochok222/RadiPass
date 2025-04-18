#include "createdatabase.h"
#include "ui_createdatabase.h"

CreateDatabase::CreateDatabase(QWidget *parent, QByteArray *masterPassword)
    : QDialog(parent)
    , ui(new Ui::CreateDatabase)
{
    ui->setupUi(this);
    ui->masterPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->repeatMasterPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    key = masterPassword;
}

CreateDatabase::~CreateDatabase()
{
    delete ui;
}



void CreateDatabase::on_saveButton_clicked()
{
    QString pass = ui->masterPassword->text();
    if(pass == ui->repeatMasterPassword->text() && ui->passState->text() != "Password is too Long" && ui->passState->text() != "Password can't be empty")
    {
        *key = ui->masterPassword->text().toUtf8();
        delete this;
    }
}


void CreateDatabase::on_masterPassword_textChanged(const QString &arg1)
{
    if(arg1.size() > 8 && arg1.size() < 32 && arg1.size() != 0)
    {
        ui->passState->setText("");
    }
    if(arg1.size() < 8)
    {
        ui->passState->setText("Password is too weak");
    }else if(arg1.size() > 32)
    {
        ui->passState->setText("Password is too Long");
    }
    else if(arg1.size() == 0)
    {
        ui->passState->setText("Password can't be empty");
    }
}

