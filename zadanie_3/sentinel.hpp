#pragma once

// Kończy zakres na pierwszej liczbie ujemnej: { 5, 12, 3, -1, 100 } -> { 5, 12, 3 }
struct UntilNegative {
    bool operator==(const int* it) const {
        // TODO
        return true;
    }
};
