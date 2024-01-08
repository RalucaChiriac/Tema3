#pragma once

#include "Abonament.h"
#include "AbonamentPremium.h"
#include "AbonamentSimplu.h"
#include "AbonamentStudent.h"

class AbonamentFactory {
public:
    template <typename T>
    Abonament* creeazaAbonament(float baza, int idClient, bool serviciuSupport = false, int numarLegitimatie = -1) {
        // Instantiate the template and return the created object
        return new T(baza, idClient, serviciuSupport, numarLegitimatie);
    }

    Abonament* creeazaSimplu(float baza, int idClient, bool serviciuSupport, int numarLegitimatie) {
        return creeazaAbonament<AbonamentSimplu>(baza, idClient, serviciuSupport, numarLegitimatie);
    }

    Abonament* creeazaPremium(float baza, int idClient, bool serviciuSupport, int numarLegitimatie) {
        return creeazaAbonament<AbonamentPremium>(baza, idClient, serviciuSupport, numarLegitimatie);
    }

    Abonament* creeazaStudent(float baza, int idClient, bool serviciuSupport, int numarLegitimatie) {
        return creeazaAbonament<AbonamentStudent>(baza, idClient, serviciuSupport, numarLegitimatie);
    }
};
