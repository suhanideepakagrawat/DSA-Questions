class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to track the position of valid elements
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not the one we want to remove
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move it to the front at index k
                k++;               // Increment the count of valid elements
            }
        }
        
        // k represents the number of elements not equal to val
        return k;
    }
};