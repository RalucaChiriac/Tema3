#ifndef ABONAMENTSTUDENT_H_INCLUDED
#define ABONAMENTSTUDENT_H_INCLUDED

#include "Abonament.h"
#include "Counter.h"

class AbonamentStudent : public Abonament, public Counter<AbonamentStudent> {
private:
    int numarLegitimatie;

public:
    AbonamentStudent(float baza, int idClient, int numarLegitimatie);
    AbonamentStudent(const AbonamentStudent& other);
    AbonamentStudent& operator=(const AbonamentStudent& other);
    ~AbonamentStudent() override;

    void afisareDetalii() const override;
    void calculeazaPret(float vechime) override;
    void afisareTip() const override;
    Abonament* clone() const override;
};


#endif // ABONAMENTSTUDENT_H_INCLUDED
