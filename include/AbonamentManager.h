
#ifndef ABONAMENTMANAGER_H_INCLUDED
#define ABONAMENTMANAGER_H_INCLUDED

#include <memory>

#include "Abonament.h"
#include "AbonamentFactory.h"

class AbonamentManager {
private:
    std::shared_ptr<AbonamentFactory> abonamentFactory;

public:
    AbonamentManager();
    void setAbonamentFactory(std::shared_ptr<AbonamentFactory> factory);
    void afiseazaStatistica() const;
    Abonament* setAbonament(int tipAbonament, int codClient);
    Abonament* setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager);
};

#endif // ABONAMENTMANAGER_H_INCLUDED