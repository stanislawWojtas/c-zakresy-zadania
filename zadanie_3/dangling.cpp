// Zadanie 3c: dangling (README.md).
// Program się nie kompiluje. Wyjaśnij błędy w komentarzach i napraw kod.
// Nie zmieniaj load_scores() ani course_name().

#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

std::vector<int> load_scores() {
    return { 40, 85, 62, 97, 71 };
}

std::string_view course_name() {
    return "Podstawy zaawansowanego C++";
}

int main() {
    // Fragment 1
    auto best = std::ranges::max_element(load_scores());
    std::cout << "Najlepszy wynik: " << *best << '\n';
    // TODO: dlaczego błąd?

    // Fragment 2
    auto found = std::ranges::find(load_scores(), 62);
    std::cout << "Znaleziono: " << *found << '\n';
    // TODO: dlaczego błąd?

    // Fragment 3
    auto space = std::ranges::find(course_name(), ' ');
    std::cout << "Znak po pierwszej spacji: " << *(space + 1) << '\n';
    // TODO: dlaczego tu NIE ma błędu, skoro course_name() też zwraca obiekt tymczasowy?

    return 0;
}
