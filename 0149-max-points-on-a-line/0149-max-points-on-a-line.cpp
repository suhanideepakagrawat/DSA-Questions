class Solution {
private:
    int get_gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int max_pts = 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slope_counts;
            int local_max = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = get_gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                slope_counts[{dx, dy}]++;
                local_max = max(local_max, slope_counts[{dx, dy}]);
            }
            max_pts = max(max_pts, local_max + 1);
        }
        return max_pts;
    }
};