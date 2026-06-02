class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                int val = board[r][c] - '1';
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (rows[r][val] || cols[c][val] || boxes[boxIndex][val]) {
                    return false;
                }
                rows[r][val] = 1;
                cols[c][val] = 1;
                boxes[boxIndex][val] = 1;
            }
        } 
        return true;
    }
};