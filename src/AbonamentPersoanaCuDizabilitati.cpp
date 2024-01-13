#include "../include/AbonamentPersoanaCuDizabilitati.h"


AbonamentPersoanaCuDizabilitati::AbonamentPersoanaCuDizabilitati(float baza, int idClient, GradHandicap gradHandicap)
    : Abonament(baza, idClient), gradHandicap(gradHandicap){}

AbonamentPersoanaCuDizabilitati::AbonamentPersoanaCuDizabilitati(const AbonamentPersoanaCuDizabilitati& other)
    : Abonament(other), gradHandicap(other.gradHandicap){}

AbonamentPersoanaCuDizabilitati& AbonamentPersoanaCuDizabilitati::operator=(const AbonamentPersoanaCuDizabilitati& other)
{
    if (this != &other)
    {
        Abonament::operator=(other);
        gradHandicap = other.gradHandicap;
    }
    return *this;
}

AbonamentPersoanaCuDizabilitati::~AbonamentPersoanaCuDizabilitati(){}

void AbonamentPersoanaCuDizabilitati::afisareDetalii() const
{
    afisareTip();
    std::cout << "Pretul platit: " << pret << "\n";
    int gradValue = static_cast<int>(gradHandicap);
    std::cout << "Grad handicap: " << gradValue << "\n";
}

void AbonamentPersoanaCuDizabilitati::calculeazaPret(float vechime = -1000000.0121F)
{
    if (vechime == -1000000.0121F)
        vechime = getVechime(this->idClient);

    float verificarePret = baza - 0.5 * vechime;

    switch (gradHandicap)
    {
    case GradHandicap::USOR:
        verificarePret -= 5;
        break;
    case GradHandicap::MODERAT:
        verificarePret -= 10;
        break;
    case GradHandicap::GRAV:
        verificarePret -= 15;
        break;
    default:
        break;
    }
    pret = verificarePret > 0 ? verificarePret : 1;
}

Abonament* AbonamentPersoanaCuDizabilitati::clone() const
{
    return new AbonamentPersoanaCuDizabilitati(*this);
}

void AbonamentPersoanaCuDizabilitati::afisareTip() const
{
    std::cout<<"Tip: Abonament pentru persoane cu handicap"<<std::endl;
}
