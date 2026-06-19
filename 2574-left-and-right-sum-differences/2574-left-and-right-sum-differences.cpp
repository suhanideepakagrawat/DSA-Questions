#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);
        
        // Calculate the total sum of the array
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            // rightSum is the remaining total minus leftSum and the current element
            int rightSum = totalSum - leftSum - nums[i];
            
            // Store the absolute difference
            answer[i] = std::abs(leftSum - rightSum);
            
            // Update leftSum to include the current element for the next iteration
            leftSum += nums[i];
        }
        
        return answer;
    }
};