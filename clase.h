#ifndef CLASE_H
#define CLASE_H
#include <iostream>
#include <string>
#include <vector>

class Masa{
     std::string zona;//restaurantul dispune de 2 zone,acestea fiind numite: interior, exterior
     int nr_masa;
     int nr_locuri;

 public:
    Masa();
    Masa(const std::string& zona_, int nr_masa_, int nr_locuri_);

    Masa(const Masa& other);

    Masa& operator=(const Masa& other);

    ~Masa();
    int get_masa(){
        return nr_masa;
        }

    friend std::ostream& operator<<(std::ostream& os, const Masa& ms) ;
};

class Preparat{
     std::string nume_preparat;
     float gramaj;
     float pret;
     int timp_preparare;//in minute

public:
     Preparat ();
     Preparat(const std::string& nume_preparat_, float gramaj_, float pret_, int timp_preparare_);

     friend std::ostream& operator<<(std::ostream& os, const Preparat& prep);

};

class Comanda{
    int ID_COMANDA;
    std::string tip_plata;//cash/card
    Masa tip_masa;
    std::vector<Preparat> preparate_comandate;

public:
      Comanda();
      Comanda(const std::string& tip_plata_, Masa tip_masa_, int id, std::vector<Preparat> preparate_comandate_) : ID_COMANDA{id}, tip_plata{tip_plata_},tip_masa{tip_masa_}, preparate_comandate(std::move(preparate_comandate_))
      {}
    int get_id(){
        return ID_COMANDA;
        }

    friend std::ostream& operator<<(std::ostream& os, Comanda& cmd);
};

class Ospatar{
     std::string nume;
     float salariu;
     Comanda cmd;
public:
    Ospatar();
    Ospatar(const std::string& nume_, float salariu_, Comanda cmd_);

    friend std::ostream& operator<<(std::ostream& os, Ospatar& osp);
};

#endif