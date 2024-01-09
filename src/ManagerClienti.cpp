#include "../include/ManagerClienti.h"
#include "../include/Abonament.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentStudent.h"
#include "../include/Client.h"
#include "../include/MyExceptions.h"
#include <iostream>
#include <algorithm>
#include "../include/ManagerClienti.h"
#include "../include/AbonamentManager.h"
#include "../include/AbonamentFactory.h"

std::shared_ptr<ManagerClienti> ManagerClienti::instance = nullptr;

ManagerClienti::ManagerClienti(): abonamentFactory(std::make_shared<AbonamentFactory>()), abonamentManager(std::make_unique<AbonamentManager>()) {
    abonamentManager->setAbonamentFactory(abonamentFactory);
}

ManagerClienti::~ManagerClienti() {
}

std::shared_ptr<ManagerClienti> ManagerClienti::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<ManagerClienti>(new ManagerClienti());
    }
    return instance;
}

Abonament* ManagerClienti::setAbonament(int tipAbonament, int codClient) {
    return abonamentManager->setAbonament(tipAbonament, codClient);
}

void ManagerClienti::afiseazaStatistica() const{
    abonamentManager->afiseazaStatistica();
}

Abonament* ManagerClienti::setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager) {
    return abonamentManager->setAbonament(codClient, vechime, manager);
}

void ManagerClienti::afiseazaMeniu() const
{
    std::cout << "\nMeniu:\n";
    std::cout << "1. Adaugare client (cu abonament)\n";
    std::cout << "2. Stergere client\n";
    std::cout << "3. Listare clienti\n";
    std::cout << "4. Schimbare abonament pentru un client\n";
    std::cout << "5. Statistica privind numarul abonamentelor\n";
    std::cout << "6. Resetare program\n";
    std::cout << "7. Inchidere\n";
    std::cout << "Alegerea dumneavoastra: ";
}

void ManagerClienti::adaugaClient()
{
    std::cout << "Introduceti numele clientului: ";
    std::string numeClient;
    std::cin >> numeClient;

    std::cout << "Introduceti id-ul clientului: ";
    int codClient;
    std::cin >> codClient;

    std::cout << "Introduceti vechimea clientului: ";
    float vechime;
    std::cin >> vechime;

    Abonament *abonament = setAbonament(codClient, vechime, shared_from_this());

    Client client = Client(numeClient, codClient, abonament, vechime);
    delete abonament;
    clienti.push_back(client);
    // delete abonament;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Clientul a fost adaugat cu succes.\n";
}

void ManagerClienti::stergeClient(const std::string &numeClient)
{
    auto it = std::remove_if(clienti.begin(), clienti.end(), [numeClient](const Client &client)
                             { return client.getNume() == numeClient; });

    if (it != clienti.end())
    {

        clienti.erase(it, clienti.end());
        std::cout << "Clientul a fost sters cu succes.\n";
    }
    else
        throw ExceptieClientInexistent();
}

void ManagerClienti::listeazaClienti() const
{
    std::cout << "Lista de clienti:\n";
    for (const auto &client : clienti)
    {
        std::cout << client;
        std::cout << "\n";
    }
}

Client &ManagerClienti::findClient(int codClient)
{
    for (auto &client : clienti)
    {
        if (client.getId() == codClient)
        {
            return client;
        }
    }
    throw ExceptieClientInexistent();
}

void ManagerClienti::schimbaAbonament(const std::string &numeClient, int tipAbonament)
{

    for (auto &client : clienti)
    {
        if (client.getNume() == numeClient)
        {
            Abonament *abonament = setAbonament(tipAbonament, client.getId());

            abonament->setter_manager(shared_from_this());
            abonament->calculeazaPret(client.getVechime());
            client.setAbonament(abonament);
            delete abonament;

            std::cout << "Abonamentul pentru -- " << numeClient << " -- a fost schimbat cu succes.\n";
            return;
        }
    }
    throw ExceptieClientInexistent();
}

void ManagerClienti::reseteazaProgram()
{
    clienti.clear();
    std::cout << "Programul a fost resetat cu succes.\n";
}

void ManagerClienti::setAbonamentFactory(std::shared_ptr<AbonamentFactory> factory) {
    abonamentManager->setAbonamentFactory(factory);
}
