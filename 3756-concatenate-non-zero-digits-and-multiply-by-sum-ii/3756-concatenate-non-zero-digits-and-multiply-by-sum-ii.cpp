class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int mod = 1e9 + 7;
        int max_nz = 0;
        for (char c : s) {
            if (c != '0') max_nz++;
        }
        vector<long long> pow10(max_nz + 1, 1);
        for (int i = 1; i <= max_nz; i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }
        vector<int> cnt(n + 1, 0);
        vector<long long> V(max_nz + 1, 0);
        vector<int> D(max_nz + 1, 0);
        int k = 0;
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            if (s[i] != '0') {
                k++;
                cnt[i + 1] = k;
                V[k] = (V[k - 1] * 10 + (s[i] - '0')) % mod;
                D[k] = D[k - 1] + (s[i] - '0');
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int a = cnt[l];
            int b = cnt[r + 1];
            if (a == b) {
                ans.push_back(0);
            } else {
                int len = b - a;
                long long x = (V[b] - (V[a] * pow10[len]) % mod + mod) % mod;
                long long sum = D[b] - D[a];
                ans.push_back((x * sum) % mod);
            }
        }
        return ans;
    }
};