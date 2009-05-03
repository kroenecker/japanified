#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_confirm_create_database.h"
#include "ui_progressbar.h"
#include "ui_history.h"
#include "ui_deletehistory.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
  ui(new Ui::MainWindowClass),
  ccd(new Ui::ConfirmCreateDatabase),
  pb(new Ui::DatabaseProgressBar),
  hd(new Ui::HistoryDialog),
  history_delete_dialog(new Ui::DeleteHistory)
{
  ui->setupUi(this);
  ccd->setupUi(&ccd_dialog);
  pb->setupUi(&pb_dialog);
  hd->setupUi(&hd_dialog);
  history_delete_dialog->setupUi(&hdelete_dialog);

  ui->historyListView->setModel(&h);

  ui->lookupPushButton->setAutoDefault(true);

  QObject::connect(&ccd_dialog, SIGNAL(accepted()), this, SLOT(actionGenerateDatabaseAccepted()));
  QObject::connect(&hd_dialog, SIGNAL(accepted()), this, SLOT(saveHistory()));
  QObject::connect(&hdelete_dialog, SIGNAL(accepted()), this, SLOT(deleteHistory()));

  QObject::connect(&d.thread, SIGNAL(progress(int)), pb->progressBar, SLOT(setValue(int)));
  QObject::connect(&d.thread, SIGNAL(finished()), &pb_dialog, SLOT(databaseComplete()));

  QObject::connect(ui->lookupTableWidget, SIGNAL(cellDoubleClicked (int, int)), this, SLOT(addHistory(int, int)));
  QObject::connect(ui->historyListView, SIGNAL(clicked(QModelIndex)), this, SLOT(showHistoryIndex(QModelIndex)));
  QObject::connect(ui->historyComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(showHistory(int)));

  fillHistory();
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

void MainWindow::showHistory(int index)
{
  h.clear();
  if(index == 0) {
    ui->deleteHistoryPushButton->setEnabled(false);
  } else {
    ui->deleteHistoryPushButton->setEnabled(true);

    int history_id            = ui->historyComboBox->itemData(index, Qt::UserRole).toInt();
    QList<Edict*> edict_words = d.selectHistoryEdictWords(history_id);
    foreach(Edict* edict, edict_words) {
      Edict e;
      e.id          = edict->id;
      e.word        = edict->word;
      e.reading     = edict->reading;
      e.definitions = edict->definitions;
      h.addWord(e);
    }
  }
}

void MainWindow::showHistoryIndex(QModelIndex index)
{
  QList<Edict *> e;
  Edict *ep = new Edict(h.getEdict(index.row()));
  e.append(ep);
  fillLookupTableWidget(e);
}

void MainWindow::fillHistory()
{
  ui->historyComboBox->clear();
  QList<History*> history = d.selectHistory();
  foreach(History* i, history) {
    ui->historyComboBox->addItem(i->title, i->id);
  }
}

void MainWindow::saveHistory()
{
  hd_dialog.hide();
  History history = d.insertHistory(hd->historyTitleLineEdit->text());
  saveHistoryEdictWords(history.id);
  fillHistory();
  ui->historyComboBox->setCurrentIndex(ui->historyComboBox->count() - 1);
  showHistory(ui->historyComboBox->currentIndex());
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

void MainWindow::saveHistoryEdictWords(int history_id)
{
  int count = h.rowCount(QModelIndex());
  for(int i = 0; i < count; i++) {
    Edict e = h.getEdict(i);
    d.insertHistoryEdictWord(history_id, e.id);
  }
}

void MainWindow::on_saveHistoryPushButton_clicked()
{
  if(ui->historyComboBox->currentIndex() == 0) {
    hd_dialog.show();
  } else {
    int history_id = ui->historyComboBox->itemData(ui->historyComboBox->currentIndex()).toInt();
    saveHistoryEdictWords(history_id);
  }
}

void MainWindow::deleteHistory()
{
  if(ui->historyComboBox->currentIndex() > 0) {
    int history_id = ui->historyComboBox->itemData(ui->historyComboBox->currentIndex()).toInt();
    d.deleteHistory(history_id);
    fillHistory();
  }
}

void MainWindow::on_deleteHistoryPushButton_clicked()
{
  history_delete_dialog->historyTitleLabel->setText("Are you sure you want to delete " + ui->historyComboBox->currentText() + "?");
  hdelete_dialog.show();
}
