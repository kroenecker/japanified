#ifndef HISTORY_H
#define HISTORY_H

#include <QString>

class History
{
public:
    History();
    History(int id, QString title);
    int id;
    QString title;
};

#endif // HISTORY_H
