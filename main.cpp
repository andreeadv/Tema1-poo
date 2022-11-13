#include <iostream>
#include<string>
#include "clase.h"
#include<vector>
#include <algorithm>


int main()
{
    std::cout<<" MESE: \n";
    Masa m1("Interior",1,3);
    Masa m2("Exterior",2,2);
    std::cout<<m1;
    std::cout<<m2;

    Preparat paste("Paste",250,32.5,20);
    Preparat limonada("Limonada",100,19.99,5);
    Preparat pizza1("Pizza Margherita",350,38,30);
    Preparat pizza2("Pizza Quattro stagioni",350,45,40);

    std:: vector<Preparat>preparate_comandate1;
    preparate_comandate1.push_back(paste);
    preparate_comandate1.push_back(limonada);
    std:: vector<Preparat>preparate_comandate2;
    preparate_comandate2.push_back(pizza1);
    preparate_comandate2.push_back(pizza2);
    std:: vector<Preparat>preparate_comandate3;
    preparate_comandate3.push_back(limonada);

    std::cout<<"***************************\n COMENZI: \n";
    Comanda c1("cash",m1,101,preparate_comandate1,0);
    Comanda c2("card",m2,102,preparate_comandate2,0);
    Comanda c3("card",m2,103,preparate_comandate3,0);
    //afisare comenzi inainte de sortare
    std::cout<<"C1: "<<c1<<"\n";
    std::cout<<"C2: "<<c2<<"\n";
    std::cout<<"C3: "<<c3<<"\n";

    //afisare nota de plata pt comanda c1
    std::cout<<"Nota de plata pentru comanda C1: "<< c1.notadeplata(preparate_comandate1)<<" lei \n";
    //afisare nota de plata pt comanda c1
    std::cout<<"Nota de plata pentru comanda C2: "<< c2.notadeplata(preparate_comandate2)<<" lei \n";
    //afisare nota de plata pt comanda c3
    std::cout<<"Nota de plata pentru comanda C3: "<< c3.notadeplata(preparate_comandate3)<<" lei \n\n";


    c1.set_timp();
    c2.set_timp();
    c3.set_timp();

    std::cout<<"TIMP C1: "<<c1.get_timp()<<"\n";
    std::cout<<"TIMP C2: "<<c2.get_timp()<<"\n";
    std::cout<<"TIMP C3: "<<c3.get_timp()<<"\n\n";

    //odonare comenzi crescator dupa timpul total de preparare
    std:: vector<Comanda>comenzi;
    comenzi.push_back(c1);
    comenzi.push_back(c2);
    comenzi.push_back(c3);

    //odonare comenzi crescator dupa timpul total de pregatire
    std::sort(comenzi.begin(),comenzi.end(),[](const Comanda & a, const Comanda & b) -> bool{
    return a.get_timp()<b.get_timp();//pentru fals se face swap
    });

    std::cout<<"COMENZI SORTATE DUPA TIMPUL DE PRGATIRE\n";
    for(unsigned int i=0;i<comenzi.size();i++) {
        std::cout << comenzi[i];
    }

    std::cout<<"***************************\n OSPATARI: \n";

    Ospatar o1("Marian",6,2500,c1);
    Ospatar o2("Adina",1,2500,c2);

    //din 2 in 2 ani salariul ospatarilor se majoreaza cu 25%
    std::cout<<o1<<"Majorare: "<<o1.salariumajorat()<<" lei\n\n";//salariul afisat este cel actualizat,majorarile adaugandu-se la salariul de baza(2500 lei)
    std::cout<<o2<<"Majorare: "<<o2.salariumajorat()<<" lei\n\n";

    return 0;
}
///notes
/*
functionalitatile implementate:
>am calcul nota de plata pentru fiecare comanda
>am calculat prentru fiecare comanda timpul total de pregatire
>am sortat comenzile crescator dupa timpul de pregatire pentru eficientizarea servirii
>am implementat o functie care majoreaza salariul ospatarilor din 2 in 2 ani, plecand de la un
salariu de baza de 2500 de lei, salariul afisat fiind cel final(dupa majorarea aferenta vechimii)
*/