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
    bool found   = false;
    foreach(Edict* i, historyList) {
        if(i->id == e.id) {
            found = true;
        }
    }
    if(!found) {
      Edict *edict = new Edict(e);
      historyList.append(edict);
      this->reset();
    }
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

Edict* HistoryListModel::getEdict(int index)
{
    const Edict* const i = historyList.at(index);
    Edict *e       = new Edict();
    e->id          = i->id;
    e->word        = i->word;
    e->reading     = i->reading;
    e->definitions = i->definitions;
    return e;
}
