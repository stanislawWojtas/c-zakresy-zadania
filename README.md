# Zakresy (`std::ranges`): zadania

Materiały: [`zakresy-materialy.md`](zakresy-materialy.md) · Dokumentacja: [cppreference](https://en.cppreference.com/cpp/algorithm/ranges) · Czas: ~70 min

## Jak zacząć

- Wymagany **C++23** (np. GCC 14+, w CLion: *Bundled MinGW*).
- W CLion otwórz folder `zakresy`, wybierz target (`zadanie_1`, `zadanie_2`, `zadanie_3a`, …) i uruchom.
- Piszesz tylko w miejscach `TODO`. Testów nie zmieniasz.
- Zadania 2–5 mają testy. Cel to wynik `Zaliczone testy: X/X`.

**Zasady:**
- algorytmy `std::ranges` bez `begin()`/`end()`,
- zamiast lambd porównujących używaj projekcji (`&Typ::pole`).

---

## Zadanie 1: Z iteratorów na zakresy (~8 min)

Przepisz `zadanie_1/main.cpp` na `std::ranges`. Wynik programu ma się nie zmienić.

- `find(...) != end()` zastąp algorytmem zwracającym `bool`.
- `*min_element` i `*max_element` zastąp algorytmami zwracającymi wartość.
- Lambdy porównujące miasta zastąp projekcją.

## Zadanie 2: Dziennik ocen (~10 min)

Uzupełnij 7 funkcji w `zadanie_2/main.cpp`. Każda to jedno wywołanie algorytmu albo jeden potok widoków.

> `find_last` zwraca podzakres (pusty, gdy nic nie znaleziono), a nie iterator.

## Zadanie 3: Własny zakres, sentinel, dangling (~20 min)

- **3a:** w `playlist.hpp` dodaj `begin()` i `end()` (również `const`), żeby przeszły `static_assert`y. Potem uzupełnij funkcje w `playlist_main.cpp`.
- **3b:** w `sentinel.hpp` uzupełnij `UntilNegative`: zakres ma się kończyć na pierwszej liczbie ujemnej. Potem uzupełnij funkcje w `sentinel_main.cpp`.
- **3c:** `dangling.cpp` się nie kompiluje. Wyjaśnij w komentarzach dlaczego, a potem napraw kod.

> Materiały, sekcje 4.1–4.3. Liczbę elementów policzysz przez `std::ranges::distance`.

## Zadanie 4: Logi serwera (~20 min)

Zaimplementuj funkcje z `log_analysis.hpp` w pliku `log_analysis.cpp`, bez pętli.

> Przydatne: `views::filter`, `views::transform`, `views::take`, `ranges::to`, `ranges::greater {}`, `find_last_if`.

## Zadanie 5: Zapisy na laboratoria (~20 min)

Zaimplementuj funkcje z `enrollment.hpp` w pliku `enrollment.cpp`:

- **A:** `admitted`, `rejected`, `mailing_list`: operacje na zbiorach (najpierw posortuj wejście).
- **B:** `WaitingList`: kopiec po średniej (`make_heap`, `push_heap`, `pop_heap`).
- **C:** `split_into_groups`: `shuffle`, a potem podział na grupy (tu pętla jest dozwolona).

> Wynik operacji na zbiorach zapisuj przez `std::back_inserter(wynik)`.
