#ifndef PROGRESSBARDIALOG_H
#define PROGRESSBARDIALOG_H

#include <QDialog>

class ProgressBarDialog : public QDialog
{
  Q_OBJECT

  public:
    ProgressBarDialog();
    void closeEvent(QCloseEvent *e);

  public slots:
    void database_complete();

  private:
    bool complete;
};

#endif // PROGRESSBARDIALOG_H
