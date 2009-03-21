#include <QVariant>
#include <QFile>
#include <QTextStream>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QChar>
#include <QMessageBox>
#include <QThread>
#include "database.h"

Database::Database(QObject *parent)
: QObject(parent)
{
  QObject::connect(&thread, SIGNAL(finished()), this, SLOT(fill_complete()));
  QObject::connect(&thread, SIGNAL(started()), this, SLOT(fill_complete()));
}

Database::~Database() {
}

bool Database::connect() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setHostName("localhost");
  db.setDatabaseName("japanified.db");
  if(!db.open()) {
    QMessageBox::critical(0, "Cannot open db connection.", "Somethings wrong...", QMessageBox::Cancel);
    return false;
  }
  return true;
}

bool Database::create() {
  QSqlQuery q;
  q.exec("CREATE TABLE IF NOT EXISTS edict_words (id INTEGER PRIMARY KEY, word TEXT, reading TEXT);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create Database Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("CREATE TABLE IF NOT EXISTS edict_definitions (id INTEGER PRIMARY KEY, edict_word_id INTEGER, definition TEXT);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create Database Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  return true;
}

bool Database::fill() {
  QSqlQuery q;
  q.exec("DROP TABLE edict_words;");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Fill Database Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("DROP TABLE edict_definitions;");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Fill Database Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }

  if(!create()) {
    return false;
  }
  thread.start();//Fill database
  return true;
}

void Database::fill_complete() {
  //emit fill complete signal
   QMessageBox::critical(0, "Thread done", "hurrah", QMessageBox::Cancel);
}
