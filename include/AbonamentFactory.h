#ifndef ABONAMENTFACTORY_H_INCLUDED
#define ABONAMENTFACTORY_H_INCLUDED

#include <memory>

#include "Abonament.h"
#include "AbonamentSimplu.h"
#include "AbonamentPremium.h"
#include "AbonamentStudent.h"

class AbonamentFactory {
public:
    Abonament* createAbonament(int tipAbonament, int codClient);
};

#endif // ABONAMENTFACTORY_H_INCLUDED