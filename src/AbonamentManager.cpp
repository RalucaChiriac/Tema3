// AbonamentManager.cpp

#include "../include/AbonamentManager.h"
#include "../include/AbonamentFactory.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentStudent.h"


AbonamentManager::AbonamentManager() : abonamentFactory(nullptr) {}

void AbonamentManager::setAbonamentFactory(std::shared_ptr<AbonamentFactory> factory) {
    abonamentFactory = factory;
}

void AbonamentManager::afiseazaStatistica() const {
    std::cout << "   Statistica: "
              << "\n";
    std::cout << "Numar total de abonamente: " << Abonament::getter_AbonamenteTotale() << '\n';
    std::cout << "Numar de abonamente Simple: " << AbonamentSimplu::getNumarAbonamenteSimplu() << '\n';
    std::cout << "Numar de abonamente Premium: " << AbonamentPremium::getNumarAbonamentePremium() << '\n';
    std::cout << "Numar de abonamente de Student: " << AbonamentStudent::getNumarAbonamenteStudent() << '\n';
}

Abonament* AbonamentManager::setAbonament(int tipAbonament, int codClient) {
    if (abonamentFactory) {
        return abonamentFactory->createAbonament(tipAbonament, codClient);
    } else {
        // Handle the case where the factory is not set
        throw std::runtime_error("AbonamentFactory not set");
    }
}

Abonament* AbonamentManager::setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager) {
    if (abonamentFactory) {
        std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student): ";
        int tipAbonament;
        std::cin >> tipAbonament;

        Abonament* abonament = abonamentFactory->createAbonament(tipAbonament, codClient);

        abonament->setter_manager(manager);
        abonament->calculeazaPret(vechime);

        return abonament;
    } else {
        // Handle the case where the factory is not set
        throw std::runtime_error("AbonamentFactory not set");
    }
}
