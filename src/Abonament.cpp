
#include "../include/Abonament.h"
#include "../include/ManagerClienti.h"

template<> int Counter<Abonament>::count = 0;

Abonament::Abonament(float baza, int idClient) : baza(baza), idClient(idClient), pret(0.0) {
    if (baza < 0) {
        throw ExceptieNumar();
    }
    if (idClient < 0) {
        throw ExceptieNumar();
    }
    Counter<Abonament>::increment();
}

Abonament::Abonament(const Abonament& other) : baza(other.baza), idClient(other.idClient), manager(other.manager), pret(other.pret) {
    Counter<Abonament>::increment();
}

Abonament& Abonament::operator=(const Abonament& other) {
    if (this != &other) {
        baza = other.baza;
        idClient = other.idClient;
        pret = other.pret;
    }
    return *this;
}

Abonament::~Abonament() {
    Counter<Abonament>::decrement();
}

float Abonament::getVechime(int codClient) {
    if (auto man = manager.lock())
        return man->findClient(codClient).getVechime();
    else {
        throw ExceptieManagerInexistent();
    }
}

int Abonament::getter_AbonamenteTotale() {
    return Counter<Abonament>::getCount();
}

void Abonament::setter_manager(std::shared_ptr<ManagerClienti> man) {
    std::weak_ptr<ManagerClienti> my_ptr = man;
    manager = my_ptr;
}