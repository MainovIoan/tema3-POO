#include "Profesor.h"

Profesor::Profesor(const string &nume, const string &prenume, int varsta,
                   const string &materie, const string &titlu)
    : Persoana(nume, prenume, varsta) {

    this->materie = materie;
    this->titlu = titlu;
}

Profesor::Profesor(const Profesor &p) : Persoana(p) {
    this->materie = p.materie;
    this->titlu = p.titlu;
    this->grupe = p.grupe;
}

Profesor::~Profesor() { }

void Profesor::adaugaGrupa(const string &grupa) {
    grupe.push_back(grupa);
}

string Profesor::getSituatie() const {
    string situatie = "[Profesor] " + titlu + " " + prenume + " " + nume;
    situatie += " | Materie: " + materie;
    situatie += " | Nr. Grupe: " + to_string(grupe.size());
    return situatie;
}

void Profesor::afisare(ostream &out) const {
    out << "[Profesor] " << titlu << " ";
    Persoana::afisare(out);
    out << " | Materie: " << materie
        << " | Nr. Grupe: " << grupe.size();
}

Persoana* Profesor::clone() const {
    return new Profesor(*this);
}
