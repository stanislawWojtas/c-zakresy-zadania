// Testy (nie zmieniaj). Rozwiązanie piszesz w enrollment.cpp.

#include <algorithm>
#include <random>
#include <ranges>
#include <string>
#include <vector>

#include "check.hpp"
#include "enrollment.hpp"

void test_sets() {
    const std::vector<std::string> registered = {
        "Nowak", "Kowalski", "Zielinska", "Wojcik", "Lewandowski", "Kaminska", "Dabrowski",
    };
    const std::vector<std::string> passed = {
        "Kaminska", "Nowak", "Mazur", "Wojcik", "Krawczyk", "Lewandowski",
    };

    const std::vector<std::string> expected_admitted = { "Kaminska", "Lewandowski", "Nowak", "Wojcik" };
    const std::vector<std::string> expected_rejected = { "Dabrowski", "Kowalski", "Zielinska" };
    const std::vector<std::string> expected_mailing = {
        "Dabrowski", "Kaminska", "Kowalski", "Krawczyk", "Lewandowski", "Mazur", "Nowak", "Wojcik", "Zielinska",
    };

    check(admitted(registered, passed) == expected_admitted, "A) dopuszczeni: Kaminska, Lewandowski, Nowak, Wojcik");
    check(rejected(registered, passed) == expected_rejected, "A) odrzuceni: Dabrowski, Kowalski, Zielinska");
    check(mailing_list(registered, passed) == expected_mailing, "A) lista mailingowa: 9 osob bez powtorzen");
    check(admitted(registered, {}).empty(), "A) nikt nie zaliczyl - nikt nie jest dopuszczony");
}

void test_waiting_list() {
    WaitingList list({
        { "Ala", 4.2 },
        { "Bartek", 3.7 },
        { "Celina", 4.8 },
        { "Darek", 3.9 },
        { "Ewa", 4.5 },
    });
    check(list.size() == 5, "B) lista rezerwowa ma 5 osob");

    check(!list.empty() && list.pop_best().name == "Celina", "B) pierwsza przyjeta: Celina (4.8)");
    check(!list.empty() && list.pop_best().name == "Ewa", "B) druga przyjeta: Ewa (4.5)");

    list.add({ "Filip", 4.6 });
    check(!list.empty() && list.pop_best().name == "Filip", "B) dopisany Filip (4.6) wskakuje na szczyt");
    check(!list.empty() && list.pop_best().name == "Ala", "B) nastepna: Ala (4.2)");
    check(list.size() == 2, "B) na liscie zostaly 2 osoby");
    check(!list.empty() && list.pop_best().name == "Darek", "B) nastepny: Darek (3.9)");
}

bool is_valid_split(const std::vector<std::vector<std::string>>& groups,
                    const std::vector<std::string>& students,
                    std::size_t group_count) {
    if (groups.size() != group_count) {
        return false;
    }
    auto group_size = [](const std::vector<std::string>& group) {
        return group.size();
    };
    auto [smallest, largest] = std::ranges::minmax(groups | std::views::transform(group_size));
    if (largest - smallest > 1) {
        return false;
    }
    auto everyone = groups | std::views::join | std::ranges::to<std::vector>();
    return std::ranges::is_permutation(everyone, students);
}

void test_groups() {
    const std::vector<std::string> students = {
        "Ala", "Bartek", "Celina", "Darek", "Ewa", "Filip", "Gosia", "Hubert", "Iza", "Janek",
    };
    std::mt19937 rng(2024);

    const auto first = split_into_groups(students, 3, rng);
    check(is_valid_split(first, students, 3), "C) 3 grupy, rozmiary 4/3/3, kazdy student dokladnie raz");

    const auto second = split_into_groups(students, 3, rng);
    check(is_valid_split(second, students, 3) && first != second, "C) kolejne losowanie daje inny podzial");

    const auto single = split_into_groups(students, 1, rng);
    check(is_valid_split(single, students, 1), "C) jedna grupa - wszyscy razem");
}

int main() {
    test_sets();
    test_waiting_list();
    test_groups();
    return summary();
}
