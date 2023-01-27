#ifndef MASA_H
#define MASA_H
#include <iostream>


template <typename T>
class Masa;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Masa<T>& ms);

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
