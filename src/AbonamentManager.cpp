#include "../include/AbonamentManager.h"
#include "../include/AbonamentFactory.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentStudent.h"
#include "../include/AbonamentPersoanaCuDizabilitati.h"

AbonamentManager::AbonamentManager(){}

void AbonamentManager::afiseazaStatistica() {
    std::cout << "   Statistica: "
              << "\n";
    std::cout << "Numar total de abonamente: " << Abonament::getter_AbonamenteTotale() << '\n';
    std::cout << "Numar de abonamente Simple: " << AbonamentSimplu::getNumarAbonamenteSimplu() << '\n';
    std::cout << "Numar de abonamente Premium: " << AbonamentPremium::getNumarAbonamentePremium() << '\n';
    std::cout << "Numar de abonamente de Student: " << AbonamentStudent::getNumarAbonamenteStudent() << '\n';
    std::cout << "Numar de abonamente de Persoane cu Dizabilitati: " << AbonamentPersoanaCuDizabilitati::getNumarAbonamentePersoaneCuDizabilitati() << '\n';
}

Abonament* AbonamentManager::setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager) {
    std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student / 4. Persoana cu handicap): ";
    int tipAbonament;
    std::cin >> tipAbonament;

    Abonament* abonament = AbonamentFactory::createAbonament(tipAbonament, codClient);

    abonament->setter_manager(manager);
    abonament->calculeazaPret(vechime);
    return abonament;
}
