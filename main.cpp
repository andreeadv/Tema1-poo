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
#include "bucatar.h"
#include "personal.h"
#include "promoter.h"
#include "exceptii.h"
//#include "dj.h"


int main()
{
    std::cout<<"-------MESE-------\n\n";
    Masa<int> masa1(1,1,2);
    Masa<int> masa2(1,2,3);
    Masa<int> masa3(1,3,6);
    Masa<int> masa4(2,4,12);
    Masa<int> masa5(2,5,5);

    std::cout<<masa1<<"->";masa1.rezervari();std::cout<<"\n";
    std::cout<<masa2<<"->";masa2.rezervari();std::cout<<"\n";
    std::cout<<masa3<<"->";masa3.rezervari();std::cout<<"\n";
    std::cout<<masa4<<"->";masa4.rezervari();std::cout<<"\n";
    std::cout<<masa5<<"->";masa5.rezervari();std::cout<<"\n";
    std::vector<Masa<int>> mese_arr = {masa1, masa2, masa3, masa4, masa5};

    std::cout<<"Nr. total de locuri disponibile la interior: "<<LocuriPeZone(mese_arr,1)<<"\n";
    std::cout<<"Nr. total de locuri disponibile la exterior: "<<LocuriPeZone(mese_arr,2)<<"\n\n";

    PreparatBuilder pb;
    Preparat paste=pb.Nume_preparat("Paste").Gramaj(250).Pret(32.5).Timp_prepare(20).build();
    Preparat limonada=pb.Nume_preparat("Limonada").Gramaj(100).Pret(19.99).Timp_prepare(5).build();
    Preparat pizza1=pb.Nume_preparat("Pizza Margherita").Gramaj(350).Pret(38).Timp_prepare(40).build();
    Preparat pizza2=pb.Nume_preparat("Pizza Quattro stagioni").Gramaj(350).Pret(45).Timp_prepare(40).build();


    std:: vector<Preparat>preparate_comandate1;
    preparate_comandate1.push_back(paste);
    preparate_comandate1.push_back(limonada);
    std:: vector<Preparat>preparate_comandate2;
    preparate_comandate2.push_back(pizza1);
    preparate_comandate2.push_back(pizza2);
    std:: vector<Preparat>preparate_comandate3;
    preparate_comandate3.push_back(limonada);
    std:: vector<Preparat>preparate_comandate4;
    preparate_comandate4.push_back(paste);
    preparate_comandate4.push_back(limonada);
    preparate_comandate4.push_back(pizza1);
    preparate_comandate4.push_back(pizza2);
    std::cout<<"***************************\n\n COMENZI: \n";
    Comanda c1("cash",masa1,preparate_comandate1,0);
    Comanda c2("card",masa2,preparate_comandate2,0);
    Comanda c3("card",masa2,preparate_comandate3,0);
    //afisare comenzi inainte de sortare

    std::cout<<"C1: "<<c1.get_id()<<c1<<"\n";
    std::cout<<"C2: "<<c2.get_id()<<c2<<"\n";
    std::cout<<"C3: "<<c3.get_id()<<c3<<"\n";
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
    std::cout<<"TIMP C3: "<<c3.get_timp()<<"\n";
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
try{
    std::cout<<"***************************\n\n OSPATARI: \n\n";
    std::cout<<">Mentiuni \nOspatarii primesc bonusuri financiare ce se calculeaza din suma de baza de "<<Ospatar::get_start()<<" lei\n";
    Ospatar o1("Anton Marian","a_marian@gmail.com","Bucuresti",20,5,2500,3);
    Ospatar o2("Micu Adina","m_adina@gmail.com","Bucuresti",18,1,2500,1);
    Ospatar o3("Craciun Alin","c_alin@gmial.com","Bucuresti",30,6,2500,2);
    Ospatar o4("Dima Miruna","d_miruna@gmial.com","Bucuresti",35,2,2500,1);
    Ospatar o5("Pascu Ionut","p_ionut@gmial.com","Bucuresti",25,1,2500,3);
    Ospatar o6("Popa Catalin","p_cata@gmial.com","Bucuresti",45,10,2500,1);
    Ospatar o7("Pavel Mircea","p_mircea@gmial.com","Bucuresti",28,4,2500,1);
    //pt acesta se va afisa mesaj de eroare, pt ca nu are varsta>=18 ani
    //Ospatar o8("Dobre Mirela","p_mircea@gmial.com","Bucuresti",17,4,2500,1);
    std::cout<<"----------Detalii initiale pentru Ospatari----------\n";
    std::cout<<o1<<"\n";
    std::cout<<o2<<"\n";
    std::cout<<o3<<"\n";
    std::cout<<o4<<"\n";
    std::cout<<o5<<"\n";
    std::cout<<o6<<"\n";
    std::cout<<o7<<"\n";
    std::cout<<"----------Raport bonusuri financiare pentru Ospatari---------\n\n";
    std::cout<<o1.get_nume()<<"\n"<<"Majorare de vechime:"<<o1.salariumajorat()<<"lei\n";
    o1.activitate();//bonusul pt schimbul de noapte se adauga la salariul curent, nu la salariul de baza
    std::cout<<o2.get_nume()<<"\n"<<"Majorare de vechime:"<<o2.salariumajorat()<<"\n";
    o2.activitate();
    std::cout<<o3.get_nume()<<"\n"<<"Majorare de vechime:"<<o3.salariumajorat()<<"\n";
    o3.activitate();
    std::cout<<o4.get_nume()<<"\n"<<"Majorare de vechime:"<<o4.salariumajorat()<<"\n";
    o4.activitate();
    std::cout<<o5.get_nume()<<"\n"<<"Majorare de vechime:"<<o5.salariumajorat()<<"\n";
    o5.activitate();
    std::cout<<o6.get_nume()<<"\n"<<"Majorare de vechime:"<<o6.salariumajorat()<<"\n";
    o6.activitate();
    std::cout<<o7.get_nume()<<"\n"<<"Majorare de vechime:"<<o7.salariumajorat()<<"\n";
    o7.activitate();
    std::cout<<"----------Detalii finale pentru Ospatari----------\n";
    std::cout<<o1<<"\n";
    std::cout<<o2<<"\n";
    std::cout<<o3<<"\n";
    std::cout<<o4<<"\n";
    std::cout<<o5<<"\n";
    std::cout<<o6<<"\n";
    std::cout<<o7<<"\n";
    std::cout<<"***************************\n\n BUCATARI: \n\n";
    Bucatar b1("Ilie Mihai","i_mihai2000@gmail.com","Bucuresti",40,"Grill chef",1,"REVELION");
    Bucatar b2("Popa Mihaela","p_miha23@gmail.com","Bucuresti",25,"Pizzar",1,"MAJORAT");
    Bucatar b3("Iacob George","i_george@gmail.com","Bucuresti",30,"Patiser",0,"BOTEZ");
    Bucatar b4("Mihai Elena","m_eli@gmail.com","Bucuresti",25,"Patiser",0,"NUNTA");
    std::cout<<"DETALII: \n\n";
    std::cout<<b1<<"\n";
    std::cout<<b2<<"\n";
    std::cout<<b3<<"\n";
    std::cout<<b4<<"\n";
    std::cout<<"ROLURILE BUCATARILOR: \n\n";
    b1.activitate();
    std::cout<<"---------------------\n";
    b2.activitate();
    std::cout<<"---------------------\n";
    b3.activitate();
    std::cout<<"---------------------\n";
    b4.activitate();
    std::cout<<"\n\n***************************\n\n PROMOTERI: \n\n";
    std::cout<<">Mentiuni \nPromoterii primesc comisionul de "<<Promoter::get_comision()<<"lei doar daca indeplinesc targetul de "<<Promoter::get_prag()<<" de anunturi distribuite\n";
    Promoter pr1("Laur Mihnea","l_mihnea@gmail.com","Ploiesti",19,40,0,100,10);//nu a indeplinit targetul=>nu are comision
    Promoter pr2("Dobre Mihaela","d_mihaela@gmail.com","Pitesti",18,80,0,200,10);
    Promoter pr3("Ion Razvan","i_razvan@gmail.com","Buzau",21,100,0,210,10);
    Promoter pr4("Mia Alina","mm_alina@gmail.com","Bucuresti",21,32,0,150,10);
    std::cout<<"\n---------Date initiale---------\n";
    std::cout<<pr1<<"\n";
    std::cout<<pr2<<"\n";
    std::cout<<pr3<<"\n";
    std::cout<<pr4<<"\n";
    std::cout<<"\n---------Status performante---------\n";
    pr1.activitate();
    pr2.activitate();
    pr3.activitate();
    pr4.activitate();
    pr3.depasire_target();//plata_finala=100*10+600+(210-200)*10=1000+600+100=17000
    std::cout<<"\n---------Date finale--------\n";//evidentierea sumei pe care promoterul o primeste la sfarsitul lunii
    std::cout<<pr1<<"\n";
    std::cout<<pr2<<"\n";
    std::cout<<pr3<<"\n";
    std::cout<<pr4<<"\n";
    //adaugare derivata dupa tag
/*
    std::cout<<"\n***************************\n\n DJ: \n\n";
    Dj dj1("Nita Adrian","n_adr@gmail.com","Buzau", 19,1,1,3500,2);
    Dj dj2("Bucur Cristian","b_cristian@gmail.com","Ploiesti",25,0,0,2500,0);

    std::cout<<dj1<<"\n";
    std::cout<<dj2<<"\n";

    std::cout<<"Raport activitate pentru fiecare dj\n\n";
    dj1.activitate();
    dj2.activitate();

    std::cout<<"\nDetali finale: \n";
    std::cout<<dj1<<"\n";
    std::cout<<dj2<<"\n";
*/
    std::cout<<"\n---RAPORT DE ACTIVITATE AL INTREGULUI PERSONAL---\n\n";
    auto ang_ = {o1.clone(), o2.clone(),o3.clone(),o4.clone(),o5.clone(),o6.clone(),o7.clone(), b1.clone(), b2.clone(),b3.clone(),b4.clone(),pr1.clone(),pr2.clone(),pr3.clone(),pr4.clone()};//vectorul contine toti angajatii restaurantului
    Personal pers{ang_};
    pers.raport_activitate();
    //afisarea tuturor angajatilor
//    for( const auto &angajat: ang_)
//         std::cout << *angajat<< "\n";
    Personal p;
    //std::cout<<"\n\ndynamic_cast\n";
    std::cout<<"\n\nValidare cu parametru --ospatar--\n";
    p.validare_salariu(&o1);
    std::cout<<"\nValidare cu parametru --promoter--\n";//promoterul este platit pe ora, astfel ca nu exista majorari pentru salariul sau
    p.validare_salariu(&pr1);

}
    catch(eroare_angajat &error)
       {std::cout<<error.what()<<"\n";}
    catch(eroare_plata &error)
       {std::cout<<error.what()<<"\n";}


    return 0;
}
