#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "masa.h"
#include "preparat.h"
#include "exceptii.h"
#include "Masa_impl.cpp"

class Comanda{
    static int id_max;
    const int ID_COMANDA;
    std::string tip_plata;//cash/card
    Masa<int> tip_masa;
    std::vector<Preparat> preparate_comandate;
    int timptotalprep;

public:

    Comanda(const std::string& tip_plata_, Masa<int> &tip_masa_,std::vector<Preparat> preparate_comandate_, int timptotalprep_);
    int get_id()const;
    friend std::ostream& operator<<(std::ostream& os, Comanda& cmd);
    //functie care sa calculeze nota de plata(pretul total al produselor comandate)
    double notadeplata(std::vector<Preparat> preparate_comandate_);
    //calculeaza timpul de pregatire al unei comenzi(suma timpurilor de preparare a preparatelor comandate)
    int timptotal(std::vector<Preparat> preparate_comandate_);
    void set_timp();
    int get_timp()const;
    Comanda (const Comanda& other);
    Comanda& operator=(const Comanda& other);

};
#endif//COMANDA_H