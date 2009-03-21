#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include "databasethread.h"

class Database : public QObject
{
  Q_OBJECT
  public:
    Database(QObject *parent = 0);
    ~Database();

    bool connect();
    bool create();
    bool fill();

  public slots:
    void fill_complete();

  private:
    DatabaseThread thread;
};

#endif // DATABASE_H
