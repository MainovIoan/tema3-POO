#include "Catalog.h"
#include <algorithm>

int Catalog::nrCataloage = 0;
Catalog* Catalog::instanta = NULL;


Catalog::Catalog(const string &numeScoala) {
    this->numeScoala = numeScoala;
    nrCataloage++;
}

Catalog* Catalog::getInstance(const string &numeScoala) {
    if (instanta == NULL)
        instanta = new Catalog(numeScoala);
    return instanta;
}

void Catalog::distruge() {
    if (instanta != NULL) {
        delete instanta;
        instanta = NULL;
    }
}

void Catalog::elibereazaMemorie() {
    for (int i = 0; i < (int)persoane.size(); i++)
        delete persoane[i];
    persoane.clear();
}

Catalog::~Catalog() {
    elibereazaMemorie();
}

void Catalog::adaugaPersoana(Persoana *p) {
    persoane.push_back(p->clone());
}


void Catalog::afiseazaSituatii() const {
    cout << "=== Situatii: " << numeScoala << " ===" << endl;
    for (int i = 0; i < (int)persoane.size(); i++)
        cout << persoane[i]->getSituatie() << endl;
}

void Catalog::afiseazaToate() const {
    cout << "=== Catalog: " << numeScoala << " ===" << endl;
    for (int i = 0; i < (int)persoane.size(); i++)
        cout << *persoane[i] << endl;
}


void Catalog::afiseazaStudentiPromovati() const {
    cout << "=== Studenti promovati ===" << endl;
    for (int i = 0; i < (int)persoane.size(); i++) {
        Student *s = dynamic_cast<Student*>(persoane[i]);
        if (s != NULL && s->estePromovat())
            cout << *s << endl;
    }
}

int Catalog::getNrCataloage() {
    return nrCataloage;
}

ostream& operator<<(ostream &out, const Catalog &c) {
    out << "Catalog[" << c.numeScoala << ", " << c.persoane.size() << " persoane]";
    return out;
}


CatalogBuilder::CatalogBuilder() {
    catalog = Catalog::getInstance();
}

CatalogBuilder& CatalogBuilder::adaugaStudent(Persoana *student) {
    catalog->adaugaPersoana(student);
    return *this;
}

CatalogBuilder& CatalogBuilder::adaugaProfesor(Persoana *profesor) {
    catalog->adaugaPersoana(profesor);
    return *this;
}

CatalogBuilder& CatalogBuilder::adaugaParinte(Persoana *parinte) {
    catalog->adaugaPersoana(parinte);
    return *this;
}

CatalogBuilder& CatalogBuilder::adaugaDirector(Persoana *director) {
    catalog->adaugaPersoana(director);
    return *this;
}

Catalog* CatalogBuilder::build() {
    return catalog;
}
