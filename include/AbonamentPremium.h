#ifndef ABONAMENTPREMIUM_H_INCLUDED
#define ABONAMENTPREMIUM_H_INCLUDED

#include "Abonament.h"
#include "Counter.h"

class AbonamentPremium : public Abonament, public Counter<AbonamentPremium> {
private:
    bool serviciuSupport;

public:
    AbonamentPremium(float baza, int idClient, bool serviciuSupport);
    AbonamentPremium(const AbonamentPremium& other);
    AbonamentPremium& operator=(const AbonamentPremium& other);
    ~AbonamentPremium() override;

    void afisareDetalii() const override;
    void afisareTip() const override;
    void calculeazaPret(float vechime) override;
    Abonament* clone() const override;
};

#endif // ABONAMENTPREMIUM_H_INCLUDED
