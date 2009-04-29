#ifndef HISTORYLISTMODEL_H
#define HISTORYLISTMODEL_H

#include "edict.h"
#include <QAbstractListModel>

class HistoryListModel : public QAbstractListModel
{
  public:
    HistoryListModel();
    ~HistoryListModel();

    int rowCount( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const;

    bool addWord(const Edict& e);
  private:
    QList<Edict *> historyList;
};

#endif // HISTORYLISTMODEL_H
