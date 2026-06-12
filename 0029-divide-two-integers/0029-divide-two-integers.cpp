class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. Handle the explicit overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // 2. Determine the sign of the quotient
        // True if one is negative and the other is positive
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // 3. Work with absolute values using long long to prevent overflow
        long long absDividend = std::labs((long long)dividend);
        long long absDivisor = std::labs((long long)divisor);
        
        long long quotient = 0;
        
        // 4. Perform bitwise exponential subtraction
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;
            
            // Double the divisor until it's larger than the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest found chunk and add its multiple to the quotient
            absDividend -= tempDivisor;
            quotient += multiple;
        }
        
        // 5. Apply the sign and return
        return isNegative ? -quotient : quotient;
    }
};