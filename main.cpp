#include <iostream>
#include<string>
#include "clase.h"
#include<vector>

int main()
{
    std::cout<<" MASA: \n";
    Masa m("Interior",2,3);
    std::cout<<m;
    Preparat paste("Paste",250,32.5,20);
    Preparat limonada("Limonada",100,19.99,5);
    Preparat pizza1("Pizza Margherita",350,38,30);

    std:: vector<Preparat>preparate_comandate;
    preparate_comandate.push_back(paste);
    preparate_comandate.push_back(limonada);
    preparate_comandate.push_back(pizza1);
    std::cout<<"***************************\n COMANDA: \n";
    Comanda c("cash",m,101,preparate_comandate);
    std::cout<<c;

    std::cout<<"***************************\n OSPATAR: \n";
    Ospatar o("Marian",1525,c);
    std::cout<<o;

    return 0;
}