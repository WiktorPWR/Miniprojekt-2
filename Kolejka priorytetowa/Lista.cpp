#include <iostream>
#include <cstdlib>
#include <time.h>
 class Lista{

public:
    int size = 0; // Inicjalizacja rozmiaru listy na 0
    struct Node { // Struktura węzła listy
        int value; // Wartość przechowywana w węźle
        int priority;
        struct Node *next; // Wskaźnik do następnego węzła
    };

    struct Node *head = NULL; // Wskaźnik na początek listy



    Lista()// Konstruktor klasy
    {
        srand(time(0));// Zainicjowanie generator liczb zmiennych
    }

    void Pushfront(int data, int prior) { // Funckja ,,wkładająca" element na pierwsze miejsca w liscie

        Node *newnode = new Node();// Utworznie nowego obiektu typu Node
        newnode->next = head;// Przypisanie pointera nowego obiektu do head(poszczatku naszej lsity)
        newnode->value = data;// Pypiszanie wartosci nowego obiektu do zmiennej podaj przez uzytkownika
        newnode->priority = prior;
        head = newnode;// Przypisanie pointer head do nowego wezła by mogł na niego wskazywać
        size += 1;// Zwiekszenie rozmiaru o jeden w tablicy
    };

    void Pushback(int data) { // Funckja ,,wkładajaca" element na ostatnie miejsce w liscie
        Node* newnode = new Node();// Utowrznie nowego obiektu typu Node
        newnode->value = data;// Przypisanie pointera nowego obiektu do head(poszczatku naszej lsity)
        newnode->next = nullptr; // Jako ze to koniec listy to pointer next nowego obiektu przypisujemy do nullptr poniewaz nie wskazuje on na zaden inny obikrt
        if (head == nullptr) {// sprawdzneie czy lista jest pusta
            head = newnode;// Jezli  lista jest pusta nastepuje przypisanie pointer head do nowego wezła by mogł na niego wskazywać
        } else {
            Node* current = head;//Jezlei nie jest pusta tworzymy nowy wskaznik ktory wskazzuje na head
            while (current->next != nullptr) {// Nastepuje przejscie przez cala liste az do momentu kiedy poinetr next komurki bedzie nullptr
                current = current->next;
            }
            current->next = newnode;// Przypisanie wartosci pointera ostatniejgo miejsca w tablicy do nowego wezla przez nas utworzonego
        }
        size++;// zwiekszenie rozmiaru o jeden
    }


    void Dltback() {// Funkcja majaca na celu
        if (head == nullptr) {
            return; // Lista jest pusta, nie ma nic do usunięcia
        }

        Node* current = head;// Utworzenie nowej zmiennej current pointujacej na head(poczatek listy)
        Node* prev = nullptr;// Utworzenei nowej zmiennej prev pointujacej do niczego. Ma ona na celu znalezienie przed ostatniego elementu w liscie

        while (current->next != nullptr) { // przejscie przez cala liste
            prev = current;
            current = current->next;
        }

        if (prev != nullptr) {// Kiedy jestesmy na przed ostatnim mijescu w talbicy
            delete current;// usuwamy aktualny ostani element w tablicy
            prev->next = nullptr; // Ustawienie wskaźnika next poprzedniego elementu na nullptr
        } else {
            // Usuwamy pierwszy element z listy
            delete head;// usuniecie pierwszego lememtu w talbicy
            head = nullptr;// przypisanie wartosci head jako nullptr
        }

        size--;// zmniejszenie rozmairu tablicy o jeden
    }



    void Dltrand() {
        if (head != nullptr) { // Jezeli lista jest pusta
            int randIndex = std::rand() % size; // Losowy indeks od 0 do size
            Node *current = head;// przypisanie pointera current do head
            Node *prev = nullptr;// przypisanie prev na nullpritn. Zmiennea to bedzie wskazywac na element poprzedzajacy elelnt do usuniecie

            if (randIndex > 0) {// Jezeli bedzie operowac na kazdym innym adresie niz pierwszy
                for (int i = 0; i < randIndex; i++) {// przechodzimy przez cala tablice az do miejsca randIndex ktore wybralismy
                    prev = current;// przypisanie wartosci prev do elemntu poprzedzajcego nasz do usuniecie
                    current = current->next;// przypisanie wartosci current do miejsca ktore chcmy usunac
                }
                if (prev != nullptr) {// jezeli jest elment poprzedzajcy nasz lsite
                    prev->next = current->next;// przypisanei pointerowi poprzedzajacego elementu do wartosci nastpenej po current
                } else {
                    head = current->next;// Jezlei nie mma elemntu poprzedzajacego wowczas head przypisujemy do wartosci current->next czyli w tym wypadku nullprt
                }
                delete current;// usuniecie naszego wezla
            } else {
                head = head->next;// Wartość pointera head zostaje zaktualizowana, aby wskazywała na następny węzeł po usuwanym węźle
                delete current;
            }
            size--;// zmniejszenie rozmiaru o jeden
        }
    }

    void Addrand(int data) {
        if (head != nullptr) {
            int randIndex = std::rand() % size; // Losowy indeks od 0 do size - 1
            Node *current = head;// utworzenie pointera do head
            Node *prev = nullptr;// utworzenie pointera wskazujacego do przedostatniego
            Node *newNode = new Node();// utwoerznie nowego wezla
            newNode->value = data;// przyrownanie wartosci nowego obiektu do naszej wartosci podanej przez uzytkownika

            if (randIndex > 0) { // jezeli nasze miejsce jest inne niz pierwsze
                for (int i = 0; i < randIndex; i++) {// przewertowanie przez wszytkie wartosci az do naszej randIndex
                    prev = current;// przyrownanie wartosci prev do eleemntu poprzedzajacego randIndex
                    current = current->next;// przyrownaine wartosci current do naszego poszukiwanego miejsca
                }
                newNode->next = current;// ustawienie wartosci next nowego wezla do wartosci current
                prev->next = newNode;// ustawieine next eleemnetu poprzedzajacego current do nowego wezla
            } else {
                newNode->next = current;// przyrownainie wartosci next nowo powestalego wezla do current czyli elementu nastepnego po nim  w liscie
                head = newNode;// ustawnienie pointer head do noweo powstalego wezla
            }
            size++;// zwiekszenie ilosc elementow w liscie
        } else {
            Pushback(data);// danie w pusta liste pierwszego elementu za pomoca pushback
        }
    }

    void Printlist() {
        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            Node *current = head;
            while (current != NULL) {// przewertowanie przez cala liste
                std::cout << current->value << " ";
                current = current->next;
            }
        }
        std::cout << "\n Ilosc elementow: " << size << "\n";

    };

    ~Lista() {// Destruktor klasy SLL1
        while (head != nullptr) { // Pętla wykonuje się dopóki istnieją węzły na liście
            Node *temp = head; // Tworzenie tymczasowego wskaźnika na początek listy
            head = head->next; // Przesunięcie wskaźnika na następny węzeł w liście
            delete temp; // Usunięcie węzła, na który wskazuje tymczasowy wskaźnik
        }
        size = 0; // Zresetowanie wartości size na 0
    }


    Node* Dltfront() { // Funkcja usuwająca pierwszy element z listy
        Node *a = head; // Przypisanie wskaźnika na pierwszy element listy
        head = head->next; // Aktualizacja wskaźnika na głowę listy, aby wskazywał na drugi element
        size -= 1; // Zmniejszenie rozmiaru listy o 1
        return a;
    }

    void Find(){ // Funkcja wyszukująca losową liczbę w liście

        Node *current = head;
        while (current != NULL) {// przewertowanie przez cala liste
            if (current->value == 18)
                break;

            current = current->next;
        }
    }

    void Find1(){ // Funkcja wyszukująca losową liczbę w liście

        Node *current = head;
        Node *prevcurrent;
        Node *pprevcurrent;
        Node *pprevtail;
        Node *prevtail;
        Node *newtail;
        while (current != NULL) {// przewertowanie przez cala liste
            prevcurrent = current;
            current = current->next;
            if(current->next == NULL){
                newtail = current;
                prevtail = prevcurrent;
            }else if(current->next == prevtail){
                newtail = prevtail;
                prevtail = current;
                /*Node *current1 = head;
                Node *prevcurrent1 = NULL;
                while (current1 != NULL){
                    if(current1->next == NULL){
                        newtail = current1;
                        prevtail = prevcurrent1;
                    }else if(current1->next == prevtail){
                        newtail = prevtail;
                        prevtail = current1;
                        break;
                    }
                    prevcurrent1 = current1;
                    current1 = current1->next;

                }*/
                if(current->value == 18 || prevtail->value == 18){
                    break;
                }
            }
        }}



    void change_value_at_position(int location) //ustawanie wartosci podanej przez uzytkownika na konkretnym miejscu
    {

        Node *cell = head; // utworzenie pointera ktory bedzie rowny head
        for (int i=0;i<=location;i++) // przeiterowanie przez elementy w liscie az do momentu kiedy nasza lokalizacja bedzie sie zgadzac z adresem w kotry chcemy wpisac
        {
            cell = cell->next; // ustawienie prevcell na nastepny adres
        }
        cell->value = 18;

    }

    int getSize() // Funkcja zwracająca rozmiar listy
    {
        return size; // Zwrócenie wartości zmiennej przechowującej rozmiar listy
    }

};