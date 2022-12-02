#include "comanda.h"

Comanda::Comanda()
{
    //std::cout<<"Constructor fara parametrii Comanda\n";
}

std::ostream& operator<<(std::ostream& os, Comanda& cmd) {
       os << "ID comanda: " << cmd.ID_COMANDA << " Tip plata: " << cmd.tip_plata<<", Nr. masa: "<<cmd.tip_masa.get_masa()<<" Preparate comandate: "<<", TIMP: "<<cmd.timptotalprep<<" minute\n\n";

       for (const auto &prep: cmd.preparate_comandate)
            os <<">"<< prep << " \n";
       return os;
    }
int Comanda::get_id()const{
        return ID_COMANDA;
        }
void Comanda::set_timp(){
    timptotalprep=timptotal(preparate_comandate);
    }
int Comanda::get_timp()const{
    return timptotalprep;
    }
double Comanda::notadeplata(std::vector<Preparat> preparate_comandate_){
       double total_plata=0;
       for(auto i = 0u;i<preparate_comandate_.size();i++)
          total_plata+=preparate_comandate_[i].get_pret();
        return total_plata;
    }
int Comanda::timptotal(std::vector<Preparat> preparate_comandate_){
       int timp_total=0;
       for(auto i = 0u;i<preparate_comandate_.size();i++)
          timp_total+=preparate_comandate_[i].get_timppreparare();
       return timp_total;
    }
