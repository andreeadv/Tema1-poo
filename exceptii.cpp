#include "exceptii.h"


eroare_angajat::eroare_angajat(const std::string &mesaj): eroare_aplicatie("Eroare Angajat: " + mesaj){}

eroare_comanda::eroare_comanda(const std::string &mesaj):eroare_aplicatie("Eroare Comanda: " + mesaj){}

eroare_plata::eroare_plata(const std::string &mesaj):eroare_aplicatie("Eroare Plata: " + mesaj){}
