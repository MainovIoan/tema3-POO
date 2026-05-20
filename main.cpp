#include <iostream>
#include "Catalog.h"
#include "Student.h"
#include "Profesor.h"
#include "Parinte.h"
#include "Director.h"
#include "Exceptii.h"
#include "FabricaPersoana.h"
#include "Colectie.h"
using namespace std;

int main() {

    
    cout << "--- Factory: creare persoane ---" << endl;

    Persoana* p1 = FabricaPersoana::creeazaStudent("Popescu", "Ion", 20, "132");
    Persoana* p2 = FabricaPersoana::creeazaStudent("Ionescu", "Maria", 21, "131");
    Persoana* p3 = FabricaPersoana::creeazaProfesor("Marinescu", "Andrei", 45, "MATE", "Conf.");
    Persoana* p4 = FabricaPersoana::creeazaParinte("Dumitrescu", "Elena", 48, "Inginer");
    Persoana* p5 = FabricaPersoana::creeazaDirector("Constantin", "Gheorghe", 55, "Informatica", 12);

    Student *s1 = dynamic_cast<Student*>(p1);
    if (s1 != NULL) {
        s1->adaugaNota(8.5);
        s1->adaugaNota(7);
        s1->adaugaNota(9);
    }

    Student *s2 = dynamic_cast<Student*>(p2);
    if (s2 != NULL) {
        s2->adaugaNota(4);
        s2->adaugaNota(3.5);
    }

    Profesor *prof1 = dynamic_cast<Profesor*>(p3);
    if (prof1 != NULL) {
        prof1->adaugaGrupa("131");
        prof1->adaugaGrupa("132");
    }

    Parinte *par1 = dynamic_cast<Parinte*>(p4);
    if (par1 != NULL)
        par1->adaugaCopil("Ion Popescu");

    cout << "Persoane create prin Factory: OK" << endl;
    cout << endl;


    
    cout << "--- Builder + Singleton: construire catalog ---" << endl;

    CatalogBuilder builder;
    builder.adaugaStudent(p1)
           .adaugaStudent(p2)
           .adaugaProfesor(p3)
           .adaugaParinte(p4)
           .adaugaDirector(p5);

    Catalog* catalog = builder.build();

    Catalog* catalog2 = Catalog::getInstance("Alt Catalog");
    if (catalog == catalog2)
        cout << "Singleton ok: catalog si catalog2 sunt aceeasi instanta" << endl;
    cout << endl;


    catalog->afiseazaToate();
    cout << endl;

    catalog->afiseazaSituatii();
    cout << endl;

    catalog->afiseazaStudentiPromovati();
    cout << endl;


    cout << "--- Colectie<string>: grupe ---" << endl;

    Colectie<string> grupe;
    grupe.adauga("131");
    grupe.adauga("132");
    grupe.adauga("133");
    grupe.adauga("134");

    cout << "Grupe: ";
    grupe.afiseaza(cout);

    int indexGrupa = cautaInColectie(grupe, string("132"));
    if (indexGrupa != -1)
        cout << "Grupa 132 gasita la pozitia: " << indexGrupa << endl;

    string maxGrupa = maximDintre(string("133"), string("134"));
    cout << "Maxim intre '133' si '134': " << maxGrupa << endl;
    cout << endl;


    cout << "--- Colectie<float>: medii studenti ---" << endl;

    Colectie<float> medii;
    if (s1 != NULL)
        medii.adauga(s1->calculeazaMedie());
    if (s2 != NULL)
        medii.adauga(s2->calculeazaMedie());

    cout << "Medii: ";
    medii.afiseaza(cout);

    float maxMedie = maximDintre(s1->calculeazaMedie(), s2->calculeazaMedie());
    cout << "Media mai mare: " << maxMedie << endl;
    cout << endl;


    cout << "Numar total persoane create: " << Persoana::getNumarTotal() << endl;
    cout << endl;


    cout << "--- Test exceptii ---" << endl;

    try {
        Student sTest("Test", "Test", 20, "100");
        sTest.adaugaNota(15);
    }
    catch (const DateInvalide &e) {
        cout << e.what() << endl;
    }

    try {
        Student sTest2("Test", "Test", 20, "");
    }
    catch (const DateLipsa &e) {
        cout << e.what() << endl;
    }

    try {
        Student sTest3("Test", "Test", 20, "100");
        for (int i = 0; i < 21; i++)
            sTest3.adaugaNota(8);
    }
    catch (const DepasireCapacitate &e) {
        cout << e.what() << endl;
    }


    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    Catalog::distruge();

    return 0;
}
