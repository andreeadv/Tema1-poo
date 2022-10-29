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


Comanda::Comanda()
{
    //std::cout<<"Constructor fara parametrii Comanda\n";
}
///explicatie??
std::ostream& operator<<(std::ostream& os, Comanda& cmd) {
       os << "ID comanda: " << cmd.ID_COMANDA << " Tip plata: " << cmd.tip_plata<<", Nr. masa: "<<cmd.tip_masa.get_masa()<<" Preparate comandate: "<<"\n\n";

       for (const auto &prep: cmd.preparate_comandate)
            os <<">"<< prep << " \n";
            /**
            for(const auto& stud : vec2) {
                std::cout << stud;
             }*/
       return os;
    }

Ospatar::Ospatar(){
    //std::cout<<"Constructor de initializare fara parametrii ospatar\n";
}
Ospatar::Ospatar(const std::string& nume_, double salariu_, const Comanda &cmd_) : nume{nume_}, salariu{salariu_}, cmd{cmd_} {
        //std::cout << "Constructor de initializare cu parametrii Ospatar\n";
    }
std::ostream& operator<<(std::ostream& os, Ospatar& osp) {
       os << "Nume: " << osp.nume << ", Salariu: " << osp.salariu <<", Comanda: "<<osp.cmd.get_id()<<"\n";
        return os;
    }
