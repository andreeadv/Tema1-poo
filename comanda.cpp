#include "comanda.h"


int Comanda::id_max=100;
Comanda::Comanda(const std::string& tip_plata_, Masa<int> &tip_masa_, std::vector<Preparat> preparate_comandate_, int timptotalprep_) : ID_COMANDA{id_max}, tip_plata{tip_plata_},tip_masa{tip_masa_}, preparate_comandate(std::move(preparate_comandate_)), timptotalprep{timptotalprep_}{
++id_max;
}

std::ostream& operator<<(std::ostream& os, Comanda& cmd) {
       os <<" Tip plata: " << cmd.tip_plata<<", Nr. masa: "<<cmd.tip_masa.get_masa()<<" Preparate comandate: "<<", TIMP: "<<cmd.timptotalprep<<" minute\n\n";

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

Comanda::Comanda(const Comanda& other)=default;

Comanda&Comanda::operator=(const Comanda& other){
        tip_plata = other.tip_plata;
        tip_masa=other.tip_masa;
        preparate_comandate=other.preparate_comandate;
        timptotalprep=other.timptotalprep;
        return *this;
    }