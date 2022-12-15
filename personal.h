#ifndef PERSONAL_H
#define PERSONAL_H
#include <iostream>
#include <string>
#include<memory>
#include <utility>
#include<vector>
#include "angajat.h"


class Personal{

    std::vector<std::shared_ptr<Angajat>> angajati;

public:
     Personal();
     explicit Personal(const std::vector<std::shared_ptr<Angajat>> &angajati_);

     void raport_activitate()const;
     //suprascris cc/op= pentru copieri/atribuiri corecte
     Personal(const Personal &other);
     Personal &operator=(Personal other);

     friend std::ostream &operator<<(std::ostream &os, const Personal &pers);

     friend void swap(Personal &p1, Personal &p2);

};



#endif
