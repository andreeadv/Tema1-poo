#ifndef MASA_H
#define MASA_H
#include <iostream>
#include <string>

class Masa{

     std::string zona;//restaurantul dispune de 2 zone: interior, exterior
     int nr_masa;
     int nr_locuri;

 public:
    Masa();
    Masa(const std::string& zona_, int nr_masa_, int nr_locuri_);

    Masa(const Masa& other);

    Masa& operator=(const Masa& other);

    ~Masa();
    int get_masa()const;
    friend std::ostream& operator<<(std::ostream& os, const Masa& ms) ;

};
#endif//MASA_H
