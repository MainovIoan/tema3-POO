# Tema 3 POO - Sistem gestiune situatii scolare

## Descriere generala

Proiectul e un sistem de gestiune a situatiilor scolare scris in C++. Fata de tema 2 am adaugat o clasa template pentru colectii de obiecte si trei design patterns: Factory, Builder si Singleton.

Baza proiectului e ierarhia de clase construita pe Persoana ca clasa abstracta, din care mostenesc Student, Profesor, Parinte si Director. Functioneaza prin pointeri de tip Persoana* iar fiecare clasa are clone(), getSituatie() si afisare() suprascrise.

## Ierarhie de clase

Persoana e clasa de baza abstracta, contine nume, prenume, varsta si un contor static numarTotal. Nu poate fi instantiata direct pentru ca are metode virtuale pure.

Student adauga grupa si un vector de note. adaugaNota() valideaza nota si arunca exceptie daca e invalida, calculeazaMedie() face media aritmetica, estePromovat() returneaza true daca media e cel putin 5.

Profesor are materie, titlu si un vector de grupe. Cu adaugaGrupa() se adauga grupele la care preda.

Parinte are ocupatie si o lista de copii inscrisi la FMI adaugati cu adaugaCopil().

Director are departament si aniExperienta. Daca are minim 5 ani experienta apare in afisare ca poate aproba burse.

## Design Patterns

Factory - FabricaPersoana are metode statice: creeazaStudent(), creeazaProfesor() etc care returneaza Persoana*. In loc de new Student direct in main totul trece prin fabrica.

Singleton - Catalog are constructorul privat si getInstance() care returneaza mereu aceeasi instanta. Nu poti crea doua cataloage, orice apel la getInstance() da acelasi obiect. La sfarsit se apeleaza Catalog::distruge() ca sa se elibereze memoria.

Builder - CatalogBuilder construieste catalogul pas cu pas, adica builder.adaugaStudent(p1).adaugaProfesor(p2).build(). Fiecare metoda returneaza referinta la builder ca sa se poata inlantui apelurile, la final build() da pointerul la catalog.

## Clasa template si functii template

Colectie<T> e o clasa template cu array dinamic care respecta Rule of Three, adica are copy constructor, operator= si destructor. Cand se umple capacitatea se dubleaza automat. Am folosit o cu Colectie<string> pentru grupe si cu Colectie<float> pentru medii.

Am mai adaugat doua functii template: cautaInColectie<T>() care cauta o valoare si returneaza indexul sau -1 daca nu e gasita, si maximDintre<T>() care returneaza maximul dintre doua valori. Ambele au fost folosite cu string si cu float.

## Ierarhie de exceptii

EroareScoala e clasa de baza pentru exceptii. Din ea mostenesc DateInvalide pentru note in afara intervalului 1-10, DateLipsa pentru campuri obligatorii goale cum ar fi grupa sau departamentul, si DepasireCapacitate cand se incearca adaugarea a mai mult de 20 de note la un student.

## Bibliografie

- https://refactoring.guru/design-patterns
- https://cppreference.com 