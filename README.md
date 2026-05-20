Tema 3 continua temele anterioare si reprezinta un sistem de gestionare a situatiilor scolare. Acesta tine evidenta persoanelor dintr o scoala: studenti cu note, profesori cu materii si grupe, parinti si directori.

Comparativ cu tema 1 si tema 2 am adaugat trei design patterns: Factory, Builder si Singleton plus o clasa template pentru colectii si doua functii template. Am pastrat tot ce era in temele anterioare si am adaugat cerintele de la tema 3. Nu am modificat nimic din ce functiona deja.

In tema 1 am creat primele clase fara mostenire. In tema 2 am adaugat ierarhia de clase, mostenire, polimorfism, functii virtuale, functia clone() si o ierarhie de exceptii. In tema 3 am lasat tema 2 asa cum era si am adaugat design patterns si clasa template.

Baza proiectului e ierarhia de clase pornind de la clasa Persoana din care mostenesc Student, Profesor, Parinte si Director. Persoana are campurile comune: nume, prenume, varsta si un contor static numarTotal care numara cate obiecte s au creat in total inclusiv copiile facute in catalog. Are doua functii virtuale pure: clone() si getSituatie(). Din aceasta cauza nu poti crea obiecte de tip Persoana direct trebuie sa folosesti una din clasele derivate.

Functia clone() este folosita in Catalog. Cand adaugi o persoana se salveaza o copie realizata cu clone() nu pointerul original. Astfel, cand la final in main faci delete pe pointerii originali catalogul nu ramane cu un pointer invalid. Fiecare clasa stie sa se copieze pe ea insasi: Student returneaza new Student(*this), Profesor returneaza new Profesor(*this) si asa mai departe. Asa catalogul are propria copie independenta si nu se incurca cu ce se intampla in main.

getSituatie() returneaza un string cu informatiile specifice fiecarui tip. La student apare grupa, media si daca este promovat sau respins. La director apare departamentul, anii de experienta si daca poate aproba burse. E utila in Catalog cand vrei sa afisezi situatia fiecarei persoane fara sa stii exact ce tip e fiecare obiect.

Student are grupa si un vector de note. Functia adaugaNota() verifica daca nota este intre 1 si 10 si daca nu s au depasit 20 de note, altfel arunca exceptia corespunzatoare. calculeazaMedie() face suma notelor impartita la numarul lor cu verificare pentru cazul in care nu are nicio nota ca sa nu imparta la 0. estePromovat() returneaza true daca media este cel putin 5. Profesorul are materie, titlu si grupe. Cu adaugaGrupa() se adauga o grupa noua. Parintele are ocupatie si o lista de copii la FMI cu adaugaCopil() pentru adaugare. Directorul are departament si ani de experienta daca are cel putin 5 ani apare in afisare ca poate aproba burse.

Toate clasele derivate au constructor de initializare, copy constructor si destructor. Constructorul de initializare apeleaza constructorul din Persoana prin lista de initializare ca sa nu trebuiasca sa setez campurile comune direct nu am voie oricum pentru ca sunt protected. Copy constructorul apeleaza copy constructorul din Persoana si copiaza campurile proprii. Destructorul este gol la toate deoarece string si vector se elibereaza singure fara sa fie nevoie de delete manual.

Ierarhia de exceptii porneste de la EroareScoala care mosteneste din exception din biblioteca standard. Din ea mostenesc DateInvalide pentru note invalide, DateLipsa pentru campuri goale cum ar fi grupa sau departamentul si DepasireCapacitate pentru mai mult de 20 de note. Fiecare are functia what() cu mesajul specific de eroare.

Primul design pattern este Factory prin clasa FabricaPersoana cu functii statice: creeazaStudent(), creeazaProfesor(), creeazaParinte() si creeazaDirector(). Toate returneaza Persoana*. In loc de new Student(...) direct in main apelezi fabrica. Daca schimb ceva la modul de creare al unui tip schimb doar in fabrica si nu trebuie sa caut prin tot codul.

Al doilea design pattern este Singleton in Catalog. Constructorul este privat deci nu poti face new Catalog() direct din main. Am o variabila statica privata instanta de tip Catalog* care porneste NULL. getInstance() verifica daca instanta e NULL: daca da o creeaza si o salveaza daca nu o returneaza pe cea existenta. Astfel exista un singur catalog in tot programul orice apel la getInstance() da mereu acelasi obiect. Catalog::distruge() sterge instanta si elibereaza memoria la final.

Al treilea design pattern este Builder prin CatalogBuilder. Constructorul apeleaza getInstance() ca sa ia instanta Singleton. Functiile de adaugare returneaza *this pentru a putea pune apelurile unul dupa altul: builder.adaugaStudent(p1).adaugaProfesor(p2).build(). Mi s a parut un mod mai ordonat de a construi catalogul decat sa apelezi adaugaPersoana() de mai multe ori separat. build() returneaza pointerul la catalog la final.

Colectie<T> este un array dinamic care functioneaza cu orice tip. T este inlocuit cu tipul real cand folosesti clasa, deci poti face Colectie<string>, Colectie<float> sau orice altceva fara sa rescrii codul. Respecta Rule of Three: copy constructor, operator= si destructor. In copy constructor si operator= se aloca un array nou si se copiaza elementele unul cate unul ca sa nu ajunga doua obiecte sa pointeze la acelasi array. Destructorul elibereaza memoria cu delete[]. Cand se umple capacitatea aceasta se dubleaza automat. Am folosit o cu string pentru grupe si cu float pentru medii.

Am adaugat doua functii template: cautaInColectie<T>() care returneaza indexul unei valori sau -1 daca nu este gasita si maximDintre<T>() care returneaza maximul dintre doua valori. Ambele au fost folosite cu string si float ca sa am minim doua apeluri pentru fiecare functie cum cerea cerinta.

In Catalog am implementat si trei functii de afisare. afiseazaToate() parcurge vectorul si afiseaza fiecare persoana cu operator<<. afiseazaSituatii() apeleaza getSituatie() pe fiecare persoana. afiseazaStudentiPromovati() foloseste dynamic_cast sa verifice daca o persoana e Student si daca e promovat. Prin functiile virtuale se apeleaza automat versiunea corecta pentru fiecare tip fara sa stii ce e fiecare obiect din vector.

In main am demonstrat tot pe rand. Am creat persoanele prin Factory, am adaugat note si grupe prin dynamic_cast, am construit catalogul prin Builder, am aratat ca Singleton functioneaza prin compararea a doi pointeri de la getInstance() care sunt egali deci e acelasi obiect. Am afisat catalogul in trei moduri: toate persoanele, situatiile si doar studentii promovati. Am demonstrat colectiile cu string si float si am apelat cautaInColectie si maximDintre cu ambele tipuri. Am testat cele trei exceptii prin try catch. La final, am eliberat toata memoria cu delete pe pointerii din main si Catalog::distruge() pentru instanta Singleton.

## Bibliografie

https://refactoring.guru/design-patterns
https://cppreference.com
