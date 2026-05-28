class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        
        int current_sum = 0;
        int result = 0;
        
        for (int num : nums) {
            current_sum += (num % 2 != 0); 
            if (prefix_counts.find(current_sum - k) != prefix_counts.end()) {
                result += prefix_counts[current_sum - k];
            }
            prefix_counts[current_sum]++;
        }
        
        return result;
    }
};