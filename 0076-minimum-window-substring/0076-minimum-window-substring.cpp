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
            // If we find a char that is needed, increment cnt
            if (hash[s[r]] > 0) cnt++;
            
            // Decrement the map for the current char (even if it goes negative)
            hash[s[r]]--;

            // When window contains all chars from t
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }

                // Try to shrink from the left
                hash[s[l]]++;
                // If the char was essential (count becomes > 0), we broke the window
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};
