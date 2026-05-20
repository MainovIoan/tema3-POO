#include "Persoana.h"

int Persoana::numarTotal = 0;

Persoana::Persoana(const string &nume, const string &prenume, int varsta) {
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    numarTotal++;
}

Persoana::Persoana(const Persoana &p) {
    this->nume = p.nume;
    this->prenume = p.prenume;
    this->varsta = p.varsta;
    numarTotal++;
}

Persoana::~Persoana() { }


void Persoana::afisare(ostream &out) const {
    out << prenume << " " << nume << ", varsta: " << varsta;
}

ostream& operator<<(ostream &out, const Persoana &p) {
    p.afisare(out);
    return out;
}

int Persoana::getNumarTotal() {
    return numarTotal;
}
