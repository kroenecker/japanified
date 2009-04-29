#include "edict.h"

Edict::Edict()
{
}

void Edict::clear()
{
  id      = -1;
  word    = "";
  reading = "";
  definitions.clear();
}
