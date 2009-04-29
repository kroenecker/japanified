#include "historylistmodel.h"

HistoryListModel::HistoryListModel()
{
}

HistoryListModel::~HistoryListModel()
{
    while(historyList.length() > 0) {
        delete historyList.takeFirst();
    }
}

bool HistoryListModel::addWord(const Edict& e)
{
    Edict *edict = new Edict(e);
    historyList.append(edict);
    this->reset();
}

int HistoryListModel::rowCount( const QModelIndex & parent) const
{
    return historyList.length();
}

QVariant HistoryListModel::data( const QModelIndex & index, int role) const
{
    if(role == Qt::DisplayRole) {
        return QVariant(historyList.at(index.row())->word);
    }
    return QVariant();
}
