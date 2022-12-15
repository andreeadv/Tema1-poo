#include "promoter.h"

Promoter::Promoter(){}

Promoter::Promoter(const std::string& nume,const  std::string& email, const std::string& localitate,int varsta,int ore_lucrate_,double plata_finala_,int anunturi_distribuite_,int plata_ora_):
Angajat(nume, email, localitate, varsta),ore_lucrate(ore_lucrate_),plata_finala(plata_finala_),anunturi_distribuite(anunturi_distribuite_), plata_ora(plata_ora_){}

void Promoter::afisare(std::ostream &os) const {

        os << "->Ore lucrate/luna: " << ore_lucrate << "\n";
        os<< "->Performanta: " << anunturi_distribuite << " anunturi\n";
        os<< "->Plata/ora: "<<plata_ora<<" lei\n";
        os<< "->Plata finala: "<<plata_finala<<" lei\n";;
    }


std::shared_ptr<Angajat>Promoter:: clone() const {
        return std::make_shared<Promoter>(*this); }
int Promoter::prag_comision=200;//daca promoterul distribuie peste 200 de anuntri primeste un comision
int Promoter::comision=600;
int Promoter::get_prag(){return prag_comision;}
int Promoter::get_comision(){return comision;}


void Promoter::activitate(){

   if(anunturi_distribuite>=get_prag())
   {
       std::cout<<nume<<" a indeplinit targetul"<<"!\n";
       //promoterul primeste comisionul doar daca a indeplinit targetul in intregime
       plata_finala+=get_comision();//la plata finala se adauga comisionul
   }
   else
       std::cout<<nume<<"nu a indeplinit targetul"<<"!\n";

   plata_finala=plata_finala+(ore_lucrate*plata_ora);

}
