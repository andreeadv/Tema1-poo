#ifndef BUCATAR_H
#define BUCATAR_H
#include <iostream>
#include <string>
#include<memory>
#include <utility>
#include "angajat.h"

class Bucatar: public Angajat{

private:
     std::string specializare;//patiser,grill chef,pizzar
     bool sef;//1 daca este bucatar sef, 0 daca nu
     std::string meniu_eveniment;//in cadrul restaurantului fiecarui bucatar ii este atribuit un anumit tip de meniu (ex:pt Nunta, Botez, Majorat, Revelion, etc)

     void afisare(std::ostream &os) const override;

public:

    Bucatar();
    Bucatar(const std::string& nume,const  std::string& email, const std::string& localitate,int varsta,const std::string& specializare_,bool sef_, const std::string& meniu_eveniment_);
    std::shared_ptr<Angajat> clone() const override;
    void activitate() override;


};







#endif