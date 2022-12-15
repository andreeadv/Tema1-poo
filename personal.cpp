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

void swap(Personal &p1, Personal &p2) {
        using std::swap;
        swap(p1.angajati, p2.angajati);
    }
