// Zadanie 3b: sentinel (README.md).
// W każdej funkcji użyj zakresu std::ranges::subrange(data, UntilNegative {}).

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <ranges>

#include "check.hpp"
#include "sentinel.hpp"

// Ile jest pomiarów?
std::ptrdiff_t count_valid(const int* data) {
    // TODO
    return 0;
}

// Największy pomiar.
int max_valid(const int* data) {
    // TODO
    return 0;
}

// Czy pomiar występuje?
bool contains_valid(const int* data, int value) {
    // TODO
    return false;
}

// Ile pomiarów jest większych niż limit?
std::ptrdiff_t count_above(const int* data, int limit) {
    // TODO
    return 0;
}

// --- Testy (nie zmieniaj) ---

static_assert(std::sentinel_for<UntilNegative, const int*>);

int main() {
    const int readings[] = { 5, 12, 3, 8, 17, -1, 100, 42, 7 };
    const int no_data[] = { -5, 3, 9 };

    check(count_valid(readings) == 5, "5 pomiarow");
    check(count_valid(readings) > 0 && max_valid(readings) == 17, "max: 17 (nie 100 zza znacznika)");
    check(contains_valid(readings, 8), "jest 8");
    check(!contains_valid(readings, 100), "100 jest za znacznikiem");
    check(count_above(readings, 6) == 3, "3 pomiary > 6");

    check(count_valid(no_data) == 0, "pusta seria: 0 pomiarow");
    check(!contains_valid(no_data, 3), "pusta seria: brak 3");

    return summary();
}
