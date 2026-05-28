class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
       unordered_map<int,int> hash;
       int n = nums.size();
       int complement = 0;
       for (int i = 0; i < n ; i++){
        complement = target - nums[i];
        if (hash.find(complement) != hash.end()){
            return {hash[complement] + 1, i+1};
        }
        hash[nums[i]] = i;
       }
     return {};
    }
};