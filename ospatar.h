#ifndef OSPATAR_H
#define OSPATAR_H
#include <iostream>
#include <string>
#include "comanda.h"

class Ospatar{
     std::string nume;
     int vechime;//in ani
     double salariu;
     Comanda cmd;
public:
    Ospatar();
    Ospatar(const std::string& nume_,int vechime_, double salariu_,const Comanda &cmd_);

    friend std::ostream& operator<<(std::ostream& os, Ospatar& osp);

    ///functie pt majorare salariu cu 25% ospatarilor din 2 in 2 ani
     double salariumajorat();
};



#endif//OSPATAR_H
