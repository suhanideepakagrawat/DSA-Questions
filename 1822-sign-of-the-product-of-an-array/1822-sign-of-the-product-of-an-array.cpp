class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        int sign = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                return 0; 
            }
            if (nums[i] < 0) {
                sign = -sign; 
            }
        }
        return sign;
    }
};