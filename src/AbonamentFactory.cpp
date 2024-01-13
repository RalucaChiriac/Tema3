#include "../include/AbonamentFactory.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentStudent.h"
#include "../include/AbonamentPersoanaCuDizabilitati.h"

Abonament* AbonamentFactory::createAbonament(int tipAbonament, int codClient) {
    int numar;
    switch (tipAbonament) {
        case 1:
            return new AbonamentSimplu(13.03F, codClient);
        case 2:
            {
            std::cout << "Doriti Support 24/7 ? Se percepe inca o taxa de 12 lei in plus! Raspuns: DA/NU"<<'\n';
            std::string raspuns;
            std::cin >> raspuns;
            if (raspuns == "DA")
                return new AbonamentPremium(21.56F, codClient, true);
            else
                return new AbonamentPremium(21.56F, codClient, false);
            }
        case 3:
            std::cout << "Introduceti numarul Legitimatiei de Student: ( >0 )";
            std::cin >> numar;
            return new AbonamentStudent(13.0F, codClient, numar);
        case 4:
            std::cout << "Introduceti gradul de handicap: ( 1, 2 sau 3 )";
            std::cin >> numar;
            if (numar >= 1 && numar <= 3) {
                GradHandicap handicap = static_cast<GradHandicap>(numar);
                return new AbonamentPersoanaCuDizabilitati(13.0F, codClient, handicap);
            } else {
                std::cout << "Input invalid. Va rugam introduceti un numar intre 1 si 3" << std::endl;

                return nullptr;
            }
        default:
                return nullptr;
    }
}
