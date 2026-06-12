class Solution {
private:
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    const int MOD = 1e9 + 7;

    // DFS to precompute depths and the first ancestor (2^0) for each node
    void dfs(int node, int parent, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        for (int i = 1; i < LOG; ++i) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Function to find the Lowest Common Ancestor using Binary Lifting
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        
        // Bring both nodes to the same depth
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        // Lift both nodes simultaneously right before they meet
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1; // Number of nodes is edges + 1 in a tree
        
        // 1. Build Adjacency List
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 2. Initialize Binary Lifting structures
        LOG = ceil(log2(n)) + 1;
        up.assign(n + 1, vector<int>(LOG, 1));
        depth.assign(n + 1, 0);
        
        // Kick off DFS from root node 1 (treating its parent as 1)
        dfs(1, 1, 0, adj);
        
        // 3. Precompute Powers of 2 up to N for O(1) retrieval
        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        
        // 4. Process Queries
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            if (u == v) {
                answer.push_back(0); // 0 edges means path sum is 0 (even). 0 ways to make it odd.
                continue;
            }
            
            int lca = get_lca(u, v);
            int L = depth[u] + depth[v] - 2 * depth[lca]; // Path length (number of edges)
            
            // Number of ways to get an odd sum on a path of length L is 2^(L-1)
            answer.push_back(pow2[L - 1]);
        }
        
        return answer;
    }
};