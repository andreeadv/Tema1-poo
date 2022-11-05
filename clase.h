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
     int gramaj;
     double pret;
     int timp_preparare;//in minute

public:
     Preparat ();
     Preparat(const std::string& nume_preparat_, int gramaj_, double pret_, int timp_preparare_);

     friend std::ostream& operator<<(std::ostream& os, const Preparat& prep);
     double get_pret()
     {
         return pret;
     }
     int get_timppreparare()
     {
         return timp_preparare;
     }
};

class Comanda{
    int ID_COMANDA;
    std::string tip_plata;//cash/card
    Masa tip_masa;
    std::vector<Preparat> preparate_comandate;
    int timptotalprep;

public:
      Comanda();
      Comanda(const std::string& tip_plata_, Masa &tip_masa_, int id, std::vector<Preparat> preparate_comandate_, int timptotalprep_) : ID_COMANDA{id}, tip_plata{tip_plata_},tip_masa{tip_masa_}, preparate_comandate(std::move(preparate_comandate_)), timptotalprep{timptotalprep_}
      {}
    int get_id(){
        return ID_COMANDA;
        }

    friend std::ostream& operator<<(std::ostream& os, Comanda& cmd);
    //functie care sa calculeze nota de plata(pretul total al produselor comandate)
    double notadeplata(std::vector<Preparat> preparate_comandate_);
    //calculeaza timpul de pregatire al unei comenzi(suma timpurilor de preparare a preparatelor comandate)
    int timptotal(std::vector<Preparat> preparate_comandate_);

    void set_timp(){timptotalprep=timptotal(preparate_comandate);}
    int get_timp(){return timptotalprep;}


};

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

#endif
