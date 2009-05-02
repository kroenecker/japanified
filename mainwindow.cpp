#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_confirm_create_database.h"
#include "ui_progressbar.h"
#include "ui_history.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), ccd(new Ui::ConfirmCreateDatabase), pb(new Ui::DatabaseProgressBar), hd(new Ui::HistoryDialog)
{
    ui->setupUi(this);
    ccd->setupUi(&ccd_dialog);
    pb->setupUi(&pb_dialog);

    ui->historyListView->setModel(&h);

    ui->lookupPushButton->setAutoDefault(true);

    QObject::connect(&ccd_dialog, SIGNAL(accepted()), this, SLOT(actionGenerateDatabaseAccepted()));
    QObject::connect(&d.thread, SIGNAL(progress(int)), pb->progressBar, SLOT(setValue(int)));
    QObject::connect(&d.thread, SIGNAL(finished()), &pb_dialog, SLOT(databaseComplete()));
    QObject::connect(ui->lookupTableWidget, SIGNAL(cellDoubleClicked (int, int)), this, SLOT(addHistory(int, int)));
    QObject::connect(ui->historyListView, SIGNAL(clicked(QModelIndex)), this, SLOT(showHistoryIndex(QModelIndex)));

    QList<History*> history = d.selectHistory();
    foreach(History* i, history) {
      ui->historyComboBox->addItem(i->title, i->id);
    }
}

MainWindow::~MainWindow()
{
    delete hd;
    delete ccd;
    delete pb;
    delete ui;
}

void MainWindow::on_actionGenerateDatabase_activated()
{
    ccd_dialog.show();
}

void MainWindow::actionGenerateDatabaseAccepted()
{
    pb_dialog.show();
    d.fill();
}

void MainWindow::on_lookupPushButton_clicked()
{
    QList<Edict *> e;
    if(ui->exactRadioButton->isChecked()) {
        e = d.lookup(c.romajiToJapanese(ui->lookupLineEdit->text()), EXACT);
    } else if(ui->beginningRadioButton->isChecked()) {
        e = d.lookup(c.romajiToJapanese(ui->lookupLineEdit->text()), BEGIN);
    } else if(ui->middleRadioButton->isChecked()) {
        e = d.lookup(c.romajiToJapanese(ui->lookupLineEdit->text()), MIDDLE);
    } else if(ui->endRadioButton->isChecked()) {
        e = d.lookup(c.romajiToJapanese(ui->lookupLineEdit->text()), END);
    }
    fillLookupTableWidget(e);
}

void MainWindow::fillLookupTableWidget(QList<Edict *> e)
{
    ui->lookupTableWidget->clear();
    ui->lookupTableWidget->setColumnCount(4);

    QStringList headerNames;
    headerNames << "id" << "Word" << "Reading" << "Definition";
    ui->lookupTableWidget->setHorizontalHeaderLabels(headerNames);
    ui->lookupTableWidget->hideColumn(0);
    ui->lookupTableWidget->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);
    ui->lookupTableWidget->setRowCount(e.length());

    int counter = 0;
    foreach(Edict *word, e) {
        QTableWidgetItem *i0 = new QTableWidgetItem(QString::number(word->id));
        i0->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->lookupTableWidget->setItem(counter, 0, i0);

        QTableWidgetItem *i1 = new QTableWidgetItem(word->word);
        i1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->lookupTableWidget->setItem(counter, 1, i1);

        QTableWidgetItem *i2 = new QTableWidgetItem(word->reading);
        i2->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->lookupTableWidget->setItem(counter, 2, i2);

        QTableWidgetItem *i3 = new QTableWidgetItem(word->definitions.join("; "));
        i3->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->lookupTableWidget->setItem(counter, 3, i3);

        counter++;
    }
    ui->lookupLineEdit->setFocus();
}

void MainWindow::showHistoryIndex(QModelIndex index)
{
    QList<Edict *> e;
    Edict *ep = new Edict(h.getEdict(index.row()));
    e.append(ep);
    fillLookupTableWidget(e);
}

void MainWindow::addHistory(int row, int column)
{
    QModelIndex i = ui->lookupTableWidget->indexAt(QPoint(row,column));
    Edict e;
    e.id          = i.sibling(row, 0).data(Qt::DisplayRole).toInt();
    e.word        = i.sibling(row, 1).data(Qt::DisplayRole).toString();
    e.reading     = i.sibling(row, 2).data(Qt::DisplayRole).toString();
    e.definitions = i.sibling(row, 3).data(Qt::DisplayRole).toString().split("; ");
    h.addWord(e);
}

void MainWindow::on_historyPushButton_clicked()
{
    if(ui->dockWidget->isHidden()) {
        ui->dockWidget->show();
    } else {
        ui->dockWidget->hide();
    }
}
