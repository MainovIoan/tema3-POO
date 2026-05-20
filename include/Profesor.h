#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persoana.h"
#include <vector>
#include <string>

class Profesor : public Persoana {
    string materie;
    string titlu;
    vector<string> grupe;

public:
    Profesor(const string &nume, const string &prenume, int varsta,
             const string &materie, const string &titlu);
    Profesor(const Profesor &p);
    ~Profesor();

    void adaugaGrupa(const string &grupa);

    Persoana* clone() const;
    string getSituatie() const;

protected:
    void afisare(ostream &out) const;
};

#endif
