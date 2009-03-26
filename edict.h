#ifndef EDICT_H
#define EDICT_H

#include <QStringList>

class Edict
{
  public:
    Edict();

    int id;
    QString word;
    QString reading;
    QStringList definitions;

    void clear();
  };

#endif // EDICT_H
