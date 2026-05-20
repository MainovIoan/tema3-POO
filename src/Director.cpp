#include "Director.h"
#include "Exceptii.h"

Director::Director(const string &nume, const string &prenume, int varsta,
                   const string &departament, int aniExperienta)
    : Persoana(nume, prenume, varsta) {

    if (departament.empty())
        throw DateLipsa();

    this->departament = departament;
    this->aniExperienta = aniExperienta;
}

Director::Director(const Director &d) : Persoana(d) {
    this->departament = d.departament;
    this->aniExperienta = d.aniExperienta;
}

Director::~Director() { }

string Director::getSituatie() const {
    string situatie = "[Director] " + prenume + " " + nume;
    situatie += " | Departament: " + departament;
    situatie += " | Experienta: " + to_string(aniExperienta) + " ani";
    if (aniExperienta >= 5)
        situatie += " | Aproba burse: DA";
    else
        situatie += " | Aproba burse: NU";
    return situatie;
}

void Director::afisare(ostream &out) const {
    out << "[Director] ";
    Persoana::afisare(out);
    out << " | Departament: " << departament;
    out << " | Experienta: " << aniExperienta << " ani";
    if (aniExperienta >= 5)
        out << " | Aproba burse: DA";
    else
        out << " | Aproba burse: NU";
}

Persoana* Director::clone() const {
    return new Director(*this);
}
