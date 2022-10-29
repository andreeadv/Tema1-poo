#include <iostream>
#include<string>
#include "clase.h"


int main()
{
    Masa m("Interior",2,3);
    std::cout<<m;
    Comanda c("cash",m,3,1);
    Ospatar o("Marian",123,c);
    std::cout<<c;
    std::cout<<o;
    return 0;
}