class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        vector<int> up(k, 0), down(k, 0);
        for (int v = 0; v < k; v++) {
            up[v] = v;               
            down[v] = k - 1 - v;     
        }
        if (n == 2) {
            long long ans = 0;
            for (int v = 0; v < k; v++) {
                ans = (ans + up[v] + down[v]) % MOD;
            }
            return (int)ans;
        }
        for (int len = 3; len <= n; len++) {
            vector<int> newUp(k, 0), newDown(k, 0);
            vector<int> prefDown(k, 0);
            vector<int> suffUp(k, 0);
            prefDown[0] = down[0];
            for (int i = 1; i < k; i++) {
                prefDown[i] = prefDown[i - 1] + down[i];
                if (prefDown[i] >= MOD) prefDown[i] -= MOD;
            }
            suffUp[k - 1] = up[k - 1];
            for (int i = k - 2; i >= 0; i--) {
                suffUp[i] = suffUp[i + 1] + up[i];
                if (suffUp[i] >= MOD) suffUp[i] -= MOD;
            }
            for (int v = 0; v < k; v++) {
                if (v > 0)
                    newUp[v] = prefDown[v - 1];

                if (v + 1 < k)
                    newDown[v] = suffUp[v + 1];
            }
            up.swap(newUp);
            down.swap(newDown);
        }
        long long ans = 0;
        for (int v = 0; v < k; v++) {
            ans += up[v];
            ans += down[v];
            ans %= MOD;
        }
        return (int)ans;
    }
};