#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QDialog>
#include "convert.h"
#include "database.h"
#include "progressbardialog.h"
#include "historylistmodel.h"

namespace Ui
{
    class MainWindowClass;
    class DatabaseProgressBar;
    class ConfirmCreateDatabase;
    class HistoryDialog;
    class DeleteHistory;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Convert c;
    Database d;
    HistoryListModel h;

    ProgressBarDialog pb_dialog;
    QDialog ccd_dialog;
    QDialog hd_dialog;
    QDialog hdelete_dialog;

    Ui::MainWindowClass *ui;
    Ui::ConfirmCreateDatabase *ccd;
    Ui::DatabaseProgressBar *pb;
    Ui::HistoryDialog *hd;
    Ui::DeleteHistory *history_delete_dialog;

    void fillLookupTableWidget(QList<Edict *> e);

public slots:
    void on_actionGenerateDatabase_activated();
    void actionGenerateDatabaseAccepted();
    void addHistory(int row, int column);
    void showHistoryIndex(QModelIndex);
    void showHistory(int index);
    void fillHistory();
    void deleteHistory();
    void saveHistory();
    void saveHistoryEdictWords(int history_id);

private slots:
    void on_deleteHistoryPushButton_clicked();
    void on_saveHistoryPushButton_clicked();
    void on_historyPushButton_clicked();
    void on_lookupPushButton_clicked();
};

#endif // MAINWINDOW_H
