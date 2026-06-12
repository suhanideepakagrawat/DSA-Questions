#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Parallel arrays (or a vector of pairs) sorting values in descending order.
        // Including subtractive forms makes the greedy choice straightforward.
        const vector<pair<int, string>> romanMapping = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        // Loop through the mappings from largest value to smallest
        for (const auto& [value, symbol] : romanMapping) {
            // While the current value can be subtracted from num
            while (num >= value) {
                result += symbol;
                num -= value;
            }
            // Early exit if num becomes 0
            if (num == 0) break;
        }
        
        return result;
    }
};