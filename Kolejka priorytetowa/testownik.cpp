#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>

#include "Kolejka_lista.cpp"
#include "Kolejka_heap.cpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // Liczba elementów i iteracji
    std::cout << "Jak dużo ma być w niej elementów? (podaj numer)" << std::endl;
    int ilosc_elementow;
    std::cin >> ilosc_elementow;

    std::cout << "Ile iteracji chcesz wykonać?" << std::endl;
    int ilosc_iteracji;
    std::cin >> ilosc_iteracji;

    // Kolejka kopca (Pr_queue_h)
    double insert_time_sum_kopiec = 0.0;
    double extract_max_time_sum_kopiec = 0.0;
    double peek_time_sum_kopiec = 0.0;
    double modify_key_time_sum_kopiec = 0.0;
    double return_size_time_sum_kopiec = 0.0;

    // Kolejka listy (Pr_queue_l)
    double insert_time_sum_lista = 0.0;
    double extract_max_time_sum_lista = 0.0;
    double peek_time_sum_lista = 0.0;
    double modify_key_time_sum_lista = 0.0;
    double return_size_time_sum_lista = 0.0;

    const int priorytety = 100000000;
    //const int priorytety = 0;
    for(int i = 0; i < ilosc_iteracji; ++i) {
        // Testy dla Pr_queue_h (kopiec)
        {
            Pr_queue_h kolejka;
            kolejka.generate_array(ilosc_elementow);

            auto start_insert = std::chrono::high_resolution_clock::now();
            kolejka.insert(69, priorytety); // Przyjmuję, że wartość 'i' będzie kluczem
            auto end_insert = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> insert_time = end_insert - start_insert;
            insert_time_sum_kopiec += insert_time.count();

            auto start_extract_max = std::chrono::high_resolution_clock::now();
            kolejka.extract_max();
            auto end_extract_max = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> extract_max_time = end_extract_max - start_extract_max;
            extract_max_time_sum_kopiec += extract_max_time.count();

            auto start_peek = std::chrono::high_resolution_clock::now();
            kolejka.peek();
            auto end_peek = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> peek_time = end_peek - start_peek;
            peek_time_sum_kopiec += peek_time.count();

            auto start_modify_key = std::chrono::high_resolution_clock::now();
            kolejka.modify_key(69, priorytety);
            auto end_modify_key = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> modify_key_time = end_modify_key - start_modify_key;
            modify_key_time_sum_kopiec += modify_key_time.count();

            auto start_return_size = std::chrono::high_resolution_clock::now();
            kolejka.return_size();
            auto end_return_size = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> return_size_time = end_return_size - start_return_size;
            return_size_time_sum_kopiec += return_size_time.count();
        }

        // Testy dla Pr_queue_l (lista)
        {
            Pr_queue_l kolejka;
            kolejka.generate_array(ilosc_elementow);

            auto start_insert = std::chrono::high_resolution_clock::now();
            kolejka.insert(69, priorytety); // Przyjmuję, że wartość 'i' będzie kluczem
            auto end_insert = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> insert_time = end_insert - start_insert;
            insert_time_sum_lista += insert_time.count();

            auto start_extract_max = std::chrono::high_resolution_clock::now();
            kolejka.extract_max();
            auto end_extract_max = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> extract_max_time = end_extract_max - start_extract_max;
            extract_max_time_sum_lista += extract_max_time.count();

            auto start_peek = std::chrono::high_resolution_clock::now();
            kolejka.peek();
            auto end_peek = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> peek_time = end_peek - start_peek;
            peek_time_sum_lista += peek_time.count();

            auto start_modify_key = std::chrono::high_resolution_clock::now();
            kolejka.modify_key(69, priorytety);
            auto end_modify_key = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> modify_key_time = end_modify_key - start_modify_key;
            modify_key_time_sum_lista += modify_key_time.count();

            auto start_return_size = std::chrono::high_resolution_clock::now();
            kolejka.return_size();
            auto end_return_size = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> return_size_time = end_return_size - start_return_size;
            return_size_time_sum_lista += return_size_time.count();
        }
        std::cout << "Podejscie " << i << std::endl;
    }

    // Wyświetlanie średnich czasów wykonania dla każdej klasy kolejki
    std::cout << "Statystyki dla kolejki kopca (Pr_queue_h):" << std::endl;
    std::cout << "Sredni czas wstawiania: " << insert_time_sum_kopiec / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas usuwania elementu o najwyższym priorytecie: " << extract_max_time_sum_kopiec / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas pobierania elementu o najwyższym priorytecie: " << peek_time_sum_kopiec / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas modyfikacji klucza: " << modify_key_time_sum_kopiec / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas zwracania rozmiaru kolejki: " << return_size_time_sum_kopiec / ilosc_iteracji << " milisekund." << std::endl;

    std::cout << std::endl;

    std::cout << "Statystyki dla kolejki listy (Pr_queue_l):" << std::endl;
    std::cout << "Sredni czas wstawiania: " << insert_time_sum_lista / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas usuwania elementu o najwyższym priorytecie: " << extract_max_time_sum_lista / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas pobierania elementu o najwyższym priorytecie: " << peek_time_sum_lista / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas modyfikacji klucza: " << modify_key_time_sum_lista / ilosc_iteracji << " milisekund." << std::endl;
    std::cout << "Sredni czas zwracania rozmiaru kolejki: " << return_size_time_sum_lista / ilosc_iteracji << " milisekund." << std::endl;

    return 0;
}
