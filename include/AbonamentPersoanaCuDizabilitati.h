#ifndef ABOANAMENTPERSOANECUDIZABILITATI_H_INCLUDED
#define ABOANAMENTPERSOANECUDIZABILITATI_H_INCLUDED

#include "Abonament.h"
#include "Counter.h"

enum class GradHandicap
{
    USOR = 1,
    MODERAT = 2,
    GRAV = 3
};

class AbonamentPersoanaCuDizabilitati : public Abonament, public Counter<AbonamentPersoanaCuDizabilitati> {
private:
    GradHandicap gradHandicap;

public:
    AbonamentPersoanaCuDizabilitati(float baza, int idClient, GradHandicap gradHandicap);
    AbonamentPersoanaCuDizabilitati(const AbonamentPersoanaCuDizabilitati& other);
    AbonamentPersoanaCuDizabilitati& operator=(const AbonamentPersoanaCuDizabilitati& other);
    ~AbonamentPersoanaCuDizabilitati() override;

    void afisareDetalii() const override;
    void afisareTip() const override;
    void calculeazaPret(float vechime) override;
    Abonament* clone() const override;
    static int getNumarAbonamentePersoaneCuDizabilitati();


};

#endif // ABOANAMENTPERSOANECUDIZABILITATI_H_INCLUDED
