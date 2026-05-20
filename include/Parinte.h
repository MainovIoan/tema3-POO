#ifndef PARINTE_H
#define PARINTE_H

#include "Persoana.h"
#include <vector>
#include <string>

class Parinte : public Persoana {
    string ocupatie;
    vector<string> copiiLaFMI;

public:
    Parinte(const string &nume, const string &prenume, int varsta,
            const string &ocupatie);
    Parinte(const Parinte &p);
    ~Parinte();

    void adaugaCopil(const string &numeCopil);

    Persoana* clone() const;
    string getSituatie() const;

protected:
    void afisare(ostream &out) const;
};

#endif
