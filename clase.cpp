#include "clase.h"

Masa::Masa(){
    //std::cout<<"Constructor fara parametrii Masa\n";
}
Masa::Masa(const std::string& zona_, int nr_masa_, int nr_locuri_) : zona{zona_}, nr_masa{nr_masa_}, nr_locuri{nr_locuri_} {
        //std::cout << "Constructor de initializare cu parametri Masa\n";
    }
Masa::Masa(const Masa& other):zona{other.zona}, nr_masa{other.nr_masa}, nr_locuri{other.nr_locuri} {
        //std::cout << "Constructor de copiere Masa\n";
    }
Masa&Masa::operator=(const Masa& other){
        zona = other.zona;
        nr_masa = other.nr_masa;
        nr_locuri=other.nr_locuri;
        //std::cout << "operator= copiere masa\n";
        return *this;
    }
 Masa::~Masa(){
        //std::cout << "Destructor Masa\n";
    }

std::ostream& operator<<(std::ostream& os, const Masa& ms) {
        os << "Zona: " << ms.zona << ", Numar masa: " << ms.nr_masa << ", Numar locuri: " << ms.nr_locuri<<"\n";
        return os;
    }
int Masa::get_masa()const{
        return nr_masa;
        }
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

Ospatar::Ospatar(){
    //std::cout<<"Constructor de initializare fara parametrii ospatar\n";
}
Ospatar::Ospatar(const std::string& nume_,int vechime_, double salariu_, const Comanda &cmd_) : nume{nume_},vechime{vechime_}, salariu{salariu_}, cmd{cmd_} {
        //std::cout << "Constructor de initializare cu parametrii Ospatar\n";
    }
std::ostream& operator<<(std::ostream& os, Ospatar& osp) {
       os << "Nume: " << osp.nume <<  ", Vechime: " <<osp.vechime<<", Salariu: " << osp.salariu <<", Comanda: "<<osp.cmd.get_id()<<"\n";
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
double Ospatar::salariumajorat(){
        if (vechime<2)
            return 0;
        int majorare=0;
        int nrmajorari=vechime/2;
        majorare+=nrmajorari*0.25*salariu;// se majoreaza cu 25% din 2 in 2 ani
        salariu+=majorare;
        return majorare;

    }
