#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QDialog>
#include "database.h"
#include "progressbardialog.h"

namespace Ui
{
    class MainWindowClass;
    class DatabaseProgressBar;
    class ConfirmCreateDatabase;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Database d;

    ProgressBarDialog pb_dialog;
    QDialog ccd_dialog;

    Ui::MainWindowClass *ui;
    Ui::ConfirmCreateDatabase *ccd;
    Ui::DatabaseProgressBar *pb;

public slots:
    void on_actionGenerage_Database_activated();
    void actionGenerate_Database_accepted();

private slots:
    void on_historyPushButton_clicked();
    void on_lookupPushButton_clicked();
};

#endif // MAINWINDOW_H
