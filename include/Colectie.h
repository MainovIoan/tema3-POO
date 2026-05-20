#ifndef COLECTIE_H
#define COLECTIE_H

#include <iostream>
using namespace std;

template <typename T>
class Colectie {
    T* elemente;
    int dimensiune;
    int capacitate;

public:
    Colectie() {
        capacitate = 4;
        dimensiune = 0;
        elemente = new T[capacitate];
    }

    Colectie(const Colectie<T> &c) {
        capacitate = c.capacitate;
        dimensiune = c.dimensiune;
        elemente = new T[capacitate];
        for (int i = 0; i < dimensiune; i++)
            elemente[i] = c.elemente[i];
    }

    Colectie<T>& operator=(const Colectie<T> &c) {
        if (this != &c) {
            delete[] elemente;
            capacitate = c.capacitate;
            dimensiune = c.dimensiune;
            elemente = new T[capacitate];
            for (int i = 0; i < dimensiune; i++)
                elemente[i] = c.elemente[i];
        }
        return *this;
    }

    ~Colectie() {
        delete[] elemente;
    }

    void adauga(const T &element) {
        if (dimensiune == capacitate) {
            capacitate = capacitate * 2;
            T* nou = new T[capacitate];
            for (int i = 0; i < dimensiune; i++)
                nou[i] = elemente[i];
            delete[] elemente;
            elemente = nou;
        }
        elemente[dimensiune] = element;
        dimensiune++;
    }

    T get(int i) const {
        return elemente[i];
    }

    int getDimensiune() const {
        return dimensiune;
    }

    bool esteGoala() const {
        return dimensiune == 0;
    }

    void afiseaza(ostream &out) const {
        for (int i = 0; i < dimensiune; i++) {
            out << elemente[i];
            if (i < dimensiune - 1)
                out << ", ";
        }
        out << endl;
    }
};

template <typename T>
int cautaInColectie(const Colectie<T> &colectie, const T &valoare) {
    for (int i = 0; i < colectie.getDimensiune(); i++)
        if (colectie.get(i) == valoare)
            return i;
    return -1;
}

template <typename T>
T maximDintre(const T &a, const T &b) {
    if (a > b)
        return a;
    return b;
}

#endif
