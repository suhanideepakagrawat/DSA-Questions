class Solution {
public:
    std::string mapWordWeights(std::vector<std::string>& words, std::vector<int>& weights) {
        std::string result = "";
        for (const std::string& word : words) {
            long long totalWeight = 0;
            for (char ch : word) {
                totalWeight += weights[ch - 'a'];
            }
            int remainder = totalWeight % 26;
            char mappedChar = 'z' - remainder;
            result += mappedChar;
        }
        return result;
    }
};