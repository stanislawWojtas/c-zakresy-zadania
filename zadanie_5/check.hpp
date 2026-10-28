#pragma once

#include <iostream>
#include <string_view>

// Mini-testy (nie zmieniaj).
inline int g_passed = 0;
inline int g_failed = 0;

inline void check(bool condition, std::string_view description) {
    if (condition) {
        ++g_passed;
        std::cout << "[ OK ] " << description << '\n';
    } else {
        ++g_failed;
        std::cout << "[FAIL] " << description << '\n';
    }
}

inline int summary() {
    std::cout << "\nZaliczone testy: " << g_passed << "/" << (g_passed + g_failed) << '\n';
    return g_failed == 0 ? 0 : 1;
}
