#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "debug.hpp"

[[maybe_unused]]
static void print_unordered_map(const std::unordered_map<int, int>& m) {
    std::cout << "Hash map contents:" << std::endl;
    for (const auto& p : m) {
        std::cout << "key: " << p.first << ", value: " << p.second << std::endl;
    }
}

void print_sorted_map(const std::unordered_map<int, int>& m) {
    std::vector<std::pair<int, int>> entries(m.begin(), m.end());
    std::sort(entries.begin(), entries.end());

    std::cout << "Hash map contents (sorted):" << std::endl;
    for (const auto& e : entries) {
        std::cout << "key: " << e.first << ", value: " << e.second << std::endl;
    }
}