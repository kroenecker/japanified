#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_confirm_create_database.h"
#include "ui_progressbar.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindowClass), ccd(new Ui::ConfirmCreateDatabase), pb(new Ui::DatabaseProgressBar)
{
  ui->setupUi(this);
  ccd->setupUi(&ccd_dialog);
  pb->setupUi(&pb_dialog);

  ui->historyListView->setModel(&h);

  QObject::connect(&ccd_dialog, SIGNAL(accepted()), this, SLOT(actionGenerate_Database_accepted()));
  QObject::connect(&d.thread, SIGNAL(progress(int)), pb->progressBar, SLOT(setValue(int)));
  QObject::connect(&d.thread, SIGNAL(finished()), &pb_dialog, SLOT(database_complete()));
  QObject::connect(ui->lookupTableWidget, SIGNAL(cellDoubleClicked (int, int)), this, SLOT(add_history(int, int)));
}

MainWindow::~MainWindow()
{
  delete ccd;
  delete pb;
  delete ui;
}

void MainWindow::on_actionGenerage_Database_activated()
{
  ccd_dialog.show();
}

void MainWindow::actionGenerate_Database_accepted()
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

    QTableWidgetItem *i3 = new QTableWidgetItem(word->definitions.join(" ;"));
    ui->lookupTableWidget->setItem(counter, 3, i3);
    
    counter++;
  }
}

void MainWindow::add_history(int row, int column)
{
    QModelIndex i = ui->lookupTableWidget->indexAt(QPoint(row,column));
    Edict e;
    e.id          = i.sibling(row, 0).data(Qt::DisplayRole).toInt();
    e.word        = i.sibling(row, 1).data(Qt::DisplayRole).toString();
    e.reading     = i.sibling(row, 2).data(Qt::DisplayRole).toString();
    e.definitions = i.sibling(row, 3).data(Qt::DisplayRole).toString().split(" ;");
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
