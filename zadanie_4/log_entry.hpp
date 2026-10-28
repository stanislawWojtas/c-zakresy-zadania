#pragma once

#include <string>

enum class Level { Info, Warning, Error, Critical };

struct LogEntry {
    int time;            // sekunda od uruchomienia serwera
    Level level;
    std::string module;  // np. "auth", "db", "api"
    int response_ms;     // czas odpowiedzi w ms
};
