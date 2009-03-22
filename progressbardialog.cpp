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

void ProgressBarDialog::database_complete() {
  complete = true;
  close();
}
