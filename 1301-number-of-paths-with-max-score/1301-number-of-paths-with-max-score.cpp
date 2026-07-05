class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp_sum(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dp_cnt(n + 1, vector<int>(n + 1, 0));
        dp_sum[n - 1][n - 1] = 0;
        dp_cnt[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'S' || board[i][j] == 'X') {
                    continue;
                }
                int max_val = max({dp_sum[i + 1][j], dp_sum[i][j + 1], dp_sum[i + 1][j + 1]});
                if (max_val == -1) {
                    continue;
                }
                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                dp_sum[i][j] = max_val + val;
                if (dp_sum[i + 1][j] == max_val) {
                    dp_cnt[i][j] = (dp_cnt[i][j] + dp_cnt[i + 1][j]) % mod;
                }
                if (dp_sum[i][j + 1] == max_val) {
                    dp_cnt[i][j] = (dp_cnt[i][j] + dp_cnt[i][j + 1]) % mod;
                }
                if (dp_sum[i + 1][j + 1] == max_val) {
                    dp_cnt[i][j] = (dp_cnt[i][j] + dp_cnt[i + 1][j + 1]) % mod;
                }
            }
        }
        if (dp_sum[0][0] == -1) {
            return {0, 0};
        }
        return {dp_sum[0][0], dp_cnt[0][0]};
    }
};