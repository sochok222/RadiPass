#include "opendatabase.h"
#include "ui_opendatabase.h"

OpenDatabase::OpenDatabase(QWidget *parent, QByteArray *result)
    : QDialog(parent)
    , ui(new Ui::OpenDatabase)
{
    ui->setupUi(this);
    ui->databasePathLabel->setText(settings.value("Last").toString());
    masterPassword = result;
    QSettings setting("AlexRadik", "RadiPass");
}

OpenDatabase::~OpenDatabase()
{
    delete ui;
}



void OpenDatabase::on_okButton_clicked()
{
    if(ui->passwordLine->text().size() > 0)
    {
        *masterPassword = ui->passwordLine->text().toUtf8();
        this->close();
    }else {
        ui->passwordCheckLabel->setText("Password line must be not null");
    }
}


void OpenDatabase::on_cancelButton_clicked()
{
    settings.setValue("Last", "");
    this->destroy(true,true);
}

