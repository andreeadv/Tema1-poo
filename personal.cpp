#include "personal.h"

Personal::Personal(){}
Personal:: Personal(const std::vector<std::shared_ptr<Angajat>> &angajati_){
         for (const auto &angajat: angajati_)
             angajati.push_back(angajat->clone());
     }



Personal::Personal(const Personal &other){
        for (const auto &angajat: other.angajati)
            angajati.push_back(angajat->clone());
    }

Personal& Personal::operator=(Personal other) {
        // std::cout << "op= ANG\n";
        swap(*this, other);
        return *this;
    }

void swap(Personal &p1, Personal &p2) {
        using std::swap;
        swap(p1.angajati, p2.angajati);
    }
void Personal::raport_activitate()const{
        for (auto &angajat: angajati)
            angajat->activitate();
    }
std::ostream &operator<<(std::ostream &os, const Personal &pers) {
        //std::cout << "op= ANG\n";
        for (const auto &angajat: pers.angajati)
            os << *angajat<< "\n";

        return os;
    }
void Personal:: testcast1(Angajat *angajat_){

  if(auto* ao = dynamic_cast<Ospatar*>(angajat_)) {
        std::cout << "test cast pointer reusit\n";
        ao->salariumajorat();
    }
    else
        std::cout << "test cast pointer nereusit\n";

    try {
        auto& ao = dynamic_cast<Ospatar&>(*angajat_);
        std::cout << "test cast referinta reusit\n";
        ao.salariumajorat();
    } catch(std::bad_cast& err) {
        std::cout << "test cast referinta nereusit: " << err.what() << "\n";
    }
}
void Personal::testcast2(Angajat& angajat_) {
    if(auto* ao = dynamic_cast<Promoter*>(&angajat_)) {
        std::cout << "test2 cast pointer reusit\n";
        ao->depasire_target();
    }
    else
        std::cout << "test2 cast pointer nereusit\n";

    try {
        auto& co = dynamic_cast<Promoter&>(angajat_);
        std::cout << "test2 cast referinta reusit\n";
        co.depasire_target();
    } catch(std::bad_cast& err) {
        std::cout << "test2 cast referinta nereusit: " << err.what() << "\n";
    }
}
