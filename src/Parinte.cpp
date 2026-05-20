#include "Parinte.h"

Parinte::Parinte(const string &nume, const string &prenume, int varsta,
                 const string &ocupatie)
    : Persoana(nume, prenume, varsta) {

    this->ocupatie = ocupatie;
}

Parinte::Parinte(const Parinte &p) : Persoana(p) {
    this->ocupatie = p.ocupatie;
    this->copiiLaFMI = p.copiiLaFMI;
}

Parinte::~Parinte() { }

void Parinte::adaugaCopil(const string &numeCopil) {
    copiiLaFMI.push_back(numeCopil);
}

string Parinte::getSituatie() const {
    string situatie = "[Parinte] " + prenume + " " + nume;
    situatie += " | Ocupatie: " + ocupatie;
    situatie += " | Copii la FMI: " + to_string(copiiLaFMI.size());
    for (int i = 0; i < (int)copiiLaFMI.size(); i++)
        situatie += " (" + copiiLaFMI[i] + ")";
    return situatie;
}

void Parinte::afisare(ostream &out) const {
    out << "[Parinte] ";
    Persoana::afisare(out);
    out << ", ocupatie: " << ocupatie
        << ", copii la FMI: " << copiiLaFMI.size();
}

Persoana* Parinte::clone() const {
    return new Parinte(*this);
}
