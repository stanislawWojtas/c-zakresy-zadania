#pragma once

#include <string>
#include <vector>

struct Order {
    int id;
    std::string customer;
    std::string city;
    std::string product;
    int quantity;
    int unit_price;  // zł
};

inline std::vector<Order> load_orders() {
    return {
        { 1, "Kowalski", "Krakow", "Laptop", 1, 3200 },
        { 2, "Nowak", "Warszawa", "Mysz", 3, 80 },
        { 3, "Wisniewska", "Krakow", "Monitor", 2, 900 },
        { 4, "Nowak", "Krakow", "Klawiatura", 1, 250 },
        { 5, "Zielinski", "Gdansk", "Laptop", 2, 3200 },
        { 6, "Kowalski", "Warszawa", "Sluchawki", 1, 400 },
        { 7, "Wisniewska", "Poznan", "Mysz", 10, 80 },
        { 8, "Nowak", "Gdansk", "Monitor", 1, 900 },
        { 9, "Lewandowska", "Krakow", "Kabel", 6, 30 },
        { 10, "Zielinski", "Warszawa", "Klawiatura", 2, 250 },
        { 11, "Kowalski", "Krakow", "Pendrive", 5, 45 },
        { 12, "Lewandowska", "Poznan", "Tablet", 1, 2100 },
    };
}
