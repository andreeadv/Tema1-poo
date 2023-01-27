#ifndef MASA_H
#define MASA_H
#include <iostream>
#include <vector>

template <typename T>
class Masa;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Masa<T>& ms);

template <typename T>
T LocuriPeZone(const std::vector<Masa<T>>&mese, T zona_);

template <typename T>
class Masa{
private:
	T zona;
	T nr_masa;
	T nr_locuri;
public:
	Masa(T zona_, T nrmasa_, T nrlocuri_);

	Masa (const Masa<T> &other);

	Masa<T> &operator=(const Masa<T> &other);

	T get_masa()const;

	friend std::ostream &operator<< <>(std::ostream &os, const Masa<T>& ms);
    //functie membru ce eticheteaza masa ca fiind rezervata/libera in functie de nr de locuri
    void rezervari();
    //determina numarul total de locuri pt fiecare zona a restaurantului
    friend T LocuriPeZone <>(const std::vector<Masa<T>>&mese, T zona_);

	~Masa();
};

/*
class Masa{

     unsigned int zona;//restaurantul dispune de mai multe zone, identificate printr-un numar
     int nr_masa;
     int nr_locuri;

 public:
    Masa();
    Masa(unsigned int zona_, int nr_masa_, int nr_locuri_);
    Masa(const Masa& other);
    Masa& operator=(const Masa& other);
    ~Masa();
    int get_masa()const;
    friend std::ostream& operator<<(std::ostream& os, const Masa& ms) ;

};

*/
#endif//MASA_H
