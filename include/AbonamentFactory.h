#ifndef ABONAMENTFACTORY_H_INCLUDED
#define ABONAMENTFACTORY_H_INCLUDED

#include "Abonament.h"
#include "ManagerClienti.h"

class AbonamentFactory {
public:
    Abonament* createAbonament(int tipAbonament, int codClient);
};

#endif // ABONAMENTFACTORY_H_INCLUDED