#include <iostream>

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

Database::Database()
{}

Database::~Database()
{
  while(!edict_words.isEmpty()) {
    delete edict_words.takeFirst();
  }
  while(!history.isEmpty()) {
    delete history.takeFirst();
  }
}

bool Database::connect()
{
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

bool Database::create()
{
  QSqlQuery q;
  q.exec("CREATE TABLE IF NOT EXISTS edict_words (id INTEGER PRIMARY KEY, word TEXT, reading TEXT);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create edict_words Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("CREATE INDEX index_edict_words on edict_words(word, reading);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create index_edict_words Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("CREATE TABLE IF NOT EXISTS edict_definitions (id INTEGER PRIMARY KEY, edict_word_id INTEGER, definition TEXT);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create edict_definitions Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("CREATE INDEX index_edict_definitions on edict_definitions(edict_word_id);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create index_edict_definitions Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("CREATE TABLE IF NOT EXISTS history (id INTEGER PRIMARY KEY, title VARCHAR(255));");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create history Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  q.exec("CREATE TABLE IF NOT EXISTS history_edict_words (id INTEGER PRIMARY KEY, history_id INTEGER, edict_word_id INTEGER);");
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Create history_edict_words Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  return true;
}

QList<History*> Database::selectHistory() {
  connect();
  while(!history.isEmpty()) {
    delete history.takeFirst();
  }
  QSqlQuery q;
  q.exec("SELECT id, title FROM history;");
  //Medidate on what to do here.  This will run before the tables have been created.
  //if(q.lastError().type()) {
  //  QMessageBox::critical(0, "Database::selectHistory Error", q.lastError().text(), QMessageBox::Cancel);
  //  return history;
  //}
  History *h = new History();
  h->id      = -1;
  h->title   = " --";
  history.append(h);

  while(q.next()) {
    History *h = new History();
    h->id      = q.value(0).toInt();
    h->title   = q.value(1).toString(); 
    history.append(h);
  }
  return history;
}

History Database::insertHistory(QString title) {
  QSqlQuery q; 
  q.prepare("INSERT INTO history(id, title) VALUES (NULL, ?);");
  q.addBindValue(title);
  q.exec();
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Database::insertHistory Error", q.lastError().text(), QMessageBox::Cancel);
    return History();
  }
  int id = q.lastInsertId().toInt();
  return History(id, title);
}

bool Database::insertHistoryEdictWord(int history_id, int edict_word_id) {
  QSqlQuery q;
  q.prepare("INSERT INTO history_edict_words (id, history_id, edict_word_id) VALUES (NULL, ?, ?);");
  q.addBindValue(history_id);
  q.addBindValue(edict_word_id);
  q.exec();
  if(q.lastError().type()) {
    QMessageBox::critical(0, "Database::insertHistoryEdictWord Error", q.lastError().text(), QMessageBox::Cancel);
    return false;
  }
  return true;
}

bool Database::fill()
{
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

QList<Edict*> Database::lookup(QString value, LookupType type)
{
  connect();
  while(!edict_words.isEmpty()) {
    delete edict_words.takeFirst();
  }

  QString like = "=";
  if(type == BEGIN) {
    value = value + "%";
    like = "LIKE";
  } else if(type == MIDDLE) {
    value = "%" + value + "%";
    like = "LIKE";
  } else if(type == END) {
    value = "%" + value;
    like = "LIKE";
  }

  QSqlQuery q;
  q.prepare("SELECT id, word, reading FROM edict_words WHERE word " + like + " ? OR  reading " + like + " ? ");
  q.bindValue(0,value);
  q.bindValue(1,value);
  q.exec();

  if(q.lastError().type()) {
    QMessageBox::critical(0, "Lookup Database Error", q.lastError().text(), QMessageBox::Cancel);
    return edict_words;
  }
  while(q.next()) {
    Edict *e   = new Edict();
    e->id      = q.value(0).toInt();
    e->word    = q.value(1).toString();
    e->reading = q.value(2).toString();
    edict_words.append(e);
  }
  foreach(Edict *e, edict_words) {
    q.prepare("SELECT definition FROM edict_definitions WHERE edict_word_id = ? ");
    q.addBindValue(e->id);
    q.exec();
    if(q.lastError().type()) {
      QMessageBox::critical(0, "Lookup Database Error", q.lastError().text(), QMessageBox::Cancel);
      return edict_words;
    }
    while(q.next()) {
      e->definitions.append(q.value(0).toString());
    }
  }
  return edict_words;
}
