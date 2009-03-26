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
#include "edict.h"

Database::Database(){}
Database::~Database() {}

bool Database::connect() {
  QSqlDatabase db = QSqlDatabase::database();
  if(!db.isOpen()) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("japanified.db");
    if(!db.open()) {
      QMessageBox::critical(0, "Cannot open db connection.", db.lastError().text(), QMessageBox::Cancel);
      return false;
    }
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
  connect();

  QSqlQuery q;
  q.exec("DROP TABLE IF EXISTS edict_words;");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Fill Database Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("DROP TABLE IF EXISTS edict_definitions;");
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

QList<Edict> Database::lookup(const QString &value, LookupType type) {
  connect();
  edict_words.clear();

  if(type == EXACT) {
    QSqlQuery q;
    q.prepare("SELECT id, word, reading FROM edict_words WHERE word = ?;");
    q.addBindValue(value);
    q.exec();
    if(q.lastError().type()) {
      QMessageBox::critical(0, "Lookup Database Error", q.lastError().text(), QMessageBox::Cancel);
      return edict_words;
    }
    while(q.next()) {
      Edict e;
      e.id      = q.value(0).toInt();
      e.word    = q.value(1).toString();
      e.reading = q.value(2).toString();
      edict_words.append(e);
    }

    foreach(Edict e, edict_words) {
      q.prepare("SELECT definition FROM edict_definitions WHERE edict_word_id = ?;");
      q.addBindValue(e.id);
      q.exec();
      if(q.lastError().type()) {
        QMessageBox::critical(0, "Lookup Database Error", q.lastError().text(), QMessageBox::Cancel);
        return edict_words;
      }
      while(q.next()) {
        e.definitions.append(q.value(0).toString());
      }
    }
  }
  return edict_words;
}
