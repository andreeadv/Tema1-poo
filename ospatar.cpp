#include "ospatar.h"

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

double Ospatar::salariumajorat(){
        if (vechime<2)
            return 0;
        int majorare=0;
        int nrmajorari=vechime/2;
        majorare+=nrmajorari*0.25*salariu;// se majoreaza cu 25% din 2 in 2 ani
        salariu+=majorare;
        return majorare;

    }
