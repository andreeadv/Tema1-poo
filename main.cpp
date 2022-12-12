#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<utility>
#include "masa.h"
#include "preparat.h"
#include "comanda.h"
#include "ospatar.h"
#include "angajat.h"


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
//t2
    std::cout<<"***************************\n\n OSPATARI: \n\n";

    Ospatar o1("Anton Marian","a_marian@gmail.com","Bucuresti",20,5,2500,c1,3);
    Ospatar o2("Micu Adina","m_adina@gmail.com","Bucuresti",18,1,2500,c2,1);
    Ospatar o3("Craciun Alin","c_alin@gmial.com","Bucuresti",30,6,2500,c3,2);


    std::cout<<"----------Detalii initiale----------\n";

    std::cout<<o1<<"\n";
    std::cout<<o2<<"\n";
    std::cout<<o3<<"\n";

    std::cout<<"----------Raport bonusuri financiare---------\n\n";

    std::cout<<o1.get_nume()<<"\n"<<"Majorare de vechime:"<<o1.salariumajorat()<<"lei\n";
    o1.activitate();//bonusul pt schimbul de noapte se adauga la salariul curent, nu la salariul de baza

    std::cout<<o2.get_nume()<<"\n"<<"Majorare de vechime:"<<o2.salariumajorat()<<"\n";
    o2.activitate();

    std::cout<<o3.get_nume()<<"\n"<<"Majorare de vechime:"<<o3.salariumajorat()<<"\n";
    o3.activitate();


    std::cout<<"----------Detalii finale----------\n";

    std::cout<<o1<<"\n";
    std::cout<<o2<<"\n";
    std::cout<<o3<<"\n";

    return 0;
}
