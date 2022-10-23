//#pragma once
#ifndef CLASE.H
#define CLASE.H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Masa{
     string zona;//restaurantul dispune de 2 zone,acestea fiind numite: interior, exterior
     int nr_masa;
     int nr_locuri;

 public:
    Masa();
    Masa(const string& zona_, int nr_masa_, int nr_locuri_);

    Masa(const Masa& other);

    Masa& operator=(const Masa& other);

    ~Masa();

    friend ostream& operator<<(ostream& os, const Masa& ms) ;
};

class Preparat{
     string nume_preparat;
     float gramaj;
     float pret;
     int timp_preparare;//in minute

public:
     Preparat ();
     Preparat(const string& nume_preparat_, float gramaj_, float pret_, int timp_preparare_);

    friend ostream& operator<<(ostream& os, const Preparat& prep);

};

class Comanda{
    int ID_COMANDA;
    string tip_plata;//cash/card
    Masa tip_masa;
    int nr_preparate;

public:
    Comanda();
      Comanda(const string& tip_plata_, Masa tip_masa_, int nr_preparate_, int id) : tip_plata{tip_plata_},tip_masa{tip_masa_}, nr_preparate{nr_preparate_}, ID_COMANDA{id}{
      }

    int get_id(){
        return ID_COMANDA;
        }

 friend ostream& operator<<(ostream& os,Comanda& cmd) {
       os << "ID comanda: " << cmd.ID_COMANDA << " tip plata: " << cmd.tip_plata <<endl;
        return os;
    }
};

class Ospatar{
     string nume;
     float salariu;
      Comanda cmd;
public:
    Ospatar();
    Ospatar(const string& nume_, float salariu_, Comanda cmd_);

    friend ostream& operator<<(ostream& os, Ospatar& osp) {
       os << "Nume: " << osp.nume << ", Salariu: " << osp.salariu <<"Comanda: "<<osp.cmd.get_id()<<endl;
        return os;
    }
};

#endif // CLASE
