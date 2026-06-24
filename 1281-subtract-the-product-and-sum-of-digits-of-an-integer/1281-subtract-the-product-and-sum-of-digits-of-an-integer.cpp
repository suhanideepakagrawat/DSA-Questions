class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit_product = 1;
        int digit_sum = 0;
        while (n > 0) {
            int current_digit = n % 10; 
            digit_product *= current_digit;
            digit_sum += current_digit;
            n /= 10; 
        }
        return digit_product - digit_sum;
    }
};