#pragma once

#include <cstddef>
#include <random>
#include <string>
#include <vector>

// A) Wejście nieposortowane, wynik posortowany alfabetycznie.

// Zapisani, którzy zaliczyli przedmiot wymagany.
std::vector<std::string> admitted(std::vector<std::string> registered, std::vector<std::string> passed);

// Zapisani, którzy go NIE zaliczyli.
std::vector<std::string> rejected(std::vector<std::string> registered, std::vector<std::string> passed);

// Wszyscy z obu list, bez powtórzeń.
std::vector<std::string> mailing_list(std::vector<std::string> registered, std::vector<std::string> passed);

// B) Lista rezerwowa jako kopiec - na szczycie najwyższa średnia.

struct Applicant {
    std::string name;
    double average;
};

class WaitingList {
public:
    explicit WaitingList(std::vector<Applicant> applicants);

    void add(const Applicant& applicant);

    // Usuwa i zwraca kandydata z najwyższą średnią (lista niepusta).
    Applicant pop_best();

    bool empty() const {
        return heap_.empty();
    }

    std::size_t size() const {
        return heap_.size();
    }

private:
    std::vector<Applicant> heap_;
};

// C) Tasuje studentów i dzieli na group_count grup (liczebności różnią się max o 1).
std::vector<std::vector<std::string>> split_into_groups(std::vector<std::string> students,
                                                        std::size_t group_count,
                                                        std::mt19937& rng);
