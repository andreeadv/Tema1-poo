#include "preparat.h"

Preparat::Preparat (){
    //std::cout<<"Constructor fara parametrii Preparat\n";
}
Preparat:: Preparat(const std::string& nume_preparat_, int gramaj_, double pret_, int timp_preparare_) : nume_preparat{nume_preparat_}, gramaj{gramaj_}, pret{pret_}, timp_preparare{timp_preparare_}{
        //std::cout << "Constructor de initializare cu parametrii Preparat\n";
    }
std::ostream& operator<<(std::ostream& os, const Preparat& prep) {
        os << "Nume preparat: " << prep.nume_preparat << ", Gramaj: " << prep.gramaj << ", Pret: " << prep.pret<<" lei"<<", Timp de preparare: " << prep.timp_preparare<<" minute \n";
        return os;
}

double Preparat::get_pret()const{
         return pret;
     }

int Preparat::get_timppreparare()const{
         return timp_preparare;
     }
