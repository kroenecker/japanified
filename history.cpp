#include "history.h"

History::History()
:id(-1), title("")
{
}

History::History(int id, QString title)
:id(id), title(title)
{
}
