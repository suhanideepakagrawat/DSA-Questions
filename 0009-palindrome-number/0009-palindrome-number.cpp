class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int original = x;
        long reversed = 0; 
        while (x > 0) {
            int last_digit = x % 10;        
            reversed = (reversed * 10) + last_digit; 
            x = x / 10;                       
        }
        return reversed == original;
    }
};