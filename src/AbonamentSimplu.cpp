#include "../include/AbonamentSimplu.h"

template<> int Counter<AbonamentSimplu>::count = 0;

AbonamentSimplu::AbonamentSimplu(float baza, int idClient) : Abonament(baza, idClient) {
    Counter<AbonamentSimplu>::increment();
}

AbonamentSimplu::AbonamentSimplu(const AbonamentSimplu& other)
    : Abonament(other) {
    Counter<AbonamentSimplu>::increment();
}

AbonamentSimplu& AbonamentSimplu::operator=(const AbonamentSimplu& other) {
    if (this != &other) {
        Abonament::operator=(other);
    }
    return *this;
}

AbonamentSimplu::~AbonamentSimplu() {
    Counter<AbonamentSimplu>::decrement();
}


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

int AbonamentSimplu::getNumarAbonamenteSimplu() {
    return Counter<AbonamentSimplu>::getCount();
}
