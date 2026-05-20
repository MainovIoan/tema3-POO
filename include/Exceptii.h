#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
using namespace std;


class EroareScoala : public exception {
public:
    virtual const char* what() const noexcept = 0;
};


class DateInvalide : public EroareScoala {
public:
    const char* what() const noexcept {
        return "Eroare: nota trebuie sa fie intre 1 si 10!";
    }
};


class DateLipsa : public EroareScoala {
public:
    const char* what() const noexcept {
        return "Eroare: camp obligatoriu gol (grupa sau departament)!";
    }
};

class DepasireCapacitate : public EroareScoala {
public:
    const char* what() const noexcept {
        return "Eroare: numarul maxim de note a fost depasit!";
    }
};

#endif
