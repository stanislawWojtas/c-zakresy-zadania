#pragma once

#include <vector>

#include "log_entry.hpp"

// Przykładowe logi (rosnąco po czasie).
inline std::vector<LogEntry> sample_logs() {
    return {
        { 1, Level::Info, "auth", 120 },
        { 3, Level::Info, "api", 85 },
        { 4, Level::Warning, "db", 640 },
        { 7, Level::Info, "api", 92 },
        { 9, Level::Error, "db", 1520 },
        { 12, Level::Info, "cache", 4 },
        { 15, Level::Info, "auth", 135 },
        { 18, Level::Warning, "api", 870 },
        { 21, Level::Info, "cache", 6 },
        { 25, Level::Error, "api", 2310 },
        { 26, Level::Info, "db", 310 },
        { 30, Level::Info, "auth", 98 },
        { 33, Level::Critical, "db", 5000 },
        { 37, Level::Info, "api", 77 },
        { 40, Level::Warning, "auth", 455 },
        { 44, Level::Info, "cache", 3 },
        { 47, Level::Error, "auth", 1105 },
        { 52, Level::Info, "api", 101 },
        { 55, Level::Info, "db", 280 },
        { 58, Level::Info, "cache", 5 },
    };
}
