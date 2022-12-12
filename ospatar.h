#ifndef OSPATAR_H
#define OSPATAR_H
#include <iostream>
#include <string>
#include "comanda.h"
#include "angajat.h"

class Ospatar: public Angajat{

private:

     int vechime;//in ani
     double salariu;
     Comanda cmd;
     int schimb;//sch 1, 2, 3
     static int start_salariu;


     void afisare(std::ostream &os) const override;

public:

    Ospatar();
    Ospatar(const std::string& nume,const  std::string& email, const std::string localitate,int varsta,int vechime_, double salariu_,const Comanda &cmd_, int schimb_);
   // friend std::ostream& operator<<(std::ostream& os, Ospatar& osp);//necomentat e eroare
    std::shared_ptr<Angajat> clone() const override;

    //Ospatar(const Ospatar &other);
    //Ospatar& operator =(const Ospatar &other);

     void set_salariu(double sal);
     //un ospatar poate sa lucreze doar pe o singur schimb
     //activitatea la ospatari se refera la bonusul pe care il primesc in functie de tura pe care lucreaza
     //pt tura de noapte ospatarul primeste un bonus de 25%
     void activitate() override;
     double get_salariu()const;
     static int get_start();//salariul de baza la care se adauga bonusurile financiare ale ospatarilor este de 2500lei
     std::string get_nume()const;
      ///functie pt majorare salariu cu 30% ospatarilor din 2 in 2 ani
     double salariumajorat();//majorarea se face la salariu de start(salariul la angajare al unui ospatar)

};


#endif//OSPATAR_H