#include "base58.h"

Cbase58* Cbase58::instance = new Cbase58();

Cbase58*
Cbase58::getInstance()
{
    return instance;/* code */;
};

