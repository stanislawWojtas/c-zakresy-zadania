# Zakresy (`std::ranges`): zadania

Materiały: [`zakresy-materialy.md`](zakresy-materialy.md) · Dokumentacja: [cppreference](https://en.cppreference.com/cpp/algorithm/ranges) · Czas: około godziny, może dłużej

## Jak zacząć

- Wymagany **C++23** 
- Piszesz tylko w miejscach `TODO`. Testów nie zmieniasz.
- Zadania 2–4 mają testy. Cel to wynik `Zaliczone testy: X/X`.
- Zadanie 5 ma dawać taki output jak w poleceniu (niech wypisuje w wymaganym formacie)

- Najłatwiej otworzyć cały folder `zakresy` w clion i dodać CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)
project(zakresy CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Uwaga: zadanie_3a celowo NIE kompiluje się, dopóki nie dodasz begin()/end() w playlist.hpp.
add_executable(zadanie_1  zadanie_1/main.cpp)
add_executable(zadanie_2  zadanie_2/main.cpp)
add_executable(zadanie_3a zadanie_3/playlist_main.cpp)
add_executable(zadanie_3b zadanie_3/sentinel_main.cpp)
add_executable(zadanie_4  zadanie_4/main.cpp zadanie_4/log_analysis.cpp)
add_executable(zadanie_5  zadanie_5/main.cpp)
```

  Plik zapisz jako `zakresy/CMakeLists.txt` (obok `README.md`). Potem w CLion wybierz target (`zadanie_1`, `zadanie_2`, `zadanie_3a`, …) i uruchom. Potrzebny jest kompilator z obsługą C++23, np. GCC 14+ (w CLion: *Bundled MinGW*).

**Zasady:**
- algorytmy `std::ranges` bez `begin()`/`end()`,
- zamiast lambd porównujących używaj projekcji (`&Typ::pole`). (tam gdzie to mozliwe)

---

## Zadanie 1: Z iteratorów na zakresy 

Przepisz `zadanie_1/main.cpp` na `std::ranges`. Wynik programu ma się nie zmienić.

- `find(...) != end()` zastąp algorytmem zwracającym `bool`.
- `*min_element` i `*max_element` zastąp algorytmami zwracającymi wartość.
- Lambdy porównujące miasta zastąp projekcją.

<details>
<summary>Podpowiedzi (kliknij, aby rozwinąć)</summary>

- Zwróć uwagę na użyte funkcje. Potraktuj to zadanie jak wprowadzenie do nich.

</details>

## Zadanie 2: Dziennik ocen

Uzupełnij 7 funkcji w `zadanie_2/main.cpp`. Każda to jedno wywołanie algorytmu albo jeden potok widoków.

<details>
<summary>Podpowiedzi (kliknij, aby rozwinąć)</summary>

- **e)** Zwróć uwagę, co zwraca `std::ranges::find_last`: podzakres (pusty, gdy nic nie znaleziono), a nie iterator.
- **g)** Użyj potoku `|` oraz `std::views::filter`, `std::views::transform` i `std::ranges::to`.

</details>

## Zadanie 3: Własny zakres, sentinel

- **3a:** w `playlist.hpp` dodaj `begin()` i `end()` (również `const`), żeby przeszły `static_assert`y. Potem uzupełnij funkcje w `playlist_main.cpp`.
- **3b:** w `sentinel.hpp` uzupełnij `UntilNegative`: zakres ma się kończyć na pierwszej liczbie ujemnej. Potem uzupełnij funkcje w `sentinel_main.cpp`.

<details>
<summary>Podpowiedzi (kliknij, aby rozwinąć)</summary>

- Materiały, sekcje 4.1–4.3.
- **3b:** napisz pomocniczą funkcję, która zwraca zakres `data` zakończony przez `UntilNegative` (`std::ranges::subrange(data, UntilNegative {})`).
- **3b:** liczbę elementów policzysz przez `std::ranges::distance`.

</details>

## Zadanie 4: Logi serwera 

Zaimplementuj funkcje z `log_analysis.hpp` w pliku `log_analysis.cpp`, bez pętli.

<details>
<summary>Podpowiedzi (kliknij, aby rozwinąć)</summary>

- Przydatne: `views::filter`, `views::transform`, `views::take`, `ranges::to`, `ranges::greater {}`, `find_last_if`.
- **`all_faster_than`:** najpierw przefiltruj logi z danego modułu i zapisz je do zmiennej, potem sprawdź limit.
- **`slowest`:** posortuj kopię wektora. Do zwrócenia `n` najwolniejszych możesz użyć `std::views::take(n)` razem z potokiem `|`.
- **`modules`:** użyj `std::views::transform` oraz `std::ranges::to<std::set>()`.
- **`last_problem`:** użyj `std::ranges::find_last_if`. Zwróć `std::nullopt`, jeśli wynik jest pusty.

</details>

## Zadanie 5: Raport sprzedaży 

Napisz samodzielnie program w `zadanie_5/main.cpp`. Lista zamówień sklepu jest w `orders.hpp`. Wartość zamówienia to `quantity * unit_price`.

Program ma wypisać raport:

1. zamówienia z Krakowa, od najdroższego (`#id=wartość`),
2. numery trzech największych zamówień,
3. klientów alfabetycznie, bez powtórzeń,
4. czy były zamówienia z Gdańska i z Łodzi,
5. ile łącznie wydał Nowak.

Oczekiwany wynik:

```
1. Krakow: #1=3200 #3=1800 #4=250 #11=225 #9=180
2. Top 3: #5 #1 #12
3. Klienci: Kowalski Lewandowska Nowak Wisniewska Zielinski
4. Gdansk: true, Lodz: false
5. Nowak wydal: 1390
```

<details>
<summary>Podpowiedzi (kliknij, aby rozwinąć)</summary>

- Projekcją może być dowolna funkcja, nie tylko pole struktury. Napisz osobną funkcję `int value(const Order&)` liczącą wartość zamówienia (`quantity * unit_price`) i sortuj po niej.
- **1.** Najpierw zapisz zamówienia z Krakowa do osobnego wektora, potem go posortuj i wypisz w odpowiednim formacie przy użyciu `for_each`.

</details>
