#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "common/debug.hpp"

/**
    Problem: Two Sum

    Given a std::vector<int> nums and an int target, return the indices i and j (with i != j) such that nums[i] + nums[j] == target.
    You can assume exactly one solution exists, and you may not use the same element twice.
    Returns the pair (i, j) with i < j. 

    Example: nums = {2, 7, 11, 15}, target = 9 gives {0, 1}.
*/

/**
    Returns the pair (i, j) with i < j. If more than one solution exists,
    returns the pair whose second index is the smallest, scanning the vector from left to right.
 */
std::pair<int, int> check_vector_and_target_v1a(const std::vector<int>& a, const int target) {
    std::pair<int, int> res(0, 0); // result pair, (0, 0) is the default value if no solution is found, a valid solution will always have i != j

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a.size() && j != i; j++) {
            if ((a[i] + a[j]) == target) {
                if (i < j) {
                    res.first = i;
                    res.second = j;
                } else {
                    res.first = j;
                    res.second = i;
                }
                return res;
            }
        }
    }

    return res;
}

/**
    Returns the pair (i, j) with i < j. If more than one solution exists,
    returns the pair whose first index is the smallest, scanning the vector from left to right.
 */
std::pair<int, int> check_vector_and_target_v1b(const std::vector<int>& a, const int target) {
    std::pair<int, int> res(0, 0); // result pair, (0, 0) is the default value if no solution is found, a valid solution will always have i != j

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a.size(); j++) {
            if (j == i) continue;

            if ((a[i] + a[j]) == target) {
                if (i < j) {
                    res.first = i;
                    res.second = j;
                } else {
                    res.first = j;
                    res.second = i;
                }
                return res;
            }
        }
    }

    return res;
}

/**
    Solution 1:
    ~ n x (n-1) comparisons -> O(nˆ2) time complexity
    O(1) space complexity
*/
std::pair<int, int> check_vector_and_target_v1(const std::vector<int>& a, const int target) {
   return check_vector_and_target_v1a(a, target);
}


/**
    Solution 2:
    ~ O(n) time complexity to read the array
    ~ O(n) space complexity for the extra hash map

    Returns the pair (i, j) with i < j. If more than one solution exists,
    returns the pair whose second index is the smallest, scanning the vector from left to right.
*/
std::pair<int, int> check_vector_and_target_v2(const std::vector<int>& a, const int target, bool debug = false) {
    std::unordered_map<int, int> m = {};
    std::pair<int, int> res(0, 0); // result pair, (0, 0) is the default value if no solution is found, a valid solution will always have i != j

    // note: target = a[i] + a[j] for some i != j
    for (size_t i = 0; i < a.size(); i++) {
        std::unordered_map<int, int>::iterator it;
        if ((it = m.find(a[i])) != m.end()) {
            if (debug) print_sorted_map(m);

            res.first = it->second; // j
            res.second = i;
            return res;
        }
        m[target - a[i]] = i;
    }

    if (debug) print_sorted_map(m);

    return res;
}

int main(int argc, char* argv[]) {
    bool debug = argc > 1 && std::string(argv[1]) == "-d";

    std::vector<int> a1 = {3, 2, 4};
    std::vector<int> a2 = {1, 2};
    int target1 = 6;
    int target2 = 10;
    
    std::pair<int, int> res1 = {};
    std::pair<int, int> res2 = {};
    std::cout << "Arguments a = {3, 2, 4}, target = 6, expected result (1, 2)." << std::endl;

    res1 = check_vector_and_target_v1(a1, target1);
    std::cout << "Solution 1 result: (" << res1.first << ", " << res1.second << ")" << std::endl;

    res2 = check_vector_and_target_v2(a1, target1, debug);
    std::cout << "Solution 2 result: (" << res2.first << ", " << res2.second << ")" << std::endl;

    std::cout << "Arguments a = {1, 2}, target = 10, expected result (0, 0)." << std::endl;

    res1 = check_vector_and_target_v1(a2, target2);
    std::cout << "Solution 1 result: (" << res1.first << ", " << res1.second << ")" << std::endl;

    res2 = check_vector_and_target_v2(a2, target2, debug);
    std::cout << "Solution 2 result: (" << res2.first << ", " << res2.second << ")" << std::endl;

    return 0;
}