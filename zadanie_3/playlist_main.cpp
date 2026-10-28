// Zadanie 3a: własny zakres (README.md).
// Nie skompiluje się, dopóki Playlist nie spełni poniższych konceptów.

#include <algorithm>
#include <ranges>
#include <string>

#include "check.hpp"
#include "playlist.hpp"

static_assert(std::ranges::range<Playlist>, "Playlist musi byc zakresem (begin/end)");
static_assert(std::ranges::range<const Playlist>, "Brakuje const begin/end");
static_assert(std::ranges::sized_range<Playlist>, "Playlist musi byc sized_range");
static_assert(std::ranges::random_access_range<Playlist>, "Playlist musi byc random_access_range");
static_assert(std::ranges::contiguous_range<Playlist>, "Playlist musi byc contiguous_range");

// Sortuj od najkrótszego utworu.
void sort_by_duration(Playlist& playlist) {
    // TODO
}

// Tytuł najdłuższego utworu albo "" dla pustej playlisty.
std::string longest_title(const Playlist& playlist) {
    // TODO
    return "";
}

// Czy jest utwór tego wykonawcy?
bool has_artist(const Playlist& playlist, const std::string& artist) {
    // TODO
    return false;
}

// Łączny czas w sekundach (std::ranges::for_each).
int total_seconds(const Playlist& playlist) {
    // TODO
    return 0;
}

// --- Testy (nie zmieniaj) ---

int main() {
    Playlist playlist;
    playlist.add({ "Bohemian Rhapsody", "Queen", 354 });
    playlist.add({ "Smells Like Teen Spirit", "Nirvana", 301 });
    playlist.add({ "Billie Jean", "Michael Jackson", 294 });
    playlist.add({ "Hotel California", "Eagles", 391 });
    playlist.add({ "Africa", "Toto", 295 });
    playlist.add({ "Under Pressure", "Queen", 248 });

    check(std::ranges::size(playlist) == 6, "rozmiar zakresu: 6");

    sort_by_duration(playlist);
    check(std::ranges::is_sorted(playlist, {}, &Song::seconds), "posortowane po czasie");
    check(std::ranges::begin(playlist)->title == "Under Pressure", "najkrotszy: Under Pressure");

    check(longest_title(playlist) == "Hotel California", "najdluzszy: Hotel California");
    check(has_artist(playlist, "Toto"), "jest Toto");
    check(!has_artist(playlist, "ABBA"), "nie ma ABBA");
    check(total_seconds(playlist) == 1883, "laczny czas: 1883 s");

    const Playlist empty;
    check(longest_title(empty).empty(), "pusta: brak najdluzszego");
    check(total_seconds(empty) == 0, "pusta: 0 s");

    std::ranges::reverse(playlist);
    check(std::ranges::begin(playlist)->title == "Hotel California", "reverse dziala");

    return summary();
}
