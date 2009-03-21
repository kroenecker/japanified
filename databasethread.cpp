#include <QVariant>
#include <QFile>
#include <QTextStream>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QChar>
#include <QMessageBox>

#include "databasethread.h"

DatabaseThread::DatabaseThread()
{
}

DatabaseThread::~DatabaseThread() {
}

void DatabaseThread::run() {
  QFile textfile("edict_utf8.txt");
  if (!textfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return;
  }

  QSqlQuery q;
  QTextStream in(&textfile);
  QRegExp     rx("\\[");

  QSqlDatabase db = QSqlDatabase::database();
  db.transaction();

  in.readLine();//get rid of ???? at the top of the file
  while (!in.atEnd()) {
    QString     word;
    QString     reading;
    QString     line        = in.readLine();
    QStringList definitions = line.split("/");

    if(rx.indexIn(definitions.at(0)) > -1) {
      QStringList wr = definitions.at(0).split("[");
      word           = wr.at(0).trimmed();
      reading        = wr.at(1);
      reading        = reading.remove(QChar(']')).trimmed();
    } else {
      word = reading = definitions.at(0).trimmed();
    }

    q.prepare("INSERT INTO edict_words (id, word, reading) VALUES (NULL, ?, ?);");
    q.addBindValue(word);
    q.addBindValue(reading);
    q.exec();
    if(q.lastError().type()) {
      QMessageBox::critical(0, "Database Error", q.lastError().text(), QMessageBox::Cancel);
      return;
    }
    int id = q.lastInsertId().toInt();

    for(int i = 1; i < definitions.length(); i++) {
      q.prepare("INSERT INTO edict_definitions (id, edict_word_id, definition) VALUES (NULL, ?, ?);");
      q.addBindValue(id);
      q.addBindValue(definitions.at(i));
      q.exec();
      if(q.lastError().type()) {
        QMessageBox::critical(0, "Database Error", q.lastError().text(), QMessageBox::Cancel);
        return;
      }
    }
  }
  db.commit();
  textfile.close();
}