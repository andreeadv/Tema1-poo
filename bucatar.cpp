#include "bucatar.h"

Bucatar::Bucatar(){}

Bucatar::Bucatar(const std::string& nume,const  std::string& email, const std::string& localitate,int varsta,const std::string& specializare_, bool sef_, const std::string& meniu_eveniment_):
Angajat(nume, email, localitate, varsta),specializare(specializare_),sef(sef_),meniu_eveniment(meniu_eveniment_){}

void Bucatar::afisare(std::ostream &os) const {
        os << "->Specializare: " << specializare << "\n";
        os<< "->Post: ";
        if (sef==1)
             os<< "Bucatar sef "<< " \n";
        else
             os<<"Bucatar "<<"\n";
        os<< "->Tip meniu eveniment: " << meniu_eveniment << "\n";
    }

std::shared_ptr<Angajat>Bucatar:: clone() const {
        return std::make_shared<Bucatar>(*this); }


void Bucatar::activitate(){
   if(sef==1)
   {   //un bucatar este sef doar pentru cei cu aceeasi specializare
       std::cout<<nume<<" este bucatar sef."<<"El ii coordoneaza pe ceilalti bucatari cu specializarea !"<<specializare<<"!\n";
   }
   if(specializare.compare("Patiser")==0)
   {
       std::cout<<nume<<" se ocupa de pregatirea candy bar pentru evenimente "<<"\n";//salariul lui va fi mai mare
   }
   std::cout<<nume<<" contribuie la pregatirea si stabilirea meniului de "<<meniu_eveniment<<"\n";
}

