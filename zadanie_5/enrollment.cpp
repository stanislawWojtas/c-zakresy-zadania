// Zadanie 5: zapisy na laboratoria (README.md). Funkcje z enrollment.hpp.

#include "enrollment.hpp"

#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>

// --- Część A ---

std::vector<std::string> admitted(std::vector<std::string> registered, std::vector<std::string> passed) {
    // TODO
    return {};
}

std::vector<std::string> rejected(std::vector<std::string> registered, std::vector<std::string> passed) {
    // TODO
    return {};
}

std::vector<std::string> mailing_list(std::vector<std::string> registered, std::vector<std::string> passed) {
    // TODO
    return {};
}

// --- Część B ---

WaitingList::WaitingList(std::vector<Applicant> applicants)
    : heap_(std::move(applicants)) {
    // TODO
}

void WaitingList::add(const Applicant& applicant) {
    // TODO
}

Applicant WaitingList::pop_best() {
    // TODO
    return {};
}

// --- Część C ---

std::vector<std::vector<std::string>> split_into_groups(std::vector<std::string> students,
                                                        std::size_t group_count,
                                                        std::mt19937& rng) {
    // TODO
    return {};
}
