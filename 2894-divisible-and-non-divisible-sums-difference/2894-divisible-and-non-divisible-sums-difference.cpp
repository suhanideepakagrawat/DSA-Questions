class Solution {
public:
    int differenceOfSums(int n, int m) {
        // 1. Calculate total sum of 1 to n
        int total_sum = n * (n + 1) / 2;
        
        // 2. Find how many multiples of m exist up to n
        int k = n / m;
        
        // 3. Calculate sum of those multiples (num2)
        int num2 = m * (k * (k + 1) / 2);
        
        // 4. Return total_sum - 2 * num2 (which equals num1 - num2)
        return total_sum - 2 * num2;
    }
};