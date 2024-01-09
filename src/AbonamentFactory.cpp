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
            return new AbonamentPremium(21.56F, codClient, true);
        case 3:
            std::cout << "Introduceti numarul Legitimatiei de Student: ( >0 )";
            std::cin >> numar;
            return new AbonamentStudent(13.0F, codClient, numar);
        case 4:
            std::cout << "Introduceti gradul de handicap: ( 1, 2 sau 3 )";
            std::cin >> numar;
            // Validate the user input
            if (numar >= 1 && numar <= 3) {
                // Convert the user input to GradHandicap enum
                GradHandicap handicap = static_cast<GradHandicap>(numar);

                // Create a new AbonamentPersoaneCuDizabilitati with the specified gradHandicap
                return new AbonamentPersoanaCuDizabilitati(13.0F, codClient, handicap);
            } else {
                std::cout << "Input invalid. Please enter a number between 1 and 3." << std::endl;
                // Handle invalid input, for example, return nullptr or ask the user to input again
                return nullptr;
            }
        default:
            throw std::runtime_error("Tip de abonament invalid");
    }
}