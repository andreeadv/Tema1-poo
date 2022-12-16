#ifndef PROMOTER_H
#define PROMOTER_H
#include <iostream>
#include <string>
#include<memory>
#include <utility>
#include "angajat.h"
#include "exceptii.h"
class Promoter: public Angajat{
//un promoter este platit/ora, nu are salariu fix
//aceastia se ocupa cu distribuirea anunturilor publicitare referitoare la activitatea restaurantului
private:

     static int prag_comision;//promoterii primesc comisionul doar daca indeplinesc un anumit target
     static int comision;
     int ore_lucrate;//pe luna
     double plata_finala;//"salariu" de la sfarsitul lunii, se actualizeaza in functie de numarul de ore lucrate
     int anunturi_distribuite;
     double plata_ora;


     void afisare(std::ostream &os) const override;

public:

    Promoter();
    Promoter(const std::string& nume,const  std::string& email, const std::string& localitate,int varsta,int ore_lucrate_,double plata_finala_,int anunturi_distribuite_,int plata_ora);
    std::shared_ptr<Angajat> clone() const override;

    static int get_prag();
    static int get_comision();
    void activitate() override;

    //pentru fiecare anunt distribuit dupa depasirea targetului se mai adauga la plata finala suma cu care promoterul este platit pe ora
    //de ex: un promoter distribuie 210 anunturi=> plata_finala=plata_ora*ore_lucrate +comision + (210-200)*plata_ora
    void depasire_target();


};

#endif


