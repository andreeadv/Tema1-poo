#include "masa.h"
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
        //std::cout << "operator= copiere Masa\n";
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
