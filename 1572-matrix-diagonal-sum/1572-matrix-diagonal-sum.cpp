#include <vector>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; ++i) {
            totalSum += mat[i][i];
            totalSum += mat[i][n - 1 - i];
        }
        if (n % 2 != 0) {
            totalSum -= mat[n / 2][n / 2];
        }
        
        return totalSum;
    }
};