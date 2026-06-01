class Solution {
private:
    const vector<string> phoneMap = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };
    void backtrack(string digits, int index, string current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        int digitNum = digits[index] - '0';
        string letters = phoneMap[digitNum];
        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        backtrack(digits, 0, "", result);
        return result;
    }
};