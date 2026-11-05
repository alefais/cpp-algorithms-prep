#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
    Problem: Two Sum on a sorted vector (two pointers)

    Given a std::vector<int> a sorted in non-decreasing order and an int target, 
    return the indices i and j with i < j such that a[i] + a[j] == target. 
    You may use only O(1) extra space. 
    You can assume exactly one solution exists. 
    If none exists, return (0, 0).

    Examples:
    a = {1, 2, 4, 6}, target = 6 gives (1, 2)
    a = {2, 7, 11, 15}, target = 9 gives (0, 1)
    a = {1, 2}, target = 10 gives (0, 0)
*/

/**
    Out of specifications: if more than one solution exists, returns the pair (i, j) with 
    the smallest first index i among all valid pairs and, for that i, the largest second index j.

    Time O(n), space O(1). Requires a sorted (non-decreasing) vector.
*/
std::pair<int, int> two_sum_ordered(const std::vector<int>& a, const int target, bool debug = false) {
    std::pair<int, int> res = {0, 0}; // default return value if no valid solution exists

    if (a.size() < 2) return res;

    std::size_t i = 0;
    std::size_t j = a.size() - 1;
    int step = 0;

    while (i < j) {
        if (debug)
            std::cout << "Step " << ++step << ": i = " << i << ", j = " << j << std::endl;

        long long sum = static_cast<long long>(a[i]) + a[j];
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            res.first = i;
            res.second = j;
            return res;
        }
    }

    return res;
}


int main(int argc, char* argv[]) {
    bool debug = argc > 1 && std::string(argv[1]) == "-d";

    std::vector<int> a1 = {1, 2, 4, 6};
    std::vector<int> a2 = {2, 7, 11, 15};
    std::vector<int> a3 = {1, 2};
    std::vector<int> a4 = {1, 5, 5};
    int target1 = 6;
    int target2 = 9;
    int target3 = 10;

    std::pair<int, int> res = {};

    // example 1: a = {1, 2, 4, 6}, target = 6, expected result (1, 2)
    std::cout << "Arguments a = {1, 2, 4, 6}, target = 6, expected result (1, 2)." << std::endl;

    res = two_sum_ordered(a1, target1);
    std::cout << "Result: (" << res.first << ", " << res.second << ")" << std::endl;

    // example 2: a = {2, 7, 11, 15}, target = 9, expected result (0, 1)
    std::cout << "Arguments a = {2, 7, 11, 15}, target = 9, expected result (0, 1)." << std::endl;

    res = two_sum_ordered(a2, target2);
    std::cout << "Result: (" << res.first << ", " << res.second << ")" << std::endl;

    // example 3: a = {1, 2}, target = 10, expected result (0, 0)
    std::cout << "Arguments a = {1, 2}, target = 10, expected result (0, 0)." << std::endl;

    res = two_sum_ordered(a3, target3);
    std::cout << "Result: (" << res.first << ", " << res.second << ")" << std::endl;

    // example 4: a = {1, 5, 5}, target = 6, expected result (0, 2) with 2 valid solution pairs (0, 1) and (0, 2)
    std::cout << "\nOut of specifications:\nArguments a = {1, 5, 5}, target = 6, expected result (0, 2) (valid solution pairs (0, 1) and (0, 2))." << std::endl;

    res = two_sum_ordered(a4, target1, debug);
    std::cout << "Result: (" << res.first << ", " << res.second << ")" << std::endl;

    return 0;
}