#include <iostream> // Biblioteka do obsługi strumieni wejścia/wyjścia

#include "dynamic_array.cpp" // Plik nagłówkowy z deklaracją klasy DynamicArray
#include <string> // Biblioteka do obsługi łańcuchów znaków
#include <cstring> // Biblioteka do obsługi operacji na łańcuchach znaków
#include <random> // Biblioteka do generowania liczb losowych
#include <fstream> // Biblioteka do obsługi plików
#include <math.h> // Biblioteka matematyczna

// Struktura blok przechowująca wartość i priorytet
struct blok{
    int value; // Wartość elementu
    int priority; // Priorytet elementu
};

// Deklaracja klasy MaxHeap reprezentującej kopiec maksymalny
class MaxHeap{
public:
    // Metoda zwracająca indeks rodzica elementu o indeksie i
    int parent(int i) { return (i-1)/2; }
    // Metoda zwracająca indeks lewego dziecka elementu o indeksie i
    int left(int i) {return (2*i + 1);}
    // Metoda zwracająca indeks prawego dziecka elementu o indeksie i
    int right(int i) {return (2*i + 2);}

    // Metoda naprawiająca własność kopca dla węzła o indeksie i
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int bgst = i;
        if(l < heap.getSize() && heap.get(l).priority > heap.get(i).priority)
            bgst = l;
        if(r < heap.getSize() && heap.get(r).priority > heap.get(bgst).priority)
            bgst = r;
        if(bgst != i){
            heap.Swap(i, bgst);
            heapify(bgst);
        }
    }

    DynamicArray<blok> heap; // Dynamiczna tablica przechowująca elementy kopca

    MaxHeap(){ // Konstruktor
        srand(time(0)); // Inicjalizacja generatora liczb pseudolosowych
    }

    ~MaxHeap() // Destruktor
    {

    }

    blok getMax(){ // Metoda zwracająca maksymalny element z kopca
        if(heap.getSize() != 0)
            return heap.front();
    }

    void insert_heap(int value, int prior){ // Metoda wstawiająca nowy element do kopca
        blok new1; // Utworzenie nowego bloku
        new1.priority = prior; // Przypisanie priorytetu
        new1.value = value; // Przypisanie wartości
        heap.push_back(new1); // Dodanie bloku do kopca
        int i = heap.getSize() - 1; // Indeks nowo wstawionego elementu
        while(i != 0 && heap.get(parent(i)).priority < heap.get(i).priority){
            heap.Swap(i, parent(i));
            i = parent(i);
        }
    }

    auto deleteMax(){ // Metoda usuwająca maksymalny element z kopca
        blok max = heap.front(); // Zapisanie maksymalnego elementu
        if(heap.getSize() != 0){ // Sprawdzenie, czy kopiec nie jest pusty
            heap.Swap(0, heap.getSize() - 1); // Zamiana pierwszego elementu z ostatnim
            heap.pop_back(); // Usunięcie ostatniego elementu
            heapify(0); // Przywrócenie własności kopca
        }
        return max; // Zwrócenie maksymalnego elementu
    }

    int size() {return heap.getSize();} // Metoda zwracająca rozmiar kopca
};
