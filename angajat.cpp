#include "angajat.h"



void Angajat::afisare(std::ostream &) const {}

 Angajat::Angajat(const Angajat &other):nume{other.nume}, email{other.email}, localitate{other.localitate},varsta{other.varsta}{
        //std::cout<<"constr de copiere\n";
    }

Angajat &Angajat::operator=(const Angajat &other){
        nume = other.nume;
        email = other.email;
        localitate=other.localitate;
        varsta=other.varsta;
        //std::cout << "operator= copiere\n";
        return *this;
    }
Angajat::Angajat()=default;

Angajat:: Angajat(const std::string& nume_,const  std::string& email_, const std::string localitate_,int varsta_):nume{nume_}, email{email_}, localitate{localitate_},varsta{varsta_}{
        //std::cout<<"constr de initializare\n";
    }

std::ostream &operator<<(std::ostream &os, const Angajat &angajat) {
        os << "\n Nume angajat: " << angajat.nume<< ", Email: " << angajat.email<< ", Adresa: " << angajat.localitate<< ", Varsta: " << angajat.varsta<<"ani\n";
        angajat.afisare(os);
        os << "\n";
        return os;
    }
Angajat::~Angajat() {
    //std::cout << "destr ang\n";
}

void Angajat::activitate(){
        std::cout<<"Detalii si operatii specifice activitatii fiecarui angajat"<<"\n";
        //ex: un ospatar primeste un bonus de 30% daca este disponibil sa participe la eveniment pe timup noptii
    }
