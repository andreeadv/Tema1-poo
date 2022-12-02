#ifndef PREPARAT_H
#define PREPARAT_H
#include <iostream>
#include <string>

class Preparat{
     std::string nume_preparat;
     int gramaj;
     double pret;
     int timp_preparare;//in minute

public:
     Preparat ();
     Preparat(const std::string& nume_preparat_, int gramaj_, double pret_, int timp_preparare_);

     friend std::ostream& operator<<(std::ostream& os, const Preparat& prep);
     double get_pret()const;
     int get_timppreparare()const;
};

#endif//PREPARAT_H
