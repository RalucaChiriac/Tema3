#include "../include/AbonamentFactory.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentStudent.h"

Abonament* AbonamentFactory::createAbonament(int tipAbonament, int codClient) {
    switch (tipAbonament) {
        case 1:
            return new AbonamentSimplu(13.03F, codClient);
        case 2:
            return new AbonamentPremium(21.56F, codClient, true);
        case 3:
            int numar;
            std::cout << "Introduceti numarul Legitimatiei de Student: ( >0 )";
            std::cin >> numar;
            return new AbonamentStudent(13.0F, codClient, numar);
        default:
            throw std::runtime_error("Tip de abonament invalid");
    }
}