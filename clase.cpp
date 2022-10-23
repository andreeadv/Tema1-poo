
#include "clase.h"
using namespace std;
Masa::Masa(){
    cout<<"Constructor fara param masa\n";
}
Masa::Masa(const string& zona_, int nr_masa_, int nr_locuri_) : zona{zona_}, nr_masa{nr_masa_}, nr_locuri{nr_locuri_} {
        cout << "Constr de inițializare cu parametri Masa\n";
    }
Masa::Masa(const Masa& other):zona{other.zona}, nr_masa{other.nr_masa}, nr_locuri{other.nr_locuri} {
        cout << "Constr de copiere Masa\n";
    }
Masa&Masa::operator=(const Masa& other){
        zona = other.zona;
        nr_masa = other.nr_masa;
        nr_locuri=other.nr_locuri;
        cout << "operator= copiere masa\n";
        return *this;
    }
 Masa::~Masa(){
        cout << "Destr Masa\n";
    }

ostream& operator<<(ostream& os, const Masa& ms) {
        os << "Zona: " << ms.zona << ", numar masa: " << ms.nr_masa << ", numar locuri: " << ms.nr_locuri<<"\n";
        return os;
    }

Preparat::Preparat (){
    cout<<"Constructor fara param preparat\n";
}
Preparat:: Preparat(const string& nume_preparat_, float gramaj_, float pret_, int timp_preparare_) : nume_preparat{nume_preparat_}, gramaj{gramaj_}, pret{pret_}, timp_preparare{timp_preparare_}{
        cout << "Constr de inițializare Preparat\n";
    }
ostream& operator<<(ostream& os, const Preparat& prep) {
        os << "Nume preparat: " << prep.nume_preparat << ", gramaj: " << prep.gramaj << ", pret: " << prep.pret<< ", timp de preparare: " << prep.timp_preparare<<"\n";
        return os;
}

Ospatar::Ospatar(){
    cout<<"constr init fara param ospatar\n";
}
Ospatar::Ospatar(const string& nume_, float salariu_, Comanda cmd_) : nume{nume_}, salariu{salariu_}, cmd{cmd_} {
        cout << "Constr de inițializare Ospatar\n";
    }
Comanda::Comanda()
{
    cout<<"constructor fara param comanda"<<endl;
}
