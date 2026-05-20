#ifndef FABRICAPERSOANA_H
#define FABRICAPERSOANA_H

#include "Persoana.h"
#include "Student.h"
#include "Profesor.h"
#include "Parinte.h"
#include "Director.h"
#include <string>
using namespace std;

class FabricaPersoana {
public:
    static Persoana* creeazaStudent(const string &nume, const string &prenume,
                                    int varsta, const string &grupa) {
        return new Student(nume, prenume, varsta, grupa);
    }

    static Persoana* creeazaProfesor(const string &nume, const string &prenume,
                                     int varsta, const string &materie,
                                     const string &titlu) {
        return new Profesor(nume, prenume, varsta, materie, titlu);
    }

    static Persoana* creeazaParinte(const string &nume, const string &prenume,
                                    int varsta, const string &ocupatie) {
        return new Parinte(nume, prenume, varsta, ocupatie);
    }

    static Persoana* creeazaDirector(const string &nume, const string &prenume,
                                     int varsta, const string &departament,
                                     int aniExperienta) {
        return new Director(nume, prenume, varsta, departament, aniExperienta);
    }
};

#endif
