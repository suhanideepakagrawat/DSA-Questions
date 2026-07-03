class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);
        int l = INT_MAX, r = 0;
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (!online[u] || !online[v]) continue;
            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }
        
        if (l > r) return -1;
        
        auto check = [&](int mid) {
            vector<long long> dis(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            
            dis[0] = 0;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > k) return false;
                if (u == n - 1) return true;
                if (d > dis[u]) continue;
                
                for (auto& [v, w] : g[u]) {
                    if (w >= mid) {
                        long long new_d = d + w; 
                        if (new_d < dis[v]) {
                            dis[v] = new_d;
                            pq.push({new_d, v});
                        }
                    }
                }
            }
            return false;
        };
        
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return res;
    }
};