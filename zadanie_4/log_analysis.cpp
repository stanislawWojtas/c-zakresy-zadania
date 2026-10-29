// Zadanie 4: logi serwera (README.md). Funkcje z log_analysis.hpp - bez pętli.

#include "log_analysis.hpp"

#include <algorithm>
#include <ranges>

std::ptrdiff_t count_errors(const std::vector<LogEntry>& logs) {
    // TODO
    return 0;
}

bool has_critical(const std::vector<LogEntry>& logs) {
    // TODO
    return false;
}

bool all_faster_than(const std::vector<LogEntry>& logs, const std::string& module, int limit_ms) {
    // TODO
    return false;
}

std::vector<LogEntry> slowest(const std::vector<LogEntry>& logs, std::size_t n) {
    // TODO
    return {};
}

std::set<std::string> modules(const std::vector<LogEntry>& logs) {
    // TODO
    return {};
}

std::optional<LogEntry> last_problem(const std::vector<LogEntry>& logs) {
    // TODO
    return std::nullopt;
}
