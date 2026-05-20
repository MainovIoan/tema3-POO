#ifndef STUDENT_H
#define STUDENT_H

#include "Persoana.h"
#include "Exceptii.h"
#include <vector>

class Student : public Persoana {
    string grupa;
    vector<float> note;

    static const int MAX_NOTE = 20;

public:
    Student(const string &nume, const string &prenume, int varsta, const string &grupa);
    Student(const Student &s);
    ~Student();

    void adaugaNota(float nota);
    float calculeazaMedie() const;
    bool estePromovat() const;

    Persoana* clone() const;
    string getSituatie() const;

protected:
    void afisare(ostream &out) const;
};

#endif
