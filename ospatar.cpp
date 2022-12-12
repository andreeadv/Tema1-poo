#include "ospatar.h"


Ospatar::Ospatar(){
    //std::cout<<"Constructor de initializare fara parametrii ospatar\n";
}

Ospatar::Ospatar(const std::string& nume,const  std::string& email, const std::string localitate,int varsta,int vechime_, double salariu_,const Comanda &cmd_, int schimb_):
                  Angajat(nume, email, localitate, varsta),vechime(vechime_),salariu(salariu_),cmd(cmd_),schimb(schimb_){
                 //std::cout << "Constructor de initializare cu parametrii Ospatar\n";
                }


//std::ostream& operator<<(std::ostream& os,const Ospatar& osp) {
//       os << "Nume: " << osp.nume <<  ", Vechime: " <<osp.vechime<<", Salariu: " << osp.salariu <<", Comanda: "<<osp.cmd.get_id()<<"\n";
//        return os;
//    }

std::shared_ptr<Angajat>Ospatar:: clone() const {
        return std::make_shared<Ospatar>(*this); }


void Ospatar::set_salariu(double sal){salariu=sal;}

void Ospatar::activitate(){
      double bonus=0;
      if(schimb==3)
      {
          std::cout<<nume<<" lucreaza tura de noapte => ";
          bonus=0.25*salariu;
          std::cout<<"Bonus ore de noapte: "<<bonus<<"lei\n\n";
          salariu+=bonus;
      }
      if(schimb==1)
      {
          std::cout<<nume<<" lucreaza tura de dimineata => nu primeste bonus de noapte\n\n";
      }
      if(schimb==2)
      {
          std::cout<<nume<<" lucreaza tura de dupa-amiaza=> nu primeste bonus de noapte\n\n";
      }

    }

double Ospatar::get_salariu()const{return salariu;}


void Ospatar::afisare(std::ostream &os) const {
        os << "->Vechime: " << vechime << " ani\n"
           << "->Salariu: " << salariu<< " lei\n"
           << "->Comanda: " << cmd.get_id() << "\n"
           << "->Schimb: " << schimb << "\n";
    }
int Ospatar::start_salariu=2500;

int Ospatar:: get_start(){ return start_salariu;}

std::string Ospatar::get_nume()const{return nume;}

double Ospatar::salariumajorat(){
        if (vechime<2)
        {
            return 0;
        }
        int nrmajorari=vechime/2;
        double majorare=nrmajorari*0.3*get_start();// se majoreaza cu 30% din 2 in 2 ani
        salariu+=majorare;
        return majorare;

    }
//Ospatar::Ospatar(const Ospatar &other):Angajat(other){
//
//vechime=other.vechime;
//salariu=other.salariu;
//cmd=other.cmd;
//schimb=other.schimb;
//}

//Ospatar &Ospatar::operator=(const Ospatar &other) {
//    Angajat::operator=(other);
//    vechime = other.vechime;
//    salariu = other.salariu;
//    cmd = other.cmd;
//    schimb=other.schimb;
//    return *this;
//}
