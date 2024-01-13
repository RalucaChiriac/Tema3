#include "../include/AbonamentStudent.h"

AbonamentStudent::AbonamentStudent(float baza, int idClient, int numarLegitimatie)
    : Abonament(baza, idClient), numarLegitimatie(numarLegitimatie) {
    if (numarLegitimatie> 1000) {
        throw ExceptieNumar();
    }
}

AbonamentStudent::AbonamentStudent(const AbonamentStudent& other)
    : Abonament(other), numarLegitimatie(other.numarLegitimatie) {}

AbonamentStudent& AbonamentStudent::operator=(const AbonamentStudent& other) {
    if (this != &other) {
        Abonament::operator=(other);
        numarLegitimatie = other.numarLegitimatie;
    }
    return *this;
}

AbonamentStudent::~AbonamentStudent() {}

void AbonamentStudent::afisareDetalii() const {
    afisareTip();
    std::cout << "Pretul platit: " << pret << "\n";
    std::cout << "Numar legitimatie: " << numarLegitimatie << "\n";
}

void AbonamentStudent::calculeazaPret(float vechime)  {

    float varLocalBaza = baza;
    vechime = 0;
    if (numarLegitimatie % 10 == 1) {
        pret = 0.9 * varLocalBaza + vechime;
    } else if (numarLegitimatie % 10 == 2) {
        pret = varLocalBaza * 0.85;
    } else {
        pret = varLocalBaza;
    }
}

Abonament* AbonamentStudent::clone() const {
    return new AbonamentStudent(*this);
}

void AbonamentStudent::afisareTip() const
{
    std::cout<<"Tip: Abonament Student"<<std::endl;
}