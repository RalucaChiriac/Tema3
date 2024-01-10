#ifndef ABONAMENTMANAGER_H_INCLUDED
#define ABONAMENTMANAGER_H_INCLUDED

#include <memory>

#include "Abonament.h"
#include "AbonamentFactory.h"

class AbonamentManager {
private:
    AbonamentFactory abonamentFactory;

public:
    AbonamentManager();
    static void afiseazaStatistica();
    static Abonament* setAbonament(int tipAbonament, int codClient);
    static Abonament* setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager);
};

#endif // ABONAMENTMANAGER_H_INCLUDED