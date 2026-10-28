#pragma once

#include <cstddef>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <vector>

#include "log_entry.hpp"

// Liczba wpisów Error (bez Critical).
std::ptrdiff_t count_errors(const std::vector<LogEntry>& logs);

// Czy jest choć jeden wpis Critical?
bool has_critical(const std::vector<LogEntry>& logs);

// Czy wszystkie żądania modułu trwały krócej niż limit_ms? (brak modułu -> true)
bool all_faster_than(const std::vector<LogEntry>& logs, const std::string& module, int limit_ms);

// n najwolniejszych wpisów, od najwolniejszego.
std::vector<LogEntry> slowest(const std::vector<LogEntry>& logs, std::size_t n);

// Unikalne nazwy modułów.
std::set<std::string> modules(const std::vector<LogEntry>& logs);

// Ostatni wpis Error lub Critical (albo std::nullopt).
std::optional<LogEntry> last_problem(const std::vector<LogEntry>& logs);

// Moduł -> najdłuższy czas odpowiedzi.
std::map<std::string, int> max_response_by_module(const std::vector<LogEntry>& logs);
