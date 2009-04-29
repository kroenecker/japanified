#include <QCloseEvent>
#include "progressbardialog.h"

ProgressBarDialog::ProgressBarDialog()
:complete(false)
{
}

void ProgressBarDialog::closeEvent(QCloseEvent *e) {
  if(complete) {
    complete = false;
    e->accept();
  } else {
    e->ignore();
  }
}

void ProgressBarDialog::databaseComplete() {
  complete = true;
  close();
}
