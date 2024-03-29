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
    AbonamentFactory abonamentFactory;
    AbonamentManager abonamentManager;

public:
    void adaugaClient();
    void stergeClient(const std::string& numeClient);
    void listeazaClienti() const;
    void schimbaAbonament(const std::string& numeClient, int tipAbonament);
    void reseteazaProgram();
    Client& findClient(int codClient);
    void afiseazaMeniu() const;
    ~ManagerClienti();

    static std::shared_ptr<ManagerClienti> getInstance();
    void setAbonamentFactory(AbonamentFactory factory);
    Abonament* setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager);
};

#endif // MANAGERCLIENTI_H_INCLUDED
