#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>
using namespace std;

class Persoana {
protected:
    string nume;
    string prenume;
    int varsta;

    static int numarTotal;

public:
    Persoana(const string &nume, const string &prenume, int varsta);
    Persoana(const Persoana &p);
    virtual ~Persoana();

    
    virtual Persoana* clone() const = 0;

    
    virtual string getSituatie() const = 0;

    
    friend ostream& operator<<(ostream &out, const Persoana &p);

    static int getNumarTotal();

protected:
    
    
    virtual void afisare(ostream &out) const;
};

#endif
