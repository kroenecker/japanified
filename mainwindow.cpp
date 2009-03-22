#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_confirm_create_database.h"
#include "ui_progressbar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), ccd(new Ui::ConfirmCreateDatabase), pb(new Ui::DatabaseProgressBar)
{
  ui->setupUi(this);
  ccd->setupUi(&ccd_dialog);
  pb->setupUi(&pb_dialog);

  QObject::connect(&ccd_dialog, SIGNAL(accepted()), this, SLOT(actionGenerate_Database_accepted()));
  QObject::connect(&d.thread, SIGNAL(progress(int)), pb->progressBar, SLOT(setValue(int)));
  QObject::connect(&d.thread, SIGNAL(finished()), &pb_dialog, SLOT(database_complete()));
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

void MainWindow::actionGenerate_Database_accepted() {
  pb_dialog.show();
  d.fill();
}
