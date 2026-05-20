#ifndef CATALOG_H
#define CATALOG_H

#include "Persoana.h"
#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class Catalog {
    string numeScoala;
    vector<Persoana*> persoane;

    static int nrCataloage;
    static Catalog* instanta;

    Catalog(const string &numeScoala);

public:
    
    static Catalog* getInstance(const string &numeScoala = "Catalog Principal");
    static void distruge();

    ~Catalog();

    void adaugaPersoana(Persoana *p);

    void afiseazaSituatii() const;

    void afiseazaToate() const;

    void afiseazaStudentiPromovati() const;

    static int getNrCataloage();

    friend ostream& operator<<(ostream &out, const Catalog &c);

private:
    void elibereazaMemorie();
};


class CatalogBuilder {
    Catalog* catalog;

public:
    CatalogBuilder();

    CatalogBuilder& adaugaStudent(Persoana *student);

    CatalogBuilder& adaugaProfesor(Persoana *profesor);

    CatalogBuilder& adaugaParinte(Persoana *parinte);

    CatalogBuilder& adaugaDirector(Persoana *director);

    Catalog* build();
};

#endif
