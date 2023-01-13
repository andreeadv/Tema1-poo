#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <stdexcept>
#include <string>

class eroare_aplicatie:public std::runtime_error {
    using std::runtime_error::runtime_error;
};
//angajatul trb sa aiba varsta minima de 18 ani
class eroare_angajat : public eroare_aplicatie {
public:
    explicit eroare_angajat(const std::string &mesaj);
};

//un promoter nu poate fi platit cu mai putin de 8 lei pe ora => plata_ora>=8lei
class eroare_plata: public eroare_aplicatie{
public:
    explicit eroare_plata(const std::string &mesaj);

};
#endif