#include "../include/AbonamentPremium.h"

template<> int Counter<AbonamentPremium>::count = 0;

AbonamentPremium::AbonamentPremium(float baza, int idClient, bool serviciuSupport)
    : Abonament(baza, idClient), serviciuSupport(serviciuSupport){}

AbonamentPremium::AbonamentPremium(const AbonamentPremium& other)
    : Abonament(other), serviciuSupport(other.serviciuSupport){}

AbonamentPremium& AbonamentPremium::operator=(const AbonamentPremium& other)
{
    if (this != &other)
    {
        Abonament::operator=(other);
        serviciuSupport = other.serviciuSupport;
    }
    return *this;
}

AbonamentPremium::~AbonamentPremium(){}

void AbonamentPremium::afisareDetalii() const
{
    afisareTip();
    std::cout << "Pretul platit: " << pret << "\n";
    std::cout << "Serviciu support 24/7: " << (serviciuSupport ? "Da" : "Nu") << "\n";
}

void AbonamentPremium::calculeazaPret(float vechime = -1000000.0121F)
{

    if(vechime == -1000000.0121F)
        vechime = getVechime(this->idClient);

    if (serviciuSupport)
    {
        pret = baza - 0.5 * vechime + 12;
    }
    else
    {
        pret = baza - 0.5 * vechime;
    }
}

Abonament* AbonamentPremium::clone() const
{
    return new AbonamentPremium(*this);
}

int AbonamentPremium::getNumarAbonamentePremium()
{
    return Counter<AbonamentPremium>::getCount();
}

void AbonamentPremium::afisareTip() const
{
    std::cout<<"Tip: Abonament Premium"<<std::endl;
}
