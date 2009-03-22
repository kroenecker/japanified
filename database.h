#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QDialog>
#include "databasethread.h"

class Database
{
  public:
    Database();
    ~Database();

    bool connect();
    bool create();
    bool fill();

    DatabaseThread thread;
};

#endif // DATABASE_H
