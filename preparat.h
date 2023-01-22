#ifndef PREPARAT_H
#define PREPARAT_H
#include <iostream>
#include <string>

class Preparat{
     std::string nume_preparat;
     int gramaj;
     double pret;
     int timp_preparare;//in minute

     friend class PreparatBuilder;

public:
     Preparat ();
     Preparat(const std::string& nume_preparat_, int gramaj_, double pret_, int timp_preparare_);

     friend std::ostream& operator<<(std::ostream& os, const Preparat& prep);
     double get_pret()const;
     int get_timppreparare()const;
};

class PreparatBuilder{
private:
    Preparat p;
public:

    PreparatBuilder()=default;

    PreparatBuilder& Nume_preparat(const std::string &nume){
        p.nume_preparat=nume;
        return (*this);
    }

    PreparatBuilder& Gramaj(int gramaj_){
        p.gramaj=gramaj_;
        return (*this);
    }

    PreparatBuilder& Pret(double pret_){
        p.pret=pret_;
        return (*this);
    }

    PreparatBuilder& Timp_prepare(int timp){
        p.timp_preparare=timp;
        return (*this);
    }
    Preparat build(){
        return p;
    }
};

#endif//PREPARAT_H
