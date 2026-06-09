class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if (nums.empty() or k == 0) return 0;
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        long long max_single_value = static_cast<long long>(max_val) - min_val;
        return max_single_value * k;
    }
};