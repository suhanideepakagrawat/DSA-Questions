class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int temp_num = num;
        while(temp_num > 0){
            int divisor = temp_num % 10;
            if (num % divisor == 0){
                count++;
            }
            temp_num = temp_num / 10;
        }
    return count; 
    }
};