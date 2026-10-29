// Zadanie 1: przepisz program na std::ranges (README.md).
// Wynik programu ma się nie zmienić !!!.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct City {
    std::string name;
    int temperature;
};

int main() {
    std::vector<int> temps = { 12, -3, 7, 21, 0, -8, 15, 7, 30, 4 };

    auto print = [](int x) {
        std::cout << x << " ";
    };

    // 1. Wszystkie pomiary
    std::cout << "Pomiary: ";

    //TODO
    std::for_each(temps.begin(), temps.end(), print);
    std::cout << "\n";

    // 2. Min i max
    //TODO
    int coldest = *std::min_element(temps.begin(), temps.end());
    int hottest = *std::max_element(temps.begin(), temps.end());
    std::cout << "Min: " << coldest << ", max: " << hottest << "\n";

    // 3. Dni z mrozem
    //TODO
    auto frosty_days = std::count_if(temps.begin(), temps.end(), [](int t) {
        return t < 0;
    });
    std::cout << "Dni z mrozem: " << frosty_days << "\n";

    // 4. Czy było 21 stopni
    //TODO
    bool was_21 = std::find(temps.begin(), temps.end(), 21) != temps.end();
    std::cout << std::boolalpha << "Bylo 21 stopni: " << was_21 << "\n";

    // 5. Czy wszystkie poniżej 35?
    //TODO
    bool all_below_35 = std::all_of(temps.begin(), temps.end(), [](int t) {
        return t < 35;
    });
    std::cout << "Wszystkie ponizej 35: " << all_below_35 << "\n";

    // 6. Pierwszy dzień powyżej 20 (tu begin() do liczenia indeksu jest OK)
    auto first_hot = std::find_if(temps.begin(), temps.end(), [](int t) {
        return t > 20;
    });
    std::cout << "Pierwszy dzien powyzej 20: indeks " << (first_hot - temps.begin()) << "\n";

    // 7. Sortowanie
    //TODO
    std::sort(temps.begin(), temps.end());
    std::cout << "Posortowane: ";
    //TODO
    std::for_each(temps.begin(), temps.end(), print);
    std::cout << "\n";

    // 8. Odwrócenie
    //TODO
    std::reverse(temps.begin(), temps.end());
    std::cout << "Odwrocone: ";
    //TODO
    std::for_each(temps.begin(), temps.end(), print);
    std::cout << "\n";

    // 9. Miasta od najzimniejszego
    std::vector<City> cities = { { "Krakow", 14 }, { "Gdansk", 9 }, { "Wroclaw", 17 }, { "Warszawa", 12 } };
    std::sort(cities.begin(), cities.end(), [](const City& a, const City& b) {
        return a.temperature < b.temperature;
    });
    std::cout << "Miasta od najzimniejszego: ";
    std::for_each(cities.begin(), cities.end(), [](const City& c) {
        std::cout << c.name << " ";
    });
    std::cout << "\n";

    // 10. Najcieplejsze miasto
    auto warmest = std::max_element(cities.begin(), cities.end(), [](const City& a, const City& b) {
        return a.temperature < b.temperature;
    });
    std::cout << "Najcieplej: " << warmest->name << "\n";

    return 0;
}
