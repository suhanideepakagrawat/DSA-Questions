#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct State {
    long long value;
    int l;
    int search_left;
    int search_right;
    int best_r;

    // Max-Heap priority based on subarray value
    bool operator<(const State& other) const {
        return value < other.value;
    }
};

class Solution {
private:
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;
    int n;

    void buildSparseTables(const vector<int>& nums) {
        int max_log = log2(n) + 1;
        st_max.assign(n, vector<int>(max_log));
        st_min.assign(n, vector<int>(max_log));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // O(1) calculation of value given exact boundaries
    long long getVal(int l, int r) {
        if (l > r) return -1;
        int k = lg[r - l + 1];
        int mx = max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
        int mn = min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
        return (long long)mx - mn;
    }

public:
    // Alias wrapper for LeetCode's template system signature mismatch
    long long maxTotalValue(vector<int>& nums, int k) {
        return maximumTotalValue(nums, k);
    }

    long long maximumTotalValue(vector<int>& nums, int k) {
        n = nums.size();
        buildSparseTables(nums);

        priority_queue<State> pq;

        // Initialize heap for each starting index 'l'
        // Property: For a fixed 'l', value(l, r) is non-decreasing with 'r'.
        // Hence, in the initial window [l, n-1], the max value is always at r = n-1.
        for (int l = 0; l < n; l++) {
            int best_r = n - 1; 
            long long val = getVal(l, best_r);
            pq.push({val, l, l, n - 1, best_r});
        }

        long long total_value = 0;

        // Extract top k elements efficiently
        while (k-- > 0 && !pq.empty()) {
            State curr = pq.top();
            pq.pop();

            total_value += curr.value;

            // Split the range around the used best_r
            // Since best_r was picking the maximum element position in the subsegment,
            // the next optimal choices within the split ranges will be their respective rightmost boundaries.
            if (curr.best_r > curr.search_left) {
                int next_r1 = curr.best_r - 1; 
                long long val1 = getVal(curr.l, next_r1);
                pq.push({val1, curr.l, curr.search_left, curr.best_r - 1, next_r1});
            }
            if (curr.best_r < curr.search_right) {
                int next_r2 = curr.search_right;
                long long val2 = getVal(curr.l, next_r2);
                pq.push({val2, curr.l, curr.best_r + 1, curr.search_right, next_r2});
            }
        }

        return total_value;
    }
};