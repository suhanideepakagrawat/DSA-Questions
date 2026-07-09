class Solution {
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                unite(i, i + 1);
            }
        }
        vector<bool> result;
        for (const auto& q : queries) {
            if (find(q[0]) == find(q[1])) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};