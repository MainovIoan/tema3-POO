#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Persoana.h"
#include <string>

class Director : public Persoana {
    string departament;
    int aniExperienta;

public:
    Director(const string &nume, const string &prenume, int varsta,
             const string &departament, int aniExperienta);
    Director(const Director &d);
    ~Director();

    Persoana* clone() const;
    string getSituatie() const;

protected:
    void afisare(ostream &out) const;
};

#endif
