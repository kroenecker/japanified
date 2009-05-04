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
    Convert convert;
    Database database;
    HistoryListModel history_model;

    ProgressBarDialog progress_bar_dialog;
    QDialog confirm_create_database_dialog;
    QDialog new_history_dialog;
    QDialog delete_history_dialog;

    Ui::MainWindowClass *ui;
    Ui::ConfirmCreateDatabase *p_confirm_create_database_dialog;
    Ui::DatabaseProgressBar *p_progress_bar_dialog;
    Ui::HistoryDialog *p_new_history_dialog;
    Ui::DeleteHistory *p_delete_history_dialog;

    void fillLookupTableWidget(QList<Edict *> e);

public slots:
    void on_actionGenerateDatabase_activated();
    void actionGenerateDatabaseAccepted();
    void addHistory(int row, int column);
    void showHistoryIndex(QModelIndex);
    void showHistory(int index);
    void fillHistoryComboBox();
    void deleteHistory();
    void newHistory();
    void historyRejected();
    void newHistoryEdictWords(int history_id);

private slots:
    void on_newHistoryPushButton_clicked();
    void on_deleteHistoryPushButton_clicked();
    void on_historyPushButton_clicked();
    void on_lookupPushButton_clicked();
};

#endif // MAINWINDOW_H
