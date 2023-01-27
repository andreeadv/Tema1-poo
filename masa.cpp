#include "masa.h"
#include <iostream>

template <typename T>
Masa<T>:: Masa(T zona_, T nrmasa_, T nrlocuri_):zona(zona_),nr_masa(nrmasa_),nr_locuri(nrlocuri_){}

template <typename T>
Masa<T>:: Masa(const Masa<T> &other):zona(other.zona), nr_masa(other.nr_masa), nr_locuri(other.nr_locuri){}

template <typename T>
Masa<T> &Masa<T>:: operator=(const Masa<T> &other){

	zona=other.zona;
	nr_masa=other.nr_masa;
	nr_locuri=other.nr_locuri;
	return (*this);
}

template <typename T>
T Masa<T>::get_masa()const{
	return nr_masa;
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const Masa<T>& ms){

	os << "Zona: ";
	if (ms.zona==1){
        os<<"interior";
	}
    else{
        os<<"exterior";
    }
	os<< ", Numar masa: " << ms.nr_masa << ", Numar locuri: " << ms.nr_locuri<<"\n";
	return os;
}

template <typename T>
Masa<T>::~Masa()=default;

template<typename T>
void Masa<T>::rezervari(){
    if(nr_locuri<4){
            std::cout<<"libera\n";
    }
    else {
        std::cout<<" rezervata pentru grupuri organizate\n";
    }

}
template <typename T>
T LocuriPeZone(const std::vector<Masa<T>>&mese, T zona_){
        T total=0;
        for(auto i=0u;i<mese.size();i++){
            if(mese[i].zona==zona_){
                total+=mese[i].nr_locuri;
            }
        }
        return total;
    }
/*
Masa::Masa(){
    //std::cout<<"Constructor fara parametrii Masa\n";
}
Masa::Masa(unsigned int zona_, int nr_masa_, int nr_locuri_) : zona{zona_}, nr_masa{nr_masa_}, nr_locuri{nr_locuri_} {
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
*/
