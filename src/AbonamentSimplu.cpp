#include "../include/AbonamentSimplu.h"

AbonamentSimplu::AbonamentSimplu(float baza, int idClient) : Abonament(baza, idClient) {}

AbonamentSimplu::AbonamentSimplu(const AbonamentSimplu& other)
    : Abonament(other) {}

AbonamentSimplu& AbonamentSimplu::operator=(const AbonamentSimplu& other) {
    if (this != &other) {
        Abonament::operator=(other);
    }
    return *this;
}

AbonamentSimplu::~AbonamentSimplu() {}


void AbonamentSimplu::afisareDetalii() const {
    afisareTip();
    std::cout << "Pretul platit: " << pret << "\n";
}

void AbonamentSimplu::calculeazaPret(float vechime = -1000000.0121F) {

    if (vechime == -1000000.0121F)
        pret = baza - 0.4 * getVechime(this->idClient);
    else
        pret = baza - 0.4 * vechime;
}

Abonament* AbonamentSimplu::clone() const {
    return new AbonamentSimplu(*this);
}

void AbonamentSimplu::afisareTip() const
{
    std::cout<<"Tip: Abonament Simplu"<<std::endl;
}
