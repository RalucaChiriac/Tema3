
#ifndef MANAGERCLIENTI_H_INCLUDED
#define MANAGERCLIENTI_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "Client.h"
#include "MyExceptions.h"
#include "AbonamentFactory.h"
#include "AbonamentManager.h"

class ManagerClienti : public std::enable_shared_from_this<ManagerClienti> {
private:
    std::vector<Client> clienti;
    ManagerClienti();
    static std::shared_ptr<ManagerClienti> instance;

    std::shared_ptr<AbonamentFactory> abonamentFactory;
    std::shared_ptr<AbonamentManager> abonamentManager;

public:
    // Adaugare client cu abonament
    void adaugaClient();

    // stergere client
    void stergeClient(const std::string& numeClient);

    // Listare clienti
    void listeazaClienti() const;

    // Schimbare abonament pentru un client
    void schimbaAbonament(const std::string& numeClient, int tipAbonament);

    // Resetare program
    void reseteazaProgram() ;

    // Statistica abonamente
    void afiseazaStatistica() const;

    Client& findClient(int codClient);

    // afiseaza meniul
    void afiseazaMeniu() const;

    ~ManagerClienti()
    {}

    static std::shared_ptr<ManagerClienti> getInstance();

    void setAbonamentFactory(std::shared_ptr<AbonamentFactory> factory);
    void setAbonamentManager(std::shared_ptr<AbonamentManager> manager);

    Abonament* setAbonament(int tipAbonament, int codClient);
    Abonament* setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager);

};

#endif // MANAGERCLIENTI_H_INCLUDED
