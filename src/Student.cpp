#include "Student.h"

Student::Student(const string &nume, const string &prenume, int varsta, const string &grupa)
    : Persoana(nume, prenume, varsta) {

    if (grupa.empty())
        throw DateLipsa();

    this->grupa = grupa;
}

Student::Student(const Student &s) : Persoana(s) {
    this->grupa = s.grupa;
    this->note = s.note;
}

Student::~Student() { }

void Student::adaugaNota(float nota) {
    if (nota < 1 || nota > 10)
        throw DateInvalide();

    if ((int)note.size() >= MAX_NOTE)
        throw DepasireCapacitate();

    note.push_back(nota);
}

float Student::calculeazaMedie() const {
    if (note.empty())
        return 0;

    float suma = 0;
    for (int i = 0; i < (int)note.size(); i++)
        suma += note[i];

    return suma / note.size();
}

bool Student::estePromovat() const {
    return calculeazaMedie() >= 5;
}

string Student::getSituatie() const {
    string situatie = "[Student] " + prenume + " " + nume;
    situatie += " | Grupa: " + grupa;
    situatie += " | Media: " + to_string(calculeazaMedie());
    if (estePromovat())
        situatie += " | PROMOVAT";
    else
        situatie += " | RESPINS";
    return situatie;
}

void Student::afisare(ostream &out) const {
    out << "[Student] ";
    Persoana::afisare(out);
    out << " | Grupa: " << grupa;
    out << " | Media: " << calculeazaMedie();
    if (estePromovat())
        out << " | PROMOVAT";
    else
        out << " | RESPINS";
}

Persoana* Student::clone() const {
    return new Student(*this);
}
