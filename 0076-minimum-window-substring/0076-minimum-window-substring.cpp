class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        unordered_map<char, int> hash;
        for (char c : t) hash[c]++;

        int l = 0, r = 0, cnt = 0, sIndex = -1;
        int minlen = INT_MAX;

        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};
