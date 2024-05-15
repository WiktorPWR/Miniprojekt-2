#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <fstream>
#include <string>
#include <cerrno>

//template <typename T>
class kolejka_l_los {
private:
    int size = 0; // Inicjalizacja rozmiaru listy na 0
    struct Node { // Struktura węzła listy
        std::string value; // Wartość przechowywana w węźle
        int priority;
        struct Node *next; // Wskaźnik do następnego węzła
    };

    struct Node *head = NULL; // Wskaźnik na początek listy


public:
    int Value; // Zmienna publiczna Value

    kolejka_l_los *Next; // Wskaźnik na następny element listy, publiczny

    kolejka_l_los() { // Konstruktor
        srand(time(0)); // Inicjalizacja generatora liczb pseudolosowych
    }

    void insert(std::string data, int priority) { // Dodawanie elementu na początek listy
        Node *newnode = new Node(); // Tworzenie nowego węzła
        newnode->next = head; // Ustawienie wskaźnika next nowego węzła na początek listy
        newnode->value = data; // Przypisanie nowej wartości do nowego węzła
        newnode->priority = priority;
        head = newnode; // Ustawienie głowy listy na nowy węzeł

        size += 1; // Zwiększenie rozmiaru listy
    }

    void generate_array(int size_of_array) // Funkcja do generowania tablicy losowych liczb
    {/*
        // Deklaracja zmiennej przechowującej losową liczbę

        std::random_device rd;
        std::mt19937 gen(rd());

        // Ustalenie zakresu losowania
        std::uniform_int_distribution<int> dist(1, std::numeric_limits<int>::max());
        std::uniform_int_distribution<int> dist_pr(1, (3*size_of_array));
        //srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

        for (int i = 0; i < size_of_array; i++) // Pętla generująca losowe liczby i zapisująca je do pliku
            {

                int rn = dist(gen);
                int pr_rn = dist_pr(gen);
                insert(rn,pr_rn);
                }*/
        std::random_device rd;
        std::mt19937 gen(rd());

        // Ustalenie zakresu losowania
        //std::uniform_int_distribution<int> dist(1, std::numeric_limits<int>::max());
        std::uniform_int_distribution<int> dist_pr(1, (3*size_of_array));

        std::ifstream Myfile("C:\\Users\\ten kosiorny\\CLionProjects\\kolejka\\konstytucja.txt"); // Tworzenie obiektu do zapisu do pliku o nazwie "random_number_file.txt"
        if (Myfile.is_open()) // Sprawdzenie, czy udało się otworzyć plik
        {
            std::string slowo;
            for (int i = 0; i < size_of_array; i++) {
                Myfile >> slowo;
                int pr_rn = dist_pr(gen);
                insert(slowo, pr_rn);
            }
        } else std::cerr << "Error opening file: " << std::strerror(errno) << std::endl;

        Myfile.close(); // Zamknięcie pliku


    }





    void Printlist() { // Wyświetlanie zawartości listy
        if (head == NULL) { // Jeśli lista jest pusta
            std::cout << "lista jest pusta"; // Wyświetl komunikat
        } else { // Jeśli lista nie jest pusta
            Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
            while (current != NULL) { // Dopóki nie dojdziemy do końca listy
                std::cout << current->priority << " " << current->value << " "; // Wyświetl wartość bieżącego węzła
                current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
            }
            std::cout << "\n Liczba z przypisanym najwiekszym priorytetem: " << find_max()->value << " - " << find_max()->priority; // Wyświetlenie wartości głowy i ogona listy
        }
        std::cout << "\n Ilosc elementow: " << size << "\n\n"; // Wyświetlenie liczby elementów w liście
    };

    ~kolejka_l_los() { // Destruktor
        while (head != nullptr) { // Dopóki istnieją węzły w liście
            Node *temp = head; // Przechowanie wskaźnika na głowę listy w zmiennej tymczasowej
            head = head->next; // Przesunięcie wskaźnika na głowę listy na następny węzeł
            delete temp; // Usunięcie węzła, na który wskazuje wskaźnik tymczasowy
        }
        size = 0; // Zresetowanie rozmiaru listy
    }

    Node* extract_max() {
        if (head != nullptr) { // Sprawdzenie, czy lista nie jest pusta
            Node* max_prev = nullptr; // Wskaźnik na poprzedni węzeł z maksymalnym priorytetem
            Node* max = head; // Wskaźnik na węzeł z maksymalnym priorytetem
            Node* a = head;
            Node* prev = nullptr; // Wskaźnik na poprzedni węzeł

            // Znalezienie węzła z maksymalnym priorytetem
            while (a->next != nullptr) {
                if (a->next->priority > max->priority) {
                    max_prev = a;
                    max = a->next;
                }
                a = a->next;
            }

            // Jeśli znaleziono węzeł z maksymalnym priorytetem
            if (max_prev != nullptr) {
                max_prev->next = max->next; // Usunięcie węzła z listy
            } else {
                head = head->next; // Aktualizacja głowy listy, jeśli usuwany węzeł to pierwszy węzeł
            }

            size--; // Zmniejszenie rozmiaru listy
            return max; // Zwrócenie węzła z maksymalnym priorytetem
        }

        return nullptr; // Zwrócenie nullptr, jeśli lista jest pusta
    }

    Node* find_max() { // Usuwanie pierwszego elementu z listy
        if (head != nullptr) { // Sprawdzenie, czy lista nie jest pusta
            Node* max_prev = nullptr; // Wskaźnik na poprzedni węzeł z maksymalnym priorytetem
            Node* max = head; // Wskaźnik na węzeł z maksymalnym priorytetem
            Node* a = head;
            Node* prev = nullptr; // Wskaźnik na poprzedni węzeł

            // Znalezienie węzła z maksymalnym priorytetem
            while (a->next != nullptr) {
                if (a->next->priority > max->priority) {
                    max_prev = a;
                    max = a->next;
                }
                a = a->next;
            }
            return max; // Zwrócenie węzła z maksymalnym priorytetem
        }

        return nullptr; // Zwrócenie nullptr, jeśli lista jest pusta

    };
/*
    void Find(){ // Funkcja wyszukująca losową liczbę w liście

        Node *current = head;
        while (current != NULL) {// przewertowanie przez cala liste
            if (current->value == 18)
                break;

            current = current->next;
        }
    }
*/
    bool modify_key(std::string data, int new_pr) {
        Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
        while (current != NULL) { // Dopóki nie dojdziemy do końca listy
            if(current->value == data){
                current->priority = new_pr;
                return 1;
            }
            current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
        }
    }

    int getSize() { // Pobieranie rozmiaru listy
        return size; // Zwrócenie rozmiaru listy
    }
};
