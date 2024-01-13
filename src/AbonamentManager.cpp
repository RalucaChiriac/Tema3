#include "../include/AbonamentManager.h"
#include "../include/AbonamentFactory.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentStudent.h"
#include "../include/AbonamentPersoanaCuDizabilitati.h"
#include "../include/Counter.h"


AbonamentManager::AbonamentManager(){}

void AbonamentManager::afiseazaStatistica() {
    std::cout << "   Statistica: "
              << "\n";
    std::cout << "Numar total de abonamente: " << Counter<Abonament>::getCount() << '\n';
    std::cout << "Numar de abonamente Simple: " << Counter<AbonamentSimplu>::getCount() << '\n';
    std::cout << "Numar de abonamente Premium: " << Counter<AbonamentPremium>::getCount() << '\n';
    std::cout << "Numar de abonamente de Student: " << Counter<AbonamentStudent>::getCount() << '\n';
    std::cout << "Numar de abonamente de Persoane cu Dizabilitati: " << Counter<AbonamentPersoanaCuDizabilitati>::getCount() << '\n';
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
