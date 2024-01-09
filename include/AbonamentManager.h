// AbonamentManager.h

#ifndef ABONAMENTMANAGER_H_INCLUDED
#define ABONAMENTMANAGER_H_INCLUDED

#include <memory>  // Include the necessary headers for std::shared_ptr

class Abonament;  // Forward declaration
class AbonamentFactory;  // Forward declaration
class ManagerClienti;  // Forward declaration

class AbonamentManager {
private:
    AbonamentFactory* abonamentFactory;

public:
    AbonamentManager();  // Declare the constructor
    void setAbonamentFactory(AbonamentFactory* factory);  // Declare the setter method
    void afiseazaStatistica() const;
    Abonament* setAbonament(int tipAbonament, int codClient);
    Abonament* setAbonament(int codClient, float vechime, std::shared_ptr<ManagerClienti> manager);
};

#endif // ABONAMENTMANAGER_H_INCLUDED
