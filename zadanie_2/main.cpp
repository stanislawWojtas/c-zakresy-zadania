// Zadanie 2: dziennik ocen (README.md).

#include <algorithm>
#include <ranges>
#include <string>
#include <vector>

#include "check.hpp"

struct Student {
    std::string name;
    std::string surname;
    int year;
    double average;
};

// a) Sortuj po nazwisku.
void sort_by_surname(std::vector<Student>& students) {
    // TODO
}

// b) Sortuj po roku; w obrębie roku zachowaj dotychczasową kolejność.
void sort_by_year_stable(std::vector<Student>& students) {
    // TODO
}

// c) Student z najwyższą średnią.
Student best_student(const std::vector<Student>& students) {
    // TODO
    return {};
}

// d) Czy jest student o tym nazwisku?
bool has_surname(const std::vector<Student>& students, const std::string& surname) {
    // TODO
    return false;
}

// e) Nazwisko ostatniego studenta z danego roku albo "brak".
std::string last_from_year(const std::vector<Student>& students, int year) {
    // TODO
    return "";
}

// f) Czy nikt nie ma średniej poniżej progu?
bool nobody_below(const std::vector<Student>& students, double threshold) {
    // TODO
    return false;
}

// g) Nazwiska studentów ze średnią >= 4.5.
std::vector<std::string> scholarship_surnames(const std::vector<Student>& students) {
    // TODO
    return {};
}

// --- Dane i testy (nie zmieniaj) ---

std::vector<Student> make_students() {
    return {
        { "Anna", "Zielinska", 2, 4.71 },
        { "Piotr", "Kowalski", 1, 3.45 },
        { "Maria", "Nowak", 3, 4.92 },
        { "Jan", "Wisniewski", 1, 4.50 },
        { "Ewa", "Dabrowska", 2, 3.10 },
        { "Tomasz", "Lewandowski", 3, 2.95 },
        { "Ola", "Kaminska", 1, 4.05 },
        { "Adam", "Wojcik", 2, 3.88 },
    };
}

int main() {
    auto students = make_students();

    sort_by_surname(students);
    check(std::ranges::is_sorted(students, {}, &Student::surname), "a) posortowani po nazwisku");
    check(students.front().surname == "Dabrowska" && students.back().surname == "Zielinska",
          "a) Dabrowska pierwsza, Zielinska ostatnia");

    sort_by_year_stable(students);
    std::vector<std::string> expected_b = {
        "Kaminska", "Kowalski", "Wisniewski",  // rok 1
        "Dabrowska", "Wojcik", "Zielinska",    // rok 2
        "Lewandowski", "Nowak",                // rok 3
    };
    check(std::ranges::equal(students, expected_b, {}, &Student::surname),
          "b) po roku, w obrebie roku alfabetycznie");

    check(best_student(make_students()).surname == "Nowak", "c) najlepsza srednia: Nowak");

    check(has_surname(make_students(), "Nowak"), "d) jest Nowak");
    check(!has_surname(make_students(), "Kowalska"), "d) nie ma Kowalskiej");

    check(last_from_year(make_students(), 1) == "Kaminska", "e) ostatni z 1. roku: Kaminska");
    check(last_from_year(make_students(), 2) == "Wojcik", "e) ostatni z 2. roku: Wojcik");
    check(last_from_year(make_students(), 4) == "brak", "e) 4. rok: brak");

    check(!nobody_below(make_students(), 3.0), "f) ktos ma ponizej 3.0");
    check(nobody_below(make_students(), 2.5), "f) nikt nie ma ponizej 2.5");

    std::vector<std::string> expected_g = { "Zielinska", "Nowak", "Wisniewski" };
    check(scholarship_surnames(make_students()) == expected_g, "g) stypendysci: Zielinska, Nowak, Wisniewski");

    return summary();
}
