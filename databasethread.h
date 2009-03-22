#ifndef DATABASETHREAD_H
#define DATABASETHREAD_H

#include <QFile>
#include <QThread>

class DatabaseThread : public QThread
{
  Q_OBJECT

  public:
    DatabaseThread();
    ~DatabaseThread();

  protected:
   void run();

  signals:
   void progress(int);
 };

#endif // DATABASETHREAD_H
