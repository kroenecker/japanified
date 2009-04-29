#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QDialog>
#include <QList>

#include "databasethread.h"
#include "edict.h"

enum LookupType
{
  EXACT  = 0,
  BEGIN  = 1,
  MIDDLE = 2,
  END    = 3
};

class Database
{
  public:
    Database();
    ~Database();

    bool connect();
    bool create();
    bool fill();
    QList<Edict*> lookup(QString value, LookupType t);

    DatabaseThread thread;

  private:
    QList<Edict*> edict_words;
};

#endif // DATABASE_H
