#include "exceptii.h"


eroare_angajat::eroare_angajat(std::string mesaj): eroare_aplicatie("Eroare Angajat: " + mesaj){}

eroare_comanda::eroare_comanda(std::string mesaj):eroare_aplicatie("Eroare Comanda: " + mesaj){}

eroare_plata::eroare_plata(std::string mesaj):eroare_aplicatie("Eroare Plata: " + mesaj){}
