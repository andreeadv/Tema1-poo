#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <iostream>
#include <string>
#include<memory>
#include <utility>
#include "exceptii.h"

//angajat va fi clasa de baza pt ospatar,dj,bucatar etc.
class Angajat{
protected:
    std::string nume;
private:
    std::string email;
    std::string localitate;
    int varsta;

//Poate nu toate derivatele adaugă atribute pe care să le afișeze, motiv pentru care nu facem funcția de afișare virtuală pură.
    virtual void afisare(std::ostream &) const;//functie apelata in op<<

//constructorul de copiere si operator egal protected pentru a putea fi apelate de derivata
protected:
    Angajat(const Angajat &other);
    Angajat &operator=(const Angajat &other);

public:

    Angajat();
    explicit Angajat(std::string nume_,std::string email_,std::string localitate_,int varsta_);
    friend std::ostream &operator<<(std::ostream &os, const Angajat &angajat) ;
    virtual std::shared_ptr<Angajat> clone() const = 0;
    virtual void activitate();
    virtual ~Angajat();

};
#endif