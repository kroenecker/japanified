#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_confirm_create_database.h"
#include "ui_progressbar.h"
#include "ui_history.h"
#include "ui_deletehistory.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
  ui(new Ui::MainWindowClass),
  p_confirm_create_database_dialog(new Ui::ConfirmCreateDatabase),
  p_progress_bar_dialog(new Ui::DatabaseProgressBar),
  p_new_history_dialog(new Ui::HistoryDialog),
  p_delete_history_dialog(new Ui::DeleteHistory)
{
  ui->setupUi(this);
  p_confirm_create_database_dialog->setupUi(&confirm_create_database_dialog);
  p_progress_bar_dialog->setupUi(&progress_bar_dialog);
  p_new_history_dialog->setupUi(&new_history_dialog);
  p_delete_history_dialog->setupUi(&delete_history_dialog);

  ui->historyListView->setModel(&history_model);

  ui->lookupPushButton->setAutoDefault(true);

  QObject::connect(&confirm_create_database_dialog, SIGNAL(accepted()), this, SLOT(actionGenerateDatabaseAccepted()));
  QObject::connect(&new_history_dialog, SIGNAL(accepted()), this, SLOT(newHistory()));
  QObject::connect(&new_history_dialog, SIGNAL(rejected()), this, SLOT(historyRejected()));
  QObject::connect(&delete_history_dialog, SIGNAL(accepted()), this, SLOT(deleteHistory()));

  QObject::connect(&database.thread, SIGNAL(progress(int)), p_progress_bar_dialog->progressBar, SLOT(setValue(int)));
  QObject::connect(&database.thread, SIGNAL(finished()), &progress_bar_dialog, SLOT(databaseComplete()));

  QObject::connect(ui->lookupTableWidget, SIGNAL(cellDoubleClicked (int, int)), this, SLOT(addHistory(int, int)));
  QObject::connect(ui->historyListView, SIGNAL(clicked(QModelIndex)), this, SLOT(showHistoryIndex(QModelIndex)));
  QObject::connect(ui->historyComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(showHistory(int)));

  fillHistoryComboBox();
}

MainWindow::~MainWindow()
{
  delete p_delete_history_dialog;
  delete p_new_history_dialog;
  delete p_confirm_create_database_dialog;
  delete p_progress_bar_dialog;
  delete ui;
}

void MainWindow::on_actionGenerateDatabase_activated()
{
  confirm_create_database_dialog.show();
}

void MainWindow::actionGenerateDatabaseAccepted()
{
  progress_bar_dialog.show();
  database.fill();
}

void MainWindow::on_lookupPushButton_clicked()
{
  QList<Edict *> e;
  if(ui->exactRadioButton->isChecked()) {
    e = database.lookup(convert.romajiToJapanese(ui->lookupLineEdit->text()), EXACT);
  } else if(ui->beginningRadioButton->isChecked()) {
    e = database.lookup(convert.romajiToJapanese(ui->lookupLineEdit->text()), BEGIN);
  } else if(ui->middleRadioButton->isChecked()) {
    e = database.lookup(convert.romajiToJapanese(ui->lookupLineEdit->text()), MIDDLE);
  } else if(ui->endRadioButton->isChecked()) {
    e = database.lookup(convert.romajiToJapanese(ui->lookupLineEdit->text()), END);
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

//---------------------------------------- History ----------------------------------------
void MainWindow::showHistory(int index)
{
  history_model.clear();
  if(index == 0) {
    ui->deleteHistoryPushButton->setEnabled(false);
  } else {
    ui->deleteHistoryPushButton->setEnabled(true);

    int history_id            = ui->historyComboBox->itemData(index, Qt::UserRole).toInt();
    QList<Edict*> edict_words = database.selectHistoryEdictWords(history_id);
    foreach(Edict* edict, edict_words) {
      Edict e;
      e.id          = edict->id;
      e.word        = edict->word;
      e.reading     = edict->reading;
      e.definitions = edict->definitions;
      history_model.addWord(e);
    }
  }
}

void MainWindow::showHistoryIndex(QModelIndex index)
{
  QList<Edict *> e;
  Edict *ep = new Edict(history_model.getEdict(index.row()));
  e.append(ep);
  fillLookupTableWidget(e);
}

void MainWindow::fillHistoryComboBox()
{
  ui->historyComboBox->clear();
  QList<History*> history = database.selectHistory();
  foreach(History* i, history) {
    ui->historyComboBox->addItem(i->title, i->id);
  }
}

void MainWindow::newHistory()
{
  new_history_dialog.hide();
  History history = database.insertHistory(p_new_history_dialog->historyTitleLineEdit->text());
  if(ui->historyComboBox->currentIndex() == 0) {
    newHistoryEdictWords(history.id);
  }

  fillHistoryComboBox();
  ui->historyComboBox->setCurrentIndex(ui->historyComboBox->count() - 1);
  showHistory(ui->historyComboBox->currentIndex());
  ui->newHistoryPushButton->setDisabled(false);
}

void MainWindow::addHistory(int row, int column)
{
  QModelIndex i = ui->lookupTableWidget->indexAt(QPoint(row,column));
  Edict e;
  e.id          = i.sibling(row, 0).data(Qt::DisplayRole).toInt();
  e.word        = i.sibling(row, 1).data(Qt::DisplayRole).toString();
  e.reading     = i.sibling(row, 2).data(Qt::DisplayRole).toString();
  e.definitions = i.sibling(row, 3).data(Qt::DisplayRole).toString().split("; ");
  history_model.addWord(e);

  int history_id = ui->historyComboBox->itemData(ui->historyComboBox->currentIndex()).toInt();
  newHistoryEdictWords(history_id);
}

void MainWindow::on_historyPushButton_clicked()
{
  if(ui->dockWidget->isHidden()) {
    ui->dockWidget->show();
  } else {
    ui->dockWidget->hide();
  }
}

void MainWindow::newHistoryEdictWords(int history_id)
{
  int count = history_model.rowCount(QModelIndex());
  for(int i = 0; i < count; i++) {
    Edict e = history_model.getEdict(i);
    database.insertHistoryEdictWord(history_id, e.id);
  }
}

void MainWindow::deleteHistory()
{
  if(ui->historyComboBox->currentIndex() > 0) {
    int history_id = ui->historyComboBox->itemData(ui->historyComboBox->currentIndex()).toInt();
    database.deleteHistory(history_id);
    fillHistoryComboBox();
  }
}

void MainWindow::on_deleteHistoryPushButton_clicked()
{
  p_delete_history_dialog->historyTitleLabel->setText("Are you sure you want to delete " + ui->historyComboBox->currentText() + "?");
  delete_history_dialog.show();
}

void MainWindow::on_newHistoryPushButton_clicked()
{  
  ui->newHistoryPushButton->setDisabled(true);
  new_history_dialog.show();
}


void MainWindow::historyRejected()
{
  ui->newHistoryPushButton->setDisabled(false);
}
