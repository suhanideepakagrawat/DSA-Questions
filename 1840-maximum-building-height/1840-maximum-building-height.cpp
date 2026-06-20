class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
            restrictions[i+1][1] = min(h2, h1 + (id2 - id1));
        }
        
        for (int i = m - 1; i > 0; --i) {
            int id1 = restrictions[i-1][0], h1 = restrictions[i-1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            restrictions[i-1][1] = min(h1, h2 + (id2 - id1));
        }
        
        int maxHeight = 0;
        
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
            int max_possible = (h1 + h2 + (id2 - id1)) / 2;
            maxHeight = max(maxHeight, max_possible);
        }
        
        int last_id = restrictions.back()[0];
        int last_h = restrictions.back()[1];
        maxHeight = max(maxHeight, last_h + (n - last_id));
        
        return maxHeight;
    }
};