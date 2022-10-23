#include <iostream>
#include<string>
#include "clase.h"
using namespace std;


int main()
{
    Masa m("Interior",2,3);
    cout<<m;
    Comanda c("cash",m,3,1);
    Ospatar o("Marian",123,c);
    cout<<c;
    cout<<o;
    return 0;
}
