// Testy (nie zmieniaj). Rozwiązanie piszesz w log_analysis.cpp.

#include <algorithm>
#include <set>
#include <string>
#include <vector>

#include "check.hpp"
#include "data.hpp"
#include "log_analysis.hpp"

int main() {
    const std::vector<LogEntry> logs = sample_logs();
    const std::vector<LogEntry> first_ten(logs.begin(), logs.begin() + 10);
    const std::vector<LogEntry> only_info = { logs[0], logs[1], logs[3] };
    const std::vector<LogEntry> no_logs;

    check(count_errors(logs) == 3, "count_errors: 3 wpisy Error");
    check(count_errors(no_logs) == 0, "count_errors: pusty log");

    check(has_critical(logs), "has_critical: jest wpis Critical");
    check(!has_critical(first_ten), "has_critical: brak wpisu Critical w pierwszych 10 wpisach");

    check(all_faster_than(logs, "cache", 10), "all_faster_than: cache zawsze ponizej 10 ms");
    check(!all_faster_than(logs, "auth", 1000), "all_faster_than: auth raz przekroczyl 1000 ms");
    check(all_faster_than(logs, "smtp", 1), "all_faster_than: nieistniejacy modul - prawda");

    const std::vector<int> expected_slowest = { 5000, 2310, 1520 };
    check(std::ranges::equal(slowest(logs, 3), expected_slowest, {}, &LogEntry::response_ms),
          "slowest: 3 najwolniejsze to 5000, 2310, 1520 ms");
    check(slowest(logs, 100).size() == logs.size(), "slowest: n wieksze niz liczba wpisow");
    check(slowest(logs, 0).empty(), "slowest: n = 0");

    const std::set<std::string> expected_modules = { "api", "auth", "cache", "db" };
    check(modules(logs) == expected_modules, "modules: api, auth, cache, db");

    const auto last = last_problem(logs);
    check(last.has_value() && last->time == 47, "last_problem: ostatni problem w 47. sekundzie");
    const auto last_in_first_ten = last_problem(first_ten);
    check(last_in_first_ten.has_value() && last_in_first_ten->time == 25,
          "last_problem: w pierwszych 10 wpisach - 25. sekunda");
    check(!last_problem(only_info).has_value(), "last_problem: same wpisy Info - brak problemu");

    return summary();
}
