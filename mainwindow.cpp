#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::configureColumns() // Showing or hiding columns in tableView according to settings
{
    // Bassically ui->tableView->setColumnHidden is false, so I don't need to set it to false if column is need to be shown
    QStringList columnTitle = settings.value("columnTitle").toStringList();
    QStringList columnUsername = settings.value("columnUsername").toStringList();
    QStringList columnPassword = settings.value("columnPassword").toStringList();
    QStringList columnURL = settings.value("columnURL").toStringList();
    QStringList columnNotes = settings.value("columnNotes").toStringList();

    ui->tableView->setColumnHidden(0,true); // Column with id of row is always hidden!

    if(columnTitle.value(0) == "shown")
        ui->tableView->setColumnHidden(1, false);
    else ui->tableView->setColumnHidden(1, true);
    if(columnTitle.value(1) == "unmasked")
        ui->tableView->setItemDelegateForColumn(1, 0);
    else ui->tableView->setItemDelegateForColumn(1, maskColumn);

    if(columnUsername.value(0) == "shown")
        ui->tableView->setColumnHidden(2, false);
    else ui->tableView->setColumnHidden(2, true);
    if(columnUsername.value(1) == "unmasked")
        ui->tableView->setItemDelegateForColumn(2, 0);
    else ui->tableView->setItemDelegateForColumn(2, maskColumn);

    if(columnPassword.value(0) == "shown")
        ui->tableView->setColumnHidden(3, false);
    else ui->tableView->setColumnHidden(3, true);
    if(columnPassword.value(1) == "unmasked")
        ui->tableView->setItemDelegateForColumn(3, 0);
    else ui->tableView->setItemDelegateForColumn(3, maskColumn);

    if(columnURL.value(0) == "shown")
        ui->tableView->setColumnHidden(4, false);
    else ui->tableView->setColumnHidden(4, true);
    if(columnURL.value(1) == "unmasked")
        ui->tableView->setItemDelegateForColumn(4, 0);
    else ui->tableView->setItemDelegateForColumn(4, maskColumn);

    if(columnNotes.value(0) == "shown")
        ui->tableView->setColumnHidden(5, false);
    else ui->tableView->setColumnHidden(5, true);
    if(columnNotes.value(1) == "unmasked")
        ui->tableView->setItemDelegateForColumn(5, 0);
    else ui->tableView->setItemDelegateForColumn(5, maskColumn);

}


MainWindow::MainWindow(QWidget *parent, QByteArray MasterKey)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << Q_FUNC_INFO; // Writing function names to see where error appears, all this messages shown in Application Output
    ui->setupUi(this);


    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);


    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)),
            SLOT(customMenuRequested(QPoint)));
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)),
            SLOT(customMenuRequested(QPoint)));
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(itemDoubleclicked(QModelIndex)));

    key = MasterKey; // Key is changed to MasterKey that passed as parameter that got from OpenDatabase
        // Default of MasterKey is ""

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Settings cells in QTableView not editable



    if(!key.isEmpty()) // If given key from database is not empty
    {
        // loadDb() loads selected database to QSqlDatabase object (&db)
        // Path to database is loaded from QSettings
        // tables is list of tables in database, loadDb() changes this list according to loaded database
        if(!DatabaseLoader::loadDb(settings.value("Last").toString(), key, &db, tables)) // Trying to load database
        {                                                                                // If not it seems that key is not right
            QMessageBox msg;                                                             // or file is broken or something else
            msg.setText("Password is uncorrect or database file is damaged\nTry again, please");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.exec(); // Showing message if can't open database
        }

        for(int i = 0; i < tables.size(); i++) // Adding tables to listWidget in screen
        {
            ui->listWidget->addItem(tables[i]);
        }
    }

    model = new QSqlTableModel(this, db); // Creating model with all tables in it
    if(tables.size() > 0) // If one or more table exists we select current first table
    {
        model->setTable(tables[0]);
    }
    model->select();
    ui->tableView->setModel(model); // Loading model to QTableView
    configureColumns();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// This function checks if file in given path exists
bool fileExists(const QString path)
{
    qDebug() << Q_FUNC_INFO;

    QFile file(path);
    if(file.exists())
        return true;
    return false;
}

void MainWindow::itemDoubleclicked(const QModelIndex &pos)
{
    qDebug() << Q_FUNC_INFO;

    if(pos.column() == 1)
    {
        copyText(pos.data().toString());
        ui->statusbar->showMessage("Title copied", 3000);
    }
    else if(pos.column() == 2)
    {
        copyText(pos.data().toString());
        ui->statusbar->showMessage("User Name copied", 3000);
    }
    else if(pos.column() == 3)
    {
        copyText(pos.data().toString());
        ui->statusbar->showMessage("Password copied", 3000);
    }
    else if(pos.column() == 4)
    {
        QDesktopServices::openUrl(QUrl(pos.data().toString()));
        ui->statusbar->showMessage("Link opened", 3000);
    }
    else if(pos.column() == 5)
    {
        copyText(pos.data().toString());
        ui->statusbar->showMessage("Notes copied", 3000);
    }
}

void MainWindow::customMenuRequested(QPoint pos){
    qDebug() << Q_FUNC_INFO;
    if(ui->tableView->indexAt(pos).isValid() && ui->tableView->underMouse()) // If mouse cursor is on tableView and on row
    {
        menu.reset(new QMenu(this)); // Resetting QMenu *menu object
        actionDelete.reset(new QAction("Delete", this)); // Resetting QAction *actionDelete object
        actionAdd.reset(new QAction("Add new", this)); // Resetting QAction *actionAdd object
        actionEdit.reset(new QAction("Edit", this)); // Resetting QAction *actionEdit object
        actionCopyPassword.reset(new QAction("Copy Password", this)); // Resetting QAction *actionCopyPass object
        actionCopyUsername.reset(new QAction("Copy User Name", this)); // Resetting QAction *actionCopyUsername object


        connect(actionCopyUsername.data(), SIGNAL(triggered()), SLOT(copyUsername()));
        connect(actionCopyPassword.data(), SIGNAL(triggered()), SLOT(copyPassword()));
        connect(actionDelete.data(), SIGNAL(triggered()), SLOT(deleteRow())); // Connecting signal of delete button to deleteRow slot
        connect(actionAdd.data(), SIGNAL(triggered()), SLOT(on_addDataButton_clicked()));
        connect(actionEdit.data(), SIGNAL(triggered()), SLOT(editRow()));


        menu->addAction(actionCopyUsername.data());
        menu->addAction(actionCopyPassword.data());
        menu->addAction(actionDelete.data());
        menu->addAction(actionAdd.data());
        menu->addAction(actionEdit.data());
        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
    }else if(ui->tableView->underMouse()) {
        menu.reset(new QMenu(this)); // Resetting QMenu *menu object
        actionDelete.reset(new QAction("Delete", this)); // Resetting QAction *actionDelete object
        actionAdd.reset(new QAction("Add new", this)); // Resetting QAction *actionAdd object
        actionEdit.reset(new QAction("Edit", this)); // Resetting QAction *actionEdit object
        actionCopyPassword.reset(new QAction("Copy Password", this)); // Resetting QAction *actionCopyPass object
        actionCopyUsername.reset(new QAction("Copy User Name", this)); // Resetting QAction *actionCopyUsername object
        actionCopyUsername->setDisabled(true);
        actionCopyPassword->setDisabled(true);
        actionDelete->setDisabled(true);
        actionEdit->setDisabled(true);

        connect(actionAdd.data(), SIGNAL(triggered()), SLOT(on_addDataButton_clicked()));

        menu->addAction(actionCopyUsername.data());
        menu->addAction(actionCopyPassword.data());
        menu->addAction(actionDelete.data());
        menu->addAction(actionAdd.data());
        menu->addAction(actionEdit.data());
        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
    }else if(ui->listWidget->indexAt(pos).isValid() && ui->listWidget->underMouse()) // If mouse cursor is at listWidget and not on tableView
    {
        menu.reset(new QMenu(this));
        actionDelete.reset(new QAction("Delete", this));
        actionAdd.reset(new QAction("Add Table", this));

        connect(actionDelete.data(), SIGNAL(triggered()), SLOT(deleteTable()));
        connect(actionAdd.data(), SIGNAL(triggered()), SLOT(on_addTableButton_clicked()));

        menu->addAction(actionDelete.data());
        menu->addAction(actionAdd.data());
        menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
    }else if(ui->listWidget->underMouse())
    {
        menu.reset(new QMenu(this));
        actionDelete.reset(new QAction("Delete", this));
        actionAdd.reset(new QAction("Add Table", this));
        actionDelete->setDisabled(true);

        connect(actionDelete.data(), SIGNAL(triggered()), SLOT(deleteTable()));
        connect(actionAdd.data(), SIGNAL(triggered()), SLOT(on_addTableButton_clicked()));

        menu->addAction(actionDelete.data());
        menu->addAction(actionAdd.data());
        menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
    }
}

void MainWindow::copyUsername()
{
    qDebug() << Q_FUNC_INFO;
    QSqlQuery query(db);
    QString getId = QString("SELECT id FROM %1 LIMIT 1 OFFSET %2").arg(model->tableName()).arg(ui->tableView->currentIndex().row());
    query.prepare(getId);
    if(!query.exec())
    {
        QMessageBox msg;
        msg.setText("Can't get row id");
        msg.setInformativeText("Query error: " + query.lastError().text());
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }
    query.next();
    QString id = query.value(0).toString();

    query.prepare("SELECT [User Name] FROM "+model->tableName()+" WHERE id == "+id);
    if(!query.exec())
    {
        QMessageBox msg;
        msg.setText("Can't get data from database");
        msg.setInformativeText("Query error: " + query.lastError().text());
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }
    query.next();

    copyText(query.value(0).toString());
}


void MainWindow::copyText(const QString text)
{
    qDebug() << Q_FUNC_INFO;
    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED, 64);

    std::string str = text.toStdString();
    const char* st = str.c_str();

    strcpy_s((char*)hGlob, 64, st);
    SetClipboardData(CF_TEXT, hGlob);
    CloseClipboard();
}


void MainWindow::copyPassword()
{
    qDebug() << Q_FUNC_INFO;
    QSqlQuery query(db);
    QString getId = QString("SELECT id FROM %1 LIMIT 1 OFFSET %2").arg(model->tableName()).arg(ui->tableView->currentIndex().row());
    query.prepare(getId);
    if(!query.exec())
    {
        QMessageBox msg;
        msg.setText("Can't get row id");
        msg.setInformativeText("Query error: " + query.lastError().text());
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }
    query.next();
    QString id = query.value(0).toString();

    query.prepare("SELECT [Password] FROM "+model->tableName()+" WHERE id == "+id);
    if(!query.exec())
    {
        QMessageBox msg;
        msg.setText("Can't get row id");
        msg.setInformativeText("Query error: " + query.lastError().text());
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }
    query.next();

    copyText(query.value(0).toString());
}

void MainWindow::editRow()
{
    qDebug() << Q_FUNC_INFO;
    EditEntry *editEntry = new EditEntry(this, ui->tableView, &db, model);
    editEntry->exec();
    delete editEntry;
    isChanged = true;
    model->select();
    ui->tableView->update();
}

void MainWindow::deleteTable()
{
    qDebug() << Q_FUNC_INFO;
    int index = ui->listWidget->currentIndex().row();

    QMessageBox::StandardButton question = QMessageBox::question(
        this, "RadiPass", "Delete Table?",
        QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes); // Creates MessageBox with buttons
    // If user clicks
    // Yes - delete row
    // No - do nothing
    if(question == QMessageBox::Yes)
    {
        if(tables.size() != 1)
        {
            if(DatabaseLoader::deleteTable(&db, ui->listWidget->item(index)->text()))
            {
                isChanged = true;
                tables.erase(tables.begin() + index);
                ui->listWidget->takeItem(index);
                model->setTable(tables[tables.size() - 1]);
                model->select();
                ui->tableView->update();
                configureColumns();
            }else
            {
                QMessageBox msg;
                msg.setText("Can`t delete this table");
                msg.button(QMessageBox::Ok);
                msg.exec();
            }
        }else {
            QMessageBox::StandardButton information = QMessageBox::information(this, "RadiPass", "At least one table must exists",
                                                                               QMessageBox::Ok, QMessageBox::Ok);
        }
    }
}

void MainWindow::deleteRow()
{
    qDebug() << Q_FUNC_INFO;
    int index = ui->tableView->currentIndex().row();

    QMessageBox::StandardButton question = QMessageBox::question(
        this, "RadiPass", "Delete row?",
        QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes); // Creates MessageBox with buttons
    // If user clicks
    // Yes - delete row
    // No - do nothing
    if(question == QMessageBox::Yes)
    {
        model->removeRow(index);
        model->select();
        ui->tableView->setModel(model);
        isChanged = true;
    }
}



/// When user hits "Add data" button this function executes
void MainWindow::on_addDataButton_clicked()
{
    qDebug() << Q_FUNC_INFO; // Writing function names to see where error appears, all this messages shown in Application Output

    isChanged = true; // If user do some changes needs to change this state to true to ask if save changes on exit

    AddPasswordDialog *dialog = new AddPasswordDialog(this, db, model->tableName()); // Create dialog that will add row to table
    dialog->exec();    // Showing dialog
    delete dialog;

    // Updating QSqlModel and QTableView to see changes
    model->setTable(model->tableName());
    model->select();
    ui->tableView->update();
    configureColumns();
}

/// If user selects another table this function executes
void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    qDebug() << Q_FUNC_INFO; // Writing function names to see where error appears, all this messages shown in Application Output

    // Updating QSqlModel and QTableView to see selected table
    model->setTable(currentText);
    model->select();
    ui->tableView->setModel(model);
    configureColumns();
}

// If user hits "Add table" button this function executes
void MainWindow::on_addTableButton_clicked()
{
    qDebug() << Q_FUNC_INFO; // Writing function names to see where error appears, all this messages shown in Application Output

    isChanged = true; // If user do some changes needs to change this state to true to ask if save changes on exit

    AddTable *addTable = new AddTable(this, &db, &tables); // This dialog will create new table in QSqlDatabase object and append new table to tables list
    addTable->exec(); // Showing dialog
    delete addTable;

    if(ui->listWidget->count() != tables.size()) // If current ListWidget size has lower value than tables this means that user added new table
    {
        ui->listWidget->clear(); // Clearing list of tables
        for(int i = 0; i < tables.size(); i++) // Adding lists to QListWidget
        {
            ui->listWidget->addItem(tables[i]);
        }
        ui->listWidget->setCurrentRow(tables.size()-1);

        // Selecting last table (this is table that user added)
        model->setTable(tables[tables.size() - 1]);
        model->select();
        ui->tableView->setModel(model);
        configureColumns();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << Q_FUNC_INFO;
    isChanged = true;
    QString file = QFileDialog::getOpenFileName(this, "Open encrypted database",
                                                QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), "*.db");
    if(!file.isEmpty())
    {
        OpenDatabase *openDb = new OpenDatabase(this, &key);
        openDb->exec();
    }

    if (!key.isEmpty())
    {
        if(!DatabaseLoader::loadDb(file, key, &db, tables))
        {
            QMessageBox msg;
            msg.setText("Password is uncorrect");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.exec();
        }
        settings.setValue("Last", file);
        ui->listWidget->clear();
        for(int i = 0; i < tables.size(); i++)
        {
            ui->listWidget->addItem(tables[i]);
        }
        model->setTable(tables[tables.size() - 1]);
        model->select();
    }
}


void MainWindow::on_actionNew_triggered()
{
    QString databasePath = QFileDialog::getSaveFileName(this, "Create new database",
                                                        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), "*.db");
    isChanged = true;
    CreateDatabase *createNew = new CreateDatabase(this, &key);
    createNew->exec();
    delete createNew;
    if(key != "")
    {
        if(!DatabaseLoader::createAndFillDatabase(databasePath, key, &db))
        {
            QMessageBox msg;
            msg.setText("Can't create new database");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.exec();
        }
        DatabaseLoader::loadDb(databasePath, key, &db, tables);
        settings.setValue("Last", databasePath);
        ui->listWidget->clear();
        for(int i = 0; i < tables.size(); i++)
        {
            ui->listWidget->addItem(tables[i]);
        }
        model->setTable(tables[tables.size() - 1]);
        model->select();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isChanged)
    {
        QMessageBox::StandardButton question = QMessageBox::question(
            this, "RadiPass", "Save changes?",
            QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes); // Creates MessageBox with buttons
        // If user clicks
        // Yes - must save changes
        // No - do not save changes
        // Cancel - do not close program
        if(question == QMessageBox::Yes)
        {
            qDebug() << "Clicked yes";
            DatabaseLoader::uploadDb(settings.value("Last").toString(), key, &db);
            event->accept();
        }else if(question == QMessageBox::No)
        {
            qDebug() << "Clicked no";
            event->accept();
        }else if(question == QMessageBox::Cancel)
        {
            qDebug() << "Clicked cancel";
            event->ignore();
        }
    }
}

void MainWindow::on_configureColumnsButton_clicked()
{
    ConfigureColumns *cfgColumns = new ConfigureColumns(this);
    cfgColumns->exec();
    delete cfgColumns;
    configureColumns();
}

