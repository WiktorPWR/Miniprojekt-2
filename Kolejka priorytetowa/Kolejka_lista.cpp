#include <iostream> // Biblioteka do obsługi strumieni wejścia/wyjścia
#include <cstdlib> // Biblioteka zawierająca różne funkcje pomocnicze, takie jak konwersja typów
#include <ctime> // Biblioteka do obsługi czasu
#include <cstring> // Biblioteka do obsługi operacji na łańcuchach znaków
#include <random> // Biblioteka do generowania liczb losowych
#include <fstream> // Biblioteka do obsługi plików
#include <string> // Biblioteka do obsługi łańcuchów znaków
#include <cerrno> // Biblioteka zawierająca definicję zmiennych związanych z obsługą błędów

#include "Lista.cpp" // Plik nagłówkowy z deklaracją klasy Lista

// Deklaracja klasy Pr_queue_l dziedziczącej po klasie Lista
class Pr_queue_l : public Lista{
public:

    void insert(int data, int priority){ // Metoda do wstawiania elementu z priorytetem
        Node *newnode = new Node(); // Tworzenie nowego węzła
        Node *temp = new Node(); // Tworzenie nowego węzła
        if(head == NULL || head->priority < priority){ // Sprawdzenie, czy lista jest pusta lub nowy element ma najwyższy priorytet
            Pushfront(data,priority); // Wstawienie na początek listy
        }
        else { // Jeśli lista nie jest pusta
            Node *node = head;
            while (node->next != NULL && node->next->priority > priority) {
                node = node->next;
            }
            temp->value = data;
            temp->priority = priority;
            temp->next = node->next;
            node->next = temp;
            size += 1;
        }

    }

    Node* extract_max() // Metoda do usuwania elementu o najwyższym priorytecie
    {
        if(head == nullptr) // Sprawdzenie, czy lista jest pusta
        {
            return nullptr; // Jeśli lista jest pusta, zwróć nullptr
        }
        Node* maxNode = head; // Zapisanie wskaźnika na węzeł o najwyższym priorytecie
        head = head->next; // Przesunięcie głowy listy na następny element
        size--; // Zmniejszenie rozmiaru listy

        return maxNode; // Zwrócenie usuniętego węzła o najwyższym priorytecie
    }


    bool modify_key(int data, int new_pr){ // Metoda do modyfikowania priorytetu elementu
        Node *cell = head; // Utworzenie wskaźnika wskazującego na głowę listy
        Node *prev = nullptr; // Wskaźnik na poprzedni węzeł, początkowo nullptr
        int success = 0;

        // Iteracja przez elementy listy
        while (cell != nullptr) {
            if (cell->value == data) { // Jeśli znaleziono szukane słowo
                success++;
                break;
            }
            prev = cell;
            cell = cell->next;
        }

        // Jeśli znaleziono szukane słowo
        if (success == 1) {
            // Usunięcie węzła ze struktury
            if (prev != nullptr) {
                prev->next = cell->next;
            } else {
                head = cell->next; // Aktualizacja głowy listy, jeśli usuwany węzeł to pierwszy węzeł
            }
            size -= 1;

            // Wstawienie węzła na nową pozycję z nowym priorytetem
            if (new_pr > cell->priority) {
                insert(data, new_pr);
            } else {
                Node *node = cell;
                while (node->next != nullptr && node->next->priority > new_pr) {
                    node = node->next;
                }
                cell->priority = new_pr;
                cell->next = node->next;
                node->next = cell;
            }

            delete cell; // Zwolnienie pamięci usuniętego węzła
            return true; // Zwrócenie sukcesu
        } else {
            return false; // Zwrócenie niepowodzenia
        }



    }

    int return_size() {return getSize();} // Metoda zwracająca rozmiar kolejki priorytetowej

    Node* peek(){ // Metoda zwracająca wskaźnik do pierwszego elementu w kolejce priorytetowej
        return head;
    }

    void print() { // Metoda do wyświetlania kolejki priorytetowej
        if (head == NULL) { // Jeśli lista jest pusta
            std::cout << "lista jest pusta"; // Wyświetl komunikat
        } else { // Jeśli lista nie jest pusta
            Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
            while (current != NULL) { // Dopóki nie dojdziemy do końca listy
                std::cout << current->priority << " " << current->value << " "; // Wyświetl wartość bieżącego węzła
                current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
            }
            std::cout << "\n Liczba z przypisanym najwiekszym priorytetem: " << head->value; // Wyświetlenie wartości głowy i ogona listy
        }
        std::cout << "\n Ilosc elementow: " << size << "\n\n"; // Wyświetlenie liczby elementów w liście
    }


    void generate_array(int size_of_array) // Metoda do generowania losowych liczb i wstawiania ich do kolejki priorytetowej
    {
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
        }
    }

};
