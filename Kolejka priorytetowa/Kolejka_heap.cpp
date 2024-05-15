#include <iostream> // Biblioteka do obsługi strumieni wejścia/wyjścia

#include <string> // Biblioteka do obsługi łańcuchów znaków
#include <cstring> // Biblioteka do obsługi operacji na łańcuchach znaków
#include <random> // Biblioteka do generowania liczb losowych
#include <fstream> // Biblioteka do obsługi plików
#include <math.h> // Biblioteka matematyczna

#include "Heap.cpp" // Plik nagłówkowy z deklaracją klasy MaxHeap

// Deklaracja klasy Pr_queue_h dziedziczącej po klasie MaxHeap
class Pr_queue_h : public MaxHeap{

public:

    void insert(int value, int prior){ // Metoda do wstawiania elementu z priorytetem do kopca
        insert_heap(value, prior); // Wywołanie metody insert_heap z klasy MaxHeap
    }

    blok extract_max(){ // Metoda do usuwania elementu o najwyższym priorytecie z kopca
        blok max = heap.front(); // Zapisanie wartości i priorytetu pierwszego elementu w kopcu
        if(heap.getSize() != 0){ // Sprawdzenie, czy kopiec nie jest pusty
            heap.Swap(0, heap.getSize() - 1); // Zamiana pierwszego elementu z ostatnim
            heap.pop_back(); // Usunięcie ostatniego elementu
            heapify(0); // Przywrócenie właściwości kopca
        }
        return max; // Zwrócenie maksymalnego elementu
    }

    bool modify_key(int value, int new_pr){ // Metoda do modyfikowania priorytetu elementu w kopcu
        if(heap.getSize() != 0){ // Sprawdzenie, czy kopiec nie jest pusty
            for(int i = 0; i < heap.getSize(); i++){ // Iteracja przez elementy kopca
                if(heap.get(i).value == value){ // Znalezienie elementu o podanej wartości
                    heap.Swap(i,heap.getSize() - 1); // Zamiana elementu z ostatnim
                    heap.pop_back(); // Usunięcie ostatniego elementu
                    insert(value, new_pr); // Wstawienie elementu z nowym priorytetem
                    heapify(0); // Przywrócenie właściwości kopca
                    return true; // Zwrócenie sukcesu
                }
            }
            return false; // Zwrócenie niepowodzenia, jeśli element nie został znaleziony
        }
        return false; // Zwrócenie niepowodzenia, jeśli kopiec jest pusty
    }

    int return_size() {return heap.getSize();} // Metoda zwracająca rozmiar kopca

    blok peek() { // Metoda zwracająca wartość i priorytet pierwszego elementu w kopcu
        if (heap.getSize() > 0) { // Sprawdzenie, czy kopiec nie jest pusty
            return heap.get(0); // Zwrócenie wartości i priorytetu pierwszego elementu w kopcu
        } else {
            // Kopiec jest pusty, więc zwracamy blok o wartości -1 i priorytecie -1
            return {-1, -1};
        }
    }

    void print() { // Metoda do wyświetlania kopca w postaci drzewa binarnego
        int n = heap.getSize(); // Rozmiar kopca
        int height = log2(n) + 1; // Wysokość drzewa

        // Iterujemy przez każdą warstwę drzewa
        for (int level = 0; level < height; ++level) {
            int nodesInLevel = 1 << level; // Ilość węzłów w danej warstwie
            int offset = (1 << (height - level - 1)) - 1; // Odległość między węzłami
            int firstNodeIndex = (1 << level) - 1; // Indeks pierwszego węzła w danej warstwie
            for (int i = 0; i < nodesInLevel; ++i) {
                int index = firstNodeIndex + i;
                // Wypisujemy odstępy przed węzłami
                for (int j = 0; j < offset; ++j) {
                    std::cout << "  ";
                }
                if (index < n) {
                    std::cout << " " << heap.get(index).priority << " " << heap.get(index).value; // Wyświetlenie wartości i priorytetu węzła
                }
                // Wypisujemy odstępy między węzłami
                for (int j = 0; j < offset; ++j) {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl << std::endl;
        }
    }

    void generate_array(int size_of_array) // Metoda do generowania losowych liczb i wstawiania ich do kopca
    {
        // Deklaracja zmiennej przechowującej losową liczbę

        std::random_device rd;
        std::mt19937 gen(rd());

        // Ustalenie zakresu losowania
        std::uniform_int_distribution<int> dist(1, std::numeric_limits<int>::max());
        std::uniform_int_distribution<int> dist_pr(1, (3*size_of_array));
        //srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

        for (int i = 0; i < size_of_array; i++) // Pętla generująca losowe liczby i zapisująca je do kopca
        {

            int rn = dist(gen);
            int pr_rn = dist_pr(gen);
            insert(rn,pr_rn); // Wstawienie liczby z losowym priorytetem do kopca
        }


    }

};

