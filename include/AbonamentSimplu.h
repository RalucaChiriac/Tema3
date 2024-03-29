#ifndef ABONAMENTSIMPLU_H_INCLUDED
#define ABONAMENTSIMPLU_H_INCLUDED

#include "Abonament.h"
#include "Counter.h"

class AbonamentSimplu : public Abonament, public Counter<AbonamentSimplu> {
public:
    AbonamentSimplu(float baza, int idClient);
    AbonamentSimplu(const AbonamentSimplu& other);
    AbonamentSimplu& operator=(const AbonamentSimplu& other);
    ~AbonamentSimplu() override;
    
    void afisareDetalii() const override;
    void afisareTip() const override;
    void calculeazaPret(float vechime) override;
    Abonament* clone() const override;
};

#endif // ABONAMENTSIMPLU_H_INCLUDED
